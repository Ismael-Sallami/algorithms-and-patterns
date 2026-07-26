# Scheduling background jobs

## Idea

Periodic jobs - price refresh, contributions, backup - registered with intervals and wrapped so that one failing job cannot kill the scheduler or the request path. A job that throws and takes the loop with it stops every other job silently.

## Cost

One timer per job. Each run is bounded by the job's own cost.

## Where it is used

Price updates and maintenance tasks in the finance service.

## Source

[`personal-finance-manager/app/scheduler.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/scheduler.py#L1) &mdash; complete file.
