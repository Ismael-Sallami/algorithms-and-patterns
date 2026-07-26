# Transforming a markup document into interactive HTML

## Idea

Parsing a question format written in Markdown and emitting self-contained interactive HTML: media, code blocks and answer handling included. The parser and the emitter are separate, so the output format can change without touching the grammar.

## Cost

O(len) over the document with one pass per stage.

## Where it is used

Generating practice tests from plain text.

## Source

[`md2html-testGenerator/md2html.py`](https://github.com/Ismael-Sallami/md2html-testGenerator/blob/main/md2html.py#L1) &mdash; complete file.
