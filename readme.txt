make 방법
make main: 일반실행파일
make main_debug: debug option이 define된 실행파일

실행파일 실행방법
./main
./main_debug

프로그램 설명: 배달음식점의 정보를 관리하는 프로그램 입니다
1. brand: 배달음식점 brand의 이름
2. category: 배달음식점 brand의 음식 종류 ex)한식, 중식, 치킨
3. phone_number: 배달음식점의 전화번호
4. main_menu: 배달음식점의 대표메뉴
5. price: 대표메뉴의 가격
6. evaluation: 해당 brand에 대한 평가


메인메뉴설명
1. Create: 새로운 정보를 생성한다
2. Read: 원하는 brand 이름을 입력하고 해당 brand의 정보를 읽어온다
3. Update: Update를 실행하면 3가지 옵션 중 한가지를 선택할 수 있다
	a. 원하는 brand 이름을 입력하고 해당 brand의 정보만 update 한다
	b. 원하는 category를 입력하고 그  category에 해당하는 모든 brand의 정보를 update한다
	c. 현재 저장되어있는 모든 브랜드들의 정보를 update한다
4. Delete: Delete를 실행하면 3가지 옵션 중 한가지를 선택할 수 있다
	a. 원하는 brand 이름을 입력하고 해당 brand의 정보만 delete 한다
	b. 원하는 category를 입력하고 그  category에 해당하는 모든 brand의 정보를 delete한다
	c. 현재 저장되어있는 모든 브랜드들의 정보를 delete한다
	(모든 옵션에 조각모음 자동 실행)
5. List: 현재 저장되어 있는 모든 정보를 출력한다
6. Search by category: 저장되어있는 정보 중 입력받은 category가 포함된 모든 brand의 정보를 출력한다
7. Search by evaluation: 저장되어있는 정보 중 입력받은 evaluation이 포함된 모든 brand의 정보를 출력한다
8. Search by price range: 시작가격과 끝가격을 입력받고 메인메뉴의 가격이 입력받은 가격대 사이에 존재하는 모든 브랜드들의 정보를 출력한다
9. Load: brands.txt에 저장되어있는 브랜드들의 정보를 가져온다
10. Save: 현재 저장되어있는 정보를 brands.txt에 저장한다
11. category, price range, evaluation 세가지를 기준으로 저장되어있는 정보 중 각각 몇개의 brands가 있는지 보여주는 보고서의 형식으로 출력하고 이를 report.txt 파일에 저장한다
12. Sort by price: 저장되어있는 정보를 가격이 brand부터 높은 brand  순으로 재배열 한다

