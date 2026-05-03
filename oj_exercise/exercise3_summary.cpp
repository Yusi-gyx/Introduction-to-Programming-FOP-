/*
题目描述
有一个长度为n的序列，请你按照顺序，选择一些数，输出他们的和。
一个数满足以下所有要求，才能被选中：
（1）能被3或者5整除；
（2）小于1000；
（3）在这个数出现之前，没有出现过-1。
（4）当前选中的数字个数小于10个。（即，最多只能选中10个数字）
注：可不用数组完成任务。

输入描述
输入占两行
第一行有一个整数n。(0 < n <= 100)
第二行有n个整数x_i，表示长度为n的序列(0 < x_i < 10000  或  x_i == -1)。数字之间用空格隔开。

输出描述
输出所有被选中的数字之和
*/

#include<iostream>
using namespace std ;

int cho_sum (int) ;

int m = 0 ;
int sum = 0 ;

int main ()
{
    int n = 0 ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
    {
        int num = 0 ;
        cin >> num ;
        if(num == -1) break ;
        sum = cho_sum(num) ;
        if(m == 10) break ;
    }
    cout << sum ;
    return 0 ;
}


int cho_sum (int a)
{
    if(((a % 3 == 0) || (a % 5 == 0)) & (a <1000))
    {
        sum += a;
        m ++ ;
    }
    return sum ;
}