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
    
    int N, L, cnt = 1, i, j, k, len = 0;
    char str[2000];
    char temp[2000];
    scanf("%d", &N);
    getchar();
    while(N--)
    {
        gets(str);
        //printf("%s\n", str);
        len = strlen(str);
        printf("Case #%d: ", cnt++);
        for(i = j = len-1;i >= 0; i--)
        {
            if(str[i] == ' ')
            {
                for(k = i+1; k <= j; k++)
                {
                    printf("%c", str[k]);    
                }    
                printf(" ");
                j = i-1;
            }
            else if(i == 0)
            {
                 for(k = 0; k <= j; k++)
                 {
                     printf("%c", str[k]);          
                 }  
                 printf("\n"); 
            }
        }
    }

    return 0;
}
