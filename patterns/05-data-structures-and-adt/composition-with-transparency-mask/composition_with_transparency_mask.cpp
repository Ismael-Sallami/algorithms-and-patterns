// Pattern: Compositing one image onto another through a mask
// Author:  Ismael Sallami Moreno
// Source:  Ismael-Sallami/Air-lines-Project -> rutas_aereas/src/imagen.cpp (lines 221-238, 240-247, 249-264)
//          https://github.com/Ismael-Sallami/Air-lines-Project/blob/main/rutas_aereas/src/imagen.cpp#L221
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

void Imagen::PutImagen(int posi,int posj, const Imagen & I, Tipo_Pegado tippegado){
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);
    
    for (int i=0;i<I.nf;i++)
      for (int j=0;j<I.nc;j++)
	        if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
	            if (I.datos[i][j].transp!=0){
	                if (tippegado==OPACO)
	                    datos[i+posi][j+posj]=I.datos[i][j];
	                else{
                        datos[i+posi][j+posj].r=(datos[i+posi][j+posj].r+I.datos[i][j].r)/2;
                        datos[i+posi][j+posj].g=(datos[i+posi][j+posj].r+I.datos[i][j].g)/2;
                        datos[i+posi][j+posj].b=(datos[i+posi][j+posj].r+I.datos[i][j].b)/2;
	                }  
	  
	            }  
	        }       
}

void Imagen::LimpiarTransp(){
    for (int i = 0; i < nf; ++i) {
        for (int j = 0; j < nc; ++j) {
            datos[i][j].transp = 0;  // Establecer la transparencia a cero para cada píxel
        }
    }

}

Imagen Imagen::ExtraeImagen(int posi,int posj,int dimi,int dimj){
     // Verificar si las coordenadas están dentro de los límites de la imagen
    assert(posi >= 0 && posi + dimi <= nf && posj >= 0 && posj + dimj <= nc);

    // Crear una nueva instancia de Imagen con las dimensiones especificadas
    Imagen imagenExtraida(dimi, dimj);

    // Copiar los píxeles de la región de la imagen original a la nueva instancia
    for (int i = 0; i < dimi; ++i) {
        for (int j = 0; j < dimj; ++j) {
            imagenExtraida.datos[i][j] = datos[posi + i][posj + j];
        }
    }

    return imagenExtraida;
}
