/*
A-Small（过不了A-large）

#define LOCAL
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp1(int a,int b){return a>b;} 
bool cmp2(int a,int b){return a<b;} 

int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int T, n, i, j, cnt = 1;
    long long int res;
    int xArr[805], yArr[805];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &xArr[i]);    
        }
        for(i = 0; i < n; i++)
        {
            scanf("%d", &yArr[i]);    
        }
        sort(xArr, xArr+n, cmp1);
        sort(yArr, yArr+n, cmp2);
        res = 0;
        for(i = 0; i < n; i++)
        {
            res += xArr[i]*yArr[i];
        }
        printf("Case #%d: %lld\n", cnt++, res);
    }

    return 0;
}

*/

//能过A-Large的
import java.io.*;  
import java.math.*;  
import java.util.*;  
public class Main {  
    public static void main(String[] args) {  
        Scanner cin = new Scanner(new BufferedInputStream(System.in));  
        int caseNum, cnt = 1 ;
        caseNum = cin.nextInt() ; 
        BigInteger res;  
        while(caseNum != 0)  
        {  
          int arrSize = cin.nextInt();
          int[] xArr = new int[arrSize];
          for(int i = 0; i < arrSize; i++)
          {
            xArr[i] = cin.nextInt();
          }
          int[] yArr = new int[arrSize];
          for(int i = 0; i < arrSize; i++)
          {
            yArr[i] = cin.nextInt();
          }
          Arrays.sort(xArr);
          Arrays.sort(yArr);
          res = BigInteger.ZERO;
            if(caseNum == -1) break ;  
            for(int i = 0; i < arrSize; i++)
            {
              BigInteger product = BigInteger.valueOf(xArr[i]).multiply(BigInteger.valueOf(yArr[arrSize-i-1]));
              res = res.add(product);
            }

            System.out.println("Case #"+new Integer(cnt).toString()+": "+res.toString()); 
            caseNum--;
            cnt++;
        }  
    }  
}  
