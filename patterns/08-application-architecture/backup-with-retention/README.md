# Backups with a retention policy

## Idea

Periodic dumps, kept to a bounded window, with old ones removed. Unbounded backups fill the disk and then the service stops accepting writes, so the retention rule is part of the backup rather than an afterthought. Verifying the dump is non-empty before rotating the previous one out matters more than the schedule.

## Cost

O(size) per dump, O(k) retained files.

## Where it is used

Database backup in the finance service.

## Source

[`personal-finance-manager/app/services/backup.py`](https://github.com/Ismael-Sallami/personal-finance-manager/blob/main/app/services/backup.py#L1-L113) &mdash; complete file.
