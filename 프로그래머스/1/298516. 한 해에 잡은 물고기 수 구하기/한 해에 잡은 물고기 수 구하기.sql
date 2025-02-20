select count(*) as FISH_COUNT

from fish_info as fi

where year(fi.time) = 2021;