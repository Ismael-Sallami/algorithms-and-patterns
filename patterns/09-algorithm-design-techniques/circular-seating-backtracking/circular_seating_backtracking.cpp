// Pattern: Seating a circular table by backtracking
// Author:  José Ángel Carretero Montes, Ismael Sallami Moreno, Fernando José Gracia Choin, Minerva Cebrián Marín, Jesús Rodríguez González
// Source:  Ismael-Sallami/algorithm-design-techniques -> src/03-backtracking-and-branch-and-bound/circular_table.cpp (lines 22-46)
//          https://github.com/Ismael-Sallami/algorithm-design-techniques/blob/main/src/03-backtracking-and-branch-and-bound/circular_table.cpp#L22
// Extract: verbatim block extract; surrounding file context and includes are in the source repository.
//          Not a standalone build. See the source repository for the
//          full build context.

void algoritmo(vector<vector<int>>& matriz, int n, int inicial, pair<vector<char>,int>& sol, vector<char>& actual, vector<bool>& usado, int& conveniencia) {
    if(inicial == n) {
        int nueva_conveniencia = 0;
        for(int i=0; i<n; i++) {
            int izq = (i-1+n)%n;
            int der = (i+1)%n;
            nueva_conveniencia+= matriz[actual[i]-'a'][actual[izq]-'a'];
            nueva_conveniencia+= matriz[actual[i]-'a'][actual[der]-'a'];
        }
        nueva_conveniencia/=2;
        if(nueva_conveniencia>sol.second) {
            sol.first=actual;
            sol.second=nueva_conveniencia;
        }
    } else {
        for(int i = 0; i < n; i++) {
            if(!usado[i]){
                usado[i]=true;
                actual[inicial]='a'+i;
                algoritmo(matriz, n, inicial+1, sol, actual, usado, conveniencia);
                usado[i]=false;
            }
        }
    }
}
