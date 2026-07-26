-- Pattern: Triggers maintaining derived counters
-- Author:  Ismael Sallami Moreno
-- Source:  Ismael-Sallami/DDSI -> LaTeX/pr3/database/publicaciones/triggers_publicaciones.sql (complete file)
--          https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/publicaciones/triggers_publicaciones.sql#L1
-- Extract: verbatim, complete file.
--          Not a standalone build. See the source repository for the
--          full build context.

-- Esto debería de ir en init
BEGIN
  EXECUTE IMMEDIATE 'CREATE INDEX IDX_ME_GUSTA_PUB ON ME_GUSTA (IDPUBLICACION)';
  EXCEPTION WHEN OTHERS THEN
    IF SQL_CODE != -955 THEN RAISE; END IF;
END;
/

BEGIN
  EXECUTE IMMEDIATE 'CREATE INDEX IDX_ME_GUSTA_USR_PUB ON ME_GUSTA (IDUSUARIO,IDPUBLICACION)';
  EXCEPTION WHEN OTHERS THEN
    IF SQL_CODE != -955 THEN RAISE; END IF;
END;
/

/* =========================================================
TRIGGER 3: BORRADO DE RELACIONES EN PUBLICACIONES BORRADAS LOGICAMENTE 
========================================================= */
/*
CREATE OR REPLACE TRIGGER TRG_PUBLICACION_SOFT_DELETE
BEFORE UPDATE OF ELIMINADO ON PUBLICACION
FOR EACH ROW
WHEN (NEW.ELIMINADO = 'Y' AND OLD.ELIMINADO = 'N')
BEGIN
    -- Eliminar likes asociados, merece la pena? Pierdes auditoría
    DELETE FROM ME_GUSTA
    WHERE IDPUBLICACION = :OLD.IDPUBLICACION;

    -- Evitar cambios posteriores
    :NEW.FECHAMODIFICACION := SYSDATE;
END;
/*/

/* =========================================================
TRIGGER 4: BORRADO EN PUBLICACIONES ACTUALIZA FECHA DE MODIFICACIÓN
========================================================= */

CREATE OR REPLACE TRIGGER TRG_PUB_FECHA_MOD
BEFORE UPDATE ON PUBLICACION
FOR EACH ROW
BEGIN
    :NEW.FECHAMODIFICACION := SYSDATE;
END;
/

/* =========================================================
TRIGGER 5: BORRADO LÓGICO 
========================================================= */

CREATE OR REPLACE TRIGGER TRG_PUB_CASCADE_LOGIC
BEFORE UPDATE OF BORRADO ON USUARIO
FOR EACH ROW
BEGIN
    UPDATE PUBLICACION
    SET ELIMINADO = 'Y'
    WHERE IDUSUARIO = :OLD.IDUSUARIO;
END;
/
