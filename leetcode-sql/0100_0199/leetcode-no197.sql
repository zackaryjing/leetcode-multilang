SELECT id
FROM Weather w
WHERE w.temperature > (
    SELECT temperature
    FROM Weather
    WHERE recordDate = w.recordDate - INTERVAL 1 DAY
)

---------------

SELECT a.id 
FROM Weather a
JOIN Weather b on datediff(a.recordDate,b.recordDate) = 1
WHERE a.temperature > b.temperature;
