#include<iostream>
#include<vector>
using namespace std ;


int dp (int row , int col , int R , int** r , int** t)
{
    //递归结束条件
    if(row == R - 1)  return t [row][col] ;
    //循环找到每一个位置走到底部的和的最大值
    if(r [row][col] != 0) return r [row][col] ;
    else
    {
        int max = 0;
        for (int j = 0; j < 2; j++)
        {
            int temp = t[row][col] + dp(row + 1, col + j, R , r , t);
            if (temp > max)
                max = temp;
        }
        return r [row][col] = max;
    }
}

int main ()
{
    int R ;
    cin >> R ;
    int** r = new int* [R] ;
    for(int i = 0 ; i < R ; i ++)
    {
        r [i] = new int [i + 1] ;
        for(int j = 0 ; j < i + 1 ; j ++) r [i][j] = 0 ;
    }
    int** t = new int* [R] ;
    for(int i = 0 ; i < R ; i ++)
    {
        t [i] = new int [i + 1] ;
    }    
    for(int i = 0 ; i < R ; i ++)
    {
        for(int j = 0 ; j <= i ; j ++)   cin >> t [i][j] ;
    }
    int max = dp(0 , 0 , R , r , t) ;
    cout << max ;
    for(int i = 0 ; i < R ; i ++)
    {
        delete[] r [i] ;
    }
    delete [] r ;
    for(int i = 0 ; i < R ; i ++)
    {
        delete [] t [i] ;
    }
    delete [] t ;
}