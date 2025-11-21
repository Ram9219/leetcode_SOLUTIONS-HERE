# Write your MySQL query statement below
select * from Person 
inner join Adress
 on
  Person.personId=Address.addressId;