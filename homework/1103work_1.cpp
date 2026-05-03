/*
题目描述
一只青蛙要从第 0 级台阶跳到第 N 级。它每次可以跳 1 级或 2 级。但有一些台阶是坏的，不能落脚，最终落在第 N 级台阶时也不能是坏台阶。请计算它有多少种不同的跳法。

输入描述
第一行两个整数 N 和 M ，分别表示台阶级数和坏台阶数量。
下面 M 行输入，每行一个整数表示坏台阶级数。

输出描述
输出一个整数，表示不同的跳法数。保证答案不超过 long long 范围。
*/

#include<iostream>
#include<vector>
using namespace std ;


bool checkbad (vector <int> a , int b)
{
    for(int i = 0 ; i < a.size() ; i ++)
    {
        if(a[i] == b) return true ;
        else continue ;
    }

    return false ;
}

int main ()
{
    int N = 0 , M = 0 ;
    cin >> N >> M ;

    vector <int> isbad (M + 1 , 0) ;
    for(int i = 1 ; i <= M ; i ++)
    {
        cin >> isbad [i] ;
    }

    for(int i = 1 ; i <= M ; i ++)
    {
        if(isbad [i] == N)
        {
            cout << 0 ;
            return 0 ;
        }
    }

    vector <long long> num(N + 1 , 0) ;
    num [0] = 1 ;
    if(checkbad(isbad , 1))
    {   
        if(checkbad(isbad , 2)) num [2] = 0 ;
        else num [2] = 1 ;
        num [1] = 0 ;
    }
    else
    {
        if(checkbad(isbad , 2)) num [2] = 0 ;
        else num [2] = 2 ;
        num [1] = 1 ;
    }

    for(int i = 3 ; i <= N ; i ++)
    {
        if(checkbad(isbad , i))
        {
            num [i] = 0 ;
            continue ;
        }
        else
        {
            num [i] = num [i - 1] + num [i - 2] ;
            continue ;
        }
    }

    cout << num [N] ;
    return 0 ;
}