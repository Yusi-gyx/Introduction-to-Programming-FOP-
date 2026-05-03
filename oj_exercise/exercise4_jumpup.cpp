/*
题目描述
一只青蛙要跳上共有𝑛阶的台阶，它每次可以跳 1 阶、2 阶或 3 阶。请计算它有多少种不同的跳法。

输入描述
一个整数 𝑛（1 ≤ n ≤ 72）

输出描述
输出一个整数，表示方案数。保证答案不超过 long long。
*/

#include<iostream>
#include<vector>
using namespace std ;

int main ()
{
    int n = 0 ;
    cin >> n ;
    vector < long long > function_arr (n , 0) ;
    function_arr [0] = 1 ;
    function_arr [1] = 2 ;
    function_arr [2] = 4 ;
    for(int i = 3 ; i < n ; i ++)
    {
        function_arr [i] = function_arr [i - 3] + function_arr [i - 2] + function_arr [i - 1] ;
    }
    cout << function_arr [n - 1] << endl ;
    return 0 ;
}