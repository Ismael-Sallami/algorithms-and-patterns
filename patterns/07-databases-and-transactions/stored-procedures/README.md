# Server-side procedures

## Idea

Multi-statement operations moved into the database. One round trip instead of several, the whole sequence inside one transaction, and the same logic for every client. The trade is that this logic now lives outside version control's usual reach, which is why the boundary of what belongs here has to be deliberate.

## Cost

Saves n-1 round trips for an n-statement operation. Execution plans are prepared once.

## Where it is used

Practice 3: advertising module.

## Source

[`oracle-dbms-project/database/publicidad/procedures_publicidad.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/publicidad/procedures_publicidad.sql#L1-L28) &mdash; complete file.
