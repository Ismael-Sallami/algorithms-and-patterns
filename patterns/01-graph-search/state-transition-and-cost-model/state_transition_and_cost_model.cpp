// Pattern: State transition function and edge cost model
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/rescue-agents -> src/rescatador.cpp (lines 1164-1220, 1347-1402, 1404-1442)
//          https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1164
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

EstadoR ComportamientoRescatador::applyR(Action accion, const EstadoR &st, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura)
{
  EstadoR next = st;
  switch (accion)
  {
  case WALK:
    if (CasillaAccesibleRescatador(st, terreno, altura))
    {
      next = NextCasillaRescatador(st);
    }
    break;
  case TURN_SR:
    next.brujula = (next.brujula + 1) % 8;
    break;
  case TURN_L:
    next.brujula = (next.brujula + 6) % 8;
    break;
  case RUN:
    next = NextCasillaRescatador(st);
    bool check1 = false, check2 = false, check3 = false, check4 = false, check5 = false;
    check1 = terreno[next.f][next.c] != 'P' and terreno[next.f][next.c] != 'M'; // Nos aseguramos que no es un precipicio ni una montaña
    check2 = terreno[next.f][next.c] != 'B';                                    // Sabemos que el rescatador no puede pasar por casillas de tipo bosque
    if (next.f == posicionAuxiliar.first && next.c == posicionAuxiliar.second)
    {
      // cout << "No se puede pasar por la casilla del auxiliar" << endl;
      // cout << "F " << next.f << " C " << next.c << endl;
      return st; // No se puede pasar por la casilla del auxiliar
    }
    next = NextCasillaRescatador(next);
    check3 = abs(altura[next.f][next.c] - altura[st.f][st.c]) <= (!st.zapatillas ? 1 : 2); // Comprobamos que la diferencia de altura es menor o igual a 1 si no tiene zapatillas, o menor o igual a 2 si tiene zapatillas
    check4 = terreno[next.f][next.c] != 'P' and terreno[next.f][next.c] != 'M';            // Nos aseguramos que no es un precipicio ni una montaña
    check5 = terreno[next.f][next.c] != 'B';                                               // Sabemos que el rescatador no puede pasar por casillas de tipo bosque
    if (next.f == posicionAuxiliar.first && next.c == posicionAuxiliar.second)
    {
      // cout << "No se puede pasar por la casilla del auxiliar" << endl;
      // cout << "F " << next.f << " C " << next.c << endl;
      return st; // No se puede pasar por la casilla del auxiliar
    }

    if (check1 and check2 and check3 and check4 and check5)
    {
      // cout << "La casilla es accesible DENTRO DE RESCATADOR" << endl;
      return next;
    }
    else
    {
      return st; // Si no es accesible, volvemos al estado original
    }
    break;
  }
  // vemos si estamos en una casilla que da las zapatillas
  if (terreno[next.f][next.c] == 'D')
  {
    next.zapatillas = true;
  }
  return next;
}

// ════════════════════════════════════════════════════════════════════════════
//                              FUNCIONES NIVEL 2
// ════════════════════════════════════════════════════════════════════════════
int ComportamientoRescatador::CosteBaseTerreno(unsigned char casilla, Action accion)
{
  switch (accion)
  {
  case WALK:
    switch (casilla)
    {
    case 'A':
      return 100;
    case 'T':
      return 20;
    case 'S':
      return 2;
    default:
      return 1;
    }
  case RUN:
    switch (casilla)
    {
    case 'A':
      return 150;
    case 'T':
      return 35;
    case 'S':
      return 3;
    default:
      return 1;
    }
  case TURN_L:
    switch (casilla)
    {
    case 'A':
      return 30;
    case 'T':
      return 5;
    case 'S':
      return 1;
    default:
      return 1;
    }
  case TURN_SR:
    switch (casilla)
    {
    case 'A':
      return 16;
    case 'T':
      return 3;
    case 'S':
      return 1;
    default:
      return 1;
    }
  default:
    return 1;
  }
}

int ComportamientoRescatador::CosteCambioAltura(int altura_origen, int altura_destino, unsigned char casilla, Action accion)
{
  if (accion != WALK && accion != RUN)
    return 0; // Solo aplica en movimientos, no en giros

  int diferencia = altura_destino - altura_origen;
  if (diferencia == 0)
    return 0;

  switch (accion)
  {
  case WALK:
    switch (casilla)
    {
    case 'A':
      return (diferencia > 0) ? 10 : -10;
    case 'T':
      return (diferencia > 0) ? 5 : -5;
    case 'S':
      return (diferencia > 0) ? 1 : -1;
    default:
      return 0; // El resto de terrenos no aplican modificación
    }
  case RUN:
    switch (casilla)
    {
    case 'A':
      return (diferencia > 0) ? 15 : -15;
    case 'T':
      return (diferencia > 0) ? 5 : -5;
    case 'S':
      return (diferencia > 0) ? 2 : -2;
    default:
      return 0; // El resto de terrenos no aplican modificación
    }
  default:
    return 0;
  }
}
