# Pattern: Database connection lifecycle
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/DDSI -> LaTeX/pr3/src/db_connection.py (complete file)
#          https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/db_connection.py#L1
# Extract: verbatim, complete file.
#          Not a standalone build. See the source repository for the
#          full build context.

import oracledb

class DBConnection:
    def __init__(self):
        self.username = "REDACTED"   
        self.password = "REDACTED"  # CAMBIAR
        self.dsn = "oracle0.ugr.es:1521/practbd"
        self.connection = None 

    def connect(self):
        try:
            self.connection = oracledb.connect(
                user=self.username,
                password=self.password,
                dsn=self.dsn
            )
            return self.connection
        except oracledb.Error as e:
            print(f"\n❌ Error conectando a Oracle: {e}")
            return None
            
    def close(self): 
        if self.connection:
            try:
                self.connection.close()
                print("Conexión cerrada.")
            except oracledb.Error:
                pass
