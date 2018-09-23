-- * para seleccionar toda la tabla
SELECT *
  FROM partidos;

-- Puedo elegir los atributos a mostrar y el orden en SELECT
-- nombreAtributo "Alias a mostrar"
SELECT siglas, presidente, idPartido "N Partido"
  FROM partidos;

-- Puedo hacer SELECT a atributos de varias tablas
-- Debo especificar a qu� tabla pertenece cada atributo
-- Puedo crear alias para las tablas (solo para esta instrucci�n)
SELECT  l.nombre "Nombre Localidad",
        l.numeroHabitantes "N Habitantes Localidad", 
        p.nombre "Nombre Provincia",
        p.numeroHabitantes "N Habitantes Provincia"
  FROM localidades l, provincias p;
  
-- Muestra los atributos y el tipo
DESCRIBE partidos;
  