/*
题目描述
给定一个二进制数，将其转换为十进制数

输入描述
一个4位的二进制数（如果不足4位，前面用0补齐）

输出描述
输入数据的十进制表示

样例输入
0010

样例输出
2
*/

#include<iostream>
using namespace std ;

int main ()
{
    int n = 0 ;
    cin >> n ;
    int a = n / 1000 ;
    int b = (n / 100) % 10 ;
    int c = (n % 100) / 10 ;
    int d = n % 10 ;
    int num = 8 * a + 4 * b + 2 * c + 1 * d ;
    cout << num ;
    return 0 ;
}