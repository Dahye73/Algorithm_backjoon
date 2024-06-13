-- 테이블
-- MEMBER_PROFILE : 고객의 정보
-- REST_REVIEW : 식당의 리뷰 정보

-- 문제 요약 : 리뷰를 가장 많이 작성한 회원의 리뷰들을 조회
-- 출력 값 :  회원이름(MEMBER_NAME), 리뷰 텍스트(REVIEW_TEXT), 리뷰 작성일(REVIEW_DATE)
-- 조건 : 리뷰 작성일 기준으로 오름차순 -> 리뷰 텍스트 기준으로 오름차순

-- 과정
-- 1. 테이블 조인 : 조인키(MEMBER_ID)
-- 2. 리뷰를 가장 많이 작성한 회원을 조회하는 서브 쿼리 작성
-- 3. 서브 쿼리에서 조회된 회원의 아이디를 사용하여 해당 회원의 리뷰들 조회
-- 4. 오름차순 정렬 


WITH REVIEW_MAX_MEMBER AS (
    SELECT M.MEMBER_NAME, R.MEMBER_ID
    FROM REST_REVIEW R
    JOIN MEMBER_PROFILE M
    ON R.MEMBER_ID = M.MEMBER_ID
    GROUP BY R.MEMBER_ID
    ORDER BY SUM(R.REVIEW_SCORE) DESC
    LIMIT 1
)

SELECT M.MEMBER_NAME, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, "%Y-%m-%d") AS REVIEW_DATE
FROM REST_REVIEW R
JOIN REVIEW_MAX_MEMBER M
ON R.MEMBER_ID = M.MEMBER_ID
ORDER BY REVIEW_DATE, REVIEW_TEXT

