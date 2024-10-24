-- 코드를 입력하세요
SELECT BOOK_ID , AUTHOR_NAME,DATE_FORMAT(PUBLISHED_DATE,'%Y-%m-%d') 

from BOOK join AUTHOR 
    on book.author_id = AUTHOR.author_id


where category = '경제'

order by published_date asc ;
