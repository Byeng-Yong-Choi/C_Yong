#include <stdio.h.>
#include <stdlib.h>

int stringcmp(char *str1, char *str2)
{
	int a = 0;
	int b = 0;
	int c;
	int i, j;

	while (str1[a++] != 0);						//������ ������ ���
	while (str2[b++] != 0);

	c = a > b ? a : b;							//�� ���ڿ��� ���ؾ� �ϹǷ� �� �� ������ ���� �޴���

	for (i = 0; i < c; i++)						//���ڸ� �տ������� ������� ���ϱ� ���� �ݺ���
	{
		if (str1[i] > str2[i])					//str1�� st2���� ũ�� 1�� ��ȯ
		{
			return 1;
		}

		else if (str1[i] < str2[i])				//str1�� str2���� ������ -1�� ��ȯ
		{
			return -1;
		}
	}
	return 0;									//str1�� str2�� ��� ���ؼ� �� ������ ��� 0�� ��ȯ
}

int stringicmp(char *str1, char *str2)			//stricmp���� �Լ� ��ҹ��� ���о��� ��
{
	int a = 0;
	int b = 0;
	int c;
	int i, j;

	while (str1[a++] != 0);
	while (str2[b++] != 0);

	c = a > b ? a : b;							//�� ���ڿ��� ���ؾ� �ϹǷ� �� �� ������ ���� �޴���

												//stricmp����
	for (j = 0; j < c; j++)
	{
		if (96 < str1[j] && str1[j] < 123)		//�ҹ��ڸ� �빮�ڷ� ��ȯ
			str1[j] -= 32;

		if (96 < str2[j] && str2[j] < 123)
			str2[j] -= 32;
	}

	for (i = 0; i < c; i++)						//���ڸ� �տ������� ������� ���ϱ� ���� �ݺ���
	{
		if (str1[i] > str2[i])					//str1�� st2���� ũ�� 1�� ��ȯ
		{
			return 1;
		}

		else if (str1[i] < str2[i])				//str1�� str2���� ������ -1�� ��ȯ
		{
			return -1;
		}
	}
	return 0;									//str1�� str2�� ��� ���ؼ� �� ������ ��� 0�� ��ȯ
}



int main()
{
	char ary1[] = "abcore";
	char ary2[] = "ABDORE";

	/*															//�Է¹޾� ���ڿ��� ���ϴ� �ڵ�
	char ary1[30] = { 0, };
	char ary2[30] = { 0. };

	printf("���ڿ� �񱳸� ���ϴ� ù��° ���ڿ��� ���ÿ� : ");
	fgets(ary1, sizeof(ary1) / sizeof(ary1[0]), stdin);
	printf("���ڿ� �񱳸� ���ϴ� �ι�° ���ڿ��� ���ÿ� : ");
	fgets(ary2, sizeof(ary2) / sizeof(ary2[0]), stdin);
	*/


	printf("strcmp(ary1, ary2)�� �� : %d\n", stringcmp(ary1, ary2));
	printf("stricmp(ary1, ary2)�� �� : %d\n", stringicmp(ary1, ary2));
}