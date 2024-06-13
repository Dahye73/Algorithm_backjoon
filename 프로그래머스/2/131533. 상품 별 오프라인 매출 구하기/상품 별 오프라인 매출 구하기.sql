-- 문제요약 : 상품코드 별 매출액(판매가 * 판매량) 합계를 출력
-- 정렬 : 매출액을 기준으로 내림차순 정렬 -> 상품코드 기준으로 오름차순 정렬

-- 과정 
-- 1. 테이블 조인(조인키 : PRODUCT_ID)
-- 2. 상품 코드로 그룹화 그룹화 


SELECT P.PRODUCT_CODE, SUM(P.PRICE * O.SALES_AMOUNT) AS SALES
FROM PRODUCT P
JOIN OFFLINE_SALE O
ON P.PRODUCT_ID = O.PRODUCT_ID 
GROUP BY P.PRODUCT_ID
ORDER BY SALES DESC, P.PRODUCT_CODE
