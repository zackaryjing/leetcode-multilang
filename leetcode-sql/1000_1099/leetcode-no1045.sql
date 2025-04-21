-- problem: https://leetcode.cn/problems/customers-who-bought-all-products/
SELECT c.customer_id
FROM Customer c
GROUP BY c.customer_id
HAVING COUNT(DISTINCT c.product_key) = (SELECT COUNT(*) FROM product);
--
-- Created By Zackary37 At 2025-04-18 14:33:26
--