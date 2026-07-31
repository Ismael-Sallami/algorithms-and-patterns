// Pattern: Greedy maximum-weight pairing, and where it settles too early
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/02-greedy/student_pairing.cpp (lines 17-46)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/student_pairing.cpp#L17-L46
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

vector<pair<pair<int, int>, int>> GreedyParejas(vector<vector<int>> matriz) {
  vector<pair<pair<int, int>, int>> S, preferencia;
  for (int i = 0; i < matriz.size(); i++) {
    for (int j = i; j < matriz.size(); j++) {
      if (matriz[i][j] > 0) {
        preferencia.push_back(pair(pair(i, j), matriz[i][j] * matriz[j][i]));
      }
    }
  }

  while (!preferencia.empty()) {
    int max = 0;
    for (int i = 0; i < preferencia.size(); i++) {
      if (preferencia[max].second < preferencia[i].second) {
        max = i;
      }
    }
    S.push_back(preferencia[max]);
    for (auto i = preferencia.begin(); i != preferencia.end(); ++i) {
      if (i->first.first == S.back().first.first ||
          i->first.second == S.back().first.second ||
          i->first.second == S.back().first.first ||
          i->first.first == S.back().first.second) {
        i = preferencia.erase(i);
        --i;
      }
    }
  }
  return S;
}
