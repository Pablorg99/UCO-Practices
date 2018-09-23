drop table consultas_datos;
drop table consultas;
drop table eventos_resultados;
drop table eventos;
drop table votantes;
drop table localidades;
drop table partidos;
drop table provincias;

create table partidos
	(idPartido number(3) primary key,
	nombreCompleto varchar2(64) not null,
	siglas varchar(6),
	direccion varchar2(64) not null,
	ciudad varchar2(64) not null,
	presidente varchar2(32) not null,
	fechaCreacion date not null,
	presupuesto number(14));

create table provincias
	(idProvincia number(3) primary key,
	nombre varchar2(64) not null,
	numeroHabitantes number(38) not null,
	comunidad varchar2(64) not null);

create table localidades
	(idLocalidad number(3) primary key,
	nombre varchar2(64) not null,
	numeroHabitantes number(38) not null,
	provincia number(3) not null,
  constraint fk_localidad_provincia foreign key (provincia) references provincias(idProvincia));

create table votantes
	(dni number(8) primary key,
	nombreCompleto varchar2(64),
	estudiosSuperiores varchar2(16) not null,
	situacionLaboral varchar2(16) not null,
	email varchar2(32) not null,
	localidad number(3) not null,
	fechaNacimiento date not null,
	telefono number(14),
	constraint ck_estudios CHECK (estudiosSuperiores in ('Ninguno','Basicos','Superiores','Doctorado')),
	constraint ck_laboral CHECK (situacionLaboral in ('Estudiante','Jubilado','Parado','Activo')),
	constraint fk_localidad_vot foreign key (localidad) references localidades(idLocalidad));

create table eventos
	(idEvento number(6) primary key,
	nombre varchar(32) not null,
	fecha date not null,
	tipo varchar(16) not null,
	detalle varchar2(1024) null,
	constraint ck_nombre CHECK (tipo in ('Europeas','Generales','Autonomicas','Locales','Otras')));

create table eventos_resultados
	(idResultado number(6) primary key,
	evento number(6) not null,
	partido number(3) not null,
	resultado real not null,
	constraint fk_evento_res foreign key (evento) references eventos(idEvento),
	constraint fk_partido_res foreign key (partido) references partidos(idPartido));

create table consultas
	(idConsulta number(6) primary key,
	evento number(6) not null,
	votante	number(8) not null,
	fecha date not null,
	constraint fk_evento foreign key (evento) references eventos(idEvento),
	constraint fk_votante foreign key (votante) references votantes(dni));

create table consultas_datos
	(idRecogida number(6) primary key,
	consulta number(6) not null,
	partido	number(3) not null,
	respuesta varchar(2) not null,
	certidumbre real not null,
	constraint fk_consulta FOREIGN KEY (consulta) REFERENCES Consultas(idConsulta),
	constraint fk_partido FOREIGN KEY (partido) REFERENCES Partidos(idPartido),
	constraint ck_respuesta CHECK (respuesta in ('Si','No')));

insert into partidos
values (1, 'Partido Popular', 'PP', 'c/ Génova 13', 'Madrid', 'Pablo Casado Blanco', '20/01/1989', 324143);
insert into partidos
values (2, 'Partido Socialista Obrero Español', 'PSOE', 'c/ Ferraz 70', 'Madrid', 'Pedro Sanchez Perez-Castejon', '02/05/1879', 420198);
insert into partidos
values (3, 'Ciudadanos', 'Cs', 'c/ Alcalá 253', 'Madrid', 'Albert Rivera Diaz', '01/06/2006', 35200);
insert into partidos
values (4, 'Podemos', null, 'c/ Zurita 21', 'Madrid', 'Pablo Iglesias Turrión', '17/01/2014', 56290);
insert into partidos
values (5, 'Izquierda Unida', 'IU', 'c/ Olimpo 35', 'Madrid', 'Alberto Garzón Espinosa', '29/04/1986', 101310);

insert into provincias
values (1, 'Córdoba', 788219, 'Andalucia');
insert into provincias
values (2, 'Sevilla', 1939775, 'Andalucia');
insert into provincias
values (3, 'Madrid', 6507184, 'Madrid');
insert into provincias
values (4, 'Barcelona', 5576037, 'Cataluña');
insert into provincias
values (5, 'Zaragoza', 970313, 'Aragon');
insert into provincias
values (6, 'Valencia', 2578719, 'Comunidad Valenciana');

insert into localidades
values (1, 'Cordoba', 326609, 1);
insert into localidades
values (2, 'Montilla', 23365, 1);
insert into localidades
values (3, 'Baena', 19782, 1);
insert into localidades
values (4, 'Sevilla', 90566, 2);
insert into localidades
values (5, 'Utrera', 52674, 2);
insert into localidades
values (6, 'Carmona', 28595, 2);
insert into localidades
values (7, 'Getafe', 176659, 3);
insert into localidades
values (8, 'Leganes', 187173, 3);
insert into localidades
values (9, 'Madrid', 3182981, 3);
insert into localidades
values (10, 'Barcelona', 1620943, 4);
insert into localidades
values (11, 'Badalona', 220977, 4);
insert into localidades
values (12, 'Gerona', 97198, 4);
insert into localidades
values (13, 'Tarrasa', 215678, 4);
insert into localidades
values (14, 'Zaragoza', 674317, 5);
insert into localidades
values (15, 'Gandia', 75514, 6);
insert into localidades
values (16, 'Valencia', 786189, 6);

insert into votantes
values (30983712, 'Jose Perez Perez', 'Basicos', 'Parado','jpp@gmail.com',5,'23/02/1982',662234293);
insert into votantes
values (41867538, 'Laura Valenzuela Ferrer', 'Doctorado', 'Activo','lavafe@gmail.com',4,'09/09/1975',722657395);
insert into votantes
values (44826745, 'Pedro Jimenez Santos', 'Basicos', 'Estudiante','jimsanped@yahoo.es',4,'12/09/1997',625336491);
insert into votantes
values (30725352, 'Marta Sanchez Rodriguez', 'Ninguno', 'Parado','martita00@hotmail.com',1,'28/01/2000',654825492);
insert into votantes
values (45245264, 'Ana María Expósito Escudero', 'Superiores', 'Activo','expositoeam@yahoo.es',6,'30/07/1992',692547885);
insert into votantes
values (31075940, 'Alberto Nuñez Fernandez', 'Basicos', 'Jubilado','anfernandez@outlook.com',1,'14/05/1950',666350983);
insert into votantes
values (45374737, 'Carolina Lopez Muriel', 'Basicos', 'Activo','karolop90@hotmail.com',5,'19/11/1988',643176224);
insert into votantes
values (30852845, 'Pablo Morales Raigan', 'Doctorado', 'Activo','morapa@telefonica.es',2,'25/03/1969',677534816);
insert into votantes
values (45628436, 'Manuel Medina Alvarez', 'Superiores', 'Activo','manuelmedinalv@gmail.com',11,'01/01/1992',625826487);
insert into votantes
values (31087814, 'Luisa Cano Vega', 'Ninguno', 'Activo','louisecave@yahoo.es',3,'05/06/1981',645623736);
insert into votantes
values (45657294, 'Alvaro Diaz Gomez', 'Basicos', 'Estudiante','alvadigo@ono.es',5,'29/08/1999',757427827);
insert into votantes
values (08727847, 'Estrella Ortiz Mengual', 'Superiores', 'Jubilado','esomen@gmail.com',4,'23/01/1953',611892544);
insert into votantes
values (75648104, 'Hector Mendoza Hernandez', 'Doctorado', 'Parado','he2men@yahoo.es',1,'14/10/1986',654264027);
insert into votantes
values (80762946, 'Andres Carrasco Cruz', 'Basicos', 'Activo','andrescaracruz@yahoo.es',7,'11/09/1992',699427546);
insert into votantes
values (30559073, 'Lucia Hoyos Martin', 'Basicos', 'Parado','hoyosmalu@hotmail.com',9,'31/03/1998',721988562);
insert into votantes
values (30559074, 'Martin Hoyos Martin', 'Basicos', 'Activo','hoyosmama@hotmail.com',9,'01/03/1996',721988563);
insert into votantes
values (30559075, 'Jose Hoyos Martin', 'Superiores', 'Activo','hoyosmaj@hotmail.com',9,'22/01/1993',721988560);

insert into eventos
values (1, 'Europa2018', '23/04/2018', 'Europeas','Elecciones al parlamento europeo');
insert into eventos
values (2, 'Europa2015', '20/03/2015', 'Europeas','Elecciones al parlamento europeo');
insert into eventos
values (3, 'España17', '26/05/2017', 'Generales','Elecciones generales');
insert into eventos
values (4, 'España13', '30/05/2013', 'Generales','Elecciones generales');
insert into eventos
values (5, 'Andalucia', '23/09/2018', 'Autonomicas','Elecciones al parlamento andaluz');
insert into eventos
values (6, 'Madrid', '23/09/2018', 'Autonomicas','Elecciones a la comunidad de madrid');
insert into eventos
values (7, 'Cataluña', '23/09/2018', 'Autonomicas','Elecciones a la generalitat');
insert into eventos
values (8, 'Cordoba', '22/01/2018', 'Locales','Elecciones al ayuntamiento de Cordoba');
insert into eventos
values (9, 'Sevilla', '22/01/2018', 'Locales','Elecciones al ayuntamiento de Sevilla');
insert into eventos
values (10, 'Madrid', '22/01/2018', 'Locales','Elecciones al ayuntamiento de Madrid');
insert into eventos
values (11, 'Estatuto', '10/01/2018', 'Otras','Aprobacion del estatuto de autonomia andaluz');

insert into eventos_resultados
values (1, 1, 1, 0.37);
insert into eventos_resultados
values (2, 1, 2, 0.24);
insert into eventos_resultados
values (3, 1, 3, 0.16);
insert into eventos_resultados
values (4, 1, 4, 0.10);
insert into eventos_resultados
values (5, 1, 5, 0.13);
insert into eventos_resultados
values (6, 2, 1, 0.30);
insert into eventos_resultados
values (7, 2, 2, 0.14);
insert into eventos_resultados
values (8, 2, 3, 0.16);
insert into eventos_resultados
values (9, 2, 4, 0.27);
insert into eventos_resultados
values (10, 2, 5, 0.13);
insert into eventos_resultados
values (11, 3, 1, 0.20);
insert into eventos_resultados
values (12, 3, 2, 0.40);
insert into eventos_resultados
values (13, 3, 3, 0.11);
insert into eventos_resultados
values (14, 3, 4, 0.09);
insert into eventos_resultados
values (15, 3, 5, 0.20);
insert into eventos_resultados
values (16, 4, 1, 0.39);
insert into eventos_resultados
values (17, 4, 2, 0.50);
insert into eventos_resultados
values (18, 4, 5, 0.11);
insert into eventos_resultados
values (19, 5, 1, 0.27);
insert into eventos_resultados
values (20, 5, 2, 0.64);
insert into eventos_resultados
values (21, 5, 3, 0.06);
insert into eventos_resultados
values (22, 5, 4, 0.01);
insert into eventos_resultados
values (23, 5, 5, 0.02);
insert into eventos_resultados
values (24, 6, 1, 0.67);
insert into eventos_resultados
values (25, 6, 2, 0.14);
insert into eventos_resultados
values (26, 6, 3, 0.06);
insert into eventos_resultados
values (27, 6, 4, 0.11);
insert into eventos_resultados
values (28, 6, 5, 0.02);
insert into eventos_resultados
values (29, 7, 1, 0.07);
insert into eventos_resultados
values (30, 7, 2, 0.62);
insert into eventos_resultados
values (31, 7, 3, 0.30);
insert into eventos_resultados
values (32, 7, 4, 0.01);
insert into eventos_resultados
values (33, 7, 5, 0.02);
insert into eventos_resultados
values (34, 8, 1, 0.34);
insert into eventos_resultados
values (35, 8, 2, 0.12);
insert into eventos_resultados
values (36, 8, 5, 0.54);
insert into eventos_resultados
values (37, 9, 1, 0.34);
insert into eventos_resultados
values (38, 9, 2, 0.12);
insert into eventos_resultados
values (39, 9, 3, 0.34);
insert into eventos_resultados
values (40, 9, 4, 0.20);
insert into eventos_resultados
values (41, 10, 1, 0.37);
insert into eventos_resultados
values (42, 10, 2, 0.24);
insert into eventos_resultados
values (43, 10, 3, 0.16);
insert into eventos_resultados
values (44, 10, 4, 0.10);
insert into eventos_resultados
values (45, 10, 5, 0.13);

insert into consultas
values (1, 1, 30983712, '22/03/2018');
insert into consultas
values (2, 1, 41867538, '22/03/2018');
insert into consultas
values (3, 1, 44826745, '22/03/2018');
insert into consultas
values (4, 1, 30725352, '21/03/2018');
insert into consultas
values (5, 1, 45245264, '22/03/2018');
insert into consultas
values (6, 1, 31075940, '21/03/2018');
insert into consultas
values (7, 1, 45374737, '22/03/2018');
insert into consultas
values (8, 1, 31087814, '21/03/2018');
insert into consultas
values (9, 1, 45628436, '21/03/2018');
insert into consultas
values (10, 3, 30983712, '12/03/2017');
insert into consultas
values (11, 3, 41867538, '12/03/2017');
insert into consultas
values (12, 3, 44826745, '12/03/2017');
insert into consultas
values (13, 3, 30725352, '11/03/2017');
insert into consultas
values (14, 3, 45245264, '12/03/2017');
insert into consultas
values (15, 3, 31075940, '11/03/2017');
insert into consultas
values (16, 3, 45374737, '12/03/2017');
insert into consultas
values (17, 3, 31087814, '11/03/2017');
insert into consultas
values (18, 3, 45628436, '11/03/2017');
insert into consultas
values (19, 8, 30725352, '19/11/2017');
insert into consultas
values (20, 8, 31075940, '19/11/2017');
insert into consultas
values (21, 8, 75648104, '19/11/2017');
insert into consultas
values (22, 6, 80762946, '31/07/2017');
insert into consultas
values (23, 6, 30559073, '31/07/2017');
insert into consultas
values (24, 6, 30559074, '31/07/2017');
insert into consultas
values (25, 6, 30559075, '31/07/2017');
insert into consultas
values (26, 5, 75648104, '31/07/2017');
insert into consultas
values (27, 5, 30983712, '31/07/2017');
insert into consultas
values (28, 5, 41867538, '31/07/2017');
insert into consultas
values (29, 5, 44826745, '30/07/2017');
insert into consultas
values (30, 5, 30725352, '31/07/2017');
insert into consultas
values (31, 5, 45245264, '30/07/2017');
insert into consultas
values (32, 5, 31075940, '31/07/2017');
insert into consultas
values (33, 5, 45374737, '29/07/2017');
insert into consultas
values (34, 5, 30852845, '29/07/2017');
insert into consultas
values (35, 5, 31087814, '29/07/2017');
insert into consultas
values (36, 5, 45657294, '29/07/2017');
insert into consultas
values (37, 5, 08727847, '31/07/2017');
insert into consultas
values (38, 2, 30983712, '21/01/2015');
insert into consultas
values (39, 2, 41867538, '21/01/2015');
insert into consultas
values (40, 2, 44826745, '21/01/2015');
insert into consultas
values (41, 2, 30725352, '22/01/2015');
insert into consultas
values (42, 2, 45245264, '21/01/2015');
insert into consultas
values (43, 2, 31075940, '21/01/2015');
insert into consultas
values (44, 2, 45374737, '22/01/2015');
insert into consultas
values (45, 2, 30852845, '21/01/2015');
insert into consultas
values (46, 2, 45628436, '22/01/2015');
insert into consultas
values (47, 2, 31087814, '21/01/2015');
insert into consultas
values (48, 2, 45657294, '22/01/2015');
insert into consultas
values (49, 2, 08727847, '21/01/2015');
insert into consultas
values (50, 2, 75648104, '21/01/2015');
insert into consultas
values (51, 2, 80762946, '21/01/2015');
insert into consultas
values (52, 2, 30559073, '22/01/2015');
insert into consultas
values (53, 2, 30559074, '22/01/2015');
insert into consultas
values (54, 2, 30559075, '22/01/2015');

insert into consultas_datos
values (1, 1, 1, 'Si', 0.90);
insert into consultas_datos
values (2, 2, 1, 'Si', 0.87);
insert into consultas_datos
values (3, 3, 1, 'Si', 0.85);
insert into consultas_datos
values (4, 4, 1, 'Si', 0.57);
insert into consultas_datos
values (5, 4, 2, 'No', 0.47);
insert into consultas_datos
values (6, 5, 1, 'Si', 0.78);
insert into consultas_datos
values (7, 6, 2, 'Si', 0.78);
insert into consultas_datos
values (8, 7, 2, 'Si', 0.92);
insert into consultas_datos
values (9, 8, 2, 'Si', 0.78);
insert into consultas_datos
values (10, 9, 3, 'Si', 0.78);
insert into consultas_datos
values (11, 10, 1, 'Si', 0.78);
insert into consultas_datos
values (12, 10, 2, 'No', 0.92);
insert into consultas_datos
values (13, 10, 3, 'No', 0.95);
insert into consultas_datos
values (14, 11, 1, 'Si', 0.58);
insert into consultas_datos
values (15, 12, 2, 'Si', 0.85);
insert into consultas_datos
values (16, 13, 2, 'Si', 0.88);
insert into consultas_datos
values (17, 14, 2, 'Si', 0.81);
insert into consultas_datos
values (18, 15, 2, 'Si', 0.81);
insert into consultas_datos
values (19, 16, 3, 'Si', 0.65);
insert into consultas_datos
values (20, 17, 4, 'Si', 0.81);
insert into consultas_datos
values (21, 18, 5, 'Si', 0.81);
insert into consultas_datos
values (22, 19, 1, 'Si', 0.81);
insert into consultas_datos
values (23, 20, 5, 'Si', 0.81);
insert into consultas_datos
values (24, 21, 5, 'Si', 0.81);
insert into consultas_datos
values (25, 22, 1, 'Si', 0.61);
insert into consultas_datos
values (26, 23, 2, 'Si', 0.78);
insert into consultas_datos
values (27, 24, 3, 'Si', 0.51);
insert into consultas_datos
values (28, 25, 4, 'Si', 0.51);
insert into consultas_datos
values (29, 26, 1, 'Si', 0.51);
insert into consultas_datos
values (30, 27, 4, 'Si', 0.56);
insert into consultas_datos
values (31, 28, 2, 'Si', 0.57);
insert into consultas_datos
values (32, 29, 4, 'Si', 0.61);
insert into consultas_datos
values (33, 30, 3, 'Si', 0.72);
insert into consultas_datos
values (34, 31, 4, 'Si', 0.83);
insert into consultas_datos
values (35, 32, 5, 'Si', 0.98);
insert into consultas_datos
values (36, 33, 5, 'Si', 0.90);
insert into consultas_datos
values (37, 34, 2, 'Si', 0.85);
insert into consultas_datos
values (38, 35, 4, 'Si', 0.84);
insert into consultas_datos
values (39, 36, 2, 'Si', 0.81);
insert into consultas_datos
values (40, 37, 2, 'Si', 0.59);
insert into consultas_datos
values (41, 38, 1, 'Si', 0.59);
insert into consultas_datos
values (42, 39, 1, 'Si', 0.99);
insert into consultas_datos
values (43, 40, 1, 'Si', 0.79);
insert into consultas_datos
values (44, 41, 2, 'Si', 0.89);
insert into consultas_datos
values (45, 42, 2, 'Si', 0.59);
insert into consultas_datos
values (46, 43, 3, 'Si', 0.86);
insert into consultas_datos
values (47, 44, 4, 'Si', 0.59);
insert into consultas_datos
values (48, 45, 2, 'Si', 0.59);
insert into consultas_datos
values (49, 46, 5, 'Si', 0.51);
insert into consultas_datos
values (50, 47, 3, 'Si', 0.50);
insert into consultas_datos
values (51, 48, 5, 'No', 0.59);
insert into consultas_datos
values (52, 49, 5, 'Si', 0.55);
insert into consultas_datos
values (53, 50, 3, 'Si', 0.66);
insert into consultas_datos
values (54, 51, 1, 'Si', 0.77);
insert into consultas_datos
values (55, 52, 1, 'Si', 0.76);
insert into consultas_datos
values (56, 53, 1, 'Si', 0.64);
insert into consultas_datos
values (57, 54, 2, 'Si', 0.99);
insert into consultas_datos
values (58, 54, 1, 'No', 0.99);
insert into consultas_datos
values (59, 54, 3, 'No', 0.76);
insert into consultas_datos
values (60, 54, 4, 'No', 0.92);
insert into consultas_datos
values (61, 54, 5, 'No', 0.82);
