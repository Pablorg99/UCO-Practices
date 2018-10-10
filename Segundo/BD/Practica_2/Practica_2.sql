-- Ejercicio 1
SELECT nombrecompleto FROM votantes
    WHERE nombrecompleto LIKE '%n';

-- Ejercicio 2
SELECT dni FROM votantes
    WHERE dni LIKE '%5%5%5%';

-- Ejercicio 3
SELECT nombrecompleto FROM votantes
    WHERE fechanacimiento > '01-01-1990';

-- Ejercicio 4
SELECT v.nombrecompleto, l.localidad FROM votantes v, localidades l
    WHERE
