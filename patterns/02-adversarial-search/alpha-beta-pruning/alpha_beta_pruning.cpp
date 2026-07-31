// Pattern: Alpha-beta pruning
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/parchis-ai -> src/AIPlayer.cpp (lines 530-613)
//          https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L530-L613
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// =====================================================
// ==                   PODA ALFA BETA                  ==
// =====================================================
float Poda_AlfaBeta(const Parchis &actual, int jugador, int profundidad, int profundidad_max, color &c_piece, int &id_piece, int &dice, float alpha, float beta, Heuristic *heuristic)
{
      // Caso base: nodo terminal o profundidad límite
      if (profundidad == profundidad_max || actual.gameOver()) {
         return heuristic->evaluate(actual, jugador);
      }

      // Nodo MAX: le toca mover al mismo jugador que invocó la búsqueda
      if (actual.getCurrentPlayerId() == jugador) {
         float valor = menosinf;
         ParchisBros hijos = actual.getChildren();

         for (ParchisBros::Iterator it = hijos.begin(); it != hijos.end(); ++it) { // se optó por dejar el iterador, en vez de usar un vector
            Parchis siguiente = *it;

            // Verificar si hemos alcanzado el límite de nodos
            if (NodeCounter::isLimitReached()) {
                  cout << "Límite de nodos alcanzado, devolviendo el mejor nodo parcial (MAX)" << endl;
                  if (profundidad == 0) {
                     c_piece  = it.getMovedColor();
                     id_piece = it.getMovedPieceId();
                     dice     = it.getMovedDiceValue();
                  }
                  return valor;
            }

            float new_val = Poda_AlfaBeta(siguiente, jugador, profundidad + 1, profundidad_max, c_piece, id_piece, dice, alpha, beta, heuristic);

            // Actualizo el mejor valor y guardo movimiento si estamos en la raíz
            if (new_val > valor) {
                  valor = new_val;
                  if (profundidad == 0) {
                     c_piece  = it.getMovedColor();
                     id_piece = it.getMovedPieceId();
                     dice     = it.getMovedDiceValue();
                  }
            }

            // Actualizo alfa
            if (valor > alpha) {
                  alpha = valor;
            }

            // Poda: si alfa mayor o igual que beta, cortamos
            if (alpha >= beta) {
                  break;
            }
         }
         return valor;
      }
      // Nodo MIN: le toca mover al oponente
      else {
         float valor = masinf;
         ParchisBros hijos = actual.getChildren();

         for (ParchisBros::Iterator it = hijos.begin(); it != hijos.end(); ++it) {
            Parchis siguiente = *it;

            // Verificar si hemos alcanzado el límite de nodos
            if (NodeCounter::isLimitReached()) {
                  cout << "Límite de nodos alcanzado, devolviendo el mejor nodo parcial (MIN)" << endl;
                  return heuristic->evaluate(actual, jugador);
            }

            float new_val = Poda_AlfaBeta(siguiente, jugador, profundidad + 1, profundidad_max, c_piece, id_piece, dice, alpha, beta, heuristic);

            // Nos quedamos con el mínimo
            if (new_val < valor) {
                  valor = new_val;
            }

            // Actualizo beta
            if (valor < beta) {
                  beta = valor;
            }

            // Poda: si beta menor o igual que alfa, cortamos
            if (beta <= alpha) {
                  break;
            }
         }
         return valor;
      }
   }
