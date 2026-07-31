// Pattern: Breadth-first search over a grid state space
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/rescue-agents -> src/rescatador.cpp (lines 1222-1302)
//          https://github.com/Ismael-Sallami/rescue-agents/blob/main/src/rescatador.cpp#L1222-L1302
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

list<Action> ComportamientoRescatador::AnchuraRescatador(const EstadoR &inicio, const EstadoR &final, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura)
{
  NodoR current_node;
  list<NodoR> frontier;
  list<Action> path;
  set<NodoR> explored;

  current_node.estado = inicio; // Asigno el estado inicial al nodo actual.
  frontier.push_back(current_node);
  bool SolutionFound = (current_node.estado.f == final.f && current_node.estado.c == final.c);

  while (!SolutionFound and !frontier.empty())
  {
    frontier.pop_front();
    explored.insert(current_node);

    // Compruebo si estoy en una casilla que da las zapatillas
    if (terreno[current_node.estado.f][current_node.estado.c] == 'i')
    {
      current_node.estado.zapatillas = true;
    }

    // Genero el hijo resultante de aplicar la acción WALK
    NodoR child_WALK = current_node;
    child_WALK.estado = applyR(WALK, current_node.estado, terreno, altura);
    if (child_WALK.estado.f == final.f and child_WALK.estado.c == final.c)
    {
      // El hijo generado es solución
      child_WALK.secuencia.push_back(WALK);
      current_node = child_WALK;
      SolutionFound = true;
    }
    else if (explored.find(child_WALK) == explored.end())
    {
      // Se mete en la lista frontier después de añadir a secuencia la acción
      child_WALK.secuencia.push_back(WALK);
      frontier.push_back(child_WALK);
    }

    // Genero el hijo resultante de aplicar la acción TURN_SR
    if (!SolutionFound)
    {
      NodoR child_TURN_SR = current_node;
      child_TURN_SR.estado = applyR(TURN_SR, current_node.estado, terreno, altura);
      if (explored.find(child_TURN_SR) == explored.end())
      {
        child_TURN_SR.secuencia.push_back(TURN_SR);
        frontier.push_back(child_TURN_SR);
      }
    }

    // Genero el hijo resultante de aplicar la acción TURN_L
    if (!SolutionFound)
    {
      NodoR child_TURN_L = current_node;
      child_TURN_L.estado = applyR(TURN_L, current_node.estado, terreno, altura);
      if (explored.find(child_TURN_L) == explored.end())
      {
        child_TURN_L.secuencia.push_back(TURN_L);
        frontier.push_back(child_TURN_L);
      }
    }

    // Paso a evaluar el siguiente nodo en la lista "frontier"
    if (!SolutionFound and !frontier.empty())
    {
      current_node = frontier.front();
      while (explored.find(current_node) != explored.end() and !frontier.empty())
      {
        frontier.pop_front();
        current_node = frontier.front();
      }
    }
  }

  // Devuelvo el camino si se ha encontrado solución
  if (SolutionFound)
    path = current_node.secuencia;

  return path;
}
