SELECT
    PT_NAME,
    PT_NO,
    GEND_CD,
    AGE,
    COALESCE(TLNO, 'NONE') AS TLNO  -- 전화번호가 NULL이면 'NONE'을 반환
FROM
    PATIENT
WHERE
    AGE <= 12       -- 12세 이하
    AND GEND_CD = 'W'  -- 여자 환자
ORDER BY
    AGE DESC,        -- 나이를 기준으로 내림차순 정렬
    PT_NAME ASC;     -- 나이가 같다면 이름을 기준으로 오름차순 정렬
