// Pattern: Greedy refuelling: always the furthest station still reachable
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/02-greedy/bus_refuelling.cpp (lines 26-52)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/02-greedy/bus_refuelling.cpp#L26-L52
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

vector<int> ParadasDeLaRuta(int distancias[][TAM], int tam, int n, int k){

    vector<int> s;
    int punto_actual = 0;

    while (n > k){

        int max_dist = 0;
        int prox_destino = 0;

        for (int i=1; i<tam; ++i)
            if (distancias[punto_actual][i] > max_dist){
                max_dist = distancias[punto_actual][i];
                prox_destino = i;
            }

        if (max_dist <= k){ // Si puedo llegar con un tanque lo añado a mi solución parcial
            s.push_back(prox_destino);
            punto_actual = prox_destino;
            n -= max_dist;
        }
        else // Nunca podré recorrer esa distancia sin parar
            distancias[punto_actual][prox_destino] = distancias[prox_destino][punto_actual] = -1;
    }

    return s;
}
