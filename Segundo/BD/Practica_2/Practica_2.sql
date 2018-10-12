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
SELECT v.nombrecompleto, l.nombre FROM votantes v, localidades l
    WHERE v.localidad = l.idlocalidad AND l.numerohabitantes > 300000;

-- Ejercicio 5
SELECT v.nombrecompleto, p.comunidad FROM votantes v, localidades l, provincias p
    WHERE v.localidad = l.idlocalidad AND l.provincia = p.idprovincia AND l.numerohabitantes > 300000;

-- Ejercicio 6
SELECT p.idpartido "Id Partido", COUNT(cd.idrecogida) "Conteo" FROM partidos p, consultas_datos cd
    WHERE cd.partido = p.idpartido GROUP BY p.idpartido;
-- La cadena de caracteres escrita en "" al lado de cada columna de SELECT, es el nombre a mostrar al imprimir la tabla.
-- GROUP BY agrupa resultados obtenidos de funciones específicas de SQL por el atributo indicado. De esta manera no da error.

-- Ejercicio 7 = Ejercicio 6

-- Ejercicio 8
SELECT p.nombrecompleto FROM partidos p, consultas_datos cd
    WHERE cd.partido = p.idpartido
    GROUP BY p.nombrecompleto
    HAVING COUNT(cd.idrecogida) > 10;
-- Para hacer condiciones con funciones específicas de SQL tenemos que usar HAVING.
-- La unión de columnas por claves se hacen en el where.
-- El orden general es: SELECT, FROM, WHERE, GROUP BY, HAVING, ORDER BY.

-- Ejercicio 9
SELECT p.nombrecompleto, COUNT(cd.idrecogida) "Conteo" FROM partidos p, consultas_datos cd
    WHERE cd.partido = p.idpartido
    GROUP BY p.nombrecompleto
    HAVING COUNT(cd.idrecogida) > 10;

-- Ejercicio 10
