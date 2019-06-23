#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
bool selectStr(char str[], int length)
{

	for (int i = 0; i < length; i++)
	{
		if (str[i] != 'A' && str[i] != 'P' && str[i] != 'T')
			return false;
		else
			return true;
	}
}
int main()

{
	int n;
	char str[101];
	scanf("%d", &n);
	while (n--)
	{
		memset(str, 0, 101);
		scanf("%s", str);
		int length = strlen(str);
		if (selectStr(str, length))
		{
			int lena = 0;
			int lenb = 0;
			int lenc = 0;
			for (int i = 0; i < length; i++)
			{
				if (str[i] != 'P')
					lena++;
				else
					break;
			}
			for (int i = 0, cnt = 0; i < length; i++)
			{
				if (str[i] != 'T')
					cnt++;
				else
				{
					lenb = cnt - lena - 1;
					lenc = length - cnt - 1;
					break;
				}

			}
			if (lenb == 0)
				printf("NO\n");
			else
			{

				if (lena*lenb == lenc)
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
			//test

		}
		else
		{
			printf("NO\n");
		}

	}

	return 0;
}