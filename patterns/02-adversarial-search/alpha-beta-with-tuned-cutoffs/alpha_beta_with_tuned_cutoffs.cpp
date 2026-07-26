// Pattern: Alpha-beta with tuned cutoff conditions
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Parcherckers -> src/AIPlayer.cpp (lines 1354-1425)
//          https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L1354
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

float Poda_AlfaBeta_Mejorada(const Parchis &actual, int jugador, int profundidad, int profundidad_max, color &c_piece, int &id_piece, int &dice, float alpha, float beta, Heuristic *heuristic, float epsilon_prune) {
   // Caso base: nodo terminal o profundidad límite
   if (profundidad == profundidad_max || actual.gameOver()) {
         return heuristic->evaluate(actual, jugador);
   }

   // Recojo hijos en un vector para poder ordenarlos
   vector<ParchisSis> hijos = actual.getChildrenList();

   // Ordenación de movimientos (solo en la raíz)
   if (profundidad == 0) {
         sort(hijos.begin(), hijos.end(), [&](const ParchisSis &a, const ParchisSis &b) {
            float ha = heuristic->evaluate(*a, jugador);
            float hb = heuristic->evaluate(*b, jugador);
            return ha > hb;
         });
   }

   // Profundidad dinámica
   int nueva_profundidad_max = profundidad_max;
   if (profundidad == 0) {
         int n_hijos = hijos.size();
         if (n_hijos <= 4) {
            nueva_profundidad_max = min(profundidad_max + 1, 10);
         } else if (n_hijos >= 12) {
            nueva_profundidad_max = max(profundidad_max - 1, 3);
         }
   }

   bool es_max = (actual.getCurrentPlayerId() == jugador);
   float valor = es_max ? menosinf : masinf;

   for (const auto &hijo_sis : hijos) {
         if (NodeCounter::isLimitReached()) {
            if (profundidad == 0) {
               c_piece  = hijo_sis.getMovedColor();
               id_piece = hijo_sis.getMovedPieceId();
               dice     = hijo_sis.getMovedDiceValue();
            }
            return valor;
         }

         Parchis hijo = *hijo_sis;
         float new_val = Poda_AlfaBeta_Mejorada(hijo, jugador, profundidad + 1, nueva_profundidad_max, c_piece, id_piece, dice, alpha, beta, heuristic, epsilon_prune);

         if (es_max) {
            if (new_val > valor) {
               valor = new_val;
               if (profundidad == 0) {
                     c_piece  = hijo_sis.getMovedColor();
                     id_piece = hijo_sis.getMovedPieceId();
                     dice     = hijo_sis.getMovedDiceValue();
               }
            }
            alpha = max(alpha, valor);
            // Poda probabilística
            if (beta <= alpha + epsilon_prune) {
               break;
            }
         } else {
            if (new_val < valor) {
               valor = new_val;
            }
            beta = min(beta, valor);
            // Poda probabilística
            if (beta <= alpha + epsilon_prune) {
               break;
            }
         }
   }
   return valor;
}
