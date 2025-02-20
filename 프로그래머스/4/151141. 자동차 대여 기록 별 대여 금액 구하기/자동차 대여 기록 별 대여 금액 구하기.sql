WITH rental AS (
    SELECT
        rh.history_id,
        cc.daily_fee,
        DATEDIFF(rh.end_date, rh.start_date) + 1 AS rental_days
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY rh
    JOIN CAR_RENTAL_COMPANY_CAR cc
      ON rh.car_id = cc.car_id
    WHERE cc.car_type = '트럭'
)
SELECT
    r.history_id,
    round((r.daily_fee * r.rental_days * (100 - COALESCE(dp.discount_rate, 0))) / 100,0) AS fee
FROM rental r
LEFT JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN dp
  ON dp.car_type = '트럭'
  AND dp.duration_type = CASE 
        WHEN r.rental_days < 7 THEN NULL
        WHEN r.rental_days >= 7 AND r.rental_days < 30 THEN '7일 이상'
        WHEN r.rental_days >= 30 AND r.rental_days < 90 THEN '30일 이상'
        WHEN r.rental_days >= 90 THEN '90일 이상'
      END
ORDER BY fee DESC, r.history_id DESC;
