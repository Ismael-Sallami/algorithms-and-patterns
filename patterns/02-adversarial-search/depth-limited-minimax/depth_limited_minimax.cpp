// Pattern: Minimax with a hard node budget
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/parchis-ai -> src/AIPlayer.cpp (lines 458-521)
//          https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L458-L521
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// Algoritmo Minimax con límite de nodos
float AIPlayer::Minimax_Limitado(const Parchis &actual, int jugador, int profundidad, int profundidad_max, color &c_piece, int &id_piece, int &dice, Heuristic *heuristic) const
{
   if (profundidad == profundidad_max || actual.gameOver())
   { // Nodo terminal o profundidad límite: llamo a la función heurística
      return heuristic->evaluate(actual, jugador);
   }
   else if (actual.getCurrentPlayerId() == jugador)
   { // Nodo MAX
      float valor = menosinf;
      ParchisBros rama = actual.getChildren();
      for (ParchisBros::Iterator it = rama.begin(); it != rama.end(); ++it)
      {
         Parchis nuevo_hijo = *it;
         // Verificar si hemos alcanzado el límite
         if (NodeCounter::isLimitReached())
         {
            cout << "Límite de nodos alcanzado, devolviendo el mejor nodo parcial" << endl;
            if(profundidad == 0)
            {
               c_piece = it.getMovedColor();
               id_piece = it.getMovedPieceId();
               dice = it.getMovedDiceValue();
            }
            return valor;
         }
         // Búsqueda en profundidad (llamada recursiva)
         float new_val = Minimax_Limitado(nuevo_hijo, jugador, profundidad + 1, profundidad_max, c_piece, id_piece, dice, heuristic);
         if (new_val > valor)
         {
            valor = new_val;
            if (profundidad == 0)
            {
               c_piece = it.getMovedColor();
               id_piece = it.getMovedPieceId();
               dice = it.getMovedDiceValue();
            }
         }
      }
      return valor;
   }
   else
   { // Nodo MIN
      float valor = masinf;
      // Obtengo los hijos del nodo actual y los recorro
      ParchisBros rama = actual.getChildren();
      for (ParchisBros::Iterator it = rama.begin(); it != rama.end(); ++it)
      {
         Parchis nuevo_hijo = *it;
         // Verificar si hemos alcanzado el límite
         if (NodeCounter::isLimitReached())
         {
            cout << "Límite de nodos alcanzado, devolviendo el mejor nodo parcial" << endl;
            return heuristic->evaluate(actual, jugador);
         }
         // Búsqueda en profundidad (llamada recursiva)
         float new_val = Minimax_Limitado(nuevo_hijo, jugador, profundidad + 1, profundidad_max, c_piece, id_piece, dice, heuristic);
         if (new_val < valor)
         {
            valor = new_val;
         }
      }
      return valor;
   }
}
