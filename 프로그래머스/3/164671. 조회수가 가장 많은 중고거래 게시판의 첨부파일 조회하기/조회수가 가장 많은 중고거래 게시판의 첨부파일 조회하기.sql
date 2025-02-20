SELECT CONCAT('/home/grep/src/', ub.board_id, '/', uf.file_id, uf.file_name, uf.file_ext) AS FILE_PATH
FROM USED_GOODS_BOARD AS ub
JOIN USED_GOODS_FILE AS uf ON ub.board_id = uf.board_id
WHERE ub.board_id = (
    SELECT ub2.board_id
    FROM USED_GOODS_BOARD AS ub2
    ORDER BY ub2.VIEWS DESC
    LIMIT 1
)
ORDER BY uf.file_id DESC;