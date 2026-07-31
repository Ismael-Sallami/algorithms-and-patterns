# Extracting text from PDF with layered fallbacks

## Idea

PDFs vary from clean text layers to scanned images, so extraction tries the cheap library first and escalates to layout analysis and then OCR only when the previous stage returns nothing usable. Running OCR on everything works and is orders of magnitude slower for no gain on the documents that did not need it.

## Cost

Cheapest stage is O(pages); OCR is orders of magnitude more expensive and runs only where needed.

## Where it is used

Converting course material to Markdown.

## Source

[`pdf-to-md/src/pdf_to_md.py`](https://github.com/Ismael-Sallami/pdf-to-md/blob/main/src/pdf_to_md.py#L2-L511) &mdash; complete file.
