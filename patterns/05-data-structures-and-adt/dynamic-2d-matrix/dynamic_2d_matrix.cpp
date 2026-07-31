// Pattern: Dynamic two-dimensional matrix with manual memory
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/image-adt -> src/image.cpp (lines 37-55, 59-65, 98-105)
//          https://github.com/Ismael-Sallami/image-adt/blob/main/src/image.cpp#L37
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

//Implemenación de la matriz con filas no contiguas Tipo 2.
void Image::Allocate(int nrows, int ncols, byte* buffer) {
    rows = nrows;
    cols = ncols;
    img = new byte*[rows];
    //inicializa la matriz con filas no contiguas en memoria
    for (int i = 0; i < rows; ++i) {
            img[i] = new byte[cols];
        }

    if (buffer != nullptr) {
        // Utiliza el búfer proporcionado
        int pos=0;
        for (int i = 0; i < rows; ++i) {
            for(int j=0;j<cols;++j){
                img[i][j]=buffer[pos++];
            }
        }
    }
}

// Función auxiliar para inicializar imágenes con valores por defecto o a partir de un buffer de datos
void Image::Initialize (int nrows, int ncols, byte * buffer){
    if ((nrows == 0) || (ncols == 0)){
        rows = cols = 0;
        img = 0;
    }
    else Allocate(nrows, ncols, buffer);
}

//destroy para la implementación de tipo II
void Image::Destroy(){
    if(!Empty()){
        for(int i=0;i<rows;++i){
            delete[]img[i];
        }
        delete [] img;
    }
}
