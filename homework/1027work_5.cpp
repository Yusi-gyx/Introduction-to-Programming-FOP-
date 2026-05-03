/*
题目描述
若一个数能被某个大于 1 的整数的平方整除，则称该数为“平方因子数”（squareful number）。
例如：
• 4 = 2² × 1 → 含平方因子 2²
• 8 = 2² × 2 → 含平方因子 2²
• 18 = 3² × 2 → 含平方因子 3²
• 因此4，8，18都是平方因子数。
给定一个整数n，请你计算在区间[1, n]内有多少个整数是非平方因子数。

输入描述
一个整数 n (1 ≤ n ≤ 107）

输出描述
一个整数，表示区间[1, n]内非平方因子数的数量。
*/

#include<iostream>
#include<cmath>
using namespace std ;

int a [10000000] = {0};
int unsquareful (int a [] ,int n)
{
    int m = 0 ;                                          //m是平方因子数的个数
    for(int i = 2 ; i <= sqrt(n) ; i ++)                 //筛法，使平方因子数的数组对应值为1
    {
        for(int k = i * i ; k <= n ; k += i * i)
        {
                a[k - 1] = 1 ;
        }
    }
    for(int i = 0 ; i < n ; i ++)
    {
        if(a[i] == 1) m ++ ;                             //计算平方因子数的个数
    }
    return n - m ;
}

int main ()
{
    int n = 0 ;
    cin >> n ;
    cout << unsquareful(a , n) ;
    return 0 ;
}


