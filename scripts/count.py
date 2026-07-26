#!/usr/bin/env python3
"""Count the entries in this repository and print the README tables.

An entry is a directory two levels below patterns/ or reference/ that holds a
README. Counts come from the tree, so they cannot drift from the contents.

Author: Ismael Sallami Moreno
"""

from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

PATTERNS = [
    [
    "01-graph-search",
        "Graph and state-space search"
    ],
    [
    "02-adversarial-search",
        "Adversarial search"
    ],
    [
    "03-metaheuristics",
        "Metaheuristics and continuous optimisation"
    ],
    [
    "04-concurrency-and-distributed",
        "Concurrency and distributed systems"
    ],
    [
    "05-data-structures-and-adt",
        "Data structures and abstract data types"
    ],
    [
    "06-applied-machine-learning",
        "Applied machine learning"
    ],
    [
    "07-databases-and-transactions",
        "Databases and transactions"
    ],
    [
    "08-application-architecture",
        "Application architecture"
    ]
]

REFERENCE = [
    [
    "01-arrays-and-hashing",
        "Arrays and hashing"
    ],
    [
    "02-two-pointers-and-sliding-window",
        "Two pointers and sliding window"
    ],
    [
    "03-stack-and-monotonic-structures",
        "Stacks and monotonic structures"
    ],
    [
    "04-binary-search",
        "Binary search"
    ],
    [
    "05-linked-lists",
        "Linked lists"
    ],
    [
    "06-trees-and-tries",
        "Trees and tries"
    ],
    [
    "07-heaps-and-priority-queues",
        "Heaps and priority queues"
    ],
    [
    "08-backtracking",
        "Backtracking"
    ],
    [
    "09-graphs",
        "Graphs"
    ],
    [
    "10-advanced-graphs",
        "Advanced graphs"
    ],
    [
    "11-dynamic-programming",
        "Dynamic programming"
    ],
    [
    "12-greedy-and-intervals",
        "Greedy algorithms and intervals"
    ],
    [
    "13-string-algorithms",
        "String algorithms"
    ],
    [
    "14-math-and-bit-manipulation",
        "Mathematics and bit manipulation"
    ],
    [
    "15-computer-architecture",
        "Computer architecture"
    ],
    [
    "16-systems-primitives",
        "Systems primitives"
    ]
]


def count(tree):
    counts = {}
    root = ROOT / tree
    if not root.is_dir():
        return counts
    for category in sorted(root.iterdir()):
        if not category.is_dir():
            continue
        counts[category.name] = sum(
            1 for child in category.iterdir()
            if child.is_dir() and (child / "README.md").exists())
    return counts


def report(heading, rows, tree):
    counts = count(tree)
    unknown = set(counts) - {slug for slug, _ in rows}
    if unknown:
        raise SystemExit(f"category without a title in {tree}: {sorted(unknown)}")
    print(f"### {heading}")
    print()
    print("| Category | Implementations |")
    print("| --- | ---: |")
    total = 0
    for slug, title in rows:
        n = counts.get(slug, 0)
        total += n
        print(f"| [{title}]({tree}/{slug}/) | {n} |")
    print()
    return total


def main():
    extracted = report("Extracted from earlier work", PATTERNS, "patterns")
    written = report("Written for this repository", REFERENCE, "reference")
    print(f"Total: {extracted + written} implementations "
          f"({extracted} extracted, {written} written here).")


if __name__ == "__main__":
    main()
