# Write your MySQL query statement below
select p.product_id, round(ifnull(SUM(p.price*u.units) /SUM(u.units),0),2) AS average_price
from Prices as p
left join UnitsSold as u 
On p.product_id = u.product_id and u.purchase_date<=p.end_date and u.purchase_date>=p.start_date
group by p.product_id;
