# Database connection lifecycle

## Idea

Opening the connection in one place, with credentials from the environment and guaranteed release on the way out. Connections leaked on an error path are invisible until the server runs out of them, which is why the release is structural rather than left to each caller.

## Cost

One connection per session instead of one per operation.

## Where it is used

Practice 3: shared by every module.

## Source

[`DDSI/LaTeX/pr3/src/db_connection.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/db_connection.py#L1) &mdash; complete file.
