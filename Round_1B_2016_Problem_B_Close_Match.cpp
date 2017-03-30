//按照官方题解的方法

#define LOCAL

#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;

char cScore[20], jScore[20];
char cScoreRes[20], jScoreRes[20];
char cScoreFinal[20], jScoreFinal[20];
char cScoreTemp[20], jScoreTemp[20];
int len = 0;
__int64 minDiff = -1;
__int64 cRes, jRes, cResTemp, jResTemp;


__int64 getDiffAbs(__int64 a, __int64 b)
{
    if(a > b)
    {
        return a-b;
    }
    else
    {
        return b-a;
    }
}

void fill(char *str, char c)
{
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '?')
        {
            str[i] = c;
        }
    }
}

int compare(char *str1, char *str2)
{
    for(int i = 0; i < len; i++)
    {
        if(str1[i] == '?' && str2[i] == '?')
        {
            str1[i] = str2[i] = '0';
        }
        else if(str1[i] == '?')
        {
            str1[i] = str2[i];
        }
        else if(str2[i] == '?')
        {
            str2[i] = str1[i];
        }
        else if(str1[i] != str2[i])
        {
            return i;
        }
    }
    return len;
}

__int64 getNumber(char *str)
{
    //printf("get number str=%s ", str);
    __int64 res = 0;
    for(int i = 0; i < len; i++)
    {
        res = (__int64)(res*10+(str[i]-'0'));
        //printf("str[%d]=%d res=%I64d res*10=%I64d ", i, str[i]-'0', res, res*10);
    }
    //printf("\n");
    return res;
}

bool updateMinDiff()
{
    __int64 diff = getDiffAbs(getNumber(cScoreTemp),getNumber(jScoreTemp));
    if(minDiff == -1 || diff < minDiff || (diff == minDiff && (getNumber(cScoreTemp) < getNumber(cScoreFinal) || getNumber(jScoreTemp) < getNumber(jScoreFinal))))
    {
        minDiff = diff;
        strcpy(cScoreFinal, cScoreTemp);
        strcpy(jScoreFinal, jScoreTemp);
        //printf("updateMinDiff=%I64d cScoreNum=%I64d jScore=%I64d cScore=%s jScore=%s\n", diff, getNumber(cScoreTemp), getNumber(jScoreTemp), cScoreFinal, jScoreFinal);
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
    freopen("B-large-practice.in", "r", stdin);
    freopen("B-large-practice.out", "w", stdout);
    #endif
    int T, caseNum;

    scanf("%d", &T);
    for(caseNum = 1; caseNum <= T; caseNum++)
    {
        scanf("%s %s", cScore, jScore);
        cRes = jRes = cResTemp = jResTemp = 0;
        minDiff = -1;
        len = strlen(cScore);
        strcpy(cScoreTemp, cScore);
        strcpy(jScoreTemp, jScore);
        int pos = compare(cScoreTemp, jScoreTemp);
        if(pos == len)
        {
            strcpy(cScoreFinal, cScoreTemp);
            strcpy(jScoreFinal, jScoreTemp);
        }
        else
        {
            strcpy(cScoreRes, cScore);
            strcpy(jScoreRes, jScore);
            int i;
            for(i = 0; i < len; i++)
            {
                if(cScoreRes[i] == '?' && jScoreRes[i] == '?')
                {
                    strcpy(cScoreTemp, cScoreRes);
                    strcpy(jScoreTemp, jScoreRes);
                    cScoreTemp[i] = '0';
                    jScoreTemp[i] = '1';
                    fill(cScoreTemp, '9');
                    fill(jScoreTemp, '0');
                    updateMinDiff();
                    strcpy(cScoreTemp, cScoreRes);
                    strcpy(jScoreTemp, jScoreRes);
                    cScoreTemp[i] = '1';
                    jScoreTemp[i] = '0';
                    fill(cScoreTemp, '0');
                    fill(jScoreTemp, '9');
                    updateMinDiff();

                    cScoreRes[i] = jScoreRes[i] = '0';
                }
                else if(cScoreRes[i] == '?')
                {
                    if(jScoreRes[i] != '9')
                    {
                        strcpy(cScoreTemp, cScoreRes);
                        strcpy(jScoreTemp, jScoreRes);
                        cScoreTemp[i] = jScoreRes[i]+1;
                        fill(cScoreTemp, '0');
                        fill(jScoreTemp, '9');
                        updateMinDiff();
                    }
                    if(jScoreRes[i] != '0')
                    {
                        strcpy(cScoreTemp, cScoreRes);
                        strcpy(jScoreTemp, jScoreRes);
                        cScoreTemp[i] = jScoreRes[i]-1;
                        fill(cScoreTemp, '9');
                        fill(jScoreTemp, '0');
                        updateMinDiff();
                    }

                    cScoreRes[i] = jScoreRes[i];
                }
                else if(jScoreRes[i] == '?')
                {
                    if(cScoreRes[i] != '9')
                    {
                        strcpy(cScoreTemp, cScoreRes);
                        strcpy(jScoreTemp, jScoreRes);
                        jScoreTemp[i] = cScoreRes[i]+1;
                        fill(cScoreTemp, '9');
                        fill(jScoreTemp, '0');
                        updateMinDiff();
                    }
                    if(cScoreRes[i] != '0')
                    {
                        strcpy(cScoreTemp, cScoreRes);
                        strcpy(jScoreTemp, jScoreRes);
                        jScoreTemp[i] = cScoreRes[i]-1;
                        fill(cScoreTemp, '0');
                        fill(jScoreTemp, '9');
                        updateMinDiff();
                    }

                    jScoreRes[i] = cScoreRes[i];
                }
                else if(cScoreRes[i] != jScoreRes[i])
                {
                    strcpy(cScoreTemp, cScoreRes);
                    strcpy(jScoreTemp, jScoreRes);
                    if(cScoreRes[i] > jScoreRes[i])
                    {
                        fill(cScoreTemp, '0');
                        fill(jScoreTemp, '9');
                    }
                    else
                    {
                        fill(cScoreTemp, '9');
                        fill(jScoreTemp, '0');
                    }
                    //printf("i=%d cScoreTemp=%s jScoreTemp=%s\n", i, cScoreTemp, jScoreTemp);
                    updateMinDiff();
                    break;
                }
            }
            //printf("minDiff = %lld\n", minDiff);
        }

        printf("Case #%d: %s %s\n", caseNum, cScoreFinal, jScoreFinal);
    }

    return 0;
}
