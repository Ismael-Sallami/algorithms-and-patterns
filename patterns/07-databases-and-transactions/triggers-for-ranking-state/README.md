# Triggers maintaining ranking state

## Idea

Trend scores updated as the underlying activity changes, rather than recomputed when someone asks for the ranking. Puts the cost on the write path, which is the right side for data read far more often than it changes.

## Cost

One update per activity row against a full aggregation per read.

## Where it is used

Practice 3: trends module.

## Source

[`oracle-dbms-project/database/tendencias/triggers_tendencias.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/tendencias/triggers_tendencias.sql#L1-L45) &mdash; complete file.
