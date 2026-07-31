# Triggers writing an audit trail

## Idea

Recording who did what, written by the database rather than by the application. An audit trail the application maintains can be bypassed by any code path that forgets it, or by anyone with direct database access; one written by a trigger cannot.

## Cost

One insert per audited operation.

## Where it is used

Practice 3: messaging module.

## Source

[`oracle-dbms-project/database/mensajeria/triggers_mensajeria.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/mensajeria/triggers_mensajeria.sql#L1-L25) &mdash; complete file.
