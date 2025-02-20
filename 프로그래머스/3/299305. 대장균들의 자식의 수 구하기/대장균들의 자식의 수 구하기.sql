with t as (
    select ed.parent_id as parent , count(*) as count
    from ecoli_data as ed
    group by ed.parent_id
    
)

select ed1.id , case
                when count is null then 0
                else count
                end
                as child_count

from ecoli_data as ed1 left join t on ed1.id = t.parent

