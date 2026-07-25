// Pattern: Dijkstra over a weighted grid with composite state
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Practica2_IA -> practica2/rescatador.cpp (lines 1444-1524)
//          https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp#L1444
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

list<Action> ComportamientoRescatador::DijkstraRescatador(const EstadoR &origen, const EstadoR &destino, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura)
{
  NodoR current_nodo;
  priority_queue<NodoR, vector<NodoR>, greater<NodoR>> frontier;
  set<NodoR> explored;
  list<Action> path;

  current_nodo.estado = origen;
  current_nodo.coste = 0;
  current_nodo.secuencia.clear();
  frontier.push(current_nodo);

  // Inicializamos matriz de coste mínimo: [filas][columnas][8 orientaciones][zapatillas, las tiene o no]
  int filas = terreno.size();
  int columnas = terreno[0].size();
  vector<vector<vector<vector<int>>>> costeMinimo(
      filas, vector<vector<vector<int>>>(
                 columnas, vector<vector<int>>(
                               8, vector<int>(2, INT_MAX)))); 

  costeMinimo[origen.f][origen.c][origen.brujula][origen.zapatillas ? 1 : 0] = 0;

  while (!frontier.empty())
  {
    current_nodo = frontier.top();
    frontier.pop();

    // Si hemos llegado al destino (ignora orientación y zapatillas)
    if (current_nodo.estado.f == destino.f && current_nodo.estado.c == destino.c)
    {
      return current_nodo.secuencia; // Devolvemos la secuencia de acciones si es la solución
    }

    // // cout << "Visitando (" << current_nodo.estado.f << "," << current_nodo.estado.c << ") orient: " << current_nodo.estado.brujula << " zap: " << current_nodo.estado.zapatillas << " coste: " << current_nodo.coste << endl;

    explored.insert(current_nodo);

    // Recoger zapatillas si estamos sobre 'D'
    if (terreno[current_nodo.estado.f][current_nodo.estado.c] == 'D')
    {
      current_nodo.estado.zapatillas = true;
    }

    // Acciones posibles
    vector<Action> acciones = {WALK, RUN, TURN_SR, TURN_L};

    for (Action accion : acciones)
    { // Hemos decidido usar un bucle para evitar repetir código
      NodoR hijo = current_nodo;
      hijo.estado = applyR(accion, current_nodo.estado, terreno, altura);
      int costeTerreno = CosteBaseTerreno(terreno[current_nodo.estado.f][current_nodo.estado.c], accion);
      int costeAltura = (accion == WALK || accion == RUN) ? CosteCambioAltura(
                                                                altura[current_nodo.estado.f][current_nodo.estado.c],
                                                                altura[hijo.estado.f][hijo.estado.c],
                                                                terreno[current_nodo.estado.f][current_nodo.estado.c],
                                                                accion)
                                                          : 0;

      hijo.coste = current_nodo.coste + costeTerreno + costeAltura;
      hijo.secuencia = current_nodo.secuencia;
      hijo.secuencia.push_back(accion);

      int f = hijo.estado.f;
      int c = hijo.estado.c;
      int ori = hijo.estado.brujula;
      int zap = hijo.estado.zapatillas ? 1 : 0;

      if (f >= 0 && f < filas && c >= 0 && c < columnas)
      {
        if (hijo.coste < costeMinimo[f][c][ori][zap])
        {
          costeMinimo[f][c][ori][zap] = hijo.coste;
          frontier.push(hijo);
        }
      }
    }
  }

  // cout << "No se encontró un camino al destino." << endl;
  return path;
}
