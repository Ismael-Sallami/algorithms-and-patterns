// Pattern: Weighted linear evaluation over hand-picked features
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Parcherckers -> src/AIPlayer.cpp (lines 766-874)
//          https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L766
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// =====================================================
// ==                   Heurística 2                  ==
// =====================================================
float Heur2::getHeuristic(const Parchis &estado, int jugador) const {
   static constexpr float GANA   = +1e7f;
   static constexpr float PIERDE = -1e7f;

   int oponente = (jugador + 1) % 2;
   int ganador  = estado.getWinner();
   if (ganador == jugador)  return GANA;
   if (ganador == oponente) return PIERDE;

   std::vector<color> mis_colores = estado.getPlayerColors(jugador);
   std::vector<color> op_colores  = estado.getPlayerColors(oponente);

   std::unordered_map<int, std::pair<int,int>> contadorPorCaja;
   for (color c : mis_colores) {
         for (int i = 0; i < num_pieces; ++i) {
            const Box &caja = estado.getBoard().getPiece(c, i).get_box();
            contadorPorCaja[caja.num].first++;
         }
   }
   for (color c : op_colores) {
         for (int i = 0; i < num_pieces; ++i) {
            const Box &caja = estado.getBoard().getPiece(c, i).get_box();
            contadorPorCaja[caja.num].second++;
         }
   }

   int total_barreras_mias = 0;
   int total_barreras_opp  = 0;
   for (auto &kv : contadorPorCaja) {
         if (kv.second.first  >= 2) total_barreras_mias++;
         if (kv.second.second >= 2) total_barreras_opp++;
   }

   int min_dist_op = INT_MAX;
   for (color c : op_colores) {
         for (int i = 0; i < num_pieces; ++i) {
            const Box &caja = estado.getBoard().getPiece(c, i).get_box();
            if (caja.type == goal) {
               min_dist_op = 0;
               break;
            }
            int dist = estado.distanceToGoal(c, i);
            if (dist < min_dist_op) min_dist_op = dist;
         }
   }
   if (min_dist_op == INT_MAX) min_dist_op = MAX_DISTANCIA_CONST;

   float puntuacion_mia = 0.0f;
   for (color c : mis_colores) {
         for (int i = 0; i < num_pieces; ++i) {
            const Piece &ficha = estado.getBoard().getPiece(c, i);
            const Box   &caja  = ficha.get_box();

            if (caja.type == home) {
               puntuacion_mia += PESO_ULTRA_PIEZA_EN_CASA;
               continue;
            }
            if (caja.type == goal) {
               puntuacion_mia += PESO_ULTRA_FICHA_META;
               continue;
            }

            int dist = estado.distanceToGoal(c, i);
            puntuacion_mia += PESO_ULTRA_PROGRESO * (MAX_DISTANCIA_CONST - dist);

            if (estado.isSafePiece(c, i)) {
               puntuacion_mia += PESO_ULTRA_FICHA_SEGURA;
            }
            if (contadorPorCaja[caja.num].first >= 2) {
               puntuacion_mia += PESO_ULTRA_BARRERA_PROPIA;
            }
            if (dist < min_dist_op) {
               puntuacion_mia += PESO_ULTRA_DISTANCIA_RELATIVA * (min_dist_op - dist);
            }
         }
   }

   float puntuacion_opp = 0.0f;
   for (color c : op_colores) {
         for (int i = 0; i < num_pieces; ++i) {
            const Piece &ficha = estado.getBoard().getPiece(c, i);
            const Box   &caja  = ficha.get_box();

            if (caja.type == home) {
               puntuacion_opp += PESO_ULTRA_PIEZA_EN_CASA;
               continue;
            }
            if (caja.type == goal) {
               puntuacion_opp += PESO_ULTRA_FICHA_META;
               continue;
            }

            int dist = estado.distanceToGoal(c, i);
            puntuacion_opp += PESO_ULTRA_PROGRESO * (MAX_DISTANCIA_CONST - dist);

            if (estado.isSafePiece(c, i)) {
               puntuacion_opp += PESO_ULTRA_FICHA_SEGURA;
            }
            if (contadorPorCaja[caja.num].second >= 2) {
               puntuacion_opp += PESO_ULTRA_BARRERA_PROPIA;
            }
         }
   }

   float penalizacion_barrera_opp = PESO_ULTRA_BARRERA_OPONENTE * total_barreras_opp;
   float bono_barrera_mia         = PESO_ULTRA_BARRERA_PROPIA * total_barreras_mias;

   return (puntuacion_mia - puntuacion_opp) + bono_barrera_mia + penalizacion_barrera_opp;
}
