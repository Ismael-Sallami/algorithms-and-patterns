# Verifying credentials against stored hashes

## Idea

Login compares a hash of the supplied password against the stored hash; the password itself is never stored and never logged. The failure message is the same whether the user does not exist or the password is wrong, so the response cannot be used to enumerate accounts.

## Cost

One hash computation and one indexed lookup per attempt.

## Where it is used

Practice 3: user management.

## Source

[`DDSI/LaTeX/pr3/src/usuarios/auth.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/usuarios/auth.py#L1) &mdash; complete file.
