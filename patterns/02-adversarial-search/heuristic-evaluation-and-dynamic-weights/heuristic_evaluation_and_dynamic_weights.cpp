// Pattern: Evaluation function with weights that follow the game phase
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/parchis-ai -> src/AIPlayer.cpp (lines 940-1007, 1009-1022, 1434-1463)
//          https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L940
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// Función auxiliar para calcular la puntuación de un solo jugador (IA u oponente)
float calcularPuntuacionJugador(const Parchis &estado, int jugador_calculado, int jugador_IA_perspectiva) {
   float puntuacion_jugador = 0.0;
   vector<color> colores_jugador = estado.getPlayerColors(jugador_calculado);

   // 1. Distancia a la Meta y Fichas en Casa/Meta/Pasillo/Seguras
   for (color c : colores_jugador) {
      for (int i = 0; i < num_pieces; ++i) { // num_pieces es 2
         const Piece& ficha = estado.getBoard().getPiece(c, i);
         const Box& casilla_ficha = ficha.get_box();

         if (casilla_ficha.type == goal) {
            puntuacion_jugador += PESO_FICHA_EN_META;
         } else if (casilla_ficha.type == home) {
            puntuacion_jugador += PESO_FICHA_EN_CASA;
         } else {
            // Distancia: Queremos que (DIST_MAX - dist_actual) sea grande. Así, una distancia pequeña da una puntuación grande.
            float distancia_a_meta = (float)estado.distanceToGoal(c, i);
            puntuacion_jugador += PESO_DISTANCIA_TOTAL * (DISTANCIA_MAX_TABLERO_APROX - distancia_a_meta);

            if (casilla_ficha.type == final_queue) {
               puntuacion_jugador += PESO_FICHA_FINAL_QUEUE;
            }
            if (estado.isSafeBox(casilla_ficha)) { 
               puntuacion_jugador += PESO_FICHA_SEGURA;
            }

            if (!estado.isSafeBox(casilla_ficha)) {
               // Si es mi ficha, es vulnerable. Si es del oponente, es una amenaza potencial para él.
               if (jugador_calculado == jugador_IA_perspectiva) {
                  puntuacion_jugador += PESO_VULNERABILIDAD_PROPIA; // Penalización por ser vulnerable
               } else {
                  puntuacion_jugador += PESO_AMENAZA_CAPTURA_A_OPONENTE; // Oportunidad de capturar al oponente
               }
            }
         }
      }
   }

   // 2. Barreras (solo cuenta si existen, se podría mirar si es efectiva y ver si bloquea a alguien.
   map<Box, int> conteo_casillas_jugador;
   for (color c : colores_jugador) {
      for (int i = 0; i < num_pieces; ++i) {
         const Box& casilla_ficha = estado.getBoard().getPiece(c,i).get_box();
         if(casilla_ficha.type == normal || casilla_ficha.type == final_queue){ // Barreras usualmente fuera de casa/meta
            conteo_casillas_jugador[casilla_ficha]++;
         }
      }
   }
   for(auto const& [casilla, num_fichas_en_casilla] : conteo_casillas_jugador){
      if(num_fichas_en_casilla == 2){ // Es una barrera del jugador_calculado
         // Solo se considera barrera si ambas fichas son del MISMO color.
         color color_barrera = estado.isWall(casilla);
         bool es_barrera_del_jugador_actual = false;
         for(color col_jug : colores_jugador){
            if(col_jug == color_barrera){
               es_barrera_del_jugador_actual = true;
               break;
            }
         }
         if(es_barrera_del_jugador_actual){
            puntuacion_jugador += PESO_BARRERA_PROPIA_SIMPLE;
         }
      }
   }


   return puntuacion_jugador;
}

float HeuristicaMejorada::getHeuristic(const Parchis &estado, int jugador_IA) const {
   int ganador = estado.getWinner();
   if (ganador != -1) {
      return (ganador == jugador_IA) ? gana : pierde;
   }

   int oponente = (jugador_IA + 1) % 2;

   float puntuacion_IA = calcularPuntuacionJugador(estado, jugador_IA, jugador_IA);
   float puntuacion_oponente = calcularPuntuacionJugador(estado, oponente, jugador_IA);

   return puntuacion_IA - puntuacion_oponente;

}

// =====================================================
// ==                  Parte Extra                  ==
// =====================================================
void ajustarPesosSegunFaseDePartida(const Parchis &estado, int jugador_IA) {
   int total_fichas_mias_en_meta = 0;
   int total_fichas_oponente_en_meta = 0;

   for (color c : estado.getPlayerColors(jugador_IA)) {
         total_fichas_mias_en_meta += estado.piecesAtGoal(c);
   }
   for (color c : estado.getPlayerColors((jugador_IA + 1) % 2)) {
         total_fichas_oponente_en_meta += estado.piecesAtGoal(c);
   }

   int total_meta = total_fichas_mias_en_meta + total_fichas_oponente_en_meta;

   if (total_meta <= 2) {
         // Inicio de partida: prioriza progresar rápido
         PESO_DISTANCIA_TOTAL = 1.0;
         PESO_FICHA_EN_META = 100.0;
         PESO_VULNERABILIDAD_PROPIA = -10.0;
   } else if (total_meta <= 6) {
         // Medio de partida: equilibrio
         PESO_DISTANCIA_TOTAL = 0.7;
         PESO_FICHA_EN_META = 120.0;
         PESO_VULNERABILIDAD_PROPIA = -20.0;
   } else {
         // Final de partida: máxima prioridad a meta
         PESO_DISTANCIA_TOTAL = 0.5;
         PESO_FICHA_EN_META = 150.0;
         PESO_VULNERABILIDAD_PROPIA = -30.0;
   }
}
