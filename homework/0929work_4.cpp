#include<iostream>
#include<cmath>
using namespace std;

int main ()
{
    int N = 0;
    cin>>N;
    int work = 0;
    for(int i = 1;i <= N;i++)
    {
        int num = 0;
        cin>>num;
        if(num % 2 !=0)
        {
            work = work + abs(num -(num % 3));
            num = num % 3;
            cout<<num<<" ";
        }
        else
        {
            cout<<num<<" ";
        }
    }
    cout<<endl;
    cout<<work<<endl;
    return 0;
}