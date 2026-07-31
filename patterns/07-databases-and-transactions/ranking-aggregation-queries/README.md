# Aggregation and ranking queries

## Idea

Grouping, counting and ordering pushed into SQL rather than done in Python over a full result set. The database has the indexes and can stop early; fetching every row to sort it in the client moves the whole table across the connection to throw most of it away.

## Cost

Index-assisted grouping in the database against O(n) transfer plus O(n log n) client-side sorting.

## Where it is used

Practice 3: trends module.

## Source

[`oracle-dbms-project/src/tendencias/functions.py`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/src/tendencias/functions.py#L2-L72) &mdash; complete file.
