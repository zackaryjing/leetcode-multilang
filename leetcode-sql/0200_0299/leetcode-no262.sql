
SELECT
    t.request_at AS Day,
    ROUND(
        SUM(CASE WHEN t.status != 'completed' THEN 1 ELSE 0 END) * 1.0
        / COUNT(*),
        2
    ) AS 'Cancellation Rate'
FROM Trips t
JOIN Users c ON t.client_id = c.users_id AND c.banned = 'No'
JOIN Users d ON t.driver_id = d.users_id AND d.banned = 'No'
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at



-- WITH sub_table AS (
--     SELECT t.client_id,
--         t.driver_id,
--         t.request_at,
--         t.status
--     FROM Trips t
--         INNER JOIN Users u ON NOT (
--             t.client_id = u.users_id
--             and u.banned = 'Yes'
--             or t.driver_id = u.users_id
--             and u.banned = 'Yes'
--         )
--     WHERE t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
-- )
-- SELECT s.request_at as Day,
--     ROUND(
--         count(
--             CASE
--                 WHEN s.status != 'completed' THEN 1
--             END
--         ) / count(*),
--         2
--     ) as 'Cancellation Rate'
-- FROM sub_table s
-- GROUP BY s.request_at
-- ORDER BY s.request_at