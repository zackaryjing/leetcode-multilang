-- https://leetcode.cn/problems/nth-highest-salary/
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN
DECLARE result INT;
SET N = N - 1;
SELECT salary INTO result
FROM (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC
    ) AS temp_table
LIMIT 1 OFFSET N;
RETURN result;
END;
-- 
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN
DECLARE M INT;
SET M = N - 1;
RETURN (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT M, 1
);
END;