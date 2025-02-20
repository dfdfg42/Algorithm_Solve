SELECT 
    a.apnt_no, 
    p.pt_name, 
    p.pt_no, 
    a.mcdp_cd, 
    d.dr_name, 
    a.apnt_ymd
FROM APPOINTMENT AS a
JOIN PATIENT AS p 
  ON a.pt_no = p.pt_no
JOIN DOCTOR AS d 
  ON a.mddr_id = d.dr_id
WHERE a.mcdp_cd = 'CS'                      -- 진료과 코드가 'CS'(흉부외과)
  AND DATE(a.apnt_ymd) = '2022-04-13'       -- 2022년 4월 13일 예약
  AND a.apnt_cncl_yn = 'N'                  -- 취소되지 않은 예약
ORDER BY a.apnt_ymd ASC;                    -- 진료예약일시 기준 오름차순 정렬
