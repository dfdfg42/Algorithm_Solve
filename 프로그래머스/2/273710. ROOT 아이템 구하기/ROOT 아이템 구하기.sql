select ii.item_id, ii.item_name

from item_info as ii

where ii.item_id in (select it.item_id
                     from item_tree as it
                    where it.parent_item_id is null)