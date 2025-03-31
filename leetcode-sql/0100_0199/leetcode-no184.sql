-- https://leetcode.cn/problems/department-highest-salary/description/ 
SELECT d.name as department,
    e.name as Employee,
    e.salary as Salary
FROM Employee e
    LEFT JOIN Department d on e.departmentId = d.id
HAVING e.salary = (
        SELECT max(t.salary)
        FROM Employee t
        WHERE t.departmentId = e.departmentId
    );
--
--
SELECT t.name as department,
    e.name as Employee,
    e.salary as Salary
FROM Employee e
    LEFT JOIN (
        SELECT d.id,
            max(salary) as salary,
            d.name
        FROM Department d
            LEFT JOIN Employee on d.id = departmentId
        GROUP BY d.id
    ) as t on e.departmentId = t.id
WHERE e.salary = t.salary;