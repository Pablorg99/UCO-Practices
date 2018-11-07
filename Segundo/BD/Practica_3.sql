-- Ejercicio 1
SELECT nombrecompleto FROM votantes
    WHERE dni like concat('%', (localidad + 1));

-- Ejercicio 2
SELECT v.nombrecompleto, DECODE(l.idlocalidad, 1, 'Madrid', 2, 'Madrid', 3, 'Madrid', l.nombre) as LOCALIDAD FROM votantes v, localidades l
    WHERE l.idlocalidad = v.localidad;

-- Ejercicio 3
SELECT p.siglas FROM partidos p, eventos_resultados er
    WHERE p.idpartido = er.partido 
    HAVING COUNT(er.partido) = (SELECT MAX(COUNT(partido)) FROM eventos_resultados GROUP BY partido)
    GROUP BY p.siglas;

-- Ejercicio 4
SELECT dni FROM votantes
    WHERE fechanacimiento = (SELECT MIN(fechanacimiento) FROM votantes
                                WHERE fechanacimiento > (SELECT MIN(fechanacimiento) FROM votantes));

-- Ejercicio 5
SELECT v.dni, COUNT(c.votante) FROM votantes v, consultas c
    WHERE v.dni = c.votante
    GROUP BY v.dni
    ORDER BY COUNT(c.votante) DESC;

-- Ejercicio 6
SELECT v.dni, COUNT(c.votante) FROM votantes v, consultas c
    WHERE v.dni = c.votante
    HAVING COUNT(c.votante) > ((SELECT COUNT(idconsulta) FROM consultas) / (SELECT COUNT(dni) FROM votantes))
    GROUP BY v.dni
    ORDER BY COUNT(c.votante) DESC;
    
-- Ejercicio 7
SELECT v.nombrecompleto FROM votantes v, consultas c
    WHERE v.dni = c.votante
    HAVING COUNT(c.votante) > ((SELECT COUNT(idconsulta) FROM consultas) / (SELECT COUNT(dni) FROM votantes))
    GROUP BY v.nombrecompleto;
    
-- Ejercicio 8
SELECT v.dni, COUNT(c.votante) FROM votantes v, consultas c
    WHERE v.dni = c.votante AND v.fechanacimiento != (SELECT MIN(fechanacimiento) FROM votantes
                                                            WHERE fechanacimiento > (SELECT MIN(fechanacimiento) FROM votantes))
    GROUP BY v.dni
    ORDER BY COUNT(c.votante) DESC;