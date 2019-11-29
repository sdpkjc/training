select to_date(to_char( to_date('2019-02-11', 'yyyy-mm-dd') + interval '1'
month, 'yyyy-mm'), 'yyyy-mm') 
- to_date
(to_char
(to_date
('2019-02-11', 'yyyy-mm-dd') , 'yyyy-mm'), 'yyyy-mm') from dual; 

to_date
('2019-02-11', 'yyyy-mm-dd') 