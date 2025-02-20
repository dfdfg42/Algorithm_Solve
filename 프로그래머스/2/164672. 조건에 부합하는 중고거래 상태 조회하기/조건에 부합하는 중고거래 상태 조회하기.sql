-- 코드를 입력하세요
SELECT ub.board_id, ub.writer_id, ub.title, ub.price ,
        case
        when ub.status = 'SALE' then '판매중'
        when ub.status = 'RESERVED' then '예약중'
        else  '거래완료'
        end
        as STATUS

from USED_GOODS_BOARD as ub

where ub.created_date = '2022-10-05'

order by ub.board_id desc;