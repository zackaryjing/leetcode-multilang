-- https://leetcode.cn/problems/department-top-three-salaries/
SELECT d.name AS Department,
    t.name AS Employee,
    salary AS Salary
FROM (
        SELECT departmentId,
            name,
            salary,
            DENSE_RANK() OVER (
                PARTITION BY departmentId
                ORDER BY salary DESC
            ) AS rank_salary
        FROM Employee
    ) as t
    LEFT JOIN Department d ON t.departmentId = d.id
WHERE rank_salary <= 3