-- problem: https://leetcode.cn/problems/students-and-examinations/submissions/615206543/ 
select s.student_id,s.student_name, b.subject_name, coalesce(t.cnt,0) as attended_exams
from students s
cross join subjects b
left join (select e.student_id,e.subject_name, count(*) as cnt from examinations e group by e.student_id, e.subject_name) as t on t.student_id = s.student_id and b.subject_name = t.subject_name
order by s.student_id,b.subject_name