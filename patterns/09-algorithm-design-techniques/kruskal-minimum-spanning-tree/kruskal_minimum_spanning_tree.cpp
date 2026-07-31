// Pattern: Kruskal with union-find over the streets of a village
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/02-greedy/street_paving.cpp (lines 84-107)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/street_paving.cpp#L84
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

  vector<vector<int>> kruskal() {
    vector<vector<int>> solucion(matrizAdyacencia.size(),
                                 vector<int>(matrizAdyacencia.size(), 0));

    sort(aristas.begin(), aristas.end(),
         [](const Arista &a, const Arista &b) { return a.peso < b.peso; });

    vector<int> padre(matrizAdyacencia.size());
    for (int i = 0; i < padre.size(); ++i)
      padre[i] = i;

    for (const auto &arista : aristas) {
      int padreOrigen = encontrarPadre(padre, arista.origen);
      int padreDestino = encontrarPadre(padre, arista.destino);

      if (padreOrigen != padreDestino) {
        solucion[arista.origen][arista.destino] = arista.peso;
        cout << "Asfaltar calle entre Plaza " << arista.origen << " y Plaza "
             << arista.destino << " con coste " << arista.peso << endl;
        unir(padre, padreOrigen, padreDestino);
      }
    }
    return solucion;
  }
