#include<iostream>
using namespace std;

int main () {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int tep_1,tep_2,tep_3,m,n;
    if(a >= b)
    {
        tep_1 = b;
    }
    else
    {
        tep_1 = a;
        a = b;
    }
    if(c >= d)
    {
        tep_2 = d;
    }
    else
    {
        tep_2 = c;
        c = d;
    }
    if(a >= c)
    {
        tep_3 = c;
    }
    else 
    {
        tep_3 = a;
        a = c;
    }
    if(tep_3 >= tep_1 && tep_3 >= tep_2)
    {
        b = tep_3;
        m = tep_1;
        n = tep_2;
    }
    if(tep_2 >= tep_1 && tep_2 >= tep_3)
    {
        b = tep_2;
        m = tep_1;
        n = tep_3;
    }
    if(tep_1 >= tep_3 && tep_1 >= tep_2)
    {
        b = tep_1;
        m = tep_2;
        n = tep_3;
    }
    if(m >= n)
    {
        c = m;
        d = n;
    }
    else
    {
        c = n;
        d = m;
    }
    cout<<d<<" "<<c<<" "<<b<<" "<<a<<"\n";
    return 0;
}