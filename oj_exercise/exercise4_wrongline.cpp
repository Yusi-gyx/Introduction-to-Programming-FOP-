/*
题目描述有 n个人和 n把椅子，每个人原本都有一把属于自己的椅子。
现在让这 n 个人随机坐到椅子上，要求没有任何一个人坐在自己的椅子上。
请计算共有多少种不同的坐法。

输入描述
输入一个整数 （1 ≤ n ≤ 20）。答案不超过 long long 。

输出描述
输出一个整数，表示符合条件的排列数量。
*/


#include<iostream>
#include<vector>
using namespace std ;

int main ()
{
    int n = 0 ;
    cin >> n ;

    if(n == 1) cout << 0 ;
    else
    {
    vector <long long> d_arr (n , 0) ;
    d_arr [0] = 0 ;
    d_arr [1] = 1 ;
    for(int i = 2 ; i < n ; i ++ )
    {
        d_arr [i] = i * d_arr[i - 2] + i * d_arr [i - 1] ;
    }
    cout << d_arr [n - 1] ;
    return 0 ;
    }
}