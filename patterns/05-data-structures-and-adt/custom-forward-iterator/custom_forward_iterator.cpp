// Pattern: Hand-written iterator over a 2D container
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/airline-routes-adt -> src/imagen.cpp (lines 1-65)
//          https://github.com/Ismael-Sallami/airline-routes-adt/blob/main/src/imagen.cpp#L6-L65
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

#include"imagen.h"
#include<cassert>
#include"imagenES.h"

//IMPLEMENTACIÓN DEL ITERADOR
Imagen::Iterator::Iterator(Pixel **ptr, int filas, int columnas)
    : puntero(ptr), filas(filas), columnas(columnas), fila_actual(0), columna_actual(0) {}

// Implementación de la sobrecarga de operadores del Iterador
Pixel& Imagen::Iterator::operator*() {
    return puntero[fila_actual][columna_actual];
}

Imagen::Iterator& Imagen::Iterator::operator++() {
    if (++columna_actual == columnas) {
        columna_actual = 0;
        ++fila_actual;
    }
    return *this;
}

bool Imagen::Iterator::operator!=(const Imagen::Iterator& otro) const {
    return fila_actual != otro.fila_actual || columna_actual != otro.columna_actual;
}

// Implementación de los métodos begin() y end()
Imagen::Iterator Imagen::begin() {
    return Iterator(datos, nf, nc);
}

Imagen::Iterator Imagen::end() {
    return Iterator(datos + nf, nf, nc);
}

//FINALIZA LA IMPLEMENTACIÓN DEL ITERADOR

//IMPLEMENTACIÓN DEL CONST_ITERATOR
Imagen::const_iterator::const_iterator(Pixel **ptr, int filas, int columnas)
    : puntero(ptr), filas(filas), columnas(columnas), fila_actual(0), columna_actual(0) {}

// Implementación de la sobrecarga de operadores del Iterador
Pixel& Imagen::const_iterator::operator*() {
    return puntero[fila_actual][columna_actual];
}

Imagen::const_iterator& Imagen::const_iterator::operator++() {
    if (++columna_actual == columnas) {
        columna_actual = 0;
        ++fila_actual;
    }
    return *this;
}

bool Imagen::const_iterator::operator!=(const Imagen::const_iterator& otro) const {
    return fila_actual != otro.fila_actual || columna_actual != otro.columna_actual;
}

// Implementación de los métodos begin() y end()
Imagen::const_iterator Imagen::begin() const{
    return const_iterator(datos, nf, nc);
}

Imagen::const_iterator Imagen::end() const{
    return const_iterator(datos + nf, nf, nc);
}
