SELECT name AS Customers
FROM Customers c
LEFT JOIN Orders o ON c.id = o.customerID
WHERE o.customerID IS NULL;