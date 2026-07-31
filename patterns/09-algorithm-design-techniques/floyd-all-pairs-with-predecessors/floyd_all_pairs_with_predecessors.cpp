// Pattern: Floyd with a predecessor matrix, so the route can be read back
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/04-dynamic-programming/flight_times.cpp (lines 8-28)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/04-dynamic-programming/flight_times.cpp#L8
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

int tiempo_min(int origen, int destino, vector<vector<int>> tiempos, vector<vector<int>> & tiempos_min, 
    vector<vector<int>> & antecesores){

    tiempos_min = tiempos;
    for (int i=0; i<4; ++i) // Inicialmente, no se harán escalas y el antecesor será el aeropuerto del que vuelen directamente
        for (int j=0; j<4; ++j)
            antecesores[i][j]= i;

    int t_escala=0;
    for (int k=0; k<4; ++k)
        for (int i=0; i<4; ++i)
            for (int j=0; j<4; ++j)
                if (k != i && k != j){
                    t_escala = tiempos_min[i][k] + tiempos_min[k][j] + 1;
                    tiempos_min[i][j] = min(tiempos_min[i][j], t_escala);
                    if (tiempos_min[i][j] == t_escala) // Si hace escala, ponemos dónde ha hecho escala en la matriz de antecesores
                        antecesores[i][j] = k;
                }

    return tiempos_min[origen][destino];
}
