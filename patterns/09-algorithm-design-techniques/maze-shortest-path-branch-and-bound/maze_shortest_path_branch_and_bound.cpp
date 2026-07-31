// Pattern: Shortest way out of a maze with a bound on the path
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/03-backtracking-and-branch-and-bound/maze_branch_and_bound.cpp (lines 61-108)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/maze_branch_and_bound.cpp#L61-L108
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

bool SolucionBranchAndBound_Laberinto(laberinto L, Pos pos_actual,
                                      vector<Pos> &Marcados, int longitud,
                                      int min_longitud) {
  int n = L.GetSize();
  if (pos_actual.x > n - 1 || pos_actual.y > n - 1) {
    Marcados.push_back(pos_actual);
    return true; // estamos ya fuera, así que devolvemos true
  }

  if (pos_actual.x == n - 1 && pos_actual.y == n - 1 &&
      Valida(pos_actual.x, pos_actual.y, Marcados, L, n)) {
    Marcados.push_back(pos_actual);
    return true; // es el destino, así que devolvemos true
  }

  if (estaEnMarcados(Marcados, pos_actual)) {
    return false;
  }

  Marcados.push_back(pos_actual);

  // Explorar movimientos posibles
  vector<Pos> movimientos = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

  for (const auto &movimiento : movimientos) {
    int nx = pos_actual.x + movimiento.x;
    int ny = pos_actual.y + movimiento.y;
    if (Valida(nx, ny, Marcados, L, n)) {
      Pos nueva_pos(nx, ny);
      int new_longitud = longitud + 1;

      // Podar si el nuevo camino es menos prometedor que la mejor solución
      // encontrada
      if (new_longitud >= min_longitud) {
        continue; // No explorar esta rama
      }

      if (SolucionBranchAndBound_Laberinto(L, nueva_pos, Marcados, new_longitud,
                                           min_longitud)) {
        // Actualizar mínima longitud encontrada
        min_longitud = new_longitud;
        return true;
      }
    }
  }
  Marcados.pop_back();
  return false;
}
