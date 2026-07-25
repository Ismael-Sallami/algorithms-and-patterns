#!/usr/bin/env python3
"""Count the patterns in this repository and print the README table.

A pattern is a directory two levels below patterns/ that holds a README and one
source file. Run from anywhere; paths are resolved from this file's location.

Author: Ismael Sallami Moreno
"""

from pathlib import Path

TITLES = {
    "01-graph-search": "Graph and state-space search",
    "02-adversarial-search": "Adversarial search",
    "03-metaheuristics": "Metaheuristics and continuous optimisation",
    "04-concurrency-and-distributed": "Concurrency and distributed systems",
    "05-data-structures-and-adt": "Data structures and abstract data types",
    "06-applied-machine-learning": "Applied machine learning",
    "07-databases-and-transactions": "Databases and transactions",
}

ROOT = Path(__file__).resolve().parent.parent


def main():
    counts = {}
    for category in sorted((ROOT / "patterns").iterdir()):
        if not category.is_dir():
            continue
        counts[category.name] = sum(
            1 for p in category.iterdir()
            if p.is_dir() and (p / "README.md").exists())

    unknown = set(counts) - set(TITLES)
    if unknown:
        raise SystemExit(f"category without a title: {sorted(unknown)}")

    print("| Category | Implementations |")
    print("| --- | ---: |")
    total = 0
    for slug, title in TITLES.items():
        n = counts.get(slug, 0)
        total += n
        print(f"| [{title}](patterns/{slug}/) | {n} |")
    print(f"| **Total** | **{total}** |")
    print()
    print(f"{total} patterns in {len(counts)} categories.")


if __name__ == "__main__":
    main()
