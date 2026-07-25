// Pattern: A* re-targeted at a resupply point when the primary goal is unreachable
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Practica2_IA -> practica2/auxiliar.cpp (lines 1302-1396)
//          https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/auxiliar.cpp#L1302
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// ════════════════════════════════════════════════════════════════════════════
//                              FUNCIONES NIVEL 4
// ════════════════════════════════════════════════════════════════════════════
vector<Action> ComportamientoAuxiliar::AEstrellaAuxiliar_lvl4(const EstadoA &origen, EstadoA &destino, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura, bool esparaRecargar = false)
{
    NodoA current_nodo;
    priority_queue<NodoA, vector<NodoA>, greater<NodoA>> frontier;
    set<NodoA> explored;
    vector<Action> path;

    current_nodo.estado = origen;
    current_nodo.coste = 0;
    current_nodo.secuencia.clear();
    frontier.push(current_nodo);

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

        // para los niveles S del 4----------------
        if (!esparaRecargar)
        {
            if (current_nodo.estado.brujula == noroeste || current_nodo.estado.brujula == suroeste || current_nodo.estado.brujula == noreste || current_nodo.estado.brujula == sureste)
            {
                if (abs(current_nodo.estado.f - destino.f) <= 3 && abs(current_nodo.estado.c - destino.c) <= 3)
                {
                    destino.f = current_nodo.estado.f;
                    destino.c = current_nodo.estado.c;
                }
            }
        }
        // para los niveles S del 4----------------

        if (current_nodo.estado.f == destino.f && current_nodo.estado.c == destino.c)
        {
            return current_nodo.secuencia; // Devuelve vector<Action>
        }

        explored.insert(current_nodo);

        if (terreno[current_nodo.estado.f][current_nodo.estado.c] == 'D')
        {
            current_nodo.estado.zapatillas = true;
        }

        vector<Action> acciones = {WALK, TURN_SR};

        for (Action accion : acciones)
        {
            NodoA hijo = current_nodo;
            hijo.estado = applyA(accion, current_nodo.estado, terreno, altura);

            int f = hijo.estado.f;
            int c = hijo.estado.c;
            if (f < 0 || f >= filas || c < 0 || c >= columnas)
                continue;

            int costeTerreno = CosteBaseTerreno(terreno[current_nodo.estado.f][current_nodo.estado.c], accion);
            int costeAltura = (accion == WALK || accion == RUN) ? CosteCambioAltura(
                                                                      altura[current_nodo.estado.f][current_nodo.estado.c],
                                                                      altura[hijo.estado.f][hijo.estado.c],
                                                                      terreno[current_nodo.estado.f][current_nodo.estado.c],
                                                                      accion)
                                                                : 0;

            int costeAccion = costeTerreno + costeAltura;
            hijo.coste = current_nodo.coste + costeAccion;
            hijo.secuencia = current_nodo.secuencia;
            hijo.secuencia.push_back(accion);

            int heuristica = abs(destino.f - hijo.estado.f) + abs(destino.c - hijo.estado.c);
            int costeEstimado = hijo.coste + heuristica;

            int ori = hijo.estado.brujula;
            int zap = hijo.estado.zapatillas ? 1 : 0;

            if (hijo.coste < costeMinimo[f][c][ori][zap])
            {
                costeMinimo[f][c][ori][zap] = hijo.coste;
                hijo.prioridad = costeEstimado;
                frontier.push(hijo);
            }
        }
    }

    // cout << "No se encontró un camino al destino (A* auxiliar)." << endl;
    return path; // Retorna vector<Action> vacío si no hay solución
}
