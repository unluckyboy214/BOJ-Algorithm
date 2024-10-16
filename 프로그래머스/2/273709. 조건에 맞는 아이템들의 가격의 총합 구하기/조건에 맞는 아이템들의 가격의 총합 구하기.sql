-- 코드를 작성해주세요
select sum(Price) 'TOTAL_PRICE'
from ITEM_INFO
where rarity = 'LEGEND';