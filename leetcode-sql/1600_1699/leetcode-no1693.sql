-- problem: https://leetcode.cn/problems/daily-leads-and-partners/

SELECT date_id, make_name, COUNT(DISTINCT d.lead_id) as unique_leads, COUNT(DISTINCT d.partner_id) as unique_partners
FROM DailySales d
GROUP BY date_id, make_name;



-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | date_id     | date    |
-- | make_name   | varchar |
-- | lead_id     | int     |
-- | partner_id  | int     |
-- +-------------+---------+

-- Created by Zackary37 at 6/10/2025 8:58 PM