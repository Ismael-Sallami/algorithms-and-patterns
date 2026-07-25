// Pattern: Probabilistic alpha-beta with depth-dependent ordering
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Parcherckers -> src/AIPlayer.cpp (lines 1213-1277)
//          https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L1213
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// =====================================================
// ==                   Combinación de Poda                  ==
// =====================================================
float Poda_AlfaBeta_Probabilistica2_Ordenada_Dinamica(const Parchis &actual, int jugador, int profundidad, int profundidad_max, color &c_piece, int &id_piece, int &dice, float alpha, float beta, Heuristic *heuristica, float epsilon_prune) {

   if (actual.gameOver()) {
      return heuristica->evaluate(actual, jugador);
   }

   if (profundidad == profundidad_max) {
      return BusquedaQuietud(actual, jugador, alpha, beta, heuristica, 0, MAX_PROFUNDIDAD_QUIETUD);
   }

   bool esMax = (actual.getCurrentPlayerId() == jugador);
   float valor_actual = esMax ? menosinf : masinf;

   vector<ParchisSis> hijos = actual.getChildrenList();

   if (hijos.empty()) {
      return heuristica->evaluate(actual, jugador);
   }

   if (profundidad == 0) {
      sort(hijos.begin(), hijos.end(), [&](const ParchisSis &a, const ParchisSis &b) {
         float va = heuristica->evaluate(*a, jugador);
         float vb = heuristica->evaluate(*b, jugador);
         return va > vb;
      });
   }

   int nueva_profundidad_max = profundidad_max;
   if (profundidad == 0) {
      int ramificacion = hijos.size();
      if (ramificacion <= UMBRAL_RAM_BAJA) {
         nueva_profundidad_max = min(profundidad_max + 1, 10);
      } else if (ramificacion >= UMBRAL_RAM_ALTA) {
         nueva_profundidad_max = max(profundidad_max - 1, 3);
      }
   }

   for (const auto &hijo : hijos) {
      if (NodeCounter::isLimitReached()) {
         return (esMax ? (valor_actual == menosinf ? heuristica->evaluate(actual, jugador) : valor_actual): (valor_actual == masinf ? heuristica->evaluate(actual, jugador) : valor_actual));
      }

      float valor_hijo = Poda_AlfaBeta_Probabilistica2_Ordenada_Dinamica(*hijo, jugador, profundidad + 1, nueva_profundidad_max, c_piece, id_piece, dice, alpha, beta, heuristica, epsilon_prune);

      if (esMax) {
         if (valor_hijo > valor_actual) {
               valor_actual = valor_hijo;
               if (profundidad == 0) {
                  c_piece  = hijo.getMovedColor();
                  id_piece = hijo.getMovedPieceId();
                  dice     = hijo.getMovedDiceValue();
               }
         }
         alpha = max(alpha, valor_actual);
         if (beta <= alpha + epsilon_prune) break;
      } else {
         if (valor_hijo < valor_actual) {
               valor_actual = valor_hijo;
         }
         beta = min(beta, valor_actual);
         if (beta <= alpha + epsilon_prune) break;
      }
   }
   return valor_actual;
}
