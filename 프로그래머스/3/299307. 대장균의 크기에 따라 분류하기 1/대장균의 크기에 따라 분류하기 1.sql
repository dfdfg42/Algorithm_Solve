select ed.id,
        case
        when ed.size_of_colony <=100 then 'LOW'
        when ed.size_of_colony >100 and ed.size_of_colony <=1000 then 'MEDIUM'
        else 'HIGH'
        end 
        as SIZE

from ecoli_data as ed

