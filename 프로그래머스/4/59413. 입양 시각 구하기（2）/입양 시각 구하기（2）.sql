WITH RECURSIVE hour_24 AS (
    SELECT 0 AS hr
    UNION ALL
    SELECT hr + 1
      FROM hour_24
     WHERE hr < 23
)
SELECT hour_24.hr AS HOUR, 
       COALESCE(a.cnt, 0) AS COUNT
  FROM hour_24
  LEFT JOIN (
      SELECT HOUR(DATETIME) AS hour_in_data,
             COUNT(*) AS cnt
        FROM ANIMAL_OUTS
       GROUP BY HOUR(DATETIME)
  ) a
    ON hour_24.hr = a.hour_in_data
 ORDER BY hour_24.hr;