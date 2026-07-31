// Pattern: Evaluation with piece safety and capture terms
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/parchis-ai -> src/AIPlayer.cpp (lines 621-684)
//          https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L621-L684
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// =====================================================
// ==                   Mi Heurística 1                  ==
// =====================================================
float Heur1::getHeuristic(const Parchis &estado, int jugador) const {
   static constexpr float GANA   = +1e6f;
   static constexpr float PIERDE = -1e6f;

   int ganador  = estado.getWinner();
   int oponente = (jugador + 1) % 2;
   if (ganador == jugador)  return GANA;
   if (ganador == oponente) return PIERDE;

   vector<color> mis_colores = estado.getPlayerColors(jugador);
   vector<color> op_colores  = estado.getPlayerColors(oponente);

   float puntuacion_mia = 0.0f;
   for (color c : mis_colores) {
         for (int id_pieza = 0; id_pieza < num_pieces; ++id_pieza) {
            const Piece &ficha = estado.getBoard().getPiece(c, id_pieza);
            const Box   &caja  = ficha.get_box();

            if (caja.type == goal) {
               puntuacion_mia += W_META;
               continue;
            }

            int dist = estado.distanceToGoal(c, id_pieza);
            puntuacion_mia += W_DISTANCIA * static_cast<float>(100 - dist);

            if (estado.isSafePiece(c, id_pieza)) {
               puntuacion_mia += W_FICHA_SEGURA;
            }

            color muro = estado.isWall(caja);
            if (muro == c) {
               puntuacion_mia += W_BARRERA_PROPIA;
            }
         }
   }

   float puntuacion_op = 0.0f;
   for (color c : op_colores) {
         for (int id_pieza = 0; id_pieza < num_pieces; ++id_pieza) {
            const Piece &ficha = estado.getBoard().getPiece(c, id_pieza);
            const Box   &caja  = ficha.get_box();

            if (caja.type == goal) {
               puntuacion_op += W_META;
               continue;
            }

            int dist = estado.distanceToGoal(c, id_pieza);
            puntuacion_op += W_DISTANCIA * static_cast<float>(100 - dist);

            if (estado.isSafePiece(c, id_pieza)) {
               puntuacion_op += W_FICHA_SEGURA;
            }

            color muro = estado.isWall(caja);
            if (muro == c) {
               puntuacion_op += W_BARRERA_OPOS;
            }
         }
   }

   return puntuacion_mia - puntuacion_op;
}
