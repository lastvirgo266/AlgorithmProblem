set @hour := -1;
SELECT 
    (@hour := @hour + 1) as 'HOUR',
    (select count(*) from animal_outs where hour(datetime) = @hour) as 'COUNT'
from 
    animal_outs
where
    @hour < 23;

--다시 공부해야함