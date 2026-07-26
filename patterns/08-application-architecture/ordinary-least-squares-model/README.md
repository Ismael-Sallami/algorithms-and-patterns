# Fitting and diagnosing a linear regression

## Idea

An econometric model end to end: fit by least squares, then test the assumptions the estimate depends on - residual normality, heteroskedasticity, multicollinearity, autocorrelation. The coefficients are meaningless without those tests, because the standard errors that make them significant assume the assumptions hold.

## Cost

O(n x k^2) for the fit with n observations and k regressors, plus the diagnostic tests.

## Where it is used

Econometrics coursework: a regression model on real economic series.

## Source

[`ModeloEconometrico/Trabajo/trabajo.py`](https://github.com/Ismael-Sallami/ModeloEconometrico/blob/main/Trabajo/trabajo.py#L1) &mdash; complete file.

## Note

statsmodels provides the estimator and the tests; the specification, the diagnostics and their interpretation are the catalogued part.
