# Symmetric encryption of stored message bodies

## Idea

Message bodies encrypted with an authenticated symmetric scheme before they reach the database, so a database dump does not expose them. Authenticated encryption rather than plain encryption because it also detects tampering; the key lives outside the database, or the exercise is pointless.

## Cost

O(n) in the message length, once per read and once per write.

## Where it is used

Practice 3: messaging module.

## Source

[`DDSI/LaTeX/pr3/src/mensajeria/cifrado.py`](https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/mensajeria/cifrado.py#L1) &mdash; complete file.
