


REM Display the nobel laureate(s) who born after 1­Jul­1960.
SELECT * FROM nobel WHERE dob>'1-jul-1960';


REM Display the Indian laureate (name, category, field, country, year awarded) who was awarded in the Chemistry category. 

SELECT name, category, field, country, year_award FROM nobel WHERE category='Che';


REM Display the laureates (name, category,field and year of award) who was awarded between 2000 and 2005 for the Physics or Chemistry category.
SELECT name, category, field, year_award FROM nobel WHERE (year_award BETWEEN 2000 AND 2005) AND (category='Phy' OR category='Che');


REM Display the laureates name with their age at the time of award for the Peace category. 
SELECT name, year_award - EXTRACT(YEAR FROM DOB) AS age_At_Award FROM nobel WHERE category='Pea';


REM Display the laureates (name,category,aff_role,country) whose name starts with A or ends with A, but not from Isreal. 

SELECT name, category, aff_role, country FROM nobel WHERE (name like 'A%' OR name like '%a') AND country!='Isreal';


REM Display the name, gender, affiliation, dob and country of laureates who was born in 1950s.Label the dob column as Born 1950.
SELECT name, gender, aff_role, dob, country FROM nobel WHERE dob between '1-jan-1950' and '31-dec-1959';


REM Display the laureates (name,gender,category,aff_role,country) whose name starts with A, D or H. Remove the laureate if he/she do not have any affiliation. Sort the results in ascending order of name. 

SELECT name, gender, category, aff_role, country FROM nobel WHERE (name like 'A%' OR name like 'D%' OR name like 'H%') AND aff_role is NOT NULL ORDER BY name;


REM Display the university name(s) that has to its credit by having at least 2 nobel laureate with them

SELECT aff_role AS universities FROM nobel WHERE aff_role IS NOT NULL AND aff_role like 'University%' GROUP BY aff_role HAVING COUNT(*) > 1;


List the date of birth of youngest and eldest laureates by country­wise. Label the column as Younger, Elder respectively. Include only the country having more than one laureate. Sort the output in alphabetical order of country

SELECT country, MAX(dob) as eldest, MIN(dob) as youngest FROM nobel GROUP BY country HAVING COUNT(country)>1 ORDER BY country;


REM Show the details (year award,category,field) where the award is shared among the laureates in the same category and field. Exclude the laureates from USA. 
SELECT year_award ,category, field FROM nobel WHERE country != 'USA' GROUP BY year_award, category, field;




REM table contents
SELECT * FROM nobel;




REM Mark an intermediate point in the transaction (savepoint)
SAVEPOINT save1;


REM Insert a new tuple into the nobel relation. 
insert into nobel values(129,'xyz','M','Pea','world organisation',2022,'SSN','19-sep-2002','India');


REM Update the aff_role of literature laureates as 'Linguists'. 
SELECT * from nobel WHERE category='Lit';
UPDATE nobel set aff_role='Linguists' WHERE category='Lit';
SELECT * from nobel WHERE category='Lit';


REM Delete the laureate(s) who was awarded in Enzymes field. 

rem showing tuples with enzymes field
SELECT * from nobel WHERE field='Enzymes';

rem deleting leaureates with enzyme field
DELETE FROM nobel WHERE field='Enzymes';

rem showing all tuples with enzymes field have been deleted
SELECT * from nobel WHERE field='Enzymes';


REM Discard the most recent update operations (rollback). 
ROLLBACK to save1;


REM Commit the changes 
COMMIT;


REM Showing the rollback 
SELECT * FROM nobel;




