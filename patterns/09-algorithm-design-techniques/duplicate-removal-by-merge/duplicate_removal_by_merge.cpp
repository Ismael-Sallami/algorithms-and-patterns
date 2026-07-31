// Pattern: Removing duplicates as a side effect of the merge
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/01-divide-and-conquer/remove-duplicates/remove_duplicates_divide.cpp (lines 10-43)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/remove-duplicates/remove_duplicates_divide.cpp#L10
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

vector<int> divideyvenceras(vector<int> &vec, bool ord) {
  if (ord == false) {
    sort(vec.begin(), vec.end());
    ord = true;
  }

  if (vec.size() > 1) {
    int mitad = vec.size() / 2;
    auto iter = find(vec.begin(), vec.end(), vec[mitad]);
    int veces = count(iter, vec.end(), vec[mitad]);
    if (veces == int(vec.size())) {

      while (vec.size() > 1) {
        vec.pop_back();
      }
    } else {
      if (vec.back() != vec[mitad]) {
        for (int i = 0; i < veces; i++) {
          iter++;
        }
      }

      vector<int> izq(vec.begin(), iter);
      vector<int> der(iter, vec.end());
      izq = divideyvenceras(izq, ord);
      der = divideyvenceras(der, ord);
      for (size_t i = 0; i < der.size(); i++) {
        izq.push_back(der[i]);
      }
      vec = izq;
    }
  }
  return vec;
}
