#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std ;

int check_pan (int n)
{
    int m = 1 ;
    vector<long long int> pan ;
    int p = n ;
    while(p /= 10)
    {
        m ++ ;   //m表示数n的位数
    }
    for(int k = 1 ; k < 10 ; k ++)  
    {
        pan.push_back(k) ;
    }
    int len = (m + 1) / 2 ;  //用一个数来生成回文数
    for(int i = 1 ; i <= pow(10 , len) ; i ++)
    {
            
        int num = i ;
        long long int obj = i ;
        int digit = 0 ;
        while(num > 0)  //生成偶数位的回文数
        {
            digit = num % 10 ;
            obj = obj * 10 + digit ;
            num /= 10 ;
        }
        if(obj <= n) pan.push_back(obj) ;
            
        num = i ;
        obj = i ;
        digit = 0 ;
        num /= 10 ;
        while(num > 0)  //生成奇数位的回文数
        {
            digit = num % 10 ;
            obj = obj * 10 + digit ;
            num /= 10 ;
        }
        if(obj <= n) pan.push_back(obj) ;
    }

    set<long long int> unique(pan.begin() , pan.end()) ;
    vector<long long int> result(unique.begin() , unique.end()) ;  //去重

    return result.size() ;
}

int main ()
{
    int N , pen = 0 , pan = 0 ;
    cin >> N ;
    int mp [8] = {6 , 28 , 496 , 8128 , 33550336} ;
    for(int i = 0 ; i < 5 ; i ++)
    {
        if(mp [i] <= N) pen ++ ;
    }
    pan = check_pan(N) ;

    cout << pen << " " << pan ;
    return 0 ;
}