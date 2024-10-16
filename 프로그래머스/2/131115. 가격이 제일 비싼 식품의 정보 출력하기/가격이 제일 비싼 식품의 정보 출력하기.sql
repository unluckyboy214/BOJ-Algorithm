-- 코드를 입력하세요
SELECT *
from FOOD_PRODUCT
where PRICE = (select max(Price) from FOOD_PRODUCT);