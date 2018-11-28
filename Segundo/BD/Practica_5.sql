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
