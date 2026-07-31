# Comparing classifiers under cross-validation

## Idea

One routine that fits, cross-validates and scores any estimator, so several model families are compared on identical splits and identical metrics. Fixing the split is what makes the comparison mean anything: a difference between models measured on different folds is mostly fold variance.

## Cost

k fits per model for k folds. Total cost is k times the number of candidates times the cost of one fit.

## Where it is used

Practice 1: supervised classification, comparing k-NN, SVM, logistic regression and ensembles.

## Source

[`machine-learning-practices/src/practice-1-supervised-learning.ipynb`](https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/practice-1-supervised-learning.ipynb#L1) &mdash; notebook cells defining `entrenar_y_evaluar`.

## Note

scikit-learn provides the estimators and the metrics; the pipeline, the protocol and the evaluation logic are the catalogued part.
