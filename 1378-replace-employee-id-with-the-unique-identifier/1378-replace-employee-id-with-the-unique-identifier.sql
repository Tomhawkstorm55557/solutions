# Write your MySQL query statement below
#1378. Replace Employee ID With The Unique Identifier
#Write a solution to show the unique ID of each user, If a user does not have a unique ID replace just show null.

#Return the result table in any order.
#so we have two tables
# replace id with 
#we will left join 
SELECT
    EmployeeUNI.unique_id,
    Employees.name
FROM
    Employees
LEFT JOIN
    EmployeeUNI
ON
    EmployeeUNI.id = Employees.id
