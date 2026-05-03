// #include<iostream>
// using namespace std;

// int main ()
// {
//     int sum = 0;
//     for(char obj = 'A';obj <= 'F';obj++)
//     {
//         sum = (obj != 'A') + (((obj == 'A')&&(obj != 'C'))||(obj != 'A')&&(obj == 'C'))
//         +(!(obj != 'A') && !(((obj == 'A')&&(obj != 'C'))||(obj != 'A')&&(obj == 'C')))
//         +(obj == 'F') + (!(!(obj != 'A') && !(((obj == 'A')&&(obj != 'C'))||(obj != 'A')&&(obj == 'C'))) && !(obj == 'F'))
//         +((obj != 'A') && (!(!(obj != 'A') && !(((obj == 'A')&&(obj != 'C'))||(obj != 'A')&&(obj == 'C'))) && !(obj == 'F'))
//         && !(((obj == 'A')&&(obj != 'C'))||(obj != 'A')&&(obj == 'C')) && !(!(obj != 'A') && !(((obj == 'A')&&(obj != 'C'))||(obj != 'A')&&(obj == 'C')))
//         && !(obj == 'F'));
//         if(sum ==3)
//         {
//             cout<<obj<<endl;
//         }
//     }
//     return 0;
// }


//下面是改进后的代码：
//优点主要在于用bool类型代表某人所说话的正确性，简化了对话的正确性判断
#include<iostream>
using namespace std;

int main () 
{   
    for(char killer = 'A';killer <= 'F';killer ++)
    {
    bool A = (killer != 'A');
    bool B = ((killer == 'A') ||(killer == 'B'));
    bool C = (!A && !B);
    bool F = (killer == 'F');
    bool D = (!C && !F);
    bool E = (A && !B && !C && D && !F);
    int sum = 0;
    sum = A + B + C + D + E + F;
    if(sum == 3)
        {
            cout<<killer<<endl;
        }
    }
    return 0;
}