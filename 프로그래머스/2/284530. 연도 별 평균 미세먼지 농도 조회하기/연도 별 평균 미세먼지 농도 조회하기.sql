select year(ap.YM) as YEAR, round( avg(ap.PM_VAL1),2) as 'PM10' , round(avg(ap.PM_VAL2),2) as 'PM2.5'

from AIR_POLLUTION as ap 

where location2 = '수원' and location1 = '경기도'

group by year(ap.YM)

order by year(ap.YM) asc;