// Pattern: Alpha-beta with move ordering
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Parcherckers -> src/AIPlayer.cpp (lines 692-757)
//          https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L692
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// =====================================================
// ==                   Poda Alfa Beta Ordenada                  ==
// =====================================================
float PodaAlfaBetaOrdenada(const Parchis &actual, int jugador, int profundidad, int profundidad_max, color &c_piece, int &id_piece, int &dice, float alpha, float beta, Heuristic *heuristic) {
   if (profundidad == profundidad_max || actual.gameOver()) return heuristic->evaluate(actual, jugador);

   bool esMax = (actual.getCurrentPlayerId() == jugador);

   // 1) Recojo hijos en un vector con su evaluación heurística
   vector<NodeInfo> lista;
   ParchisBros hijos = actual.getChildren();
   int n_hijos = 0;
   for (ParchisBros::Iterator it = hijos.begin(); it != hijos.end(); ++it) ++n_hijos;
   lista.reserve(n_hijos);
   for (ParchisBros::Iterator it = hijos.begin(); it != hijos.end(); ++it) {
         Parchis hijo = *it;
         color   cm   = it.getMovedColor();
         int     im   = it.getMovedPieceId();
         int     dm   = it.getMovedDiceValue();
         float   h    = heuristic->evaluate(hijo, jugador);
         lista.push_back({ hijo, cm, im, dm, h });
   }

   // 2) Ordeno la lista: si es MAX, descendente; si es MIN, ascendente
   if (esMax) {
         sort(lista.begin(), lista.end(), [](const NodeInfo &a, const NodeInfo &b) { return a.score > b.score; });
   } else {
         sort(lista.begin(), lista.end(), [](const NodeInfo &a, const NodeInfo &b) { return a.score < b.score; });
   }

   // 3) Itero sobre la lista ordenada para poda alfa-beta
   if (esMax) {
         float valor = menosinf;
         for (const NodeInfo &ni : lista) {
            if (NodeCounter::isLimitReached()) {
               if (profundidad == 0) {
                     c_piece  = ni.c_move;
                     id_piece = ni.id_move;
                     dice     = ni.dice_move;
               }
               return valor;
            }
            float new_val = PodaAlfaBetaOrdenada(ni.estado, jugador, profundidad + 1, profundidad_max, c_piece, id_piece, dice, alpha, beta, heuristic);
            if (new_val > valor) {
               valor = new_val;
               if (profundidad == 0) {
                     c_piece  = ni.c_move;
                     id_piece = ni.id_move;
                     dice     = ni.dice_move;
               }
            }
            if (valor > alpha) alpha = valor;
            if (alpha >= beta) break;
         }
         return valor;
   } else {
         float valor = masinf;
         for (const NodeInfo &ni : lista) {
            if (NodeCounter::isLimitReached()) {
               return heuristic->evaluate(actual, jugador);
            }
            float new_val = PodaAlfaBetaOrdenada(ni.estado, jugador, profundidad + 1, profundidad_max, c_piece, id_piece, dice, alpha, beta, heuristic);
            if (new_val < valor) valor = new_val;
            if (valor < beta) beta = valor;
            if (beta <= alpha) break;
         }
         return valor;
   }
}
