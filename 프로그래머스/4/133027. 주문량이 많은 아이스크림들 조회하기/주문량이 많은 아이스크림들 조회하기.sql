-- 테이블
-- first_half : 상반기 주문 정보
-- july : 7월의 아이스크림 주문 정보

-- 문제 요약 : 7월 아이스크림 총 주문량과 상반기의 아이스크림 총 주문량을 더한 값이 큰 순서대로 상위 3개의 맛을 조회 

-- 1. 테이블 조인
-- 2. 맛(FLAVOR) 별로 그룹화
-- 3. 각 그룹(맛) 내에서 상반기 주문량(FIRST_HALF.TOTAL_ORDER)과 7월 주문량(JULY.TOTAL_ORDER)을 각각 합산
-- 4. 두 합산 값을 더한 총 주문량을 기준으로 내림차순 정렬
-- 5. 합산 값이 큰 순서대로 상위 3개의 맛 추출

SELECT F.FLAVOR
FROM FIRST_HALF F
JOIN JULY AS J
ON F.FLAVOR = J.FLAVOR
GROUP BY F.FLAVOR
ORDER BY(SUM(J.TOTAL_ORDER) + SUM(F.TOTAL_ORDER)) DESC
LIMIT 3
