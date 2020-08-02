CREATE TABLE User (
    ID INT AUTO_INCREMENT,
    Role INT(5) NOT NULL,
    Details INT NOT NULL,
    LegalType INT NOT NULL,
    Email VARCHAR(150) NOT NULL,
    Username VARCHAR(20) NOT NULL,
    Password VARCHAR(255) NOT NULL,
    SecurityQuestionID INT NOT NULL,
    SecurityAnswer VARCHAR(255) NOT NULL,
    PRIMARY KEY (ID)
);

CREATE TABLE UserDetails (
    ID INT,
    UserID INT,
    fName VARCHAR(100) NOT NULL,
	lName VARCHAR(100) NOT NULL,
    Company VARCHAR(100),
    Address1 VARCHAR(100) NOT NULL,
    Address2 VARCHAR(100) NOT NULL,
	Address3 VARCHAR(100) NOT NULL,
    Town VARCHAR(100) NOT NULL,
    Region VARCHAR(100) NOT NULL,
    Postcode VARCHAR(15) NOT NULL,
    Country VARCHAR(20) NOT NULL,
    Landline VARCHAR(20) NOT NULL,
    Mobile VARCHAR(20),
    SMS BOOL NOT NULL,
    PRIMARY KEY (ID)
);

CREATE TABLE LegalType (
ID INT,
String VARCHAR(255) NOT NULL,
PRIMARY KEY (ID)
);

CREATE TABLE SecurityQuestion (
ID INT,
String VARCHAR(255) NOT NULL,
PRIMARY KEY (ID)
);

CREATE TABLE Domain (
Name VARCHAR(50) NOT NULL,
ID INT AUTO_INCREMENT,
Registered DATE,
Renewal DATE,
Price FLOAT(10,2),
AutoRenew BOOL,
NS1 VARCHAR(100) NOT NULL,
NS2 VARCHAR(100),
NS3 VARCHAR(100),
NS4 VARCHAR(100),
NS5 VARCHAR(100),
PRIMARY KEY (ID)
);