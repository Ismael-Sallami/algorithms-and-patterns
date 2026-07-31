# Symmetric encryption of stored message bodies

## Idea

Message bodies encrypted with an authenticated symmetric scheme before they reach the database, so a database dump does not expose them. Authenticated encryption rather than plain encryption because it also detects tampering; the key lives outside the database, or the exercise is pointless.

## Cost

O(n) in the message length, once per read and once per write.

## Where it is used

Practice 3: messaging module.

## Source

[`oracle-dbms-project/src/mensajeria/cifrado.py`](https://github.com/Ismael-Sallami/oracle-dbms-project/blob/main/src/mensajeria/cifrado.py#L1-L14) &mdash; complete file.
