-- https://leetcode.cn/problems/article-views-i/description/ 
SELECT DISTINCT author_id as id
FROM Views
WHERE author_id = viewer_id
ORDER BY author_id