--1. Mostrar el nombre de la localidad y su número de habitantes para el votante con menor edad

SELECT l.nombre, l.numerohabitantes FROM votantes v, localidades l
    WHERE v.localidad = l.idlocalidad
    AND v.dni = (
        SELECT dni FROM votantes
            WHERE fechanacimiento = (SELECT MAX(fechanacimiento) FROM votantes)
    );

-- 2. Mostrar el nombre y la fecha de nacimiento de los votantes andaluces que han
-- nacido después de la creación del partido popular. Ordenar el resultado por
-- edad (de mayor a menor edad).

SELECT v.nombrecompleto, v.fechanacimiento FROM votantes v, localidades l, provincias p
    WHERE v.localidad = l.idlocalidad
    AND l.provincia = p.idprovincia
    AND p.comunidad = 'Andalucia' 
    AND v.fechanacimiento > 
    (
        SELECT fechacreacion FROM partidos
            WHERE siglas = 'PP'
    )
    ORDER BY fechanacimiento ASC;

-- 3. Mostrar el nombre de las localidades y su comunidad autónoma para aquellas
-- localidades que tienen un número de habitantes mayor que la localidad del
-- votante que es el segundo votante de más edad de entre todos los votantes
-- existentes en la base de datos. Ordenar el resultado alfabéticamente por
-- nombre de localidad.

SELECT l.nombre, p.comunidad FROM localidades l, provincias p
    WHERE l.provincia = p.idprovincia
    AND l.numerohabitantes >
    (
        SELECT numerohabitantes FROM localidades
            WHERE idlocalidad =
            (
            SELECT localidad FROM votantes
                WHERE dni =
                (
                    SELECT dni FROM votantes
                        WHERE fechanacimiento =
                        (
                        SELECT MIN(fechanacimiento) FROM votantes
                            WHERE fechanacimiento >
                            (
                                SELECT MIN (fechanacimiento) FROM votantes
                            )
                        )
                )
            )
    )
    ORDER BY l.nombre;