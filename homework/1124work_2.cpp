#include<iostream>
#include<vector>
using namespace std ;

int f(int x)
{
    if(x == 1) return 1 ;
    else
    {
        if(x % 2 != 0)
        {
            return f((x - 1) / 2) + f((x + 1) / 2) ;
        }
        else
        {
            return f(x / 2) ;
        }
    }
}

int main ()
{
    int n = 0 ;
    cin >> n ;
    vector<int> x(n) ;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> x[i] ;
    }
    for(int i = 0 ; i < n ; i ++)
    {
        cout << f(x [i]) ;
        if(i != n - 1) cout << endl ;
    }
    return 0 ;
}