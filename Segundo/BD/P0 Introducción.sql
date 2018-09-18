CREATE table Prueba (
	Edad number (2, 0),
	Nombre varchar2 (40)
);

INSERT INTO Prueba
	Values (23, 'Perez Perez, Jose');

INSERT INTO Prueba
	Values (19, 'Rodriguez Guillen, Pablo');

SELECT *
	From Prueba;

UPDATE Prueba
		SET Edad = 46
		Where Edad = 23;

DELETE
	From Prueba
	Where Edad = 19;

SELECT *
	From Prueba;

DROP table Prueba;
