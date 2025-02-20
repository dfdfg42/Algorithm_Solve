SELECT ai.animal_id, ai.name

from animal_ins as ai join animal_outs as ao on ai.animal_id = ao.animal_id


order by datediff(ao.dateTime ,ai.datetime) desc

limit 2;