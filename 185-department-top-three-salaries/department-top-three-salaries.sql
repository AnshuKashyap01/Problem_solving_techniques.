# Write your MySQL query statement below
select Department , Employee , Salary from
(SELECT d.name as Department , e.name as Employee ,e.salary as Salary,
       DENSE_RANK() OVER (
           PARTITION BY d.id
           ORDER BY e.salary DESC
       ) AS ranking
FROM Employee AS e
INNER JOIN Department AS d
ON e.departmentId = d.id) as top
where ranking<=3;

