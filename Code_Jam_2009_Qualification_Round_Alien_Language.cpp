#define LOCAL

#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;

int L, D, N;
char dic[5005][20];
char pattern[20][30];

int inDic()
{
    int res = 0, i, j, k;
    for(i = 0; i < D; i++)
    {
        for(j = 0; j < L; j++)
        {
            for(k = 0; pattern[j][k]!='\0';k++)
            {
                if(dic[i][j] == pattern[j][k])
                {
                    break;
                }    
            }
            if( pattern[j][k]=='\0')
            {
                break;
            }
        }    
        if(j == L)
        {
            res++;    
        }
    }  
    return res;  
}

/*递归法，可行但是时间太长 
bool inDic(char *str)
{
    for(int i = 0; i < D; i++)
    {
        if(strcmp(str, dic[i]) == 0)
        {
            return true;
        }    
    }
    return false;
}

char temp[20];
int countRes(int level)
{
    if(level < L)
    {
        int res = 0;
        int pLen = strlen(pattern[level]);
        for(int i = 0; i < pLen; i++)
        {
            temp[level] = pattern[level][i];
            res += countRes(level+1);
        }     
        return res;   
    }
    else
    {
        temp[level]  = '\0';
        //printf("%s\n", temp);
        if(inDic(temp))
        {
            return 1;
        }
        else
        {
            return 0;    
        }
    }
}
*/

int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    char str[505];
    int len;
    bool flag;
    
    scanf("%d%d%d", &L, &D, &N);
    for(int i = 0; i < D; i++)
    {
        scanf("%s", dic[i]);    
    }
    
    
    for(int i = 0; i < N; i++)
    {
        scanf("%s", str);    
        len = strlen(str);
        flag = false;
        int k = 0, m = 0;
        for(int j = 0; j < len; j++)
        {
            if(flag)
            {
                if(str[j] == ')')
                {
                    pattern[k][m] = '\0';
                    m = 0;
                    k++;
                    flag = false;
                }
                else
                {
                    pattern[k][m++] = str[j];
                }
            }
            else
            {
                if(str[j] == '(')
                {
                    flag = true;
                }
                else
                {
                    pattern[k][0] = str[j];
                    pattern[k][1] = '\0';
                    m = 0;
                    k++;
                }
            }
        }
        /*
        for(int ii = 0; ii < k; ii++)
        {
            printf("%s\n", pattern[ii]);
        }
        */
        printf("Case #%d: %d\n", i+1, inDic());
    }
    
    return 0;
}
