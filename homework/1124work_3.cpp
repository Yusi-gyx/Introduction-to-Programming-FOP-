#include<iostream>
#include<vector>
using namespace std ;

void swap (int* i , int* j)
{
    int temp = *i ;
    *i = *j ;
    *j = temp ;
}

void output (int begin , int min_index , int n , vector<int> a)
{
    cout << "swap(a[" << begin << "], a[" << min_index << "]):" ;
    for(int i = 0 ; i < n ; i ++)
        cout << a [i] << " " ;
    if(begin != n - 1) cout << endl ;
}

void sorting(vector<int> a , int begin , int n)
{
    if(begin >= n) return ;
    int min = a [begin] ;
    int min_index = begin ;
    for(int i = begin ; i < n ; i ++)
    {
        if(a [i] < min) 
        {
            min_index = i ; 
            min = a [i] ;
        }
    }
    swap(&a [begin] , &a [min_index]) ;
    output(begin , min_index , n , a) ;
    sorting(a , begin + 1 , n) ;
}

int main ()
{
    int n = 0 ;
    cin >> n ;
    vector<int> a(n) ;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a [i] ;
    }
    int begin = 0 , end = n - 1 ;
    sorting(a , 0 , n) ;
    return 0 ;
}