#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std ;

int main ()
{ 
    int m , p , q ;
    cin >> m >> p >> q ;
    vector<int> a(p) ;
    vector<int> b(q) ;
    for(int i = 0 ; i < p ; i ++)
    cin >> a [i] ;
    for(int i = 0 ; i < q ; i ++)
    cin >> b [i] ;
    int mini = 1e9 ;

    int i = 0 , j = 0 ;
    while(i < p && j < q)
    {
        int len = abs(a [i] - b [j]) ;
        if(len == 0)
        {
            mini = 0 ;
            break ;
        }
        if(len < mini) mini = len ;

        if(a [i] < b [j]) i ++ ;
        else j ++ ;

    }
    cout << fixed << setprecision(2) << sqrt(1 + mini * mini) ;
    return 0 ;
}