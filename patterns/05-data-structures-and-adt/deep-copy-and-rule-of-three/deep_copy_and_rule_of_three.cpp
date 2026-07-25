// Pattern: Deep copy, assignment and destruction
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/TDA-Imagen -> ej01_imagenes/estudiante/src/image.cpp (lines 75-81, 144-147, 151-153, 157-163)
//          https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/image.cpp#L75
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++)
            set_pixel(i,j,orig.get_pixel(i,j));
    }
}

// Constructor de copias
Image::Image (const Image & orig){
    assert (this != &orig);
    Copy(orig);
}

// Destructor
Image::~Image(){
    Destroy();
}

// Operador de Asignación
Image & Image::operator= (const Image & orig){
    if (this != &orig){
        Destroy();
        Copy(orig);
    }
    return *this;
}
