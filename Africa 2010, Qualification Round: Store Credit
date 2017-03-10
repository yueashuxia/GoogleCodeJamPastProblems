#define LOCAL

#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;

int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int N, C, I, i, j, res1, res2;
    int P[2005], cnt = 0;
    bool flag;
    scanf("%d", &N);
    while(N--)
    {
        flag = false;
        res1 = res2 = 0;
        scanf("%d", &C);
        scanf("%d", &I);
        for(i = 0; i < I; i++)
        {
            scanf("%d", &P[i]);
            if(flag == false)
            {
                for(j = i-1; j >= 0; j--)
                {
                    if(P[i]+P[j] == C)
                    {
                        flag = true;
                        res1 = j+1;
                        res2 = i+1;
                    }
                }
            } 
        }
        
        printf("Case #%d: %d %d\n", ++cnt, res1, res2);
    }

    return 0;
}
