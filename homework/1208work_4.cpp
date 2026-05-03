#include<iostream>
#include<vector>
using namespace std ;

int ff = 1 ;      //标示两种对角线的填充方式
int cnt = 1 ;     //表示填充的数字

void lu (vector<vector<int>> &matrix , int num , int n)         //从下向上填充
{
    if(num < n)   //矩阵的上半部分
    {
    for(int i = 0 ; i <= num ; i ++)
    {
        matrix [num - i][i] = cnt ++ ;
    }
    }
    else          //矩阵的下半部分
    {
    for(int i = num - n + 1  ; i <= n - 1 ; i ++)
    {
        matrix [num - i][i] = cnt ++ ;
    }        
    }
}

void ul (vector<vector<int>> &matrix , int num , int n)         //从上向下填充
{
    if(num < n)  //矩阵的上半部分
    {
    for(int i = 0 ; i <= num ; i ++)
    {
        matrix [i][num - i] = cnt ++ ;
    }
    }
    else         //矩阵的下半部分
    {
    for(int i = num - n + 1 ; i <= n - 1 ; i ++)
    {
        matrix [i][num - i] = cnt ++ ;
    }        
    }
}

void (*funcarr [2])(vector<vector<int>> &matrix , int num , int n) = {lu , ul} ;        //建立函数跳转表

void snake_matrix(vector<vector<int>> &matrix , int n , int num)
{
    //判断终止条件
    if(num >= 2 * n - 1) return ;

    //对角线进行循环
    funcarr [ff](matrix , num , n) ;
    ff = 1 - ff ;    //矩阵模式转换

    //递归其他对角线
    snake_matrix(matrix , n , num + 1) ;
}

int main ()
{
    int n = 0 ;
    cin >> n ;
    vector<vector<int>> matrix(n , vector<int>(n , 0)) ;    //构建矩阵

    snake_matrix(matrix , n , 0) ;

    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            cout << matrix [i][j] << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}