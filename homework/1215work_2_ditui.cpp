#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std ;
/*思路：飞弹拦截实际上就是找到最长不递减/不递增序列，
在其中加入必须打下来的导弹，实际上就是将导弹序列进行一个划分，
类似于分治思想，将导弹分为多个序列，每个序列找到最长的即可*/

int main ()
{
    int n ; 
    cin >> n ;

    //对高度数组进行初始化
    vector<int> h(n + 2 , 0) ;
    h [0] = - 100 ;     //起点赋一个不可能比这个还小的高度
    for(int i = 1 ; i <= n ; i ++) cin >> h [i] ;
    h [n + 1] = INT_MAX ;    //末尾赋一个不可能比这个还大的高度                  

    int m = 0 ;
    cin >> m ;
        

    //无必须拦截的情况
    if(m == 0)        
    {
        //动态规划状态
        vector<int> dp(n + 1 , 1) ;
        //注意这里动态规划的初值是1，因为任意一个导弹自身可以作为一个序列

        for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j < i ; j ++)
            {
                if(h [i] >= h [j]) dp [i] = max(dp [i] , dp [j] + 1) ;
            }
        }
        int max_missle = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] > max_missle)
                max_missle = dp[i];
        }
        cout << max_missle;
    }
    //有必须拦截的情况
    else              
    {
        //动态规划状态
        vector<int> dp(n + 1 , 1) ;
        int max_missle = 0 ;

        //储存必须拦截的导弹（第一个数为-1，最后一个数为高度数组的最后一个+1）
        vector<int> obj_missle(m + 2) ;
        obj_missle [0] = 0 ;
        obj_missle [m + 1] = n + 1 ;

        //储存输入的必须拦截导弹
        for(int i = 1 ; i <= m ; i ++)  
        {
            cin >> obj_missle [i] ;
            obj_missle [i] ++ ;      //将下标+1，与h对应
        }

        //将导弹序列通过必须要击打的导弹进行分隔，一共分为m+1段
        for(int i = 1 ; i <= m + 1 ; i ++)            
        {
            int max_len = 0 ;    //每个子区间上面的最大长度

            for(int j = obj_missle [i - 1] + 1 ; j < obj_missle [i] ; j ++)
            {
                if(h [j] > h [obj_missle [i]] || h [j] < h [obj_missle [i - 1]]) continue ;
                //每个子区间上的导弹不能小于前一个，不能大于后一个
                else
                {
                    for(int k = obj_missle [i - 1] + 1 ; k < j ; k ++)
                    {
                        //不能超过前后两个划分的范围（这个判断很重要，j对应的导弹已经判断过，但是k对应的导弹还没有判断过）
                        if(h [k] > h [obj_missle [i]] || h [k] < h [obj_missle [i - 1]]) continue ; 
                        if(h [j] >= h [k]) dp [j] = max(dp [j] , dp [k] + 1) ;
                    }
                }
                max_len = max(max_len , dp [j]) ;
            }

            max_missle += max_len ;
        }
        cout << max_missle + m ;
        cout << endl;
    }

    return 0 ;
}