-- Ejercicio 1
SET SERVEROUTPUT ON;
DECLARE
    v_dni NUMBER := 30983712;
    v_nombre_completo votantes.nombrecompleto%type;
    v_email votantes.email%type;
BEGIN
    SELECT nombrecompleto, email INTO v_nombre_completo, v_email FROM votantes
        WHERE dni = v_dni;
    DBMS_OUTPUT.PUT_LINE(v_nombre_completo||' con correo '|| v_email);
END;

-- Ejercicio 2
SET SERVEROUTPUT ON;
DECLARE
    v_dni NUMBER := 30983712;
    v_nombre_completo votantes.nombrecompleto%type;
    v_email votantes.email%type;
BEGIN
    SELECT SUBSTR(nombrecompleto, 1, INSTR(nombrecompleto, ' ')), email INTO v_nombre_completo, v_email FROM votantes
        WHERE dni = v_dni;
    DBMS_OUTPUT.PUT_LINE(v_nombre_completo||'con correo '|| v_email);
END;

-- Ejercicio 3
SET SERVEROUTPUT ON;
DECLARE
    v_dni NUMBER := 30983712;
    v_nombre_completo votantes.nombrecompleto%type;
    v_email votantes.email%type;
BEGIN
    -- Devuelve Jose + ' ' :)
    SELECT DECODE(SUBSTR(nombrecompleto, 1, INSTR(nombrecompleto, ' ')), 'Jose ' , 'Pepe '), email INTO v_nombre_completo, v_email FROM votantes
        WHERE dni = v_dni;
    DBMS_OUTPUT.PUT_LINE(v_nombre_completo||'con correo '|| v_email);
END;
