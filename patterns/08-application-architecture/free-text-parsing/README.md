# Parsing expenses from free text

## Idea

Extracting amount, category and date from a message typed by a person, with defaults for what is missing. Designed to reject rather than guess when the amount is ambiguous, because a wrongly parsed expense is worse than a rejected one - it enters the totals silently.

## Cost

O(len) per message with a bounded set of patterns.

## Where it is used

The Telegram bot's expense entry.

## Source

[`personal-finance-manager/app/services/expenses_parse.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/expenses_parse.py#L1) &mdash; complete file.
