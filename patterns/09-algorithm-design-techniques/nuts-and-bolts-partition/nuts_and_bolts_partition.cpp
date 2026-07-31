// Pattern: Matching nuts to bolts without comparing two of a kind
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/01-divide-and-conquer/nuts-and-bolts/nuts_and_bolts_divide.cpp (lines 22-47)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/nuts-and-bolts/nuts_and_bolts_divide.cpp#L22
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

int Dividir(vector<int> &v, vector<int> &v2, int inicio, int fin) {
  int pivote;
  if (v[inicio] == v2[inicio])
    pivote = v2[inicio];
  else {
    auto iterador = find(v2.begin(), v2.end(), v[inicio]);
    pivote = *iterador;
  }

  int izq = inicio + 1;
  int der = fin;

  while (izq <= der) {
    while (izq <= der && v[izq] <= pivote)
      izq++;

    while (izq <= der && v[der] > pivote)
      der--;

    if (izq < der)
      swap(v[izq], v[der]);
  }

  swap(v[inicio], v[der]);
  return der;
}
