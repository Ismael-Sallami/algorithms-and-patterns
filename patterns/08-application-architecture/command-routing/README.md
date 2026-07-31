# Routing bot commands to handlers

## Idea

A conversational interface as a command table plus per-command state: parse the message, route to a handler, keep the multi-step conversations alive between messages. Handlers never parse and the router never computes, which is what keeps a chat interface from becoming one long conditional.

## Cost

O(1) routing, O(users) conversation state.

## Where it is used

The Telegram interface to the finance service.

## Source

[`personal-finance-manager/app/services/bot.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/bot.py#L1-L578) &mdash; complete file.
