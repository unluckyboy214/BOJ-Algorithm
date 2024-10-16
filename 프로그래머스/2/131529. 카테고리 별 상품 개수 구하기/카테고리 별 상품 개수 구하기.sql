-- 코드를 입력하세요
SELECT substr(PRODUCT_CODE, 1,2) CATEGORY, count(PRODUCT_CODE) PRODUCTS
from product 
group by CATEGORY
order by CATEGORY;
