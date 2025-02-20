-- 코드를 입력하세요
SELECT cr.car_id, cr.car_type, cr.daily_fee, cr.options

from car_rental_company_car as cr

where cr.options like '%네비게이션%'

order by cr.car_id desc;