# Business rules enforced by triggers

## Idea

Rules that no key or check constraint can express - derived totals, state transitions, audit rows - implemented as row-level triggers. They fire inside the same transaction as the statement that caused them, so either both take effect or neither does. Enforcing this in application code would mean every client had to remember to.

## Cost

One trigger execution per affected row. A trigger that writes to a table with its own triggers multiplies that cost.

## Where it is used

Practice 3: advertising module.

## Source

[`DDSI/LaTeX/pr3/database/publicidad/triggers_publicidad.sql`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/publicidad/triggers_publicidad.sql#L1) &mdash; complete file.
