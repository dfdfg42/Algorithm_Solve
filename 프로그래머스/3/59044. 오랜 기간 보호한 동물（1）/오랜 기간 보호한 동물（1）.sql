SELECT ai.name AS NAME, ai.datetime AS DATETIME
FROM ANIMAL_INS AS ai
LEFT JOIN ANIMAL_OUTS AS ao ON ai.animal_id = ao.animal_id
WHERE ao.animal_id IS NULL
ORDER BY ai.datetime ASC
LIMIT 3;