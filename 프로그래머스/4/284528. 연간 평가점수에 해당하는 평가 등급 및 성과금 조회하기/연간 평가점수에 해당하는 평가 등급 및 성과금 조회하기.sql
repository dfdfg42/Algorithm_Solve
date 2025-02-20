WITH t AS (
    SELECT 
        hg.emp_no,
        CASE 
            WHEN AVG(hg.score) >= 96 THEN 'S'
            WHEN AVG(hg.score) >= 90 THEN 'A'
            WHEN AVG(hg.score) >= 80 THEN 'B'
            ELSE 'C'
        END AS grade,
        CASE 
            WHEN AVG(hg.score) >= 96 THEN 20
            WHEN AVG(hg.score) >= 90 THEN 15
            WHEN AVG(hg.score) >= 80 THEN 10
            ELSE 0
        END AS bonus_rate
    FROM hr_grade AS hg
    -- WHERE hg.year = 2022  -- 여러 년도 데이터가 있다면 이 조건 추가
    GROUP BY hg.emp_no
)
SELECT 
    he.emp_no AS EMP_NO,
    he.emp_name AS EMP_NAME,
    t.grade AS GRADE,
    -- 보너스: (보너스율) * (연봉) / 100
    (t.bonus_rate * he.sal / 100) AS BONUS
FROM hr_employees AS he
JOIN t 
    ON he.emp_no = t.emp_no
ORDER BY he.emp_no ASC;
