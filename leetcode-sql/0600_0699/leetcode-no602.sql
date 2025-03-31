-- https://leetcode.cn/problems/friend-requests-ii-who-has-the-most-friends/description/ 
SELECT requester_id as id,
    count(*) as num
FROM (
        SELECT r.requester_id,
            r.accepter_id
        FROM RequestAccepted r
        WHERE accept_date IS NOT NULL
        UNION
        SELECT b.accepter_id as requester_id,
            b.requester_id as accepter_id
        FROM RequestAccepted b
        WHERE accept_date IS NOT NULL
    ) as t
GROUP BY requester_id
ORDER BY count(*) DESC
LIMIT 1