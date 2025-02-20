-- 코드를 입력하세요
SELECT ai.animal_type,
        case 
        when ai.name is null then 'No name'
        else ai.name
        end
        , ai.sex_upon_intake

from ANIMAL_INS as ai

