// Pattern: Iterated local search with simulated annealing as the local optimiser
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/metaheuristics -> src/practice-3/src/ils_es.cpp (complete file)
//          https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-3/src/ils_es.cpp#L3-L38
// Extract: verbatim, complete file.
//          Not a standalone build. See the source repository for the
//          full build context.

#include "ils_es.h"

using namespace std;

ResultMH<double> ILSES::optimize(Problem<double> &problem, int maxevals) {
    int total_evals = 0;
    SimulatedAnnealing es(m_mu, m_phi, m_tf, m_ratio, m_max_vecinos, m_max_exitos);

    // Initial phase: random solution refined by Simulated Annealing.
    tSolution<double> current_sol = problem.createSolution();
    
    // Each SA execution is capped by m_max_evals_bl to distribute the total budget.
    ResultMH<double> result = es.optimize(problem, m_max_evals_bl, current_sol);
    total_evals += result.evaluations;

    tSolution<double> best_sol = result.solution;
    tFitness best_fitness = result.fitness;

    // Successive phases: perturb the best found solution and refine it with SA.
    for (int i = 1; i < m_num_starts; ++i) {
        if (total_evals >= maxevals) break;

        tSolution<double> mutated_sol = best_sol;
        mutate(mutated_sol);
        // Ensure mutated solution respects bounds and normalization
        problem.fix(mutated_sol);

        ResultMH<double> result_mut = es.optimize(problem, m_max_evals_bl, mutated_sol);
        total_evals += result_mut.evaluations;

        if (result_mut.fitness > best_fitness) {
            best_fitness = result_mut.fitness;
            best_sol = result_mut.solution;
        }
    }

    return ResultMH<double>(best_sol, best_fitness, total_evals);
}
