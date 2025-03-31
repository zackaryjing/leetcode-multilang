-- https://leetcode.cn/problems/tree-node/submissions/615733043/ 
SELECT t.id,
    CASE
        WHEN t.p_id is NULL THEN 'Root'
        WHEN t.id NOT IN (
            SELECT p_id
            FROM Tree
            WHERE p_id IS NOT NULL
        ) THEN 'Leaf'
        ELSE 'Inner'
    END as type
FROM Tree t;
---
---
---
SELECT DISTINCT t.id,
    CASE
        WHEN t.p_id is NULL THEN 'Root'
        WHEN p.p_id IS NULL THEN 'Leaf'
        Else 'Inner'
    END as type
From tree t
    LEFT JOIN tree p on t.id = p.p_id;
---
---
---
SELECT t.id,
    CASE
        WHEN t.p_id is NULL THEN 'Root'
        WHEN t.id IN (
            SELECT p_id
            FROM Tree
            WHERE p_id IS NOT NULL
        )
        AND t.p_id is not null THEN 'Inner'
        ELSE 'Leaf'
    END as type
FROM Tree t;