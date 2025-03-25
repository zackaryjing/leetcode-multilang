SELECT class 
FROM Courses
GROUP BY class
HAVING count(*) >= 5