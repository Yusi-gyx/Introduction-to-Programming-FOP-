/*
题目描述
给定字符串，将其中的奇数位的字母改为大写（如果是字母且是小写的话），偶数位的数字改为它的后继（如果该位是数字的话。数字9的后续是数字0，0的后续是1，1的是2 ....），最后输出结果。

输入描述
输入为一个字符串。（字符串长度小于1000）

输出描述
输出为按照题目要求转换后的字符串。
*/

#include<iostream>
#include<cstring>
using namespace std ;


void check_change (char arr[] , int n)
{
    if((n + 1) % 2 == 0)
    {
        if(arr[n] >= '0' && arr[n] <= '9')
        {
            if(arr[n] == '9') arr[n] = '0' ;
            else arr[n] ++ ;
        }
    }
    else
    {
        if(arr[n] >= 'a' && arr[n] <= 'z') arr[n] -= 32 ;
    }
}


int main ()
{
    char arr [1001] ;
    cin >> arr ;
    int n = strlen (arr) ;
    for(int i = 0 ; i < n ; i ++)
    {
        check_change (arr , i) ;
    }

    cout << arr << endl ;
    return 0 ;
}