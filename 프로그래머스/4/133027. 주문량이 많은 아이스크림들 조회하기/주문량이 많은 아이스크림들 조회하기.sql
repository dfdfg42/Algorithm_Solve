with t as(
    select j.flavor , sum(j.total_order) as total
    
    from july as j
    
    group by j.flavor
)


SELECT f.flavor

from first_half as f join t on  f.flavor = t.flavor

group by f.flavor

order by sum(f.total_order + t.total) desc

limit 3;
