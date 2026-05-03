/*
题目描述
徐老师有A，B，C，D四个得意门生，在中秋节他收到一份礼物，十分高兴，但不知道是谁送的。徐老师询问了四个学生，得到了如下答案： 
A：不是我送的礼物 
B：是我送的礼物 
C：不是B送的礼物 
D：是C送的礼物
已知四个学生中只有一个说了假话，那么到底是谁送的礼物呢？

输入描述
无

输出描述
送礼物的学生的代号。
*/

#include<iostream>
using namespace std ;

int main ()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        char obj = 'A' ;
        obj += i ;
        bool c1 = (obj != 'A');
        bool c2 = (obj == 'B');
        bool c3 = (obj != 'B');
        bool c4 = (obj == 'C');
        if(c1 + c2 + c3 + c4 == 3)
        {
            cout << obj <<endl;
            return 0 ;
        }
    }
}