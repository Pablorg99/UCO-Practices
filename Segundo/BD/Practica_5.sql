-- Ejercicio 1
SET SERVEROUTPUT ON;
DECLARE
    CURSOR c_votantes IS SELECT * FROM votantes;
    last_digit NUMBER;
BEGIN
    FOR row IN c_votantes LOOP
        last_digit := SUBSTR(row.dni, -1); 
        IF last_digit = (row.localidad + 1) THEN dbms_output.put_line(row.nombrecompleto);
        END IF;        
    END LOOP;
END; 

-- Ejercicio 2
SET SERVEROUTPUT ON;
DECLARE
    CURSOR c_votantes IS SELECT * FROM votantes;
    v_madrid NUMBER := 0;
    v_localidad localidades.nombre % type;
BEGIN
    FOR row IN c_votantes LOOP
        SELECT DECODE(l.idlocalidad, 1, 'Madrid', 2, 'Madrid', 3, 'Madrid', l.nombre) INTO v_localidad FROM localidades l, votantes v
            WHERE l.idlocalidad = v.localidad AND v.dni = row.dni;
        DBMS_OUTPUT.PUT_LINE(row.nombrecompleto || ' es de ' || v_localidad);
        IF v_localidad = 'Madrid' THEN v_madrid := v_madrid + 1;
        END IF;        
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Hay ' || v_madrid || ' votantes de Madrid');
END;

-- Ejercicio 3
SET SERVEROUTPUT ON;
DECLARE
    CURSOR c_votantes IS SELECT * FROM votantes ORDER BY dni DESC;
    votanteData1 votantes % ROWTYPE;
    votanteData2 votantes % ROWTYPE;
BEGIN
    OPEN c_votantes;
    FETCH c_votantes INTO votanteData1;
    FETCH c_votantes INTO votanteData2;
    LOOP
        DBMS_OUTPUT.PUT_LINE(votanteData1.dni || ' va antes de ' || votanteData2.dni);
        votanteData1 := votanteData2;
        FETCH c_votantes INTO votanteData2;
        EXIT WHEN c_votantes %NOTFOUND;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(votanteData1.dni || 'es el menor');
END;

-- Ejercicio 4
SET SERVEROUTPUT ON;
DECLARE
    CURSOR v_cursor IS SELECT v.dni, COUNT(c.votante) as veces FROM votantes v, consultas c
                            WHERE v.dni = c.votante
                            HAVING COUNT(c.votante) > ((SELECT COUNT(idconsulta) FROM consultas) / (SELECT COUNT(dni) FROM votantes))
                            GROUP BY v.dni
                            ORDER BY COUNT(c.votante) DESC;
BEGIN
    FOR votante IN v_cursor LOOP
        DBMS_OUTPUT.PUT_LINE(votante.dni || ' ha participado ' || votante.veces || 'veces');
    END LOOP;    
END;

-- Ejercicio 5 (Bonito)
CREATE TABLE votantesAntiguos AS SELECT * FROM votantes WHERE fechanacimiento < '01/01/1980';
ALTER TABLE votantesAntiguos ADD Sueldo NUMBER(6);
UPDATE votantesAntiguos SET sueldo = 1500 WHERE situacionlaboral = 'Activo';
UPDATE votantesAntiguos SET sueldo = 0 WHERE situacionlaboral <> 'Activo';
SET SERVEROUTPUT ON;
DECLARE
    CURSOR c_old_votantes IS SELECT * FROM votantesAntiguos;
    n_votantes NUMBER;
BEGIN
    SELECT COUNT(dni) INTO n_votantes FROM votantesAntiguos;
    FOR votante IN c_old_votantes LOOP
        IF votante.situacionlaboral = 'Activo' THEN votante.sueldo := 1500;
        ELSE votante.sueldo := 0;
        END IF;
        DBMS_OUTPUT.put_line(votante.nombrecompleto || ' insertado');
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Se ha insertado un total de ' || n_votantes || ' votantes');
END;

-- Ejercicio 5 (Monito)
DROP TABLE votantesAntiguos;
CREATE TABLE votantesAntiguos AS (SELECT * FROM votantes WHERE dni = NULL);
ALTER TABLE votantesAntiguos ADD Sueldo NUMBER;
SET SERVEROUTPUT ON;
DECLARE
    CURSOR c_old_votantes IS SELECT * FROM votantes WHERE fechanacimiento < '01/01/1980';
    sueldo NUMBER;
    n_votantes NUMBER := 0;
BEGIN
    FOR votante IN c_old_votantes LOOP
        sueldo := 0;
        IF votante.situacionlaboral = 'Activo' THEN sueldo := 1500;
        END IF;
        INSERT INTO votantesAntiguos
            VALUES(votante.dni, votante.nombrecompleto, votante.estudiossuperiores, votante.situacionlaboral, votante.email, votante.localidad, votante.fechanacimiento, votante.telefono, sueldo);
        DBMS_OUTPUT.put_line(votante.nombrecompleto || ' insertado');
        n_votantes := n_votantes + 1; 
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Se ha insertado un total de ' || n_votantes || ' votantes');
END;

-- Ejercicio 6
SET SERVEROUTPUT ON;
DECLARE
    CURSOR c_old_votantes IS SELECT * FROM votantesAntiguos;
    new_sueldo NUMBER;
BEGIN
    FOR votante IN c_old_votantes LOOP
    
        IF votante.situacionlaboral = 'Jubilado' THEN new_sueldo := 1000;
        ELSIF votante.situacionlaboral = 'Activo' AND votante.estudiossuperiores = 'Ninguno' THEN new_sueldo := votante.sueldo + 100;
        ELSIF votante.situacionlaboral = 'Activo' AND votante.estudiossuperiores = 'Basicos' THEN new_sueldo := votante.sueldo + 200;
        ELSIF votante.situacionlaboral = 'Activo' AND votante.estudiossuperiores = 'Superiores' THEN new_sueldo := votante.sueldo + 300;
        ELSIF votante.situacionlaboral = 'Activo' AND votante.estudiossuperiores = 'Doctorado' THEN new_sueldo := votante.sueldo + 1000;         
        END IF;
    
        DBMS_OUTPUT.put_line(votante.nombrecompleto || ' pasa de cobrar ' || votante.sueldo || ' a cobrar ' ||  new_sueldo);
        UPDATE votantesAntiguos
            SET sueldo = new_sueldo
            WHERE dni = votante.dni;
            
    END LOOP;
END;