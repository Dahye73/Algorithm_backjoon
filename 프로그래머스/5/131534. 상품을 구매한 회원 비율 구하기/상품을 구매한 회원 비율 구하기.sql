-- 테이블
-- USER_INFO : 가입한 회원 정보
-- ONLINE_SALE : 온라인 상품 판매 정보

-- 문제요약 : 2021년에 가입한 전체 회원들 중 상품을 구매한 회원 수와 상품을 구매한 회원의 비율을 년, 월 별로 출력
-- 조건 : 비율은 소수점 두번째자리에서 반올림
-- 정렬 : 년을 기준으로 오름차순 -> 월을 기준으로 오름차순

-- 과정
-- 1. 테이블 조인 (조인 키 : USER_ID)
-- 2. 가입 시기가 2021년인 사용자 필터링
-- 3. 연도와 월별로 그룹화 
--   - DATE_FORMAT 함수를 사용해서 SALES_DATE를 연도(YEAR)와 월(MONTH)로 변환 
-- 4. 각 그룹별로 구매한 사용자 수 계산
-- 5. 서브 쿼리를 사용해서 전체 2021년 가입 사용자 계산 후 비율 계산
-- 6. 정렬

SELECT DATE_FORMAT(O.SALES_DATE, '%Y') AS YEAR,
       DATE_FORMAT(O.SALES_DATE, '%m') AS MONTH,
       COUNT(DISTINCT U.USER_ID) AS PUCHASED_USERS,
       ROUND(COUNT(DISTINCT U.USER_ID)/( SELECT COUNT(*)
                                          FROM USER_INFO
                                          WHERE JOINED LIKE '2021%'),1)
            AS PUCHASED_RATIO 
FROM USER_INFO U
JOIN ONLINE_SALE O
ON U.USER_ID = O.USER_ID
WHERE U.JOINED LIKE '2021%'
GROUP BY YEAR, MONTH 
ORDER BY YEAR, MONTH
