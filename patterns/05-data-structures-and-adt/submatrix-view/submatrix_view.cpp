// Pattern: Cropping a submatrix
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/image-adt -> src/imageop.cpp (lines 71-84)
//          https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageop.cpp#L71-L84
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

 // Genera una subimagen.
Image Image::Crop(int nrow, int ncol, int height, int width) const{
    assert(nrow>=0 && ncol>=0 && height>=0 && width>=0);
    Image imagen_recortada(height,width);
    int posi=0;
    for(int i=nrow;i<nrow+height;i++){
        int posj=0;
        for(int j=ncol;j<ncol+width;j++){
            imagen_recortada.set_pixel(posi,posj,get_pixel(i,j));
            posj++;
        }
        posi++;
    }
    return imagen_recortada;
}
