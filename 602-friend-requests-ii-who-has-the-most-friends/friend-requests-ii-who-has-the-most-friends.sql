# Write your MySQL query statement below
with f_count as (
select requester_id as id from RequestAccepted
union all
select accepter_id  from RequestAccepted
) 


select id,count(*) as num
from f_count
group by id
order by num desc
limit 1;







