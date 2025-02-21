with t as (
    
    select rr.member_id , mp.member_name
    
    from rest_review as rr join member_profile as mp on rr.member_id = mp.member_id
    
    group by rr.member_id
    
    order by count(*) desc
    
    limit 1
)

SELECT t.member_name , r.review_text , DATE_FORMAT(r.review_date,'%Y-%m-%d') as review_date

from rest_review as r  join t on r.member_id = t.member_id

where r.member_id = t.member_id

order by   r.review_date ASC,
    r.review_text ASC;
