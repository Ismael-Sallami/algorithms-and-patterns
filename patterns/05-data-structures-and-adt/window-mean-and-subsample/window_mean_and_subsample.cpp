// Pattern: Window mean and subsampling
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/TDA-Imagen -> ej01_imagenes/estudiante/src/imageop.cpp (lines 43-51, 54-68)
//          https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp#L43
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// Calcula la media de los píxeles de una imagen entera o de un fragmento de ésta.
double Image::Mean (int i, int j, int height, int width) const{
    double media=0;
    for(int x=i;x<height+i;x++){
        for(int y=j;y<width+j;y++){
            media+=get_pixel(x,y);
        }
    }
    return media/(height*width);
}

// Genera un icono como reducción de una imagen.
Image Image::Subsample(int factor) const{
   assert(factor>0);
   int new_rows = get_rows() / factor;
   int new_cols = get_cols() / factor;
   Image icono(new_rows, new_cols);
   for(int i=0,x=0;i<get_rows();i+=factor){
      for(int j=0,y=0;j<get_cols();j+=factor){
        double valor=Mean(i,j,factor,factor);
        icono.set_pixel(x,y,valor);
        y++;
      }
      x++;
   }
   return icono;
}
