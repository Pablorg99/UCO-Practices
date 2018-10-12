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
INSERT INTO votantes
  Values (30653845, 'Maria Gonzalez Ramirez', 'Doctorado', 'Activo',
          'goram@telefonica.es', 1, '21/08/89', 677544822);


-- Ejercicio 6
-- Compruebo que se ha insertado
SELECT * FROM votantes;


-- Ejercicio 7
-- Borro buscando con el DNI
DELETE FROM votantes
  WHERE DNI = 30653845;
-- De nuevo Compruebo
SELECT * FROM votantes;


-- Ejercicio 8
INSERT INTO partidos
  Values (6, 'Unión, Progreso y Democracia', 'UPYD', 'c/ Ferraz 30',
          'Madrid', 'Toni Cantó', '15/03/2004', 24300);
INSERT INTO provincias
  Values (7, 'Málaga', 569009, 'Andalucia');
-- Compruebo que las insercciones se han realizado
SELECT * FROM partidos;
SELECT * FROM provincias;


-- Ejercicio 9
-- Miro los atributos
DESCRIBE eventos;
--Hago select a los que me piden
SELECT nombre, tipo, fecha FROM eventos;


-- Ejercicio 10
-- Concateno con || y establezco el alias pedido por el enunciado
SELECT nombre||tipo||fecha Convocatoria FROM eventos;


-- Ejercicio 11
-- Para visualizar los atributos comodamente
DESCRIBE partidos;
DESCRIBE localidades;
-- Ahora ejecuto 2 SELECT con concatenaciones
SELECT nombrecompleto||siglas Partido FROM partidos;
SELECT nombre||numerohabitantes Localidad FROM localidades;
