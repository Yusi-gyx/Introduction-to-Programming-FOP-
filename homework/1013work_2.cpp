/*
补全代码，计算方程实根的数量：
*/

#include <iostream>

using namespace std;



// 计算一元二次方程的判别式

double delta(double a, double b, double c)

{   // 填写代码
    int d = b*b - 4*a*c;
    return d;
}



// 根据方程系数，返回方程实根的数量

int root_num(double a, double b, double c)

{   // 填写代码
    int num = 0;
    
    if(a == 0)
    {
        if(b == 0 && c == 0)
            num = -1;
        else if(c != 0 && b == 0)
            num = 0;
        else
            num = 1;
    }
    else
    {
        if(delta(a,b,c) == 0) 
        num = 1;
        else if(delta(a,b,c) < 0)
        num = 0;
        else
        num = 2;
    }
    
    return num;
}



int main()

{

    double a, b, c;

    cin >> a >> b >> c;

   

    cout << root_num(a, b, c);

   

    return 0;

}


