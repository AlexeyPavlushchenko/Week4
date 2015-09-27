#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
using namespace std;

char s[100], a[300], temp[20] = "0x";
bool buf = false;
int len, pos = 0, temppos, num = 0;

char* convert(char* s)
{
	len = strlen(s);
	for (int i = 0; i <= len; i++)
	{
		if (!isdigit(s[i]))
			if (!buf)
				a[pos++] = s[i];
			else
			{
				temppos = 2;
				do
				{
					if (num % 16 < 10)
						temp[temppos++] = num % 16 + '0';
					else
						temp[temppos++] = num % 16 - 10 + 'A';
					num = (num - (num % 16)) / 16;
				} while (num);
				for (int i = 2; i < (temppos + 2) / 2; i++)
					swap(temp[i], temp[temppos + 1 - i]);
				temp[temppos] = '\0';
				a[pos] = '\0';
				strcat(a, temp);
				pos += strlen(temp);
				a[pos++] = s[i];
				buf = false;
			}
		else
		{
			num = num * 10 + s[i] - '0';
			buf = true;
		}
	}
	return a;
}
int main()
{
	char s[] = "aaaaa258xxx";
	cout << convert(s) << endl;
	return 0;
}