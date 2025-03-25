SELECT name, bonus 
FROM Employee a
LEFT JOIN Bonus b ON a.empID = b.empID
WHERE bonus < 1000 OR bonus is NULL
