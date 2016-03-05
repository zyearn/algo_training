# Write your MySQL query statement below

select a.name 
from Employee as a inner join Employee as b on a.ManagerId== b.Id
where a.Salary > b.Salary
