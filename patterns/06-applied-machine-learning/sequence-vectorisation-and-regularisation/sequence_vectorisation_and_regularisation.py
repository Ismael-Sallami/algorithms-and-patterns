# Pattern: One-hot sequence encoding and network regularisation
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/AA-practices -> practice-3/P3_SALLAMI_MORENO_ISMAEL.ipynb (notebook cells defining vectorizar_secuencias, construir_modelo_regularizado)
#          https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-3/P3_SALLAMI_MORENO_ISMAEL.ipynb
# Extract: selected code cells, concatenated in notebook order; output and narrative cells removed.
#          Not a standalone build. See the source repository for the
#          full build context.

def vectorizar_secuencias(secuencias, dimension=10000):
    """
    Convierte una lista de secuencias en un array bidimensional utilizando una representación binaria de Saco de Palabras (Bag-of-Words), también referida técnicamente como Multi-hot Encoding.

    Parámetros:
    -----------
    secuencias : list de list de int
        Lista principal que contiene las reseñas. Cada reseña es una sublista de enteros.
    dimension : int, opcional
        El tamaño máximo del vocabulario, que define la longitud del vector de salida
        para cada secuencia (por defecto 10000).

    Retorna:
    --------
    resultados : numpy.ndarray
        Una matriz de NumPy de dimensiones (len(secuencias), dimension) conteniendo
        valores de punto flotante 0.0 y 1.0.
    """
    # Inicializamos una matriz de ceros con la forma (número_de_reseñas, dimensión_vocabulario)
    # Se utiliza el tipo float32, altamente compatible con los tensores de TensorFlow.
    resultados = np.zeros((len(secuencias), dimension), dtype=np.float32)

    # Iteramos sobre cada reseña en la lista de secuencias
    for i, secuencia in enumerate(secuencias):
        # Aprovechamos la indexación avanzada de NumPy para asignar 1.0
        # en los índices que corresponden a las palabras de esta reseña específica.
        resultados[i, secuencia] = 1.0

    return resultados

# Aplicamos la función de vectorización a nuestros datos de entrenamiento y de test.
# Estos ndarray serán fácilmente convertibles a tensores de TensorFlow posteriormente.
x_train = vectorizar_secuencias(train_data)
x_test = vectorizar_secuencias(test_data)

# Mostramos el resultado para verificar la transformación geométrica
print(f"Forma del tensor x_train: {x_train.shape}")
print(f"Forma del tensor x_test: {x_test.shape}")
print(f"Ejemplo de la primera reseña vectorizada (primeros 50 elementos):\\n{x_train[0, :50]}")


def construir_modelo_regularizado(input_dim=10000, tasa_dropout=0.5):
    """
    Construye un modelo de red neuronal secuencial para clasificación binaria
    incorporando capas de regularización Dropout para mitigar el sobreajuste.

    Parámetros:
    -----------
    input_dim : int, opcional
        Dimensionalidad del tensor de entrada (por defecto 10000).
    tasa_dropout : float, opcional
        Fracción de unidades a apagar aleatoriamente en el entrenamiento (por defecto 0.5).

    Retorna:
    --------
    model : tf.keras.Sequential
        Modelo de Keras compilado computacionalmente.
    """
    model = Sequential()
    model.add(keras.Input(shape=(input_dim,)))

    # Capas ocultas con regularización Dropout
    model.add(Dense(16, activation='relu'))
    model.add(Dropout(tasa_dropout))
    model.add(Dense(16, activation='relu'))
    model.add(Dropout(tasa_dropout))

    # Capa de salida
    model.add(Dense(1, activation='sigmoid'))
    return model

# Instanciamos, compilamos y definimos callbacks
modelo_mejorado = construir_modelo_regularizado(tasa_dropout=0.5)
modelo_mejorado.compile(optimizer='rmsprop', loss='binary_crossentropy', metrics=['accuracy'])
parada_temprana = EarlyStopping(monitor='val_loss', patience=3, restore_best_weights=True)

# Entrenamos el modelo (AQUÍ se ajustan los pesos)
historial_mejorado = modelo_mejorado.fit(
    x_train,
    train_labels,
    epochs=30,
    batch_size=512,
    validation_split=0.2,
    callbacks=[parada_temprana],
    verbose=1
)

# Evaluamos la arquitectura regularizada al final
resultados_mejorados = modelo_mejorado.evaluate(x_test, test_labels, verbose=0)
print(f"Pérdida en el conjunto de Test (Modelo Regularizado): {resultados_mejorados[0]:.4f}")
print(f"Precisión en Test (Modelo Regularizado): {resultados_mejorados[1]:.4f}")
plot_curvas_aprendizaje(historial_mejorado)
