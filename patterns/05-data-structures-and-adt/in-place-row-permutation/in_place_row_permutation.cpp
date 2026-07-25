// Pattern: In-place row permutation
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/TDA-Imagen -> ej01_imagenes/estudiante/src/imageop.cpp (lines 104-113)
//          https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp#L104
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

//Método adaptado al tipo 2 de la implementación de la matriz imagen.
void Image::ShuffleRows() {
    const int p = 9973;
    Image temp(rows,cols);
    int newr;
    for (int r=0; r<rows; r++){
        newr = r*p % rows;
        temp.img[r]=img[newr];
    }
    Copy(temp);
}
