// Pattern: Absolute majority by splitting the vote in halves
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/01-divide-and-conquer/absolute-majority/absolute_majority_divide.cpp (lines 18-55)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/01-divide-and-conquer/absolute-majority/absolute_majority_divide.cpp#L18
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

int divideYVenceras(const vector<int> &arr, int inicio, int fin) { // O(n*log(n))

    // Tomamos como candidatos iniciales los elementos que quedan en subvectores de tamaño 1
    if (inicio == fin) {
        return arr[inicio];
    }

    int mitad = inicio + (fin - inicio) / 2;

    // Llamada recursiva en las dos mitades
    int mayoria_izquierda = divideYVenceras(arr, inicio, mitad);
    int mayoria_derecha = divideYVenceras(arr, mitad + 1, fin);

    // Si un número es mayoría en la izquierda y en la derecha del vector, lo es en todo el vector
    if (mayoria_izquierda == mayoria_derecha) {
        return mayoria_derecha;
    }

    int contador_izquierda = 0, contador_derecha = 0;

    // Contar votos totales de cada candidato en el vector
    for (int i = inicio; i <= fin; ++i) {
        if (arr[i] == mayoria_izquierda) 
            contador_izquierda++;
        else if (arr[i] == mayoria_derecha) 
            contador_derecha++;
    }

    // Vemos si alguno es mayoría absoluta, si no devolvemos -1
    if (contador_izquierda > (fin - inicio + 1) / 2) 
        return mayoria_izquierda;

    if (contador_derecha > (fin - inicio + 1) / 2)
        return mayoria_derecha;
    
    return -1;
        
}
