// Pattern: Greedy and random move policies
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/parchis-ai -> src/AIPlayer.cpp (lines 156-228, 260-298, 300-337)
//          https://github.com/Ismael-Sallami/parchis-ai/blob/main/src/AIPlayer.cpp#L156
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// }
void AIPlayer::thinkAleatorio(color& c_piece, int& id_piece, int& dice) const{
   // IMPLEMENTACIÓN INICIAL DEL AGENTE
   // Esta implementación realiza un movimiento aleatorio.
   // Se proporciona como ejemplo, pero se debe cambiar por una que realice un movimiento inteligente
   //como lo que se muestran al final de la función.

   // OBJETIVO: Asignar a las variables c_piece, id_piece, dice (pasadas por referencia) los valores,
   //respectivamente, de:
   // - color de ficha a mover
   // - identificador de la ficha que se va a mover
   // - valor del dado con el que se va a mover la ficha.

   // El id de mi jugador actual.
   int player = actual->getCurrentPlayerId();

   // Vector que almacenará los dados que se pueden usar para el movimiento
   vector<int> current_dices;
   // Vector que almacenará los ids de las fichas que se pueden mover para el dado elegido.
   vector<tuple<color, int>> current_pieces;

   // Se obtiene el vector de dados que se pueden usar para el movimiento
   current_dices = actual->getAvailableNormalDices(player);
   // Elijo un dado de forma aleatoria.
   dice = current_dices[rand() % current_dices.size()];

   // Se obtiene el vector de fichas que se pueden mover para el dado elegido
   current_pieces = actual->getAvailablePieces(player, dice);

   // Si tengo fichas para el dado elegido muevo una al azar.
   if (current_pieces.size() > 0){
      int random_id = rand() % current_pieces.size();
      id_piece = get<1>(current_pieces[random_id]); // get<i>(tuple<...>) me devuelve el i-ésimo
      c_piece = get<0>(current_pieces[random_id]); // elemento de la tupla
   }
   else{
      // Si no tengo fichas para el dado elegido, pasa turno (la macro SKIP_TURN me permite no mover).
      id_piece = SKIP_TURN;
      c_piece = actual->getCurrentColor(); // Le tengo que indicar mi color actual al pasar turno.
   }

   
   // El siguiente código se proporciona como sugerencia para iniciar la implementación del agente.

   float valor; // Almacena el valor con el que se etiqueta el estado tras el proceso de busqueda.
   float alpha = menosinf, beta = masinf; // Cotas iniciales de la poda AlfaBeta
   // Llamada a la función para la poda (los parámetros son solo una sugerencia, se pueden modificar).
   ValoracionTest valoracionTest;

   // ----------------------------------------------------------------- //

   // Si quiero poder manejar varios comportamientos, puedo usar la variable id del agente para usar una u otra.
   // switch (id)
   // {
   // case 0:
   //    // Mi implementación base de la poda con ValoracionTest
   //    valor = Poda_AlfaBeta(*actual, jugador, 0, PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, &valoracionTest);
   //    break;
   // case 1:
   //    // Mi implementación definitiva con la que gano a todos los ninjas.
   //    valor = Poda_Final2DefinitivaAhoraSi(*actual, jugador, 0, PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, &miValoracion3);
   //    break;
   // case 2:
   //    // Las distintas pruebas que he realizado (primera prueba)
   //    valor = Poda_AlfaBeta_Mejorada(*actual, jugador, 0, PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, &miValoracion1);
   //    break;
   // case 3:
   //    // Las distintas pruebas que he realizado (segunda prueba)
   //    valor = Poda_AlfaBeta_SegundaMejora(*actual, jugador, 0, PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, &miValoracion1);
   //    break;
   //  // ...
   // }

}

void AIPlayer::thinkFichaMasAdelantada(color &c_piece, int &id_piece, int &dice) const
{
   // Elijo el dado haciendo lo mismo que el jugador aleatorio.
   thinkAleatorio(c_piece, id_piece, dice);
   // Tras llamar a esta función, ya tengo en dice el número de dado que quiero usar.
   // Ahora, en vez de mover una ficha al azar, voy a mover (o a aplicar
   // el dado especial a) la que esté más adelantada
   // (equivalentemente, la más cercana a la meta).
   int player = actual->getCurrentPlayerId();
   vector<tuple<color, int>> current_pieces = actual->getAvailablePieces(player, dice);
   int id_ficha_mas_adelantada = -1;
   color col_ficha_mas_adelantada = none;
   int min_distancia_meta = 9999;
   for (int i = 0; i < current_pieces.size(); i++)
   {
      // distanceToGoal(color, id) devuelve la distancia a la meta de la ficha [id] del color que le indique.
      color col = get<0>(current_pieces[i]);
      int id = get<1>(current_pieces[i]);
      int distancia_meta = actual->distanceToGoal(col, id);
      if (distancia_meta < min_distancia_meta)
      {
         min_distancia_meta = distancia_meta;
         id_ficha_mas_adelantada = id;
         col_ficha_mas_adelantada = col;
      }
   }
   // Si no he encontrado ninguna ficha, paso turno.
   if (id_ficha_mas_adelantada == -1)
   {
      id_piece = SKIP_TURN;
      c_piece = actual->getCurrentColor(); // Le tengo que indicar mi color actual al pasar turno.
   }
   // En caso contrario, moveré la ficha más adelantada.
   else
   {
      id_piece = id_ficha_mas_adelantada;
      c_piece = col_ficha_mas_adelantada;
   }
}

void AIPlayer::thinkMejorOpcion(color &c_piece, int &id_piece, int &dice) const
{
   // Vamos a mirar todos los posibles movimientos del jugador actual accediendo a los hijos del estado actual.
   // Cuando ya he recorrido todos los hijos, la función devuelve el estado actual. De esta forma puedo saber
   // cuándo paro de iterar.
   // Para ello, vamos a iterar sobre los hijos con la función de Parchis getChildren().
   // Esta función devuelve un objeto de la clase ParchisBros, que es una estructura iterable
   // sobre la que se pueden recorrer todos los hijos del estado sobre el que se llama.
   ParchisBros hijos = actual->getChildren();
   bool me_quedo_con_esta_accion = false;
   // La clase ParchisBros viene con un iterador muy útil y sencillo de usar.
   // Al hacer begin() accedemos al primer hijo de la rama,
   // y cada vez que hagamos ++it saltaremos al siguiente hijo.
   // Comparando con el iterador end() podemos consultar cuándo hemos terminado de visitar los hijos.
   for (ParchisBros::Iterator it = hijos.begin();
         it != hijos.end() and !me_quedo_con_esta_accion; ++it)
   {
      Parchis siguiente_hijo = *it;
      // Si en el movimiento elegido comiera ficha, llegara a la meta o ganara, me quedo con esa acción.
      // Termino el bucle en este caso.
      if (siguiente_hijo.isEatingMove() or
         siguiente_hijo.isGoalMove() or
         (siguiente_hijo.gameOver() and siguiente_hijo.getWinner() == this->jugador))
      {
         me_quedo_con_esta_accion = true;
         c_piece = it.getMovedColor();
         id_piece = it.getMovedPieceId();
         dice = it.getMovedDiceValue();
      }
   }
   // Si he encontrado una acción que me interesa, la guardo en las variables pasadas por referencia.
   // (Ya lo he hecho antes, cuando les he asignado los valores con el iterador).
   // Si no he encontrado ninguna acción que me interese, voy a mover la ficha más adelantada como en el caso
   // anterior.
   if(!me_quedo_con_esta_accion){
      thinkFichaMasAdelantada(c_piece, id_piece, dice);
   }
}
