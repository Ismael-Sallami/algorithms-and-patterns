// Pattern: Quiescence search at the horizon
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/parchis-ai -> src/AIPlayer.cpp (lines 1025-1107)
//          https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L1025-L1107
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

float BusquedaQuietud(const Parchis &actual, int jugador_IA, float alpha, float beta, Heuristic *heuristica, int profundidad_q, int max_profundidad_q) {

   // Comprobación de límite de nodos también aquí
   if (NodeCounter::isLimitReached()) {
         return heuristica->evaluate(actual, jugador_IA); // Fallback si se alcanza el límite
   }

   // "Stand-pat" score: la evaluación del nodo actual si no se hacen más movimientos tácticos.
   // Esto representa el valor mínimo que el jugador actual puede obtener si decide "quedarse quieto".
   float stand_pat_score = heuristica->evaluate(actual, jugador_IA);

   // Si hemos alcanzado la profundidad máxima de la búsqueda de quietud, o la partida ha terminado.
   if (profundidad_q == max_profundidad_q || actual.gameOver()) {
      return stand_pat_score;
   }

   bool es_nodo_max_q = (actual.getCurrentPlayerId() == jugador_IA);

   if (es_nodo_max_q) { // Nodo MAX en la búsqueda de quietud
         // Si el stand_pat_score ya es mejor que lo que MAX puede obtener en otras ramas,

         if (stand_pat_score >= beta) { // El oponente (MIN) no dejaría que esto ocurra si tiene algo mejor
            return stand_pat_score;    // podemos retornar beta, oero tras probar, parece que no es lo correcto
      }
      alpha = max(alpha, stand_pat_score);
   } else { // Nodo MIN en la búsqueda de quietud
         // Si el stand_pat_score ya es peor para MAX que lo que MIN puede forzar en otras ramas,
         if (stand_pat_score <= alpha) { // MAX no elegiría este camino si tiene algo mejor
            return stand_pat_score;     
      }
      beta = min(beta, stand_pat_score);
   }

   // Generar SOLO movimientos tácticos/relevantes, entendemos como tácticos aquellos que pueden cambiar significativamente el estado del juego.
   vector<ParchisSis> todos_hijos = actual.getChildrenList();
   vector<ParchisSis> movimientos_tacticos;

   for (const auto& parchis_sis_hijo : todos_hijos) {
         Parchis estado_hijo_potencial = *parchis_sis_hijo;
      bool es_tactico = false;

         // Criterios para movimiento táctico (ejemplos):
      if (estado_hijo_potencial.isEatingMove()) es_tactico = true;
      if (!es_tactico && estado_hijo_potencial.isGoalMove()) es_tactico = true;

      if (es_tactico) {
         movimientos_tacticos.push_back(parchis_sis_hijo);
      }
   }

   // Si no hay movimientos tácticos, el estado es "quieto".
   if (movimientos_tacticos.empty()) {
      return stand_pat_score;
   }

   if (es_nodo_max_q) {
         float mejor_valor_q = stand_pat_score; // Empezamos con el valor de no hacer nada táctico

      for (const auto& movimiento_tactico_sis : movimientos_tacticos) {
         Parchis estado_hijo_tactico = *movimiento_tactico_sis;
         float valor_hijo = BusquedaQuietud(estado_hijo_tactico, jugador_IA, alpha, beta, heuristica, profundidad_q + 1, max_profundidad_q);
         mejor_valor_q = max(mejor_valor_q, valor_hijo);
         alpha = max(alpha, mejor_valor_q);
         if (beta <= alpha) { // Poda
            break;
         }
      }
      return mejor_valor_q;
   } else { // Nodo MIN en la búsqueda de quietud
         float peor_valor_q = stand_pat_score; // Empezamos con el valor de no hacer nada táctico

         for (const auto& movimiento_tactico_sis : movimientos_tacticos) {
            Parchis estado_hijo_tactico = *movimiento_tactico_sis;
            float valor_hijo = BusquedaQuietud(estado_hijo_tactico, jugador_IA, alpha, beta, heuristica, profundidad_q + 1, max_profundidad_q);
            peor_valor_q = min(peor_valor_q, valor_hijo);
            beta = min(beta, peor_valor_q);
            if (beta <= alpha) { // Poda
               break;
            }
         }
         return peor_valor_q;
      }
}
