
SELECT ai.animal_id , ai.name,
        case
        when ai.sex_upon_intake like '%Neutered%' then 'O'
        when ai.sex_upon_intake like '%Spayed%' then 'O'
        else 'X'
        end
        as '중성화'

from animal_ins as ai

order by ai.animal_id asc;