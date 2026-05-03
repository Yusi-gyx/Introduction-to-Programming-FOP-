#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std ;

int dp(int** v , int** h , vector<vector<int>>& t , int n , int m , int row , int col)
{
    //递归终止条件
    if(row == 0 && col == 0) return 0 ;
    //判断是否已经求过，避免重复
    if(t [row][col] != 0) return t [row][col] ;
    //递归dp
    int min_time = INT_MAX ;
    //1.判断在边界上的情况
    if(row == 0) min_time = dp (v , h , t , n , m , row , col - 1) + h [row][col - 1] ;
    else if(col == 0) min_time = dp (v , h , t , n , m , row - 1 , col) + v [row - 1][col] ;
    //2.普通dp
    else min_time = min(dp (v , h , t , n , m , row , col - 1) + h [row][col - 1] , dp (v , h , t , n , m , row - 1 , col) + v [row - 1][col]) ;
    //3.返回最大值
    return t [row][col] = min_time ;
}

int main ()
{
    ios::sync_with_stdio(false) ;

    int n , m ;
    cin >> n >> m ;
    int** v = new int* [n] ;
    for(int i = 0 ; i < n ; i ++)
    {
        v [i] = new int [m + 1] ;
        for(int j = 0 ; j < m + 1 ; j ++) cin >> v [i][j] ;
    }
    int** h = new int* [n + 1] ;
    for(int i = 0 ; i < n + 1 ; i ++)
    {
        h [i] = new int [m] ;
        for(int j = 0 ; j < m ; j ++) cin >> h [i][j] ;
    }

    vector<vector<int>> t(n + 1 , vector<int> (m + 1 , 0)) ;   //总时间的数组
    //递推dp（从第一个开始）
    dp(v , h , t , n , m , n , m) ;
    cout << t [n][m] ;

    for(int i = 0 ; i < n ; i ++) delete [] v [i] ;
    delete [] v ;
    for(int i = 0 ; i < n + 1 ; i ++) delete [] h [i] ;
    delete [] h ;
    
    return 0 ;
}