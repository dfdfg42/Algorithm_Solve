-- 코드를 입력하세요
SELECT cr.car_id

from CAR_RENTAL_COMPANY_CAR as cr 

where cr.car_type ='세단' and cr.car_id in (select ch.car_id
                                          from CAR_RENTAL_COMPANY_RENTAL_HISTORY as ch
                                          where month(ch.start_date)= 10
                                                )
                                                
order by cr.car_id desc