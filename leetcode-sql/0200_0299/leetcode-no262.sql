WITH sub_table AS (
    SELECT t.client_id,
        t.driver_id,
        t.request_at,
        t.status
    FROM Trips t
        INNER JOIN Users u ON NOT (
            t.client_id = u.users_id
            and u.banned = 'Yes'
            or t.driver_id = u.users_id
            and u.banned = 'Yes'
        )
    WHERE t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
)
SELECT s.request_at as Day,
    ROUND(
        count(
            CASE
                WHEN s.status != 'completed' THEN 1
            END
        ) / count(*),
        2
    ) as 'Cancellation Rate'
FROM sub_table s
GROUP BY s.request_at
ORDER BY s.request_at