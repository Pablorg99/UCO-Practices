-- Ejercicio 1
SELECT concat (l1.nombre, concat(' va antes de ', l2.nombre))
    FROM localidades l1, localidades l2
    WHERE l1.idlocalidad = l2.idlocalidad - 1;

-- Ejercicio 2
SELECT nombre
    FROM localidades
    WHERE numerohabitantes > (
        SELECT numerohabitantes
            FROM localidades
            WHERE idlocalidad = (
                SELECT localidad FROM votantes
                    WHERE fechanacimiento = (
                        SELECT MIN(fechanacimiento)
                            FROM votantes
                            WHERE fechanacimiento > (
                                SELECT MIN(fechanacimiento) 
                                    FROM votantes
                            )
                    )
            )
    )