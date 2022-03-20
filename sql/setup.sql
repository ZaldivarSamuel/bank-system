CREATE DATABASE bank;

USE bank;

CREATE TABLE Accounts(

    accountNumber INT NOT NULL,
    firstName VARCHAR(255) NOT NULL,
    lastName VARCHAR(255) NOT NULL,
    balance FLOAT DEFAULT 0.00 NOT NULL,

    PRIMARY KEY(accountNumber)
); 