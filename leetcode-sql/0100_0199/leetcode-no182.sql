SELECT email 
FROM Person
GROUP BY email
HAVING COUNT(*) > 1;

-- SELECT email
-- FROM (
--         SELECT email,
--             COUNT(*) AS count
--         FROM Person
--         GROUP BY email
--         ORDER BY count DESC
--         LIMIT 1
--     ) AS subquery;