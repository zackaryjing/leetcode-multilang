-- problem:project-employees-i 
SELECT p.project_id,
    Round(avg(experience_years), 2) AS average_years
FROM Project p
    LEFT JOIN Employee e on p.employee_id = e.employee_id
GROUP BY project_id