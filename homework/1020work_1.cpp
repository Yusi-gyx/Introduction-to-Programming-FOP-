/*
题目描述
123321是一个非常特殊的数，它从左边读和从右边读是一样的。
输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n 。

输入描述
输入一行，包含一个正整数n。

输出描述
按从小到大的顺序输出满足条件的整数，每个整数占一行。
样例输入
*/


#include <iostream>
using namespace std;
bool checkSpecial(int i, int n);      // 未定义，需要完成

int main() {
    int n;
    cin >> n;
    for (int i = 10000; i < 1000000; i ++) {
        if (checkSpecial(i, n)) {
            cout << i << endl;
        }
    }
    return 0;
}

bool checkSpecial(int i, int n)
{
    if(i < 100000)
    {
        if(((i / 10000) == (i % 10)) && (((i / 1000) % 10 ) == ((i %100) / 10)))
        {
            if((i / 10000) + (i % 10) + ((i / 1000) % 10 ) + ((i %100) / 10) + ((i / 100) % 10) == n)
            {
                return 1 ;
            }
            else return 0 ;
        }
        else return 0 ;
    }
    else
    {
        if(((i / 100000) == (i % 10)) && ((i / 10000) % 10 == (i % 100) / 10) &&((i / 1000) % 10 == (i % 1000) / 100))
        {
            if((i / 100000) + (i % 10) + ((i / 10000) % 10) + ((i % 100) / 10) + ((i / 1000) % 10) + ((i % 1000) / 100)  == n)
            {
                return 1 ;
            }
            else return 0 ;
        }
        else return 0 ;
    }
}