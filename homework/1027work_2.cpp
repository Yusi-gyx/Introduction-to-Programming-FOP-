/*
题目描述
补全代码：
函数 process_chars - 将小写改大写，大写保持不变，数字转成#，其他非字母非数字的字符转成 小数点。
函数 count_chars - 统计字符数组中 字母个数、数字个数、非字母非数字字符个数，以三个指针变量返回。

输入描述
输入一个字符数组（数组长度小于100）

输出描述
输出处理完的字符串，以及字符数组中 字母个数、数字个数、非字母非数字字符个数

样例输入
C++ is fun 2025 :)

样例输出
C...IS.FUN.####...
Letters: 6, Digits: 4, Others: 8
*/

#include <iostream>
#include <cstring>
using namespace std;

// 统计原字符串中字母、数字、非字母非数字的个数
void count_chars(const char a[], int *p_letter, int *p_digit, int *p_other)
{
    for(int i = 0 ; i < 100 ; i ++)
    {
        if(a[i] >= 48 && a[i] <= 57)
        {
            (*p_digit) ++ ;
            continue ;
        }
        else if((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122))
        {
            (*p_letter) ++ ;
            continue ;
        }
        else
        {
            if(a[i] == '\0') break ;
            else
            {
            (*p_other) ++ ;
            continue ;
            }
        }
    }
}

// 将小写改大写，大写保持不变，数字变为#，其他变为.
void process_chars(char a[])
{
    for(int i = 0 ; i < 100 ; i ++)
    {
        if(a[i] >= 48 && a[i] <= 57)
        {
            a[i] = '#' ;
            continue ;
        }
        else if((a[i] >= 65 && a[i] <= 90))
        {
            continue ;
        }
        else if((a[i] >= 97 && a[i] <= 122))
        {
            a[i] -= 32 ;
            continue ;
        }
        else
        {
            if(a[i] == '\0') break ;
            else
            {
            a[i] = '.' ;
            continue ;
            }
        }
    }
}

int main()
{
    char s[100];
    cin.getline(s, 100);

    int letters = 0, digits = 0, others = 0;
    count_chars(s, &letters, &digits, &others);

    process_chars(s);
    cout << s << endl;

    cout << "Letters: " << letters
         << ", Digits: " << digits
         << ", Others: " << others;
    return 0;
}