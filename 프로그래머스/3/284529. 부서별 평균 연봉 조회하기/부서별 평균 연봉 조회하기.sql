select hd.dept_id , hd.dept_name_en, round(avg(sal)) as avg_sal

from HR_DEPARTMENT as hd join HR_EMPLOYEES as he on hd.dept_id = he.dept_id


group by hd.dept_id

order by  round(avg(sal)) desc;