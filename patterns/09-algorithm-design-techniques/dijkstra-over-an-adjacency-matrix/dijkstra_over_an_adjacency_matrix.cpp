// Pattern: Dijkstra over an adjacency matrix of sensor links
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/02-greedy/sensor_network.cpp (lines 90-146)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/sensor_network.cpp#L90-L146
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

vector<int> dijkstra(vector<vector<int>>& matriz, int inicio, int n) {
    vector<int> distancia(n, INF);
    vector<vector<int>> predecesores(matriz.size()); 
    distancia[inicio] = 0;

    // Usamos una cola de prioridad para almacenar los nodos a visitar
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, inicio});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        // Si la distancia actual es mayor que la distancia almacenada, no procesamos
        if (dist_u > distancia[u]) continue;

        // Recorremos los vecinos de u
        for (int v = 0; v < n; ++v) {
            // Si hay un camino de u a v (que corresponde con que en la matriz de 
            //adyacencia haya un valor distinto de 0 en la pos i j, 
            //siendo i,j los nodos) 
            //y la distancia de inicio a u más la distancia de u a v es menor que la distancia almacenada para v
            if (matriz[u][v] && distancia[u] + matriz[u][v] < distancia[v]) {
                distancia[v] = distancia[u] + matriz[u][v];
                pq.push({distancia[v], v});
                //vamos a ir añadiendo a la lista de predecesores todos los que vamos recorriendo de 
                //esta manera lo que hacemos es
                // cada vez que vamos añadir uno añadimos los que ya estaban y acto seguido por el que vamos a pasar ahora
                predecesores[v].insert(predecesores[v].begin(), predecesores[u].begin(), predecesores[u].end());
                // Agregamos v al final de la lista de predecesores de v
                predecesores[v].push_back(v);
            }
        }
    }

    // Imprimir las distancias más cortas desde el origen
    for (int i = 0; i < matriz.size(); i++) {
        if (distancia[i] == INF) {
            cout << "El vértice " << i << " es inalcanzable desde el origen" << endl;
        } else {
            cout << "Distancia del origen al vértice " << i << ": " << distancia[i] << endl;
        }
    }

    cout << "La lista de predecesores es: " << endl;

    for(int i=0;i<matriz.size();i++){
        for(int j=0;j<predecesores[i].size();j++){
            cout << predecesores[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return distancia;
}
