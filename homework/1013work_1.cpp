/*
补全代码，以32位补码方式输出变量内容：
*/

#include <iostream>

using namespace std;



// 整数m的第pos位的二进制位是否为1。是返回true，否返回false

bool is_one(int m, int pos)

{   // 填写代码
    if(m & (1 << pos))
        return true;
    else
        return false;
}



// 从高位到低位，输出整数m的各二进制位，中间无空格

void print_bits(int m)

{   // 填写代码
    for(int i = 31 ; i >= 0 ; i --)   //注意这里是0到32，取第pos位则1要左移pos-1位
    {
        if(is_one(m, i))
            cout<<1;
        else
            cout<<0;
    }
}



int main()

{

    int n;

    cin >> n;

    print_bits(n);

    return 0;

}

