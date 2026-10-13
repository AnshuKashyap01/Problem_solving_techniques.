# Write your MySQL query statement below
select q.query_name , round(avg(q.rating/q.position),2 )as quality , round((select count(p.rating) from Queries as p where p.rating<3 and q.query_name = p.query_name )*100/count(*),2)as poor_query_percentage
from Queries as q
group by q.query_name;


