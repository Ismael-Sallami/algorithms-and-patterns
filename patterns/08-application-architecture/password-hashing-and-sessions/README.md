# Password hashing and session tokens

## Idea

Passwords through a deliberately slow salted hash, sessions as signed tokens with an expiry. The hash is slow on purpose: it is the only thing standing between a leaked table and the plaintext passwords, and a fast hash makes that table trivial to crack offline.

## Cost

One hash per login, deliberately expensive. Token verification is a signature check.

## Where it is used

Authentication for the finance service.

## Source

[`personal-finance-manager/app/security.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/security.py#L1-L76) &mdash; complete file.
