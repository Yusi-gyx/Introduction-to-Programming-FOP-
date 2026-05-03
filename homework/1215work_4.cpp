#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ;

struct stick {
    int len ;
    int power ;
} ;

bool find_stick(int lenth , vector<stick>& a)
{
    for(auto x : a)
    {
        if(x.len == lenth) return true ;
    }
    return false ;
}

int find_stick_power(int lenth , vector<stick>& a)
{
    int temp = 0 ;
    for(auto x : a)
    {
        if(x.len == lenth) temp = max(temp , x.power) ;
    }
    return temp ;
}

int main ()
{
    int N , M ;
    cin >> N >> M ;
    vector<stick> a(N) ;
    for(int i = 0 ; i < N ; i ++) cin >> a [i].len ;
    for(int i = 0 ; i < N ; i ++) cin >> a [i].power ;
    vector<int> power_record(M + 1 , 0) ;

    //找到最短的棒的长度
    int min_len = M + 1 ;
    for(auto x : a)
    {
        if(x.len < min_len) min_len = x.len ;
    }

    //从最短的棒开始递推
    //棒的连接有两种方式：1.直接有短棒  2.由短棒连接
    for(int i = min_len ; i <= M ; i ++)
    {
        int tem_power = 0 ;
        
        //确定有没有短棒与这个长度对应
        if(find_stick(i , a))
        {
            tem_power = find_stick_power(i , a) ;
        }
        
        //递推求最大的power
        if(i >= 2 * min_len)
        {
            for(int j = min_len ; j <= i - min_len ; j ++)
            {
                if(j != i - j)
                {
                    if(power_record [j] != 0 && power_record [i - j] != 0)
                    tem_power = max(power_record [j] + power_record [i - j] , tem_power) ;
                }
                else
                {
                    if(power_record [j] != 0 && power_record [i - j] != 0)
                    tem_power = max(power_record [j] * 2 + 233 , tem_power) ;
                }
            }
        }
        //储存该棒的最大长度
        power_record [i] = tem_power ;
    }
    cout << power_record [M] ;
    return 0 ;
}