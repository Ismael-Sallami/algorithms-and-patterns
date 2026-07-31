// Pattern: The same pairing by backtracking, which finds what greedy misses
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/03-backtracking-and-branch-and-bound/student_pairing.cpp (lines 34-61)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/student_pairing.cpp#L34-L61
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

void backtrackingparejas(vector<pair<pair<int, int>, int>> vectorparejas,
                         pair<vector<pair<int, int>>, int> &solparcial,
                         int inicial) {
  auto vectorcopia = vectorparejas;
  pair<vector<pair<int, int>>, int> solcopia;

  solcopia.second = 0;
  solcopia.first.push_back(vectorcopia[inicial].first);
  solcopia.second += vectorcopia[inicial].second;
  Borrar(vectorcopia, make_pair(vectorcopia[inicial].first.first,
                                vectorcopia[inicial].first.second));

  while (vectorcopia.empty() == false) {
    solcopia.first.push_back(vectorcopia[0].first);
    solcopia.second += vectorcopia[0].second;
    Borrar(vectorcopia,
           make_pair(vectorcopia[0].first.first, vectorcopia[0].first.second));
  }

  if (solcopia.second > solparcial.second) {
    solparcial = solcopia;
  }

  if (inicial < vectorparejas.size() - 1) {
    backtrackingparejas(vectorparejas, solparcial, inicial + 1);
  }
  return;
}
