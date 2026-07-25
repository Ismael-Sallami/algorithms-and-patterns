// Pattern: Basic multistart with a shared best
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/MH-Practices -> practice-3/code/src/bmb.cpp (complete file)
//          https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/bmb.cpp#L1
// Extract: verbatim, complete file.
//          Not a standalone build. See the source repository for the
//          full build context.

#include "bmb.h"
#include <vector>

using namespace std;

ResultMH<double> BMB::optimize(Problem<double> &problem, int maxevals) {
    tSolution<double> global_best_sol;
    tFitness global_best_fitness = -1e18; 
    int total_evals = 0;

    LocalSearch bl(m_ratio);

    // Iterative loop for independent multi-starts.
    for (int i = 0; i < m_num_starts; ++i) {
        // Halt if the global evaluation budget is exhausted.
        if (total_evals >= maxevals) break;

        // Stage 1: generate an explicit random initial solution.
        tSolution<double> initial_sol = problem.createSolution();

        // Stage 2: run the local search starting from the generated solution.
        // Each search is limited by m_max_evals_bl.
        ResultMH<double> result = bl.optimize(problem, m_max_evals_bl, initial_sol);
        total_evals += result.evaluations;

        // Track the best solution discovered across all trajectories.
        if (result.fitness > global_best_fitness) {
            global_best_fitness = result.fitness;
            global_best_sol = result.solution;
        }
    }

    return ResultMH<double>(global_best_sol, global_best_fitness, total_evals);
}
