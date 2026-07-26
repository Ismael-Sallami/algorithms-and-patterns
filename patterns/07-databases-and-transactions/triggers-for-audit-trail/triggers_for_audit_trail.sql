-- Pattern: Triggers writing an audit trail
-- Author:  Ismael Sallami Moreno
-- Source:  Ismael-Sallami/DDSI -> LaTeX/pr3/database/mensajeria/triggers_mensajeria.sql (complete file)
--          https://github.com/Ismael-Sallami/DDSI/blob/main/LaTeX/pr3/database/mensajeria/triggers_mensajeria.sql#L1
-- Extract: verbatim, complete file.
--          Not a standalone build. See the source repository for the
--          full build context.

CREATE OR REPLACE TRIGGER crear_conversaciones
    BEFORE INSERT ON mensaje 
    FOR EACH ROW
DECLARE
    -- Declaramos una variable para guardar el resultado del conteo
    v_cantidad NUMBER;
BEGIN
    -- Comprobamos si existe la conversación
    SELECT COUNT(*)
    INTO v_cantidad
    FROM CONVERSA 
    WHERE (IDUSUARIO1 = :NEW.IDUSUARIO1 AND IDUSUARIO2 = :NEW.IDUSUARIO2) 
       OR (IDUSUARIO1 = :NEW.IDUSUARIO2 AND IDUSUARIO2 = :NEW.IDUSUARIO1);

    -- Si es 0 no existe la conversación, la insertamos
    IF v_cantidad = 0 THEN
        -- Insertamos las dos direcciones
        INSERT INTO CONVERSA (IDUSUARIO1, IDUSUARIO2) 
        VALUES (:NEW.IDUSUARIO1, :NEW.IDUSUARIO2);
        
        INSERT INTO CONVERSA (IDUSUARIO1, IDUSUARIO2) 
        VALUES (:NEW.IDUSUARIO2, :NEW.IDUSUARIO1);
    END IF;
END;
/
