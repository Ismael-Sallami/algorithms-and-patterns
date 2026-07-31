# Pattern: Choosing the number of clusters
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/machine-learning-practices -> src/practice-2-unsupervised-learning.ipynb (notebook cells defining evaluate_optimal_k, perform_eda_and_scaling)
#          https://github.com/Ismael-Sallami/machine-learning-practices/blob/main/src/practice-2-unsupervised-learning.ipynb#L1
# Extract: selected code cells, concatenated in notebook order; output and narrative cells removed.
#          Not a standalone build. See the source repository for the
#          full build context.

def perform_eda_and_scaling(data: pd.DataFrame, features: list) -> pd.DataFrame:
    """
    Realiza un Análisis Exploratorio de Datos (EDA) trazando histogramas y boxplots
    para las características seleccionadas, y aplica la estandarización Z-score.

    Argumentos:
        data (pd.DataFrame): El conjunto de datos original (df_clustering).
        features (list): Lista de cadenas con los nombres de las columnas a analizar y escalar.

    Retorna:
        pd.DataFrame: Un nuevo DataFrame estructurado con las características ya escaladas.
    """
    # Análisis Exploratorio de Datos (EDA)
    # Creamos una cuadrícula de gráficos: 2 filas (Histogramas y Boxplots) y tantas columnas como features
    fig, axes = plt.subplots(nrows=2, ncols=len(features), figsize=(12, 8))
    fig.suptitle('EDA: Distribuciones y Detección de Outliers', fontsize=16)

    # Iteramos sobre cada variable para generar su representación gráfica
    for i, col in enumerate(features):
        # Histogramas para evaluar la distribución y asimetría
        sns.histplot(data[col], kde=True, ax=axes[0, i], color='skyblue')
        axes[0, i].set_title(f'Histograma de {col}') # kde = Kernel Density Estimate

        # Boxplots para identificar la mediana, cuartiles y valores atípicos
        sns.boxplot(y=data[col], ax=axes[1, i], color='lightgreen')
        axes[1, i].set_title(f'Boxplot de {col}')

    # Ajustamos el layout para evitar superposición de textos
    plt.tight_layout(rect=[0, 0, 1, 0.95])
    plt.show()

    # Preprocesamiento: Escalamiento (StandardScaler)
    # Extraemos el subconjunto de datos que vamos a usar en el entrenamiento
    subset_data = data[features].copy()

    # Inicializamos el escalador basado en la normalización Z-score
    scaler = StandardScaler()

    # El método fit_transform calcula la media y desviación estándar (fit)
    # y luego aplica la transformación matemática (transform) a los datos.
    scaled_array = scaler.fit_transform(subset_data)

    # Reconstruimos el DataFrame con los datos normalizados para preservar su legibilidad
    scaled_df = pd.DataFrame(scaled_array, columns=features)

    return scaled_df

# Definimos las variables recomendadas para la visualización 2D
selected_features = ['Annual Income (k$)', 'Spending Score (1-100)']

# Aplicamos nuestra función al dataframe
scaled_df_clustering = perform_eda_and_scaling(df_clustering, selected_features)

# Imprimimos los primeros registros para verificar que la media tiende a 0 y la varianza a 1
print("Primeros registros del dataset escalado:")
display(scaled_df_clustering.head())



def evaluate_optimal_k(data_scaled: pd.DataFrame, max_k: int = 10):
    """
    Evalúa el algoritmo K-Means iterando sobre distintos valores de k.
    Calcula la Inercia (para el Método del Codo) y el Coeficiente de Silueta.

    Argumentos:
        data_scaled (pd.DataFrame): Datos preprocesados y escalados.
        max_k (int): Límite superior del rango de clústeres a evaluar.
    """
    inertias = []
    silhouette_scores = []

    # El análisis de silueta requiere al menos 2 clústeres para comparar distancias inter-clúster
    k_range = range(2, max_k + 1)

    for k in k_range:
        # Inicializamos el modelo.
        # Utilizamos init=k-means++ para alejar probabilísticamente
        # los centroides iniciales, evitando caer en mínimos locales subóptimos.
        kmeans = KMeans(n_clusters=k, init='k-means++', random_state=42, n_init='auto')

        # Ajustamos el modelo (Complejidad temporal O(n * k * d))
        cluster_labels = kmeans.fit_predict(data_scaled)

        # Almacenamos las métricas extraídas tras la convergencia
        inertias.append(kmeans.inertia_)
        silhouette_scores.append(silhouette_score(data_scaled, cluster_labels))

    # Representación gráfica en una figura con dos subgráficos
    fig, axes = plt.subplots(nrows=1, ncols=2, figsize=(15, 5))
    fig.suptitle('Evaluación de Hiperparámetro $k$ para K-Means', fontsize=16)

    # Gráfico 1: Método del Codo (Inercia)
    axes[0].plot(k_range, inertias, marker='o', linestyle='--', color='blue', markersize=8)
    axes[0].set_title('Método del Codo (Inercia)')
    axes[0].set_xlabel('Número de clústeres ($k$)')
    axes[0].set_ylabel('Inercia (WCSS)')
    axes[0].set_xticks(k_range)
    axes[0].grid(True, linestyle=':', alpha=0.7)

    # Gráfico 2: Análisis de Silueta (Extra académico)
    axes[1].plot(k_range, silhouette_scores, marker='s', linestyle='-', color='green', markersize=8)
    axes[1].set_title('Análisis de Silueta (Validación)')
    axes[1].set_xlabel('Número de clústeres ($k$)')
    axes[1].set_ylabel('Coeficiente de Silueta Promedio')
    axes[1].set_xticks(k_range)
    axes[1].grid(True, linestyle=':', alpha=0.7)

    plt.tight_layout()
    plt.show()

# Ejecutamos la función sobre nuestro subset de 2 variables escaladas
evaluate_optimal_k(scaled_df_clustering, max_k=10)
