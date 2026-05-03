// #include<iostream>
// using namespace std;

// int main ()
// {
//     int one,two,three,four;
//     for(one = 0;one <= 1;one++)
//         for(two = 0;two <= 1;two++)
//             for(three = 0;three <= 1;three++)
//                 for(four = 0;four <= 1;four++)
//                 {
//                     int cc1 = 0,cc2 = 0,cc3 = 0,cc4 = 0;

//                     if(two == 1) cc1++;
//                     if(four == 1) cc2++;
//                     if(three != 1) cc3++;
//                     if(!(four == 1)) cc4++;  //判断专家的话

//                     if((one + two + three + four == 1)&&(cc1 + cc2 +cc3 + cc4 == 1))  //使最佳赛车和说对的专家只有一个
//                     {
//                         if(one == 1) cout<<1<<endl;
//                         if(two == 1) cout<<2<<endl;
//                         if(three == 1) cout<<3<<endl;
//                         if(four == 1) cout<<4<<endl;   //输出赛车

//                         if(cc1 == 1) cout<<"A"<<endl;
//                         if(cc2 == 1) cout<<"B"<<endl;
//                         if(cc3 == 1) cout<<"C"<<endl;
//                         if(cc4 == 1) cout<<"D"<<endl;  //输出专家
//                     }
//                 }
//     return 0;
// }


#include<iostream>
using namespace std;

int main ()
{
    for(int best = 1;best <= 4;best++)
    {
        bool A = (best == 2);
        bool B = (best == 4);
        bool C = (best != 3);
        bool D = !B;

        if(A + B + C + D == 1)
        {
            cout<<best<<endl;
            if(A) cout<<"A";
            if(B) cout<<"B";
            if(C) cout<<"C";
            if(D) cout<<"D";
            break;
        }
    }
    return 0;
}
