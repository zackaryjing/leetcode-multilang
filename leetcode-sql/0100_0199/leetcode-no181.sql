SELECT name AS Employee
FROM Employee e
WHERE managerID IS NOT NULL
    AND e.salary > (
        SELECT salary
        FROM Employee
        WHERE id = e.managerID
    );

-- 分隔

SELECT a.name AS Employee
FROM Employee a
    JOIN Employee b on a.managerID = b.id
WHERE a.Salary > b.Salary;