// Pattern: Cheapest descent of a mountain, filled bottom-up
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/04-dynamic-programming/mountain_descent.cpp (lines 11-41)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/mountain_descent.cpp#L11-L41
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

calcularCosteMinimo(const vector<vector<int>> &montana) {
  int f = montana.size();
  int c = montana[0].size();
  vector<vector<int>> T(f, vector<int>(c, INT_MAX));

  // Inicializar la primera fila
  for (int j = 0; j < c; ++j) {
    T[0][j] = montana[0][j];
  }

  // Llenar la tabla T utilizando la ecuación recurrente
  for (int i = 1; i < f; ++i) {
    for (int j = 0; j < c; ++j) {
      T[i][j] = montana[i][j] + T[i - 1][j];
      if (j > 0) {
        T[i][j] = min(T[i][j], montana[i][j] + T[i - 1][j - 1]);
      }
      if (j < c - 1) {
        T[i][j] = min(T[i][j], montana[i][j] + T[i - 1][j + 1]);
      }
    }
  }

  // Encontrar el valor objetivo
  int V = INT_MAX;
  for (int j = 0; j < c; ++j) {
    V = min(V, T[f - 1][j]);
  }

  return {T, V};
}
