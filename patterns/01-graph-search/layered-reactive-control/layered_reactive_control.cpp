// Pattern: Layered reactive control without a plan
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/rescue-agents -> src/rescatador.cpp (lines 121-343)
//          https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L121-L343
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// ════════════════════════════════════════════════════════════════════════════
//                             NIVEL 0
// ════════════════════════════════════════════════════════════════════════════
Action ComportamientoRescatador::ComportamientoRescatadorNivel_0(Sensores sensores)
{
  // Vemos numerosos // cout, pero que ayudan a depurar el código.
  // cout << "#################RESCATADOR-INICIO#################" << endl;

  Action accion;
  visitados[sensores.posF][sensores.posC]++;
  visitadosBool[sensores.posF][sensores.posC] = true;
  contador++;
  // cout << "Contador: " << contador << endl;

  // pinta el valor de sensor superficie y la de los adyacentes
  // cout << "Terreno actual: " << DescripcionTerreno(sensores.superficie[0]) << endl;
  // cout << "Terreno delante: " << DescripcionTerreno(sensores.superficie[2]) << endl;
  // cout << "Terreno derecha: " << DescripcionTerreno(sensores.superficie[3]) << endl;
  // cout << "Terreno izquierda: " << DescripcionTerreno(sensores.superficie[1]) << endl;
  // cout << "Sensores superficie en la casilla 6 :" << sensores.superficie[6] << endl;
  // El comportamiento de seguir un camino hasta encontrar un puesto base.
  // Actualización de variables de estado
  // SituarSensorEnMapaR(mapaResultado, mapaCotas, sensores);
  if (visitados[sensores.posF][sensores.posC] > 1500)
  {
    // cout << "Entra en el max acciones y el valor de la casilla es: " << visitados[sensores.posF][sensores.posC] << endl;
    // devolvemos un random entre 0,1,2 y si la casilla es transitable la pasa.
    return TURN_SR;
  }
  if (sensores.superficie[0] == 'D')
    tiene_zapatillas = true;

  // pintamos las dimensiones del mapa usando mapaResultado
  // cout << "Dimensiones del mapa: " << mapaResultado.size() << "x" << mapaResultado[0].size() << endl;

  // Definición del comportamiento
  if (sensores.superficie[0] == 'X')
  { // Llegué al Objetivo
    return IDLE;
  }
  else if (giro45Izq != 0)
  { // Estoy haciendo un TURN_SL
    accion = TURN_SR;
    giro45Izq--;
  }
  else if (contador > 2200)
  { // este if se usa para aumentar la aleatoriedad, y de esta manera mejorar el comporamiento reactivo del código y conseguir la meta.
    if (sensores.superficie[2] == 'X' || sensores.superficie[6] == 'X')
      return WALK;
    if (contador < 2500)
    {
      if ((sensores.superficie[3] == 'X' || sensores.superficie[3] == 'C') && sensores.agentes[3] != 'a')
      {
        return TURN_SR;
      }
      else if (sensores.superficie[2] == 'X' || sensores.superficie[2] == 'C' || sensores.superficie[6] == 'X')
      {
        return WALK;
      }
      else
        return TURN_L;
    }
    else
    {
      if ((sensores.superficie[1] == 'X' || sensores.superficie[1] == 'C') && sensores.agentes[1] != 'a')
      {
        return TURN_L;
      }
      else if (sensores.superficie[2] == 'X' || sensores.superficie[2] == 'C' || sensores.superficie[6] == 'X')
      {
        return WALK;
      }
      else
        return TURN_SR;
    }
  }
  else
  {

    char i = ViablePorAltura(sensores.superficie[1], sensores.cota[1] - sensores.cota[0], tiene_zapatillas);
    char c = ViablePorAltura(sensores.superficie[2], sensores.cota[2] - sensores.cota[0], tiene_zapatillas);
    char d = ViablePorAltura(sensores.superficie[3], sensores.cota[3] - sensores.cota[0], tiene_zapatillas);

    int pos = VeoCasillaInteresante(i, c, d, tiene_zapatillas);

    switch (pos)
    {

    case 2: // Vamos a avanzar hacia delante
      // cout << "Entra en case 2" << endl;
      if (sensores.agentes[2] == 'a' || sensores.agentes[6] == 'a' || sensores.agentes[12] == 'a')
      {
        // cout << "Evito posible colisión con Auxiliar (cerca o delante+1)" << endl;
        accion = TURN_SR;
        giro45Izq = 3;
      }
      else
      {
        // Verificar opciones transitables, de nuevo al ser el caso que más se devuelve en la mayoría de los casos, aumentamos la aleatoriedad.
        bool delante = (sensores.superficie[2] == 'C' || sensores.superficie[2] == 'X');
        bool derecha = (sensores.superficie[3] == 'C' || sensores.superficie[3] == 'X');
        bool izquierda = (sensores.superficie[1] == 'C' || sensores.superficie[1] == 'X');

        // Si hay múltiples opciones, elegir una aleatoria
        if (delante && derecha && izquierda)
        {
          int opcion = rand() % 3; // Generar un número aleatorio entre 0 y 2
          if (opcion == 0)
          {
            accion = WALK; // Avanzar
          }
          else if (opcion == 1)
          {
            accion = TURN_SR; // Girar a la izquierda
            giro45Izq = 6;
          }
          else
          {
            accion = TURN_SR; // Girar a la derecha
          }
        }
        else if (delante && derecha)
        {
          int opcion = rand() % 2; // Generar un número aleatorio entre 0 y 1
          if (opcion == 0)
          {
            accion = WALK; // Avanzar
          }
          else
          {
            accion = TURN_SR; // Girar a la derecha
          }
        }
        else if (delante && izquierda)
        {
          int opcion = rand() % 2; // Generar un número aleatorio entre 0 y 1
          if (opcion == 0)
          {
            accion = WALK; // Avanzar
          }
          else
          {
            accion = TURN_SR; // Girar a la izquierda
            giro45Izq = 6;
          }
        }
        else
        {
          contador_Acciones++;
          if (contador_Acciones > MAX_ACCIONES)
          {
            // cout << "Entra en el if donde no hay caminos transitables Y MUCHAS OPCIONES" << endl;
            // calcula un random entre 0,1,2 y si la casilla es transitable la pasa.
            int opcion = rand() % 3; // Generar un número aleatorio entre 0 y 2
            if (opcion == 0)
            {
              return TURN_L;
            }
            else if (opcion == 1)
            {
              return accion = TURN_SR;
            }
            else if (opcion == 2)
            {
              return accion = WALK;
            }
          }
          else
          {
            return WALK;
          }
        }
      }
      break;
    case 1:
      // cout << "Entra en case 1" << endl;
      giro45Izq = 1;
      accion = TURN_L;
      break;
    case 3:
      // cout << "Entra en case 3" << endl;
      accion = TURN_SR;
      break;
    case 0:
      // cout << "Entra en case 0" << endl;
      // comprobamos si los superficie 6 no son viable por altura
      char correr = ViablePorAltura(sensores.superficie[6], sensores.cota[6] - sensores.cota[0], tiene_zapatillas);
      if (correr == 'P')
      {
        // cout << "Entra en el if de la casilla 6" << endl;
        return TURN_L;
      }

      // contador ++, esto se habia añadido para aumentar la aleatoriedad, pero no es necesario.

      // si la casilla de supeficies en 2 y 6 es C o D que devuelva RUN, esto es para evitar que el rescatador se quede atascado en un bucle y así usar el RUN, además de que hay mapas específicos que lo requieren.
      if ((sensores.superficie[2] == 'C' || sensores.superficie[2] == 'D' || sensores.superficie[6] == 'C' || sensores.superficie[6] == 'D') &&
          (sensores.superficie[2] != 'M' && sensores.superficie[6] != 'M'))
      {
        // cout << "Entra en el if de la casilla 2 y 6" << endl;
        return RUN;
      }
      accion = TURN_L;
      break;
    }
  }

  if (last_action == accion)
  {
    acciones_Seguidas++; // aumentamos el contador de acciones seguidas, ya que hay ciertos mapas que se quedan atascados en un bucle y no avanzan, como es el caso del ajedrez.
  }
  else if (acciones_Seguidas > 0)
  {
    acciones_Seguidas--;
  }

  // Imprimimos el contador
  // cout << "Contador: " << contador << endl;
  // cout << "#################RESCATADOR-FIN################# con terreno" << sensores.superficie[0] << endl;

  if (sensores.energia == 2512)
    return TURN_L;
  // Devolver la siguiente acción a hacer
  last_action = accion;
  return accion;
}
