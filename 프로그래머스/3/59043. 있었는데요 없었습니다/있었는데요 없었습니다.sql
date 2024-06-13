-- 테이블
-- ANIMAL_INS : 동물 보호소에 들어온 동물의 정보
-- ANIMAL_OUTS : 동물 보호소에서 입양 보낸 동물의 정보

-- 문제 요약 : 보호 시작일보다 입양일이 더 빠른 동물의 아이디와 이름을 조회
-- 정렬 : 보호 시작일이 빠른 순으로 조회
-- 출력 : ALIMAL_ID, NAME

-- 과정
-- 1. 테이블 조인 (조인키 : ANIMAL_ID)
-- 2. 날짜 비교
-- 3. 

SELECT AI.ANIMAL_ID, AI.NAME
FROM ANIMAL_INS AI, ANIMAL_OUTS AO
WHERE AI.ANIMAL_ID = AO.ANIMAL_ID AND AO.DATETIME < AI.DATETIME
ORDER BY AI.DATETIME