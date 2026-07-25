// Pattern: Best-first selection of the next cell to explore
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Practica2_IA -> practica2/rescatador.cpp (lines 1650-1673)
//          https://github.com/Ismael-Sallami/Practica2_IA/blob/main/practica2/rescatador.cpp#L1650
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// función para ver las casillas con mas interrogaciones alrededor
priority_queue<CasillaDescubrimiento> ComportamientoRescatador::cola_con_casillas_con_interrogacion(Sensores sensores)
{
  priority_queue<CasillaDescubrimiento> explorables;

  for (int f = 1; f < mapaResultado.size() - 1; ++f)
  {
    for (int c = 1; c < mapaResultado[0].size() - 1; ++c)
    {
      if (!visitadosCasillasInterrogacion[f][c])
      {
        if (!casillaTransitable(mapaResultado[f][c]))
          continue;

        int numInterrogantes = contarInterrogantesAlrededor(mapaResultado, f, c);
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
