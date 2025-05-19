-- problem: https://leetcode.cn/problems/product-sales-analysis-iii/
SELECT s.product_id as product_id,
    s.year as first_year,
    s.quantity as quantity,
    s.price as price
FROM Sales s
    JOIN (
        SELECT min(s2.year) as first_year,
            s2.product_id as id
        FROM Sales s2
        GROUP BY s2.product_id
    ) as fy ON s.product_id = fy.id
    AND s.year = fy.first_year;
--
-- Created By Zackary37 At 2025-05-19 22:05:08
- -