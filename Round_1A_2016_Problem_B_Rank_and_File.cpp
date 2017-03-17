#define LOCAL

#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int T, N, caseNum;
    int H, heights[2505];
    scanf("%d", &T);
    for(caseNum = 1; caseNum <= T; caseNum++)
    {
        memset(heights, 0, sizeof(heights));
        scanf("%d", &N);
        for(int i = 0; i < N*2-1; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &H);
                heights[H]++;
            }
        }
        printf("Case #%d:", caseNum);
        for(int i = 1; i < 2501; i++)
        {
            if(heights[i]%2 == 1)
            {
                printf(" %d", i);
            }
        }
        printf("\n");
    }

    return 0;
}
