# Write your MySQL query statement below
SELECT  x  , y  , z ,
IF ( 
( 
    IF((x+y)>z ,1 ,0)
    AND
    IF((y+z)>x ,1 ,0)
    AND
    IF((z+x)>y ,1 ,0)
)
    = 1 
    , 'Yes' , 'No')    as triangle  

    FROM 
    Triangle;