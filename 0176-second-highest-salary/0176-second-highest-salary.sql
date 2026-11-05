# Write your MySQL query statement below
# Write your MySQL query statement below
(select salary as SecondHighestSalary
from Employee 
where salary <(select max(salary) from Employee)
order by salary desc
limit 1)
union 
select null as SecondHighestSalary from Employee having count(*)<2 or (select min(salary) from Employee)=(select max(salary) from Employee);