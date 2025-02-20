select ii.item_id , ii.item_name , ii.RARITY

from item_info as ii

where  ii.item_id in ( select it.item_id                   
                      from item_tree as it
                        where it.PARENT_ITEM_ID in (
                                                select ii2.item_id
                                                from item_info as ii2
                                                where ii2.rarity = 'rare'
                                                
                                            )
                                           )
                                          
order by ii.item_id desc;