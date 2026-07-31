// Pattern: Breaking movement loops with visit counters
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/rescue-agents -> src/rescatador.cpp (lines 500-507, 518-526)
//          https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L500
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

bool ComportamientoRescatador::CasillVisitadamasde10veces(int f, int c)
{
  if (visitados[f][c] > 6)
  {
    return true;
  }
  return false;
}

bool ComportamientoRescatador::casillaVisitada(int f, int c)
{
  if (visitadosBool[f][c])
  {
    return true;
  }
  else
    return false;
}
