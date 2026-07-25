// Pattern: Single-index access over two-dimensional storage
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/TDA-Imagen -> ej01_imagenes/estudiante/src/image.cpp (lines 205-227)
//          https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp#L205
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

//get y set desenrollado para la implementación tipo II

// This doesn't work if representation changes
void Image::set_pixel (int k, byte value) {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse set_pixel(i,j,value)?

    int r=k/rows;//calcula la posición en la fila
    int c=k%cols; //calcula la posición en la columna

    img[r][c] = value;
}

// This doesn't work if representation changes
byte Image::get_pixel (int k) const {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse get_pixel(i,j)?

    int r=k/rows;//calcula la posición en la fila
    int c=k%cols; //calcula la posición en la columna
    return img[r][c];
}
