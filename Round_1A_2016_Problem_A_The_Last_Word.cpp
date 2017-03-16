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
    int T, caseNum;
    char str[1005];
    char res[1005];
    char temp[1005];
    scanf("%d", &T);
    for(caseNum = 1; caseNum <= T; caseNum++)
    {
        scanf("%s", str);
        res[0] = str[0];
        res[1] = '\0';
        for(int i = 1; str[i] != '\0'; i++)
        {
            temp[0] = str[i];
            temp[1] = '\0';
            if(str[i] >= res[0])
            {
                strcat(temp, res);
                strcpy(res, temp);
            }
            else
            {
                strcat(res, temp);
            }
        }

        printf("Case #%d: %s\n", caseNum, res);
    }


    return 0;
}
