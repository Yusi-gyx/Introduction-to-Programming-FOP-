/*
题目描述
有一段共有 𝑛阶的楼梯，第 𝑖阶台阶上写着一个非负花费 𝑐𝑜𝑠𝑡𝑖。你从楼梯的起点（在第 1 阶之前）出发，每次可以爬 1 阶或 2 阶。当你 到达顶端（即越过第 𝑛阶）时结束。
每当你落在某一阶台阶上时，需要支付该台阶的花费。起点不需要花费，顶端（越过第 𝑛阶的位置）也不需要花费。
请计算到达顶端所需支付的最小总花费。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main ()
{
    int n = 0 ;
    cin >> n ;

    if(n == 1) 
    {
        cout << 0 ;
        return 0 ;
    }
    
    else
    {
        vector <long long> cost_arr (n , 0) ;
        for(int i = 0 ; i < n ; i ++ )
        {
            cin >> cost_arr [i] ;
        }
        vector <long long> costsum (n + 1 , 0) ;
        
        costsum [0] = 0 ;
        costsum [1] = cost_arr [0] ;
        costsum [2] = cost_arr [1] ;

        for(int i = 3 ; i < n + 1 ; i ++)
        {
            costsum [i] = min ( costsum [i-1], costsum [i-2] )  + cost_arr[i-1] ;  //先算出到每个台阶的花费
        }

        long long dp = min ( costsum [n] , costsum [n - 1] ) ;
        cout << dp ;
        return 0 ;
    }
}