# Triggers maintaining derived counters

## Idea

Counters that must stay in step with the rows they count, maintained by triggers on insert and delete. Recomputing them on read is correct but costs a scan per query; maintaining them on write costs one update per change and keeps reads cheap.

## Cost

One trigger per affected row on write; reads become O(1) instead of O(n).

## Where it is used

Practice 3: publications module.

## Source

[`oracle-dbms-project/database/publicaciones/triggers_publicaciones.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/publicaciones/triggers_publicaciones.sql#L2-L58) &mdash; complete file.
