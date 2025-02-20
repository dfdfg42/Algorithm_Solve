SELECT 
    f.order_id, 
    f.product_id, 
    DATE_FORMAT(f.out_date, '%Y-%m-%d') AS out_date,
    CASE
        WHEN f.out_date IS NULL THEN '출고미정'
        WHEN f.out_date <= '2022-05-01' THEN '출고완료'
        ELSE '출고대기'
    END AS 출고여부
FROM food_order AS f
ORDER BY f.order_id ASC;
