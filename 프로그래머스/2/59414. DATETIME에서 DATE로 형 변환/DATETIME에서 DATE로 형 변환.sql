SELECT ai.animal_id , ai.name,date_FORMAT(ai.datetime, '%Y-%m-%d') as 날짜

from animal_ins as ai

order by ai.animal_id