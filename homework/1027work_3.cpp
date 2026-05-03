/*
题目描述
如果在长为n的数组a中对某个下标 i (0 < i < n)满足 a[i-1] > a[i] 并且 a[i+1] > a[i]，则a[i]为数组a中的一个波谷。
补全代码：函数 count_valley 统计整数数组中的波谷的个数并返回。

输入描述
第一行一个正整数 n（3 ≤ n ≤ 10^6）。
第二行 n 个整数，表示序列 a[i]（−10^9 ≤ a[i] ≤ 10^9），相邻两数用空格分隔。

输出描述
输出一个整数，表示序列中波谷的个数。
*/


#include <iostream>
using namespace std;

int count_valley(const int a[], int n)
{
    int cnt = 0 ;
    if(n >= 3)
    {
    for(int i = 1 ; i < n - 1 ; i ++)
    {
        if(a[i] < a[i - 1] && a[i] < a[i + 1]) cnt ++ ;
    }
    return cnt ;
    }
    else return 0 ;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++) cin >> a[i];

    // 调用函数返回波谷个数
    cout << count_valley(a, n) << endl;

    return 0;
}