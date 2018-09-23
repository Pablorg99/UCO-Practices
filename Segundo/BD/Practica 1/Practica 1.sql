-- Ejercicio 2
SELECT table_name FROM user_tables;

-- Ejercicio 3
DESCRIBE consultas;
DESCRIBE consultas_datos;
DESCRIBE eventos;
DESCRIBE eventos_resultados;
DESCRIBE localidades;
DESCRIBE partidos;
DESCRIBE provincias;
DESCRIBE votantes;

-- Ejercicio 4
DROP table votantes;
-- No se puede realizar el borrado de la tabla porque su clave primaria es
-- referenciada por claves foráneas de otra tabla por lo que hay que hacer el
-- borrado de estas claves foráneas previamente usando:
DROP table votantes CASCADE CONSTRAINTS;
-- Procediendo de la misma manera con el resto
DROP table consultas_datos CASCADE CONSTRAINTS;
DROP table consultas CASCADE CONSTRAINTS;
DROP table eventos_resultados CASCADE CONSTRAINTS;
DROP table eventos CASCADE CONSTRAINTS;
DROP table localidades CASCADE CONSTRAINTS;
DROP table partidos CASCADE CONSTRAINTS;
DROP table provincias CASCADE CONSTRAINTS;

-- Ejercicio 5
-- IMPORTO DE NUEVO LA BD (Script BD.sql)
