#include "mng.h"

int main()
{
	int select;
	int bun;

	one();

	while (1)
	{
		printf("���ϴ� �۾��� �����ϼ���. ����(1), �ε�(2), ���(3), ����(4), ����(5), ����(6), ����(7), �ʱⰪ(8), ����(99) : ");
		scanf_s("%d", &select);

		if ((select < 1 || select>8) && (select != 99))					//��ȣ�� �Է��ϴ� ������ �ٸ� ��� �����˻�
		{
			printf("�߸� �����ϼ̽��ϴ�. �ٽ� ����ּ���\n");
		}

		switch (select)													//select�� ���ϴ� �۾� ��ȣ�� �ް� ����
		{
		case 1:
			Save();														//����
			break;

		case 2:
			Load(0);														//�ε�
			break;

		case 3:
			print();													//���
			break;

		case 4:															//����
			Jung();
			break;

		case 5:															//����
			in();
			break;

		case 6:															//����
			sak();
			break;

		case 7:															//����
		{
			printf("�̸�(1), ����(2) �� ���ϴ� ���Ĺ� �Ѱ����� ��� ��ȣ�� �����ּ��� : ");
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

		case 99:														//����
			system("cls");
			printf("�ƹ�Ű�� ������ ����˴ϴ�.");
			_getch();
			free(data);
			return 0;
		}
	}
}