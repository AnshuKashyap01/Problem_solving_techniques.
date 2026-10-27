# Write your MySQL query statement 

with eligible as (
    select product_id , max(change_date) as change_date
    from Products 
    where change_date<='2019-08-16'
    group by product_id
)

select p.product_id , p.new_price as price
from Products as p
join eligible as e 
on p.product_id=e.product_id and p.change_date = e.change_date 

Union
select distinct product_id , 10 as price
from Products
where product_id not in (
    select product_id from eligible
);




