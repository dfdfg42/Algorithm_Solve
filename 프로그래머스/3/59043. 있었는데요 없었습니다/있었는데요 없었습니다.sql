-- 코드를 입력하세요
SELECT ai.animal_id , ai.name

FROM ANIMAL_INS as ai join   ANIMAL_OUTS ao  on ai.animal_id = ao.animal_id

where ai.datetime > ao.datetime

order by ai.datetime asc;