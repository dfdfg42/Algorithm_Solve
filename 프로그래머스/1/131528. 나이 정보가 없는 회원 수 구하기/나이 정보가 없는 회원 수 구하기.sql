-- 코드를 입력하세요
SELECT count(*) as 'USERS'

from user_info as ui

group by ui.age

having ui.age is null