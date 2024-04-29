CREATE TABLE IF NOT EXISTS student (
    date VARCHAR(45),
    studentId VARCHAR(10),
    studentTitle VARCHAR(45),
    studentFirstName VARCHAR(255),
    studentLastName VARCHAR(255), 
    studentYear INT,
    studyField VARCHAR(255),
    advisor VARCHAR(255),
    addressNumber VARCHAR(255),
    moo VARCHAR(255), 
    tumbol VARCHAR(255), 
    amphur VARCHAR(255), 
    province VARCHAR(255), 
    postalCode VARCHAR(10),
    phone VARCHAR(10),
    mobilePhone varchar(10),
    cause varchar(255)
);

CREATE TABLE IF NOT EXISTS subject(
studentId VARCHAR(10),
    subjectCode VARCHAR(45),
    subjectName VARCHAR(255),
    subjectSection VARCHAR(6),
    subjectDate VARCHAR(45),
    subjectCredit INT,
    subjectTeacher VARCHAR(255),
    subjectTeacherCheck BIT,
    type VARCHAR(30)
);