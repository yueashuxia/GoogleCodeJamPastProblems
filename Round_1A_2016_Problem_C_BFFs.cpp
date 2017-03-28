#define LOCAL

#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;

int maxCircleLen;
int maxChainLen;
int bff[1005];
int chainLen[1005];

int main()
{
    #ifdef LOCAL
    freopen("C-large-practice.in", "r", stdin);
    freopen("C-large-practice.out", "w", stdout);
    #endif
    int T, N, caseNum, res, F;
    scanf("%d", &T);
    for(caseNum = 1; caseNum <= T; caseNum++)
    {
        memset(chainLen, 0, sizeof(chainLen));
        maxCircleLen = 2;
        maxChainLen = 0;
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &F);
            bff[i] = F;
        }
        for(int i = 1; i <= N; i++)
        {
            int len = 2;
            int t = bff[i];
            while(true)
            {
                if(bff[t] == i)
                {
                    if(len > maxCircleLen)
                    {
                        maxCircleLen = len;
                    }
                    break;
                }
                else if(len > N)
                {
                    break;
                }
                t = bff[t];
                len++;
            }
        }
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                int t = bff[j];
                if(bff[t] != j)
                {
                    chainLen[t] = max(chainLen[t], 1+chainLen[j]);
                }
            }
        }
        for(int i = 1; i <= N; i++)
        {
            //printf("ChainLen[%d] = %d\n", i, chainLen[i]);
            if(bff[bff[i]] == i)
            {
                maxChainLen += chainLen[i]+chainLen[bff[i]]+2;
            }
        }
        printf("Case #%d: %d\n", caseNum, max(maxCircleLen, maxChainLen/2));
    }

    return 0;
}
