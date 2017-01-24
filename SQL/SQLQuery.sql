CREATE TABLE tblPatients(
id int IDENTITY PRIMARY KEY,
szFirstName nvarchar(32),
szLastName nvarchar(32)
)


INSERT INTO tblPatients (szFirstName, szLastName) VALUES ('Carl', 'Johnson')
INSERT INTO tblPatients (szFirstName, szLastName) VALUES ('Big', 'Smoke')
INSERT INTO tblPatients (szFirstName, szLastName) VALUES ('Madd', 'Dogg')
INSERT INTO tblPatients (szFirstName, szLastName) VALUES ('OG', 'Loc')
INSERT INTO tblPatients (szFirstName, szLastName) VALUES ('Eddie', 'Pulaski')
INSERT INTO tblPatients (szFirstName, szLastName) VALUES ('Kendl', 'Johnson')
INSERT INTO tblPatients (szFirstName, szLastName) VALUES ('Sweet', '')
INSERT INTO tblPatients (szFirstName, szLastName) VALUES ('Ryder', '')
INSERT INTO tblPatients (szFirstName, szLastName) VALUES ('Cesar', 'Vialpando')

USE InteropDb

CREATE ROLE rlViewer
GRANT SELECT TO rlViewer
EXEC sp_addrolemember 'rlViewer', 'NarutoUA'


CREATE TABLE tblDetails(
id int PRIMARY KEY FOREIGN KEY REFERENCES tblPatients(id),
iSkinId int,
szSkinModel nvarchar(64),
szSkinType nvarchar(64),
szLocation nvarchar(64),
szGender nvarchar(16)
)

ALTER TABLE tblDetails
ADD szPicPath nvarchar(260)


INSERT INTO tblDetails VALUES (1, 0, 'cj', 'Carl "CJ" Johnson', 'Anywhere', 'Male')
INSERT INTO tblDetails VALUES (2, 269, 'smoke', 'Melvin "Big Smoke" Harris', 'San Andreas', 'Male')
INSERT INTO tblDetails VALUES (3, 297, 'maddogg', 'Madd Dogg', 'Madd Dogg`s Mansion, Los Santos', 'Male')
INSERT INTO tblDetails VALUES (4, 293, 'ogloc', 'Jeffery "OG Loc" Martin/Cross', 'Los Santos Burger Shot', 'Male')
INSERT INTO tblDetails VALUES (5, 266, 'pulaski', 'Officer Eddie Pulaski (Corrupt Cop)', 'Missions', 'Male')
INSERT INTO tblDetails VALUES (6, 65, 'kendl', 'Kendl Johnson', 'Los Santos and San Fierro', 'Female')
INSERT INTO tblDetails VALUES (7, 270, 'sweet', 'Sean "Sweet" Johnson', 'Los Santos/San Fierro', 'Male')
INSERT INTO tblDetails VALUES (9, 292, 'cesar', 'Cesar Vialpando', 'Los Santos/San Fierro', 'Male')
INSERT INTO tblDetails VALUES (10, 271, 'ryder', 'Lance "Ryder" Wilson', 'Los Santos/San Fierro', 'Male')


UPDATE tblDetails SET szPicPath = 'D:\Downloads\GtaSkins\00.bmp' WHERE id = 1
UPDATE tblDetails SET szPicPath = 'D:\Downloads\GtaSkins\269.bmp' WHERE id = 2
UPDATE tblDetails SET szPicPath = 'D:\Downloads\GtaSkins\297.bmp' WHERE id = 3
UPDATE tblDetails SET szPicPath = 'D:\Downloads\GtaSkins\293.bmp' WHERE id = 4
UPDATE tblDetails SET szPicPath = 'D:\Downloads\GtaSkins\266.bmp' WHERE id = 5
UPDATE tblDetails SET szPicPath = 'D:\Downloads\GtaSkins\65.bmp' WHERE id = 6
UPDATE tblDetails SET szPicPath = 'D:\Downloads\GtaSkins\270.bmp' WHERE id = 7
UPDATE tblDetails SET szPicPath = 'D:\Downloads\GtaSkins\292.bmp' WHERE id = 9
UPDATE tblDetails SET szPicPath = 'D:\Downloads\GtaSkins\271.bmp' WHERE id = 10
