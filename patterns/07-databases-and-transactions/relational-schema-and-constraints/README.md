# Relational schema with declarative constraints

## Idea

The schema for a social platform, with primary and foreign keys, uniqueness and check constraints, and cascade rules on delete. Every rule expressed declaratively here is one the application cannot violate by accident, from any code path, including the ones written later.

## Cost

Constraint checks are index lookups. Cascade deletes cost one traversal per dependent row, which is the price of not orphaning them.

## Where it is used

Practice 3: the database behind the application.

## Source

[`oracle-dbms-project/database/00_init_tablas.sql`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/database/00_init_tablas.sql#L1-L225) &mdash; complete file.
