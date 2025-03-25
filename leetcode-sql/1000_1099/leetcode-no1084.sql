-- problem: sales-analysis-iii 
SELECT DISTINCT p.product_id,
    p.product_name
FROM Sales s
    LEFT JOIN product p ON s.product_id = p.product_id
WHERE s.product_id NOT IN (
        SELECT t.product_id
        FROM Sales t
        WHERE t.sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31 23:59:59'
    );
SELECT p.product_id, p.product_name
FROM Product p
WHERE EXISTS (
        SELECT 1
        FROM Sales s
        WHERE s.product_id = p.product_id
            AND s.sale_date BETWEEN '2019-01-01' AND '2019-03-31 23:59:59'
    )
    AND NOT EXISTS (
        SELECT 1
        FROM Sales s
        WHERE s.product_id = p.product_id
            AND s.sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31 23:59:59'
    )