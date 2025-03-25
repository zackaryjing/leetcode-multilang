SELECT p.product_name,
    s.year,
    s.price -- prbllem: product-sales-analysis-i
FROM product p
    JOIN Sales s ON p.product_id = s.product_id