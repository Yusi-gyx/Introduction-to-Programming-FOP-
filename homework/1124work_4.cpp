#include<iostream>
using namespace std ;

int f(int x , int n)
{
    if(n <= 0) return 0 ;
    else if(n == 1) return x ;
    else
    {
        return f(x , n - 1) + f(x , n / 2) + f(x , n / 3) ;
    }
}

int main ()
{
    int x , n ;
    cin >> x >> n ;
    cout << f(x , n) ;
    return 0 ;
}