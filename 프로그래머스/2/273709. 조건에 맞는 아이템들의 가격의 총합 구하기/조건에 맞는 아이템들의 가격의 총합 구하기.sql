SELECT SUM(PRICE) AS TOTAL_PRICE

from item_info as ii

where ii.RARITY = 'LEGEND'