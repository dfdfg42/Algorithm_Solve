SELECT
    MONTH(cr.start_date) AS MONTH,
    cr.car_id,
    COUNT(*) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY AS cr
-- 8월 1일부터 10월 말까지만
WHERE cr.start_date >= '2022-08-01'
  AND cr.start_date <  '2022-11-01'
  -- 5회 이상 대여된 자동차의 CAR_ID만 서브쿼리로 필터링
  AND cr.car_id IN (
    SELECT car_id
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE start_date >= '2022-08-01'
      AND start_date <  '2022-11-01'
    GROUP BY car_id
    HAVING COUNT(*) >= 5
  )
GROUP BY
    MONTH(cr.start_date),
    cr.car_id
ORDER BY
    MONTH(cr.start_date) ASC,  -- 월 오름차순
    cr.car_id DESC;            -- CAR_ID 내림차순
