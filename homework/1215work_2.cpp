#include<iostream>
#include<vector>
using namespace std ;

int max_missle = 0 ;
vector<int> missle ;

void comparison()
{
    int len = missle.size() ;
    if(len > max_missle) max_missle = len ;
}

void Try_w (int n , vector<int> height , int cnt)   //无必须拦截的情况
{
    int len = missle.size() ;
    //递归终止条件：计数的cnt等于n
    if(cnt == n) 
    {
        comparison() ;
        return ;
    }
    //剪枝
    int remain = n - cnt; // 剩余导弹数量
    if (len + remain <= max_missle) return; // 即使全拦截也不可能超过当前最优
    //准备打这个导弹，判断这个导弹能不能拦截
    if (len >= 1)
    {
        if (height[cnt] < missle[len - 1])
            Try_w(n, height, cnt + 1);
        else
        {
            Try_w(n, height, cnt + 1); // 可以跳过当前导弹

            missle.push_back(height[cnt]); // 拦截当前导弹之后判断下一个导弹
            Try_w(n, height, cnt + 1);
            //回溯missle的状态，递归其他情况
            missle.pop_back() ;
        }
    }
    else
    {
        Try_w(n, height, cnt + 1); // 可以跳过当前导弹

        missle.push_back(height[cnt]); // 拦截当前导弹之后判断下一个导弹
        Try_w(n, height, cnt + 1);
        //回溯missle的状态，递归其他情况
        missle.pop_back() ;
    }
}

void Try_y(int n , vector<int> height , int cnt , vector<int> obj , int obj_cnt , int m)
{
    int len = missle.size() ;
    //判断递归终止条件
    if(cnt == n)
    {
        comparison() ;
        return ;
    }
    if(obj_cnt < m && len >= 1)   //无法拦截下一个必须拦截的导弹
        if(missle [len - 1] > height [obj [obj_cnt]])  return ;
    //剪枝
    int remain = n - cnt; // 剩余导弹数量
    if (len + remain <= max_missle) return; // 即使全拦截也不可能超过当前最优
    //准备打这个导弹
    //还有必须拦截的导弹没有拦截
    if(obj_cnt < m)       
    {
            //如果是必须打击的目标，直接添加
        if (cnt == obj[obj_cnt])
        {
            missle.push_back(height[cnt]);
            Try_y(n, height, cnt + 1, obj, obj_cnt + 1 , m);
            // 回溯missle的状态，递归其他情况
            missle.pop_back();
        }
        else// 非必须击打的目标
        {
            if (len >= 1)
            {
                if (height[cnt] < missle[len - 1])
                    Try_y(n, height, cnt + 1 , obj , obj_cnt , m);
                else
                {
                    Try_y(n, height, cnt + 1 , obj , obj_cnt , m); // 可以跳过当前导弹

                    missle.push_back(height[cnt]); // 拦截当前导弹之后判断下一个导弹
                    Try_y(n, height, cnt + 1 , obj , obj_cnt , m);
                    // 回溯missle的状态，递归其他情况
                    missle.pop_back();
                }
            }
            else
            {
                Try_y(n, height, cnt + 1 , obj , obj_cnt , m); // 可以跳过当前导弹

                missle.push_back(height[cnt]); // 拦截当前导弹之后判断下一个导弹
                Try_y(n, height, cnt + 1 , obj , obj_cnt , m);
                // 回溯missle的状态，递归其他情况
                missle.pop_back();
            }
            // }
        }
    }
    else    //最后没有必须拦截的导弹时类似于第一种情况
    {
        Try_w(n , height , cnt) ;
    }
}

int main ()
{
    int n ; 
    cin >> n ;
    vector<int> height(n , 0) ;
    for(int i = 0 ; i < n ; i ++) cin >> height [i] ;
    int m = 0 ;
    cin >> m ;
    if(m == 0)        //无必须拦截的情况
    {
        Try_w(n , height , 0) ;
    }
    else              //有必须拦截的情况
    {
        vector<int> obj (m) ;
        for(int i = 0 ; i < m ; i ++) cin >> obj [i] ;
        Try_y(n , height , 0 , obj , 0 , m) ;
    }

    cout << max_missle ;
    return 0 ;
}