# Configuration parsing and run reproducibility

## Idea

Every parameter and the random seed come from a configuration file, with defaults for anything absent. Recording the seed with the results is what makes a run reproducible; without it a reported number cannot be regenerated, and the comparison stops being an experiment.

## Cost

O(k) for k configuration keys, once per run.

## Where it is used

Shared by every algorithm in this category.

## Source

[`MH-Practices/practice-3/code/src/config_reader.cpp`](https://github.com/Ismael-Sallami/MH-Practices/blob/main/practice-3/code/src/config_reader.cpp#L1) &mdash; complete file.
