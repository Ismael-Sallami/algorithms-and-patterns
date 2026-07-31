# Parsing delimited numeric series

## Idea

Reading the historical price series: split on the delimiter, convert, and reject malformed rows instead of letting a failed conversion enter the data as a zero. A silent parse failure here becomes a wrong fitness value, and the algorithm optimises against it without any symptom.

## Cost

O(bytes) with one pass and no reallocation per row.

## Where it is used

Data loading for the portfolio problem.

## Source

[`metaheuristics/src/practice-1/src/csv_reader.cpp`](https://github.com/Ismael-Sallami/metaheuristics/blob/main/src/practice-1/src/csv_reader.cpp#L11-L94) &mdash; complete file.
