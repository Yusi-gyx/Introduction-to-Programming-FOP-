#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

void quick_sort (vector<int> &a , int begin , int end)
{
    if(begin >= end) return ;
    ///1.找到扫描的起点和标准数
    int z = begin , y = end ;
    int k = a [z] ;

    ///2.从左右分别扫描
    do
    {
        while(z < y && a [y] < k) y -- ;
        if(z < y) a [z ++] = a [y] ;

        while(z < y && a [z] >= k) z ++ ;
        if(z < y) a [y --] = a [z] ;
    }while(z != y) ;

    a [z] = k ;    //完成分区操作，数值k归位

    ///3.给子数列排序
    quick_sort(a , begin , z - 1) ;
    quick_sort(a , z + 1 , end) ;
}

bool comparison(int a , int b)
{
    return a > b ;
}

int main ()
{
    int n , q ;
    cin >> n >> q ;
    vector<int> a (n) ;
    for(int i = 0 ; i < n ; i ++)
    cin >> a [i] ;
    // quick_sort(a , 0 , n - 1) ;
    sort(a.begin() , a.end() , comparison) ;
    for(int i = 0 ; i < q ; i ++)
    {
        int cnt = 0 ;
        cin >> cnt ;
        cout << a [cnt - 1] << " ";
    }
    return 0 ;
}