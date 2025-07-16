# Write your MySQL query statement below
-- SELECT employee_id, department_id
-- FROM Employee 
-- GROUP BY employee_id
-- HAVING
--  count(department_id) = 1 
-- OR  
--  primary_flag = 'Y';   

SELECT e1.employee_id , IFNULL(e2.department_id , e1.department_id) as department_id 
    FROM Employee  e1
    LEFT JOIN
(SELECT employee_id , department_id 
FROM Employee WHERE primary_flag = 'Y')  as e2
    ON e1.employee_id  = e2.employee_id 
    GROUP BY e1.employee_id , e2.department_id ;
