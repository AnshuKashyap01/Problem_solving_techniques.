# Write your MySQL query statement below
select Department , Employee , Salary from

(select d.name as Department  , e.name as Employee , e.salary as Salary , rank() over(partition by d.name  order by e.salary desc) as ranking 
from Employee as e 
left join Department as d 
on e.departmentId = d.id) as sal
 where ranking=1;
;
