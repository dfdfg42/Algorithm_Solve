-- 코드를 입력하세요
SELECT ai.animal_id, ai.name

FROM ANIMAL_INS as ai

where ai.name like '%EL%' and ai.animal_type = 'Dog'

order by ai.name asc