# Pattern: Choosing the DBSCAN neighbourhood radius from data
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/AA-practices -> practice-2/P2_Sallami_Moreno_Ismael.ipynb (notebook cells defining calcular_epsilon_optimo, justificar_epsilon_por_silueta)
#          https://github.com/Ismael-Sallami/AA-practices/blob/main/practice-2/P2_Sallami_Moreno_Ismael.ipynb
# Extract: selected code cells, concatenated in notebook order; output and narrative cells removed.
#          Not a standalone build. See the source repository for the
#          full build context.

def calcular_epsilon_optimo(data_scaled, min_samples=5, zoom_tail_percent=0.15):
    """
    Calcula el valor de epsilon usando la heurística de k-distancia.
    Aplica el algoritmo Kneedle solo a la "cola" de la distribución
    para evitar sesgos en curvas muy asimétricas (L-shaped).
    """
    # Cálculo de distancias a los k-vecinos
    neighbors = NearestNeighbors(n_neighbors=min_samples)
    neighbors_fit = neighbors.fit(data_scaled[['Annual Income (k$)', 'Spending Score (1-100)']])
    distances, _ = neighbors_fit.kneighbors(data_scaled[['Annual Income (k$)', 'Spending Score (1-100)']])

    # Ordenamos las distancias de menor a mayor
    k_distances = np.sort(distances[:, min_samples-1], axis=0)
    indices = np.arange(len(k_distances))

    # AISLAMIENTO DE LA COLA
    # Tomamos solo el porcentaje final de los datos (ej. último 15%)
    # donde sabemos que se produce el cambio drástico de densidad.
    cut_index = int(len(k_distances) * (1 - zoom_tail_percent))
    indices_tail = indices[cut_index:]
    k_distances_tail = k_distances[cut_index:]

    # Aplicación de Kneedle SOLO en la zona de interés
    # Aumentamos ligeramente la sensibilidad (S=2.0) para que sea más exigente
    kneedle = KneeLocator(indices_tail, k_distances_tail, S=2.0, curve="convex", direction="increasing")

    # Si por algún motivo no encuentra el codo en la cola, usamos el máximo como seguridad
    eps_optimo = kneedle.knee_y if kneedle.knee_y is not None else np.max(k_distances_tail)

    # Visualización de la curva completa y la zona analizada
    plt.figure(figsize=(10, 6))

    # Dibujamos toda la curva
    plt.plot(indices, k_distances, color='blue', label='Distancias ordenadas')

    # Sombreamos la zona donde el algoritmo ha buscado (el zoom)
    plt.axvspan(cut_index, len(k_distances), color='lightgray', alpha=0.4, label='Zona de búsqueda Kneedle')

    if kneedle.knee_y is not None:
        plt.axhline(y=eps_optimo, color='red', linestyle='--', label=f'Epsilon Óptimo ≈ {eps_optimo:.3f}')
        plt.plot(kneedle.knee, eps_optimo, 'ro', markersize=10, label='Codo Real (Detectado)')

    plt.title(r'Detección de $\epsilon$ Focalizada en la Zona de Ruido', fontsize=14)
    plt.xlabel('Puntos de datos (ordenados)', fontsize=12)
    plt.ylabel('Distancia al vecino k', fontsize=12)
    plt.legend()
    plt.grid(True, alpha=0.3)
    plt.show()

    return eps_optimo

# Uso de la función
eps_final = calcular_epsilon_optimo(scaled_df_clustering, min_samples=5, zoom_tail_percent=0.20)
print(f"El valor de epsilon validado en la cola de la distribución es: {eps_final:.4f}")


def justificar_epsilon_por_silueta(data_scaled, min_samples=5):
    """
    Evalúa un rango de valores de epsilon cercanos al codo empírico (0.2 a 0.6)
    para encontrar el valor que maximiza la calidad de los clústeres (Silhouette).
    """
    # Definimos un rango de búsqueda sensato basado en el gráfico de k-distancias
    rango_eps = np.arange(0.20, 0.65, 0.05)

    siluetas = []
    num_clusters = []

    for eps in rango_eps:
        # Instanciamos y entrenamos el modelo
        dbscan = DBSCAN(eps=eps, min_samples=min_samples)
        etiquetas = dbscan.fit_predict(data_scaled[['Annual Income (k$)', 'Spending Score (1-100)']])

        # DBSCAN puede devolver un solo clúster o todo ruido (-1).
        # Silhouette requiere al menos 2 clústeres definidos (sin contar el ruido).
        etiquetas_validas = set(etiquetas) - {-1}

        if len(etiquetas_validas) > 1:
            # Calculamos la silueta ignorando el ruido para ver la calidad de los grupos reales
            mascara_sin_ruido = etiquetas != -1
            score = silhouette_score(
                data_scaled[['Annual Income (k$)', 'Spending Score (1-100)']].iloc[mascara_sin_ruido],
                etiquetas[mascara_sin_ruido]
            )
            siluetas.append(score)
            num_clusters.append(len(etiquetas_validas))
        else:
            siluetas.append(-1) # Penalización si no logra segmentar
            num_clusters.append(0)

    # Visualización del análisis de Silueta
    fig, ax1 = plt.subplots(figsize=(10, 5))

    color = 'tab:blue'
    ax1.set_xlabel(r'Valor de $\epsilon$', fontsize=12)
    ax1.set_ylabel('Silhouette Score', color=color, fontsize=12)
    ax1.plot(rango_eps, siluetas, marker='o', color=color, linewidth=2, label='Calidad (Silueta)')
    ax1.tick_params(axis='y', labelcolor=color)
    ax1.grid(True, linestyle=':', alpha=0.7)

    # Segundo eje Y para el número de clústeres
    ax2 = ax1.twinx()
    color = 'tab:red'
    ax2.set_ylabel('Número de Clústeres (sin ruido)', color=color, fontsize=12)
    ax2.plot(rango_eps, num_clusters, marker='x', linestyle='--', color=color, label='Nº Clústeres')
    ax2.tick_params(axis='y', labelcolor=color)

    plt.title(r'Validación de $\epsilon$ mediante Análisis de Silueta (Rousseeuw, 1987)', fontsize=14)
    fig.tight_layout()
    plt.show()

    # Encontrar el mejor EPS basado en la silueta
    mejor_indice = np.argmax(siluetas)
    mejor_eps = rango_eps[mejor_indice]

    print(f"La evaluación interna determina que el mejor valor es epsilon = {mejor_eps:.2f}")
    print(f"Con este valor, se forman {num_clusters[mejor_indice]} clústeres con un Silhouette Score de {siluetas[mejor_indice]:.3f}")

    return mejor_eps

# Ejecutamos la validación
eps_definitivo = justificar_epsilon_por_silueta(scaled_df_clustering, min_samples=5)
