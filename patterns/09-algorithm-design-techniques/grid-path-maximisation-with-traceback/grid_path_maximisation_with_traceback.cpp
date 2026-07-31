// Pattern: Most gold collectable crossing a grid, and the path that does it
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/04-dynamic-programming/gold_grid.cpp (lines 20-59)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/gold_grid.cpp#L20
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

pair<vector<vector<int>>, int> Max_oro(const vector<vector<char>>& mapa, int n, int m) {
    vector<vector<int>> T(n, vector<int>(m, 0));
    T[0][0] = Oro(mapa, 0, 0); // Inicializamos la primera casilla

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //Recorremos nuestra matriz que representa el mapa del juego
            if (mapa[i][j] == 'M') { // Si en la posicion (i,j) hay un muro
                T[i][j] = INT_MIN; //corresponde con el -infinito
            } else {//Si no hay un muro puede ser que en la casilla haya o no oro
                int oro = Oro(mapa, i, j);
                // Evitamos reescribir la celda inicial (0,0)
                if (!(i == 0 && j == 0)) {
                    if (i > 0 && j > 0) {
                        if (T[i-1][j-1] != INT_MIN) {
                            T[i][j] = max(T[i][j], T[i-1][j-1] + oro);
                        }
                    }
                    if (i > 0) {
                        if (T[i-1][j] != INT_MIN) {
                            T[i][j] = max(T[i][j], T[i-1][j] + oro);
                        }
                    }
                    if (j > 0) {
                        if (T[i][j-1] != INT_MIN) {
                            T[i][j] = max(T[i][j], T[i][j-1] + oro);
                        }
                    }
                    // Si todas las anteriores fueron INT_MIN, esta debe serlo también
                    if (T[i][j] == INT_MIN) {
                        T[i][j] = INT_MIN; // esto es redundante pero claro
                    }
                }
            }
        }
    }

    int V = T[n-1][m-1];
    return make_pair(T, V); //Devolvemos la matriz y el numero max de oro que podemos conseguir
}
