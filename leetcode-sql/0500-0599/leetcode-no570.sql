--  https://leetcode.cn/problems/managers-with-at-least-5-direct-reports/ 
SELECT t.name
FROM Employee e
    INNER JOIN Employee t ON e.managerId = t.id
GROUP BY e.managerId
HAVING count(*) >= 5