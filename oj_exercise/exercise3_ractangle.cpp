/*
题目描述
给定一个矩形的长和宽，请用*打印出这个矩形的边框。
输入描述
输入仅有一行，为两个整数a(2<=a<=20)和b(2<=b<=20)，分别代表矩形的长和宽。
输出描述
输出格式为多行，为矩形的边框图案。
输出的矩形边框图形应为a行b列
*/

#include<iostream>
using namespace std ;

void space(int);


int main ()
{
    int a = 0 , b = 0 ;
    cin>>a>>b;
    for(int i = 1 ; i <= a ; i ++)
    {
        if( i == 1 || i == a)
        {
            for(int x = 1 ; x <= b ; x ++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        else
        {       
            cout<<"*";
            space(b);
            cout<<"*";
            cout<<endl;
        }
    }
    return 0 ;
}

void space(int m)
{
    for(int i = 1 ; i <= m - 2 ; i ++)
    {
        cout<<" ";
    }
}
