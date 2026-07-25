# Pattern: Comparing classifiers under cross-validation
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/AA-practices -> practice-1/P1_Ismael_Sallami_Moreno.ipynb (notebook cells defining entrenar_y_evaluar)
#          https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-1/P1_Ismael_Sallami_Moreno.ipynb
# Extract: selected code cells, concatenated in notebook order; output and narrative cells removed.
#          Not a standalone build. See the source repository for the
#          full build context.

# FUNCIÓN EVALUADORA CENTRALIZADA
def entrenar_y_evaluar(modelo, nombre_modelo, X_train, y_train, X_test, y_test):
    """
    Función que entrena un clasificador, genera predicciones y muestra
    las métricas multiclase exigidas junto con la matriz de confusión.
    """
    print(f"======================================================")
    print(f" ENTRENANDO Y EVALUANDO: {nombre_modelo}")
    print(f"======================================================\n")

    # Entrenamiento (Fit)
    modelo.fit(X_train, y_train)

    # Predicción (Predict)
    y_pred = modelo.predict(X_test)

    # Accuracy
    acc = accuracy_score(y_test, y_pred)
    print(f" Accuracy Global: {acc * 100:.2f}%\n")

    # Informe de Clasificación (Macro y Weighted)
    print(" Informe de Clasificación (Precision, Recall, F1-Score):")
    # Al pasarle las predicciones, Scikit-Learn calcula automáticamente las métricas multiclase
    print(classification_report(y_test, y_pred))

    # Matriz de Confusión (Heatmap)
    cm = confusion_matrix(y_test, y_pred)

    plt.figure(figsize=(6, 5))
    # annot=True muestra los números, cmap define el color, fmt='d' asegura que sean enteros, cbar es la barra de color ("apagamos" la leyenda)
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', cbar=False,
                xticklabels=['Gama 0', 'Gama 1', 'Gama 2', 'Gama 3'],
                yticklabels=['Gama 0', 'Gama 1', 'Gama 2', 'Gama 3'])
    plt.title(f'Matriz de Confusión: {nombre_modelo}')
    plt.xlabel('Predicción del Modelo')
    plt.ylabel('Valor Real')
    plt.show()
    print("\n")

    return acc # Devolvemos el accuracy para compararlos al final
