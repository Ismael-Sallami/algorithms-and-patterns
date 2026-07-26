# Triggers maintaining derived counters

## Idea

Counters that must stay in step with the rows they count, maintained by triggers on insert and delete. Recomputing them on read is correct but costs a scan per query; maintaining them on write costs one update per change and keeps reads cheap.

## Cost

One trigger per affected row on write; reads become O(1) instead of O(n).

## Where it is used

Practice 3: publications module.

## Source

[`DDSI/LaTeX/pr3/database/publicaciones/triggers_publicaciones.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/publicaciones/triggers_publicaciones.sql#L1) &mdash; complete file.
