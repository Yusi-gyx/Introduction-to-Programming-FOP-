/*
检查整数序列，是不是递增数列，若是则函数返回0；若不是则函数返回第一个不递增的位置。

输入描述
输入序列长度n（1≤n≤100），以及n个整数。

输出描述
若是递增数列则函数返回0，否则返回第一个不递增的位置。
*/


#include <iostream>
using namespace std;

// 检查整数序列是否为递增数列
// 若为递增数列，返回0；否则返回第一个不递增的位置（从0开始计数）
int check_increasing(int a[], int n)
{
    int cnt = 0 ;
    for(int i = 0 ; i < n - 1 ; i ++)
    {
        if(a[i + 1] <= a[i])
        return i + 1 ;
    }

    return 0 ;
}

int main()
{
    int n;
    cin >> n; // 输入元素个数
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i]; // 输入序列元素

    cout << check_increasing(a, n);
    return 0;
}