// Pattern: Zoom by pixel replication and interpolation
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/image-adt -> src/imageop.cpp (lines 117-160)
//          https://github.com/Ismael-Sallami/image-adt/blob/main/src/imageop.cpp#L117-L160
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

// Genera una imagen aumentada 2x.
Image Image::Zoom2X() const{
   //creamos nuestro objeto image resultado del zoom
   Image resultado((2*get_rows())-1,(2*get_cols())-1);


   //copiamos la matriz origen en la de salida, no usamos copy ya que no queremos que modifique ni las filas ni las columnas
   for(int i=0;i<get_rows();i++){
       for(int j=0;j<get_cols();j++){
           resultado.set_pixel(i,j,get_pixel(i,j));
       }
   }


   int rows=get_rows();
   int cols=get_cols();
   int rows_salida=resultado.get_rows();
   int cols_salida=resultado.get_cols();
  
   //aumentamos columnas
   for(int i=0;i < rows_salida;i++){
       for(int j=0;j<cols_salida-1;j+=2){
           double value=resultado.get_pixel(i,j)+resultado.get_pixel(i,j+1);
           int valor=round(value/2);
               for(int x=cols_salida-1;x>j+1;x--){
                   resultado.set_pixel(i,x,resultado.get_pixel(i,x-1));
                   }
                   resultado.set_pixel(i,j+1,valor);
                   
       }
   }

   //Aumentamos filas
   for(int i=0;i<rows_salida-1;i+=2){
    for(int j=0;j<cols_salida;j++){
        double value=resultado.get_pixel(i,j)+resultado.get_pixel(i+1,j);
        int valor=round(value/2);
        for(int x=rows_salida-1;x>i+1;x--){
            resultado.set_pixel(x,j,resultado.get_pixel(x-1,j));
        }
        resultado.set_pixel(i+1,j,valor);
    }
   }
   return resultado;
}
