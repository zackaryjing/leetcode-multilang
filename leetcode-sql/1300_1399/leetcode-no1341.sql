-- problem: https://leetcode.cn/problems/movie-rating/

(SELECT u.name results
 FROM (SELECT COUNT(*) cnt, m.user_id user_id
       FROM MovieRating m
       GROUP BY m.user_id) AS temp
          LEFT JOIN users u
                    ON u.user_id = temp.user_id
 ORDER BY temp.cnt DESC, u.name LIMIT 1)

UNION ALL

(SELECT mv.title results
 FROM (SELECT AVG(m.rating) rating, m.movie_id movie_id
       FROM MovieRating m
       WHERE m.created_at between '2020-02-01' AND '2020-02-29'
       GROUP BY m.movie_id) AS temp
          LEFT JOIN Movies mv
                    ON mv.movie_id = temp.movie_id
 ORDER BY temp.rating DESC, mv.title LIMIT 1);


-- Created by Zackary37 at 6/10/2025 7:56 PM
