#include<iostream>
#include<vector>
#include<climits>
using namespace std ;

int main ()
{
    long long n , L ;
    cin >> n >> L ;
    vector<long long> r(n + 1 , -1) ;  //备忘录法
    vector<int> a(n + 1) ;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a [i] ;
    }
    vector<long long> prefix(n + 1 , 0) ;
    prefix [0] = 0 ;
    for(int i = 1 ; i <= n ; i ++)    //递推法求前i项和
    {
        prefix [i] = prefix [i - 1] + a [i] ;
    }
    r [0] = 0 ;
    for(int i = 1 ; i <= n ; i ++)
    {
        long long max = LLONG_MAX ;
        for(int j = 0 ; j < i ; j ++)
        {
            long long sub = prefix [i] - prefix [j] ;
            long long temp = r [j] + (sub - L) * (sub - L) ;
            if(temp < max) max = temp ;
        }
        r [i] = max ;
    }
    cout << r [n] ;
    return 0 ;
}