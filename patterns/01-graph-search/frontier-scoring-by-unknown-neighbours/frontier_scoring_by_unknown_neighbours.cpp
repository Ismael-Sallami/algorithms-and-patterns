// Pattern: Scoring frontier cells by surrounding unknown area
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/rescue-agents -> src/auxiliar.cpp (lines 1534-1553, 1556-1579)
//          https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/auxiliar.cpp#L1534-L1579
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

int contarInterrogantesAlrededor_A(const vector<vector<unsigned char>> &mapa, int f, int c)
{
    int total = 0;
    for (int df = -1; df <= 1; ++df)
    {
        for (int dc = -1; dc <= 1; ++dc)
        {
            if (df == 0 && dc == 0)
                continue; // Saltar la casilla central
            int nf = f + df;
            int nc = c + dc;
            if (nf >= 0 && nf < mapa.size() && nc >= 0 && nc < mapa[0].size())
            {
                if (mapa[nf][nc] == '?')
                    total++;
            }
        }
    }
    return total;
}

// función para ver las casillas con mas interrogaciones alrededor
priority_queue<CasillaDescubrimiento_Auxiliar> ComportamientoAuxiliar::cola_con_casillas_con_interrogacion(Sensores sensores)
{
    priority_queue<CasillaDescubrimiento_Auxiliar> explorables;

    for (int f = 1; f < mapaResultado.size() - 1; ++f)
    {
        for (int c = 1; c < mapaResultado[0].size() - 1; ++c)
        {
            if (!visitadosCasillasInterrogacion[f][c])
            {
                if (!casillaTransitable(mapaResultado[f][c], tiene_zapatillas))
                    continue;

                int numInterrogantes = contarInterrogantesAlrededor_A(mapaResultado, f, c);
                if (numInterrogantes > 0)
                {
                    explorables.push({f, c, numInterrogantes});
                    visitadosCasillasInterrogacion[f][c] = true; // Marcar como visitada
                }
            }
        }
    }
    return explorables;
}
