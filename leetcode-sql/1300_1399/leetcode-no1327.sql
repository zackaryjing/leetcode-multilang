-- problem: https://leetcode.cn/problems/list-the-products-ordered-in-a-period/submissions/615230433/ 
select p.product_name,
    sum(o.unit) as unit
from orders o
    left join products p on p.product_id = o.product_id
where o.order_date between '2020-02-01' and '2020-02-29'
group by o.product_id
having sum(o.unit) >= 100