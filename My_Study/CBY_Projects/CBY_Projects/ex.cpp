#include <stdio.h>

int ee(int a);
void swap(char *a, char*b, int i);

int main()
{
	int	sum = 0;
	int gg;
	int size;
	int i, j;
	int su = 0;
	int num;
	char a = 'A';
	char b = 'B';
	char c = 'C';

	printf("�� �Է�: ");
	scanf_s("%d", &size);

	for (i = 0; i < size; i++)
	{
		gg = 1;
		for (j = 0; j < i; j++)
		{
			gg *= 2;
		}
		sum += gg;
	}

	printf("Ƚ�� %d\n", sum);
	num = ee(size);

	for (i = 1 ;i < num+1 ;i++)
	{
		su = i % 3;
		switch (su)
		{
		case 0:										//���� 3��°
			swap(&b,&c,su+3);
			break;
			
		case 1:										//���� 1��°
			swap(&a, &c, su);
			break;
			
		case 2:										//���� 2��°
			swap(&a, &b, su);
			break;
		}

	}





}

int ee(int a)						// 2���� �ڸ����� ������ �ް� ��� 1�϶��� ��
{
	static int sum;
	if(a==1)
	{
		sum += 1;
		return sum;
	}
	
	sum += 2 * (ee(a-1)/2+1);
	return sum;
}
/*
1, 2^0
2, 2^0+2^1
3, 2^0+2^1+2^2
*/

void swap(char *a, char *b, int i)
{
	char temp;

	printf("%d�� %c -> %c\n", i, *a, *b);

	temp = *a;
	*a = *b;
	*b = temp;

}