#include <stdio.h.>
#include <stdlib.h>

int stringcmp(char *str1, char *str2)
{
	int a = 0;
	int b = 0;
	int c;
	int i, j;

	while (str1[a++] != 0);						//글자의 갯수를 계산
	while (str2[b++] != 0);

	c = a > b ? a : b;							//두 문자열을 비교해야 하므로 더 긴 문장의 수를 받는중

	for (i = 0; i < c; i++)						//글자를 앞에서부터 순서대로 비교하기 위한 반복문
	{
		if (str1[i] > str2[i])					//str1이 st2보다 크면 1을 반환
		{
			return 1;
		}

		else if (str1[i] < str2[i])				//str1이 str2보다 작으면 -1을 반환
		{
			return -1;
		}
	}
	return 0;									//str1과 str2를 모두 비교해서 다 같았을 경우 0을 반환
}

int stringicmp(char *str1, char *str2)			//stricmp구현 함수 대소문자 구분없이 비교
{
	int a = 0;
	int b = 0;
	int c;
	int i, j;

	while (str1[a++] != 0);
	while (str2[b++] != 0);

	c = a > b ? a : b;							//두 문자열을 비교해야 하므로 더 긴 문장의 수를 받는중

												//stricmp구현
	for (j = 0; j < c; j++)
	{
		if (96 < str1[j] && str1[j] < 123)		//소문자를 대문자로 변환
			str1[j] -= 32;

		if (96 < str2[j] && str2[j] < 123)
			str2[j] -= 32;
	}

	for (i = 0; i < c; i++)						//글자를 앞에서부터 순서대로 비교하기 위한 반복문
	{
		if (str1[i] > str2[i])					//str1이 st2보다 크면 1을 반환
		{
			return 1;
		}

		else if (str1[i] < str2[i])				//str1이 str2보다 작으면 -1을 반환
		{
			return -1;
		}
	}
	return 0;									//str1과 str2를 모두 비교해서 다 같았을 경우 0을 반환
}



int main()
{
	char ary1[] = "abcore";
	char ary2[] = "ABDORE";

	/*															//입력받아 문자열을 비교하는 코드
	char ary1[30] = { 0, };
	char ary2[30] = { 0. };

	printf("문자열 비교를 원하는 첫번째 문자열을 쓰시오 : ");
	fgets(ary1, sizeof(ary1) / sizeof(ary1[0]), stdin);
	printf("문자열 비교를 원하는 두번째 문자열을 쓰시오 : ");
	fgets(ary2, sizeof(ary2) / sizeof(ary2[0]), stdin);
	*/


	printf("strcmp(ary1, ary2)의 값 : %d\n", stringcmp(ary1, ary2));
	printf("stricmp(ary1, ary2)의 값 : %d\n", stringicmp(ary1, ary2));
}