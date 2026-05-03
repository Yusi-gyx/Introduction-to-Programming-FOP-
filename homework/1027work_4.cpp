/*
题目描述
给定一个最高次数为 N（N ≤ 5）的多项式，其系数按升幂存放在长度足以容纳这 N+1 个值的一维数组中：
• 数组下标 0 对应常数项 a₀
• 数组下标 1 对应一次项系数 a₁
• …
• 数组下标 n 对应 n 次项系数 aₙ
补全代码：函数 Eval_Polynomial 计算给定多项式在点 x 处的值并返回，结果保留三位小数。

输入描述
共三行，第一行一个双精度浮点数 x，表示求值点。
第二行一个整数N，表示多项式最高次数。
第三行 N+1 （N ≤ 5）个双精度浮点数表示多项式的系数， 依次是a₀、a₁…aₙ，每两个系数中间用空格分开。

输出描述
多项式在指定点 x 处的值，保留三位小数。
*/


#include <bits/stdc++.h>

using namespace std;

void Eval_Polynomial(const double a[], int n, double x)
{
    double sum = 0 ;
    for(int i = 0 ; i < n + 1 ; i ++)
    {
        sum += (a[i] * pow(x , i)) ;
    }
    return sum ;
}

int main()
{
    double x;
    cin >> x;
    double a[6];
    int n;
    cin >> n;
    for(int i = 0; i < n + 1; i ++) cin >> a[i];

    // 求多项式在 x 处的值并输出
    cout << Eval_Polynomial(a, n, x);

    return 0;
}