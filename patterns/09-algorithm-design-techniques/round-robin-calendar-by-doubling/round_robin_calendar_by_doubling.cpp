// Pattern: Round-robin calendar built by doubling a half-sized one
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/01-divide-and-conquer/tournament-calendar/tournament_calendar_divide.cpp (lines 37-50)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/tournament-calendar/tournament_calendar_divide.cpp#L37
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

int dyv(int **partidos, int n){

    if (n == 2){
        partidos[0][0]=2;
        partidos[1][0]=1;
        return 0;
    }

    dyv(partidos, n/2);
    copiar_submatriz (0, 0, n/2, n/2 -1, n/2, partidos);
    rellenar_columna(n, partidos);

    return 0;
}
