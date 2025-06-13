-- problem: https://leetcode.cn/problems/the-number-of-employees-which-report-to-each-employee/description/


SELECT e1.reports_to         as employee_id,
       e2.name,
       COUNT(e1.reports_to)  as reports_count,
       ROUND(AVG(e1.age), 0) as average_age
FROM Employees e1
         JOIN Employees e2
              ON e1.reports_to IS NOT NULL AND e1.reports_to = e2.employee_id
GROUP BY e1.reports_to
ORDER BY e1.reports_to
;



-- +-------------+---------+------------+-----+
-- | employee_id | name    | reports_to | age |
-- +-------------+---------+------------+-----+
-- | 9           | Hercy   | null       | 43  |
-- Output:
-- +-------------+-------+---------------+-------------+
-- | employee_id | name  | reports_count | average_age |
-- +-------------+-------+---------------+-------------+

-- Created by Zackary37 at 6/12/2025 11:15 AM