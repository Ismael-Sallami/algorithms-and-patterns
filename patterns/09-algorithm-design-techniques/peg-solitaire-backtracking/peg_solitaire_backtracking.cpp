// Pattern: Peg solitaire on a 33-square board
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/03-backtracking-and-branch-and-bound/senku.cpp (lines 23-64)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/senku.cpp#L23-L64
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

queue<movimiento> encontrar_posibles_movimientos(vector<vector<char>> tablero){

    queue<movimiento> movimientos;
    movimiento m;
    for (int i=0; i<7; ++i)
        for (int j=0; j<7; ++j){
            //Movimientos a la izquierda
            if (i >= 2 && tablero[i][j]=='o' && tablero [i-1][j]=='o' && tablero[i-2][j]==' '){
                m.x_inicial=i;
                m.y_inicial=j;
                m.x_final=i-2;
                m.y_final=j;
                movimientos.push(m);
            }
            //Movimientos a la derecha
            if (i <= 4 && tablero[i][j]=='o' && tablero [i+1][j]=='o' && tablero[i+2][j]==' '){
                m.x_inicial=i;
                m.y_inicial=j;
                m.x_final=i+2;
                m.y_final=j;
                movimientos.push(m);
            }
            //Movimientos arriba
             if (j >= 2 && tablero[i][j]=='o' && tablero [i][j-1]=='o' && tablero[i][j-2]==' '){
                m.x_inicial=i;
                m.y_inicial=j;
                m.x_final=i;
                m.y_final=j-2;
                movimientos.push(m);
            }
            //Movimientos abajo
             if (j <= 4 && tablero[i][j]=='o' && tablero [i][j+1]=='o' && tablero[i][j+2]==' '){
                m.x_inicial=i;
                m.y_inicial=j;
                m.x_final=i;
                m.y_final=j+2;
                movimientos.push(m);
            }
        }

    return movimientos;
}
