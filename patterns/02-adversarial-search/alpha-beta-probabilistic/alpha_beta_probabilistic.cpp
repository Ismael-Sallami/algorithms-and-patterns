// Pattern: Probabilistic cutoff in a chance node tree
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Parcherckers -> src/AIPlayer.cpp (lines 1139-1207)
//          https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L1139
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// =====================================================
// ==                   Probabilística                  ==
// =====================================================
float Poda_AlfaBeta_Probabilistica(const Parchis &actual, int jugador, int profundidad, int profundidad_max,color &c_piece, int &id_piece, int &dice,float alpha, float beta, Heuristic *heuristica,float epsilon_prune) { // Nuevo parámetro epsilon

   // if (profundidad == profundidad_max || actual.gameOver()) {
   //    return heuristica->evaluate(actual, jugador);
   // }

   // PruebaImprimirVariables(); // Imprime las variables de la heurística,es para una prueba de depuración

   if (actual.gameOver()) { // Si la partida realmente ha terminado
      return heuristica->evaluate(actual, jugador);
   }
  if (profundidad == profundidad_max) { // Límite de profundidad principal alcanzado
      return BusquedaQuietud(actual, jugador, alpha, beta, heuristica, 0, MAX_PROFUNDIDAD_QUIETUD);
   }

   bool es_nodo_max = (actual.getCurrentPlayerId() == jugador);
   float valor_nodo_actual = es_nodo_max ? menosinf : masinf;

   ParchisBros hijos = actual.getChildren(); // Para la versión sin ordenación de movimientos.

   if (hijos.begin() == hijos.end() && profundidad < profundidad_max && !actual.gameOver()) {
      return heuristica->evaluate(actual, jugador);
   }

   for (ParchisBros::Iterator it = hijos.begin(); it != hijos.end(); ++it) {
      if (NodeCounter::isLimitReached()) {
         return (es_nodo_max ? (valor_nodo_actual == menosinf ? heuristica->evaluate(actual, jugador) : valor_nodo_actual) : (valor_nodo_actual == masinf ? heuristica->evaluate(actual, jugador) : valor_nodo_actual));
      }

      Parchis estado_hijo = *it;

      // Llamada recursiva (pasando epsilon también, aunque no se usa en niveles más profundos
      float valor_hijo = Poda_AlfaBeta_Probabilistica(estado_hijo, jugador, profundidad + 1, profundidad_max,c_piece, id_piece, dice,alpha, beta, heuristica, epsilon_prune);

      if (es_nodo_max) {
         if (valor_hijo > valor_nodo_actual) {
            valor_nodo_actual = valor_hijo;
            if (profundidad == 0) {
               c_piece = it.getMovedColor();
               id_piece = it.getMovedPieceId();
               dice = it.getMovedDiceValue();
            }
         }
         alpha = max(alpha, valor_nodo_actual);

         /* --- Condición de Poda Modificada ---
         Poda estándar: beta <= alpha
         Poda probabilística: si beta no es "suficientemente mejor" que alpha, podamos.
         "Suficientemente mejor" significa beta > alpha + epsilon_prune
         Por lo tanto, podamos si beta <= alpha + epsilon_prune*/

         if (beta <= alpha + epsilon_prune) { // (concepto de umbral y condición)
            // cout << "Poda Prob. MAX: beta(" << beta << ") <= alpha(" << alpha << ") + eps(" << epsilon_prune << ")" << endl;
            break;
         }
      } else { // Nodo MIN
         if (valor_hijo < valor_nodo_actual) {
            valor_nodo_actual = valor_hijo;
         }
         beta = min(beta, valor_nodo_actual);

         if (beta <= alpha + epsilon_prune) { //(concepto de umbral y condición)
            // cout << "Poda Prob. MIN: beta(" << beta << ") <= alpha(" << alpha << ") + eps(" << epsilon_prune << ")" << endl;
            break;
         }
      }
   }
   return valor_nodo_actual;
}
