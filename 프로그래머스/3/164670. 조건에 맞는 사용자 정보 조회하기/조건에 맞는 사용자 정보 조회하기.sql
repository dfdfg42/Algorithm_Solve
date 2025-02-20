SELECT u.user_id,u.nickname, concat(u.city,' ',u.street_address1,' ',u.street_address2) as 전체주소 ,
        concat(substr(u.tlno,1,3) ,'-',substr(u.tlno,4,4) ,'-',substr(u.tlno,8,4)) as 전화번호

from USED_GOODS_USER as u

where u.user_id in ( select ub.writer_id
                      from USED_GOODS_BOARD ub
                     group by ub.writer_id
                     having count(*)>=3)
                     
order by u.user_id desc;