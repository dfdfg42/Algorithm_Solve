-- 코드를 입력하세요
SELECT substr(p.product_code ,1, 2) as CATEGORY , count(*) as PRODUCTS

from product as p

group by  substr(p.product_code ,1, 2)

order by substr(p.product_code , 1,2);