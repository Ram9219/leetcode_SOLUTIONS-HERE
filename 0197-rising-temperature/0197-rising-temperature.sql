# Write your MySQL query statement belowSELECT
SELECT today.id FROM WEATHER today join weather yesterday on datediff(today.recordDate,yesterday.recorddate)=1
where today.temperature>yesterday.temperature;