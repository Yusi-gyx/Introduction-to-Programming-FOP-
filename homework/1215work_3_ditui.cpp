#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

/*数字金字塔的思路：递归会产生很多函数调用的开销，
这里使用的是递推dp，递推dp一般是自下向上，从这一级的上一级考虑，
每一个数字可以加上下面的两个数字，找到二者中最大的即可 */

int main ()
{
    int R ;
    cin >> R ;
    int** t = new int* [R] ;   //动态数组的空间开销会比较小
    for(int i = 0 ; i < R ; i ++)
    {
        t [i] = new int [i + 1] ;
    }    
    for(int i = 0 ; i < R ; i ++)
    {
        for(int j = 0 ; j <= i ; j ++)   cin >> t [i][j] ;
    }

    for(int i = R - 2 ; i >= 0 ; i --)
    {
        for(int j = 0 ; j <= i ; j ++)
        {
            t [i][j] += max(t [i + 1][j] , t [i + 1][j + 1]) ;   //递推关系式
        }
    }
    cout << t [0][0] ;

    for(int i = 0 ; i < R ; i ++)
    {
        delete [] t [i] ;
    }
    delete [] t ;
    return 0 ;
}