-- # Write your MySQL query statement below
-- SELECT *
-- FROM Employees reports_to
-- WHERE reports_to IS NOT NULL;

SELECT e1.employee_id , e1.name , count(*) as reports_count , round(avg(e2.age)) as average_age 
FROM Employees e1
JOIN Employees e2
ON e1.employee_id = e2.reports_to
GROUP BY e1.employee_id
ORDER BY e1.employee_id; 
-- WHERE reports_to IS NOT NULL;
