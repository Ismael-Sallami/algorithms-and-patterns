// Pattern: Contrast adjustment through a lookup table
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/TDA-Imagen -> ej01_imagenes/estudiante/src/imageop.cpp (lines 24-40)
//          https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/src/imageop.cpp#L24
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

//Modifica el contraste de una imagen
void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2){
    //comprobaciones
    assert(0<=in1 && in1 <=255 && 0<=in2 && in2 <=255 && 0<=out1 && out1 <=255 && 0<=out2 && out2 <=255 && in1<in2 && out1<out2);
    double e1=in1,e2=in2,s1=out1,s2=out2;
    //calculo de valor constante
    double valor=(s2-s1)/(e2-e1);
    for (int i = 0; i < (get_cols() * get_rows()); i++) {
    // Nos aseguramos de que el píxel de entrada esté en el rango válido
        byte pixel = get_pixel(i);
        if (pixel >= in1 && pixel <= in2) {
            double pre_insert = (s1 + (valor * (pixel - e1)));
            byte insert = static_cast<byte>(round(pre_insert));
            set_pixel(i, insert);
        }
        // Si el píxel de entrada está fuera del rango, lo dejamos sin cambios.
    }
}
