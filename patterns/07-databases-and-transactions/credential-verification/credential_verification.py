# Pattern: Verifying credentials against stored hashes
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/DDSI -> LaTeX/pr3/src/usuarios/auth.py (complete file)
#          https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/usuarios/auth.py#L1
# Extract: verbatim, complete file.
#          Not a standalone build. See the source repository for the
#          full build context.

from . import seguridad


def login(conn, email, contrasena):
    cursor = conn.cursor()
    try:
        pwd_hash_in = seguridad.hash_password_sha256(contrasena)

        cursor.execute("""
            SELECT IDUSUARIO
            FROM USUARIO
            WHERE LOWER(EMAIL) = LOWER(:1)
              AND CONTRASENIA = :2
              AND BORRADO = 'N'
        """, [email, pwd_hash_in])

        row = cursor.fetchone()
        if row is None:
            return False, "Email o contraseña incorrectos"

        return True, row[0]   # id_usuario_activo

    except Exception as e:
        return False, f"Error SQL: {e}"
    finally:
        cursor.close()
