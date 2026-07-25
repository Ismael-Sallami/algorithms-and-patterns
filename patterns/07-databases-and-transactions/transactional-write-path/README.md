# Multi-statement writes with commit and rollback

## Idea

Operations that touch several tables, wrapped so that a failure anywhere rolls the whole thing back. The pattern is the same in both: validate, write, commit on success, roll back on any exception, and let the caller see the error. Without the rollback a mid-sequence failure leaves a user row with no profile, and nothing detects it afterwards.

## Cost

One round trip per statement; the commit is what makes them one unit. Locks are held from first write to commit, so long transactions cost concurrency.

## Where it is used

Practice 3: user management.

## Source

[`DDSI/LaTeX/pr3/src/usuarios/functions.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/usuarios/functions.py#L8) &mdash; lines 8-49, 132-168.
