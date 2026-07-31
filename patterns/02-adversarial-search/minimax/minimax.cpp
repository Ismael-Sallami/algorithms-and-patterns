// Pattern: Minimax over a game tree
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/parchis-ai -> src/AIPlayer.cpp (lines 401-454)
//          https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L401-L454
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// Algoritmo Minimax 
float AIPlayer::Minimax(const Parchis &actual, int jugador, int profundidad, int profundidad_max, color &c_piece, int &id_piece, int &dice, Heuristic *heuristic) const
{ // debo de añadir const al final de la función
   if (profundidad == profundidad_max || actual.gameOver())
   { // Nodo terminal o profundidad límite: llamo a la función heurística
      // IMPORTANTE: USAMOS EL MÉTODO evaluate AUNQUE HAYAMOS REDEFINIDO LA CLASE HEURISTIC
      return heuristic->evaluate(actual, jugador);
   }
   // Comparo mi jugador con el actual de la partida para saber en qué tipo de nodo estoy
   else if (actual.getCurrentPlayerId() == jugador)
   { // Nodo MAX
      float valor = menosinf; // Inicialización lo más pequeña posible para ir calculando el máximo
      // Obtengo los hijos del nodo actual y los recorro
      // Se ha cambiado a vector
      vector<ParchisSis> rama = actual.getChildrenList();
      for (int i = 0; i < rama.size(); i++)
      {
         ParchisSis hijo_i = rama[i]; // Acceso al estado con el hijo i-ésimo del vector
         Parchis nuevo_hijo = *hijo_i; // Acceso al estado
         // Búsqueda en profundidad (llamada recursiva)
         float new_val = Minimax(nuevo_hijo, jugador, profundidad + 1, profundidad_max, c_piece, id_piece, dice, heuristic);
         if (new_val > valor)
         {
            // Me voy quedando con el máximo
            valor = new_val;
            if (profundidad == 0)
            {
               // Acceso al movimiento del i-ésimo hijo.
               c_piece = hijo_i.getMovedColor();
               id_piece = hijo_i.getMovedPieceId();
               dice = hijo_i.getMovedDiceValue();
            }
         }
      }
      return valor;
   }
   else
   { // Nodo MIN
      float valor = masinf; // Inicialización lo más grande posible para ir calculando el mínimo
      // Obtengo los hijos del nodo actual y los recorro
      ParchisBros rama = actual.getChildren();
      for (ParchisBros::Iterator it = rama.begin(); it != rama.end(); ++it)
      {
         Parchis nuevo_hijo = *it;
         // Búsqueda en profundidad (llamada recursiva)
         float new_val = Minimax(nuevo_hijo, jugador, profundidad + 1, profundidad_max, c_piece, id_piece, dice, heuristic);
         // Me voy quedando con el mínimo
         if (new_val < valor)
         {
            valor = new_val;
         }
      }
      return valor;
   }
}
