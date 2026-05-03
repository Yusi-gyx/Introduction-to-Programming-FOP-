/*
题目描述
数学里有一个函数叫做max(a,b)，为a和b中更大的那一个。
现在，请完成函数max2，要求返回当前遇见过的所有数字中，第二大的数字。
你只能使用全局变量a1和a2来保存信息，不能使用数组来存储。

输入描述
第一行一个数字n，表示有n个正整数，2<=n<=100。
第二行有n个正整数，分别是数列的n项，数列各项互不相等。

输出描述
输出只有一行，一个整数，表示数列的第二大数字。
*/


#include <iostream>
using namespace std;
int a1 = 0,a2 = 0;
int max2(int number);           // 未定义，需要完成

int main() {
    int res = 0;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        res = max2(num);
    }
    cout << res << endl;
    return 0;
}

int max2(int a)
{
    if(a > a1) 
    {   
        int tep = a1 ;
        a1 = a ;
        a2 = tep ;
    }
    else
    {
        if(a > a2) a2 = a ;
    }
    return a2 ;
}