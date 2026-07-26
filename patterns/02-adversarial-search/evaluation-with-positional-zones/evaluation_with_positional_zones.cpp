// Pattern: Evaluation with positional zones and distance bands
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Parcherckers -> src/AIPlayer.cpp (lines 881-930)
//          https://github.com/Ismael-Sallami/Parcherckers/blob/main/src/AIPlayer.cpp#L881
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// =====================================================
// ==                   Nueva Heurística                  ==
// =====================================================
float HeuristicaNueva::getHeuristic(const Parchis& estado, int jugador) const {
   int oponente = (jugador + 1) % 2;
   float valor = 0.0f;

   // 1. Peso de distancia a meta
   float peso_dist = -0.8; // menor distancia, mejor
   for (color c : estado.getPlayerColors(jugador)) {
      for (int i = 0; i < 2; i++) {
         valor += peso_dist * estado.distanceToGoal(c, i);
      }
   }
   for (color c : estado.getPlayerColors(oponente)) {
      for (int i = 0; i < 2; i++) {
         valor -= peso_dist * estado.distanceToGoal(c, i);
      }
   }

   // 2. Peso de fichas en meta
   float peso_meta = 10.0;
   for (color c : estado.getPlayerColors(jugador)) {
      valor += peso_meta * estado.piecesAtGoal(c);
   }
   for (color c : estado.getPlayerColors(oponente)) {
      valor -= peso_meta * estado.piecesAtGoal(c);
   }

   // 3. Fichas en casillas seguras
   float peso_seguro = 2.0;
   for (color c : estado.getPlayerColors(jugador)) {
      for (int i = 0; i < 2; i++) {
         if (estado.isSafePiece(c, i)) valor += peso_seguro;
      }
   }
   for (color c : estado.getPlayerColors(oponente)) {
      for (int i = 0; i < 2; i++) {
         if (estado.isSafePiece(c, i)) valor -= peso_seguro;
      }
   }

   // 4. Potenciales capturas o vulnerabilidad
   if (estado.isEatingMove()) valor += 15.0;
   if (estado.isGoalMove()) valor += 10.0;

   // 5. Detectar el final de la partida (ganador)
   int ganador = estado.getWinner();
   if (ganador == jugador) return 9999.0;
   if (ganador == oponente) return -9999.0;

   return valor;
}
