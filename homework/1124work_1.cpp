#include<iostream>
using namespace std ;

int get_num(int a , int b)
{
    int num = 0 ;
    if(a % b == 0) return b ;
    else
    {
        int c = a % b ;
        num = get_num(b , c) ;
        return num ;
    }
}

int main()
{
    int a = 0 , b = 0 ;
    cin >> a >> b ;
    int num = 0 ;
    num = get_num(a , b) ;
    cout << num ;
    return 0 ;
}