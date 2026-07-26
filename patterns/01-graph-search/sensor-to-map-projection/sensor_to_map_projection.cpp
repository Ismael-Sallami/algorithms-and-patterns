// Pattern: Projecting a local sensor reading onto a global map
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Practica2_IA -> practica2/auxiliar.cpp (lines 378-401, 403-472)
//          https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/auxiliar.cpp#L378
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// ════════════════════════════════════════════════════════════════════════════
//                              FUNCIONES NIVEL 1
// ════════════════════════════════════════════════════════════════════════════
pair<int, int> rotarA(int f, int c, int rumbo)
{
    switch (rumbo)
    {
    case 0:
        return {f, c}; // Norte
    case 1:
        return {(f - c), (f + c)}; // Noreste
    case 2:
        return {c, -f}; // Este
    case 3:
        return {(-f - c), (c - f)}; // Sureste
    case 4:
        return {-f, -c}; // Sur
    case 5:
        return {(-c + f), (-f - c)}; // Suroeste
    case 6:
        return {-c, f}; // Oeste
    case 7:
        return {(c + f), (-c + f)}; // Noroeste
    default:
        return {f, c};
    }
}

void SituarSensorEnMapaA(vector<vector<unsigned char>> &mapaTerreno, vector<vector<unsigned char>> &mapaAlturas, const Sensores &sensores)
{
    pair<int, int> desplazamientosEste[16] = {{0, 0}, {-1, 1}, {0, 1}, {1, 1}, {-2, 2}, {-1, 2}, {0, 2}, {1, 2}, {2, 2}, {-3, 3}, {-2, 3}, {-1, 3}, {0, 3}, {1, 3}, {2, 3}, {3, 3}};
    pair<int, int> desplazamientosOeste[16] = {{0, 0}, {1, -1}, {0, -1}, {-1, -1}, {2, -2}, {1, -2}, {0, -2}, {-1, -2}, {-2, -2}, {3, -3}, {2, -3}, {1, -3}, {0, -3}, {-1, -3}, {-2, -3}, {-3, -3}};
    pair<int, int> desplazamientosNorte[16] = {{0, 0}, {-1, -1}, {-1, 0}, {-1, 1}, {-2, -2}, {-2, -1}, {-2, 0}, {-2, 1}, {-2, 2}, {-3, -3}, {-3, -2}, {-3, -1}, {-3, 0}, {-3, 1}, {-3, 2}, {-3, 3}};
    pair<int, int> desplazamientosSur[16] = {{0, 0}, {1, 1}, {1, 0}, {1, -1}, {2, 2}, {2, 1}, {2, 0}, {2, -1}, {2, -2}, {3, 3}, {3, 2}, {3, 1}, {3, 0}, {3, -1}, {3, -2}, {3, -3}};
    pair<int, int> desplazamientosSuroeste[16] = {{0, 0}, {1, 0}, {1, -1}, {0, -1}, {2, 0}, {2, -1}, {2, -2}, {1, -2}, {0, -2}, {3, 0}, {3, -1}, {3, -2}, {3, -3}, {2, -3}, {1, -3}, {0, -3}};
    pair<int, int> desplazamientosSureste[16] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {0, 3}, {1, 3}, {2, 3}, {3, 3}, {3, 2}, {3, 1}, {3, 0}};
    pair<int, int> desplazamientosNoreste[16] = {{0, 0}, {-1, 0}, {-1, 1}, {0, 1}, {-2, 0}, {-2, 1}, {-2, 2}, {-1, 2}, {0, 2}, {-3, 0}, {-3, 1}, {-3, 2}, {-3, 3}, {-2, 3}, {-1, 3}, {0, 3}};
    pair<int, int> desplazamientosNoroeste[16] = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {0, -2}, {-1, -2}, {-2, -2}, {-2, -1}, {-2, 0}, {0, -3}, {-1, -3}, {-2, -3}, {-3, -3}, {-3, -2}, {-3, -1}, {-3, 0}};

    pair<int, int> desplazamientosSeleccionados[16];
    switch (sensores.rumbo)
    {
    case norte:
        for (int i = 0; i < 16; i++)
        {
            desplazamientosSeleccionados[i] = desplazamientosNorte[i];
        }
        break;
    case sur:
        for (int i = 0; i < 16; i++)
        {
            desplazamientosSeleccionados[i] = desplazamientosSur[i];
        }
        break;
    case este:
        for (int i = 0; i < 16; i++)
        {
            desplazamientosSeleccionados[i] = desplazamientosEste[i];
        }
        break;
    case oeste:
        for (int i = 0; i < 16; i++)
        {
            desplazamientosSeleccionados[i] = desplazamientosOeste[i];
        }
        break;
    case noroeste:
        for (int i = 0; i < 16; i++)
        {
            desplazamientosSeleccionados[i] = desplazamientosNoroeste[i];
        }
        break;
    case noreste:
        for (int i = 0; i < 16; i++)
        {
            desplazamientosSeleccionados[i] = desplazamientosNoreste[i];
        }
        break;
    case sureste:
        for (int i = 0; i < 16; i++)
        {
            desplazamientosSeleccionados[i] = desplazamientosSureste[i];
        }
        break;
    case suroeste:
        for (int i = 0; i < 16; i++)
        {
            desplazamientosSeleccionados[i] = desplazamientosSuroeste[i];
        }
        break;
    }

    for (int i = 0; i < 16; i++)
    {
        mapaTerreno[sensores.posF + desplazamientosSeleccionados[i].first][sensores.posC + desplazamientosSeleccionados[i].second] = sensores.superficie[i];
        mapaAlturas[sensores.posF + desplazamientosSeleccionados[i].first][sensores.posC + desplazamientosSeleccionados[i].second] = sensores.cota[i];
    }
}
