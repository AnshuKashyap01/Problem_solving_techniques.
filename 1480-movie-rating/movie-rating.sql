# Write your MySQL query statement below
(select u.name as results
from MovieRating as m 
inner join Users as u
on m.user_id = u.user_id 
group by m.user_id 
order by count(*) desc , u.name asc
limit 1)

union all

(select mov.title as results
from MovieRating as m
inner join movies as mov
on m.movie_id = mov.movie_id 
where m.created_at>='2020-02-01' and m.created_at <'2020-03-01' 
group by m.movie_id

order by avg(rating) desc,mov.title asc
limit 1 )

;