# Write your MySQL query statement below
select E.name , B.bonus
from Employee as E 
left Join Bonus as B
on E.empId = B.empID 
where B.bonus is Null or B.bonus<1000;