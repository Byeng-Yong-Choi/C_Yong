#include "mng.h"

int main()
{
	int select;
	int bun;

	one();

	while (1)
	{
		printf("원하는 작업을 선택하세요. 저장(1), 로드(2), 출력(3), 수정(4), 삽입(5), 삭제(6), 정렬(7), 초기값(8), 종료(99) : ");
		scanf_s("%d", &select);

		if ((select < 1 || select>8) && (select != 99))					//번호를 입력하는 범위와 다를 경우 오류검사
		{
			printf("잘못 선택하셨습니다. 다시 골라주세요\n");
		}

		switch (select)													//select에 원하는 작업 번호를 받고 실행
		{
		case 1:
			Save();														//저장
			break;

		case 2:
			Load(0);														//로드
			break;

		case 3:
			print();													//출력
			break;

		case 4:															//수정
			Jung();
			break;

		case 5:															//삽입
			in();
			break;

		case 6:															//삭제
			sak();
			break;

		case 7:															//정렬
		{
			printf("이름(1), 총점(2) 중 원하는 정렬법 한가지를 골라 번호를 적어주세요 : ");
			scanf_s("%d", &bun);
			switch (bun)
			{
			case 1:
				Name();
				break;

			case 2:
				Num();
				break;
			}
			break;
		}
		
		case 8:
			Load(1);
			break;

		case 99:														//종료
			system("cls");
			printf("아무키나 누르면 종료됩니다.");
			_getch();
			free(data);
			return 0;
		}
	}
}