-- https://leetcode.cn/problems/game-play-analysis-iv/ 
SELECT ROUND(
        (
            SELECT COUNT(*)
            FROM (
                    SELECT player_id,
                        min(event_date) as event_date
                    FROM Activity
                    GROUP BY player_id
                ) as a
                LEFT JOIN Activity b on a.player_id = b.player_id
                and b.event_date = DATE_ADD(a.event_date, INTERVAL 1 DAY)
            WHERE b.event_date IS NOT NULL
        ) / COUNT(DISTINCT k.player_id),
        2
    ) as fraction
FROM Activity k