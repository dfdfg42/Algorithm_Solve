SELECT
    cr.HISTORY_ID,
    cr.CAR_ID,
    DATE_FORMAT(cr.START_DATE, '%Y-%m-%d') AS START_DATE,
    DATE_FORMAT(cr.END_DATE, '%Y-%m-%d') AS END_DATE,
    CASE
        WHEN DATEDIFF(cr.END_DATE, cr.START_DATE) +1 >= 30 THEN '장기 대여'
        ELSE '단기 대여'
    END AS RENT_TYPE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY cr
WHERE YEAR(cr.START_DATE) = 2022
  AND MONTH(cr.START_DATE) = 9
ORDER BY cr.HISTORY_ID DESC;