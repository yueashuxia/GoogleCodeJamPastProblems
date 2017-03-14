#define LOCAL

#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;

bool intersect(int a1, int b1, int a2, int b2)
{
    if((a1 > a2 && b1 < b2) || (a1 < a2 && b1 > b2))
    {
        return true;    
    }
    else 
    {
        return false;
    }
}

int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int T, N, res;
    int wires[1005][2];
    scanf("%d", &T);
    for(int c = 1; c <= T; c++)
    {
        res = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d%d", &wires[i][0], &wires[i][1]);
            //printf("%d %d\n", wires[i][0], wires[i][1]);
            for(int j = i-1; j >= 0; j--)
            {
                if(intersect(wires[i][0], wires[i][1], wires[j][0], wires[j][1]))
                {
                    res++;
                }    
            }
        }
        printf("Case #%d: %d\n", c, res);
    }

    return 0;
}
