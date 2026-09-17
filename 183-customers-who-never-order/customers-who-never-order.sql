# Write your MySQL query statement below
 SELECT Name AS Customers  #creates new column named Customers
FROM Customers
WHERE id NOT IN (  
    SELECT CustomerId FROM Orders
);