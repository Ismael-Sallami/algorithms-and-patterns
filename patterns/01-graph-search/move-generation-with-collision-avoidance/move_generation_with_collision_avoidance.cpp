// Pattern: Legal move generation with collision avoidance
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/rescue-agents -> src/rescatador.cpp (lines 528-662, 683-692)
//          https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L528
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

vector<Action> ComportamientoRescatador::obtenerPosiblesMovimientos(const Sensores &sensores, int filaActual, int colActual)
{
  vector<Action> posiblesMovimientos;

  if (sensores.rumbo == norte)
  {
    if (filaActual - 1 >= 0 && escasillavalida_lvl1(sensores, 2) && !visitadosBool[filaActual - 1][colActual])
    {
      posiblesMovimientos.push_back(WALK);
    }
    else if (filaActual - 1 >= 0 && colActual - 1 >= 0 && escasillavalida_lvl1(sensores, 1) && !visitadosBool[filaActual - 1][colActual - 1])
    {
      giro45Izq = 1;
      posiblesMovimientos.push_back(TURN_L);
    }
    else if (filaActual - 1 >= 0 && colActual + 1 < visitadosBool[0].size() && escasillavalida_lvl1(sensores, 3) && !visitadosBool[filaActual - 1][colActual + 1])
    {
      posiblesMovimientos.push_back(TURN_SR);
    }
  }
  else if (sensores.rumbo == noreste)
  {
    if (filaActual - 1 >= 0 && colActual + 1 < visitadosBool[0].size() && escasillavalida_lvl1(sensores, 2) && !visitadosBool[filaActual - 1][colActual + 1])
    {
      posiblesMovimientos.push_back(WALK);
    }
    else if (filaActual - 1 >= 0 && escasillavalida_lvl1(sensores, 1) && !visitadosBool[filaActual - 1][colActual])
    {
      giro45Izq = 1;
      posiblesMovimientos.push_back(TURN_L);
    }
    else if (colActual + 1 < visitadosBool[0].size() && escasillavalida_lvl1(sensores, 3) && !visitadosBool[filaActual][colActual + 1])
    {
      posiblesMovimientos.push_back(TURN_SR);
    }
  }
  else if (sensores.rumbo == este)
  {
    if (colActual + 1 < visitadosBool[0].size() && escasillavalida_lvl1(sensores, 2) && !visitadosBool[filaActual][colActual + 1])
    {
      posiblesMovimientos.push_back(WALK);
    }
    else if (filaActual - 1 >= 0 && colActual + 1 < visitadosBool[0].size() && escasillavalida_lvl1(sensores, 1) && !visitadosBool[filaActual - 1][colActual + 1])
    {
      giro45Izq = 1;
      posiblesMovimientos.push_back(TURN_L);
    }
    else if (filaActual + 1 < visitadosBool.size() && colActual + 1 < visitadosBool[0].size() && escasillavalida_lvl1(sensores, 3) && !visitadosBool[filaActual + 1][colActual + 1])
    {
      posiblesMovimientos.push_back(TURN_SR);
    }
  }
  else if (sensores.rumbo == sureste)
  {
    if (filaActual + 1 < visitadosBool.size() && colActual + 1 < visitadosBool[0].size() && escasillavalida_lvl1(sensores, 2) && !visitadosBool[filaActual + 1][colActual + 1])
    {
      posiblesMovimientos.push_back(WALK);
    }
    else if (colActual + 1 < visitadosBool[0].size() && escasillavalida_lvl1(sensores, 1) && !visitadosBool[filaActual][colActual + 1])
    {
      giro45Izq = 1;
      posiblesMovimientos.push_back(TURN_L);
    }
    else if (filaActual + 1 < visitadosBool.size() && escasillavalida_lvl1(sensores, 3) && !visitadosBool[filaActual + 1][colActual])
    {
      posiblesMovimientos.push_back(TURN_SR);
    }
  }
  else if (sensores.rumbo == sur)
  {
    if (filaActual + 1 < visitadosBool.size() && escasillavalida_lvl1(sensores, 2) && !visitadosBool[filaActual + 1][colActual])
    {
      posiblesMovimientos.push_back(WALK);
    }
    else if (filaActual + 1 < visitadosBool.size() && colActual + 1 < visitadosBool[0].size() && escasillavalida_lvl1(sensores, 1) && !visitadosBool[filaActual + 1][colActual + 1])
    {
      giro45Izq = 1;
      posiblesMovimientos.push_back(TURN_L);
    }
    else if (filaActual + 1 < visitadosBool.size() && colActual - 1 >= 0 && escasillavalida_lvl1(sensores, 3) && !visitadosBool[filaActual + 1][colActual - 1])
    {
      posiblesMovimientos.push_back(TURN_SR);
    }
  }
  else if (sensores.rumbo == suroeste)
  {
    if (filaActual + 1 < visitadosBool.size() && colActual - 1 >= 0 && escasillavalida_lvl1(sensores, 2) && !visitadosBool[filaActual + 1][colActual - 1])
    {
      posiblesMovimientos.push_back(WALK);
    }
    else if (filaActual + 1 < visitadosBool.size() && escasillavalida_lvl1(sensores, 1) && !visitadosBool[filaActual + 1][colActual])
    {
      giro45Izq = 1;
      posiblesMovimientos.push_back(TURN_L);
    }
    else if (colActual - 1 >= 0 && escasillavalida_lvl1(sensores, 3) && !visitadosBool[filaActual][colActual - 1])
    {
      posiblesMovimientos.push_back(TURN_SR);
    }
  }
  else if (sensores.rumbo == oeste)
  {
    if (colActual - 1 >= 0 && escasillavalida_lvl1(sensores, 2) && !visitadosBool[filaActual][colActual - 1])
    {
      posiblesMovimientos.push_back(WALK);
    }
    else if (filaActual + 1 < visitadosBool.size() && colActual - 1 >= 0 && escasillavalida_lvl1(sensores, 1) && !visitadosBool[filaActual + 1][colActual - 1])
    {
      giro45Izq = 1;
      posiblesMovimientos.push_back(TURN_L);
    }
    else if (filaActual - 1 >= 0 && colActual - 1 >= 0 && escasillavalida_lvl1(sensores, 3) && !visitadosBool[filaActual - 1][colActual - 1])
    {
      posiblesMovimientos.push_back(TURN_SR);
    }
  }
  else if (sensores.rumbo == noroeste)
  {
    if (filaActual - 1 >= 0 && colActual - 1 >= 0 && escasillavalida_lvl1(sensores, 2) && !visitadosBool[filaActual - 1][colActual - 1])
    {
      posiblesMovimientos.push_back(WALK);
    }
    else if (colActual - 1 >= 0 && escasillavalida_lvl1(sensores, 1) && !visitadosBool[filaActual][colActual - 1])
    {
      giro45Izq = 1;
      posiblesMovimientos.push_back(TURN_L);
    }
    else if (filaActual - 1 >= 0 && escasillavalida_lvl1(sensores, 3) && !visitadosBool[filaActual - 1][colActual])
    {
      posiblesMovimientos.push_back(TURN_SR);
    }
  }

  return posiblesMovimientos;
}

bool ComportamientoRescatador::evitarColisionAuxiliar(const Sensores &sensores, Action &accion, int &giro45Izq)
{
  if (sensores.agentes[2] == 'a' || sensores.agentes[6] == 'a' || sensores.agentes[12] == 'a')
  {
    // cout << "Evito posible colisión con Auxiliar (cerca o delante+1)" << endl;
    accion = TURN_L;
    return true;
  }
  return false;
}
