/*
题目描述
有三根柱子 A、B、C。起初有 n 个大小各不相同的圆盘，从小到大（小在上、大在下）依次叠在柱子 A 上。
一次移动被定义为：从某一根柱子上取下该柱子最上方的一个圆盘，并将其放到另一根柱子的最上方。
在任何时刻，不得将较大的圆盘放在较小的圆盘上。请计算将整叠圆盘从柱子 A 移到柱子 C 所需的最少移动次数。

输入描述
一行一个整数 n ，表示圆盘数量。

输出描述
输出一行，一个整数表示最少移动次数。保证答案不超过64位无符号整数范围。
*/

#include<iostream>
#include<vector>
using namespace std ;

int main ()
{
    int n = 0 ;
    cin >> n ;
    vector <unsigned long long> times (n , 0) ;

    times [0] = 1 ;
    for(int i = 1 ; i < n ; i ++)
    {
        times [i] = 2 * times [i - 1] + 1;
    }

    cout << times [n - 1] ;
    return 0 ;
}

