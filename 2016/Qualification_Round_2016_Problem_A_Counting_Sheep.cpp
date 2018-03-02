#define LOCAL

#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;

int mark = 0; //max 1111111111 - 9 8 7 6 5 4 3 2 1 0

void markNum(int n)
{
	int t = n;
	while(t != 0)
	{
		mark |= 1 << (t%10);
		t /= 10;
	}
}

int main()
{
    #ifdef LOCAL
    freopen("A-large-practice.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	
	int N, res = 0;
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		mark = 0;
		scanf("%d", &N);
		printf("Case #%d: ", i);
		if(N == 0)
		{
			printf("INSOMNIA\n");
		}
		else
		{
			int j = 0;
			while(++j && mark != 1023)
			{
				res = N*j;
				markNum(res);
				//printf("res = %d, mark = %d\n", res, mark);
			}
			printf("%d\n", res);
		}
	}


	//system("pause");
    return 0;
}
