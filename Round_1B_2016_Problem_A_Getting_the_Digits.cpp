#define LOCAL

#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;

int countLetter[30];
int countNumber[10];

int main()
{
    #ifdef LOCAL
    freopen("A-large-practice.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int T, c;
	char S[2005];
	scanf("%d", &T);
	for(c = 1; c <= T; c++)
	{
		scanf("%s", S);
		memset(countLetter, 0, sizeof(countLetter));
		memset(countNumber, 0, sizeof(countNumber));
		for(int i = 0; S[i] != '\0'; i++)
		{
			countLetter[S[i]-'A']++;
		}
		countNumber[0] = countLetter['Z'-'A'];
		for(int i = 0; i < countNumber[0]; i++)
		{
			countLetter['Z'-'A']--;
			countLetter['E'-'A']--;
			countLetter['R'-'A']--;
			countLetter['O'-'A']--;
		}
		countNumber[2] = countLetter['W'-'A'];
		for(int i = 0; i < countNumber[2]; i++)
		{
			countLetter['T'-'A']--;
			countLetter['W'-'A']--;
			countLetter['O'-'A']--;
		}
		countNumber[4] = countLetter['U'-'A'];
		for(int i = 0; i < countNumber[4]; i++)
		{
			countLetter['F'-'A']--;
			countLetter['O'-'A']--;
			countLetter['U'-'A']--;
			countLetter['R'-'A']--;
		}
		
		countNumber[6] = countLetter['X'-'A'];
		for(int i = 0; i < countNumber[6]; i++)
		{
			countLetter['S'-'A']--;
			countLetter['I'-'A']--;
			countLetter['X'-'A']--;
		}
		
		countNumber[8] = countLetter['G'-'A'];
		for(int i = 0; i < countNumber[8]; i++)
		{
			countLetter['E'-'A']--;
			countLetter['I'-'A']--;
			countLetter['G'-'A']--;
			countLetter['H'-'A']--;
			countLetter['T'-'A']--;
		}
		
		countNumber[1] = countLetter['O'-'A'];
		for(int i = 0; i < countNumber[1]; i++)
		{
			countLetter['O'-'A']--;
			countLetter['N'-'A']--;
			countLetter['E'-'A']--;
		}
		
		countNumber[3] = countLetter['R'-'A'];
		for(int i = 0; i < countNumber[3]; i++)
		{
			countLetter['T'-'A']--;
			countLetter['H'-'A']--;
			countLetter['R'-'A']--;
			countLetter['E'-'A']--;
			countLetter['E'-'A']--;
		}
		
		countNumber[5] = countLetter['F'-'A'];
		for(int i = 0; i < countNumber[5]; i++)
		{
			countLetter['F'-'A']--;
			countLetter['I'-'A']--;
			countLetter['V'-'A']--;
			countLetter['E'-'A']--;
		}
		
		countNumber[7] = countLetter['S'-'A'];
		for(int i = 0; i < countNumber[7]; i++)
		{
			countLetter['S'-'A']--;
			countLetter['E'-'A']--;
			countLetter['V'-'A']--;
			countLetter['E'-'A']--;
			countLetter['N'-'A']--;
		}
		
		countNumber[9] = countLetter['I'-'A'];
		
		
		printf("Case #%d: ", c);
		for(int i = 0; i <= 9; i++)
		{
			for(int j = 0; j < countNumber[i]; j++)
			{
				printf("%d", i);
			}
		}
		printf("\n");
	}

    return 0;
}
