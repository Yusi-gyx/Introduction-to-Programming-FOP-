#include<iostream>
#include<vector>
using namespace std ;


void split(int num , int step , vector<int>& split_num)
{
    //如果这时的num等于0，就输出相关拆分
    if(num == 0)
    {
        for(int i = 0 ; i < step ; i ++)
        cout << split_num [i] << " " ;
        cout << endl ;
        return ;
    }

    //找到循环的最大值(拆分的下一个数不能大于上一个数)
    int max_val = step > 0 ? min(split_num [step - 1] , num) : num ;

    //循环遍历所有可能(从等于num开始，完成字典序输出)
    for(int i = max_val ; i >= 1 ; i --)
    {
        split_num [step] = i ;
        split(num - i , step + 1 , split_num) ;
    }
}

int main ()
{
    int n = 0 ;
    cin >> n ;
    vector<int> split_num (n) ;
    split(n , 0 , split_num) ;
    return 0 ;
}