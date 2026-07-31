# Unit tests for the optimisation components

## Idea

Tests over the problem definition, the solution encoding and the neighbourhood operators. These are the parts where a bug does not crash: it produces a slightly wrong fitness, every algorithm optimises against it, and the results look plausible. Testing the objective is what makes the rest of the comparison trustworthy.

## Cost

Constant-size fixtures; the suite runs in well under a second.

## Where it is used

Regression suite for the metaheuristics framework.

## Source

[`metaheuristics/src/practice-1/tests/test.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-1/tests/test.cpp#L1-L731) &mdash; complete file.
