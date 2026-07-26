// Pattern: Repeated-run protocol with mean and standard deviation
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/MH-Practices -> practice-3/code/main.cpp (lines 116-166, 169-194)
//          https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/main.cpp#L116
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// Run a stochastic algorithm multiple times
Statistics run_stochastic_experiment(
    MH<double> &algoritmo,
    PortfolioProblem &prob_train,
    PortfolioProblem &prob_test,
    int num_executions,
    int max_evals,
    long int base_seed)
{
    Statistics results = {0, 0, 0, 0, 0, 0, {}};
    results.fitness_history.reserve(num_executions);

    for (int i = 0; i < num_executions; ++i)
    {
        Random::seed(base_seed + i);

        auto inicio = high_resolution_clock::now();
        // Train on 2015-2024 data
        auto resultado = algoritmo.optimize(prob_train, max_evals);
        auto fin = high_resolution_clock::now();

        // Test weights on 2025
        double fitness_2025 = prob_test.fitness(resultado.solution);
        double profit_2025 = prob_test.getProfit(resultado.solution);

        // Accumulate metrics
        results.mean_train_fitness += resultado.fitness;
        results.mean_test_fitness += fitness_2025;
        results.mean_test_profit += profit_2025;
        results.mean_time_seconds += duration<double>(fin - inicio).count();
        results.mean_evaluations += resultado.evaluations;

        results.fitness_history.push_back(resultado.fitness);
    }

    // Calculate averages
    results.mean_train_fitness /= num_executions;
    results.mean_test_fitness /= num_executions;
    results.mean_test_profit /= num_executions;
    results.mean_time_seconds /= num_executions;
    results.mean_evaluations /= num_executions;

    // Calculate standard deviation
    double variance = 0.0;
    for (double fitness : results.fitness_history)
    {
        variance += pow(fitness - results.mean_train_fitness, 2);
    }
    results.standard_deviation = sqrt(variance / num_executions);

    return results;
}

// Run a deterministic algorithm once
Statistics run_deterministic_experiment(
    MH<double> &algoritmo,
    PortfolioProblem &prob_train,
    PortfolioProblem &prob_test)
{
    Statistics results = {0, 0, 0, 0, 0, 0, {}};

    auto inicio = high_resolution_clock::now();
    auto resultado = algoritmo.optimize(prob_train, 1);
    auto fin = high_resolution_clock::now();

    // Test weights on 2025
    double fitness_2025 = prob_test.fitness(resultado.solution);
    double profit_2025 = prob_test.getProfit(resultado.solution);

    results.mean_train_fitness = resultado.fitness;
    results.mean_test_fitness = fitness_2025;
    results.mean_test_profit = profit_2025;
    results.mean_time_seconds = duration<double>(fin - inicio).count();
    results.mean_evaluations = resultado.evaluations;
    results.standard_deviation = 0.0;

    results.fitness_history.push_back(resultado.fitness);

    return results;
}
