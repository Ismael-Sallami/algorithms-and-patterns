# Pattern: Multi-statement writes with commit and rollback
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/DDSI -> LaTeX/pr3/src/usuarios/functions.py (lines 8-49, 132-168)
#          https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/src/usuarios/functions.py#L8
# Extract: verbatim block extract; surrounding file context and includes are in the source repository.
#          Not a standalone build. See the source repository for the
#          full build context.

# -------------------------------------------------------------------
# RF4.1: Crear usuario
# -------------------------------------------------------------------
def crear_usuario(conn, nombre_usuario, correo, contrasena, imagen_perfil=None, biografia=None):
    cursor = conn.cursor()
    try:
        # Comprobaciones mínimas
        if not nombre_usuario or not nombre_usuario.strip():
            return "Nombre de usuario no puede estar vacío"
        if not correo or not correo.strip():
            return "Correo no puede estar vacío"
        if not contrasena or not contrasena.strip():
            return "Contraseña no puede estar vacía"

        cursor.execute("SELECT 1 FROM USUARIO WHERE LOWER(NOMBREUSUARIO) = LOWER(:1)", [nombre_usuario])
        if cursor.fetchone():
            return "Nombre de usuario ya existe"

        cursor.execute("SELECT 1 FROM USUARIO WHERE LOWER(EMAIL) = LOWER(:1)", [correo])
        if cursor.fetchone():
            return "Correo ya existe"

        contrasena_hash = seguridad.hash_password_sha256(contrasena)

        cursor.execute("""
            INSERT INTO USUARIO (NOMBREUSUARIO, EMAIL, CONTRASENIA, IMAGENDEPERFIL, BIOGRAFIA)
            VALUES (:1,:2,:3,:4,:5)
        """, [nombre_usuario, correo, contrasena_hash, imagen_perfil, biografia])

        conn.commit()

        cursor.execute("""
            SELECT IDUSUARIO
            FROM USUARIO
            WHERE LOWER(EMAIL) = LOWER(:1)
        """, [correo])

        id_usuario = cursor.fetchone()
        return f"Usuario creado (ID={id_usuario[0]})"

    except Exception as e:
        conn.rollback()
        return f"Error SQL: {e}"
    finally:
        cursor.close()

# -------------------------------------------------------------------
# RF4.3: Eliminar usuario
# -------------------------------------------------------------------
def eliminar_usuario(conn, id_usuario, contrasena):
    cursor = conn.cursor()
    try:
        if not contrasena or not contrasena.strip():
            return "Contraseña no puede estar vacía"

        contrasena_hash = seguridad.hash_password_sha256(contrasena)

        # Verificar credenciales y que no esté ya borrado
        cursor.execute("""
            SELECT 1
            FROM USUARIO
            WHERE IDUSUARIO = :1
              AND CONTRASENIA = :2
              AND BORRADO = 'N'
        """, [id_usuario, contrasena_hash])

        if cursor.fetchone() is None:
            return "Credenciales incorrectas, usuario no existe o ya está eliminado"

        # Borrado lógico
        cursor.execute("""
            UPDATE USUARIO
            SET BORRADO = 'Y',
                FECHAELIMINACION = SYSDATE,
                FECHAMODIFICACION = SYSDATE
            WHERE IDUSUARIO = :1
        """, [id_usuario])

        conn.commit()
        return "Usuario eliminado (borrado lógico)"

    except Exception as e:
        conn.rollback()
        return f"Error SQL: {e}"
    finally:
        cursor.close()
