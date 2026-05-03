/*
题目描述
打印n阶实心菱形
输入描述
输入一个整数n，1<=n<=10
输出描述
输出n阶实心菱形，占2*n-1行。
注意，每一行最后一个*之后，不要输出空格。
菱形最长一行左右均无空格，其他按规律输出空格和星号，使得整体形成菱形。
*/

#include<iostream>
using namespace std ;

void space(int,int) ;
void print(int) ;

int main ()
{
    int n = 0 ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(i == n)
        {
            print(i);
            cout<<endl;
        }
        else
        {
            space(i , n) ;
            print(i);
            space(i , n) ;
            cout<<endl;
        }
    }
    for(int i = n - 1 ; i >= 1 ; i --)
    {
        space(i , n) ;
        print(i);
        space(i , n) ;
        cout<<endl;
    }
    return 0 ;
}


void space(int m ,int n)
{
    int i = n - m ;
    if(i != 0)
    {
        for(int x = 1 ; x <= i ; x ++)
        {
            cout<<" ";
        }
    }
}

void print(int i)
{
    for(int x = 1 ; x <= 2*i - 1 ; x ++)
    {
        cout<<"*";
    }
}