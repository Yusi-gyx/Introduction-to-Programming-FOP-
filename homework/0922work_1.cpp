#include<iostream>
#include<iomanip>
using namespace std;

int main () 
{
    int a,b,c,d,e,f;
    float sum = 0;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    cin>>e;
    cin>>f;
    if(a % 3 == 0 && a % 2 != 0)
        {a = a;
            sum++;
        }
    else 
        a = 0;
    if(b % 3 == 0 && b % 2 != 0)
        {b = b;
            sum++;
        }
    else
        b = 0;
    if(c % 3 == 0 && c % 2 != 0)
        {c = c;
            sum++;
        }
    else
        c = 0;
    if(d % 3 == 0 && d % 2 != 0)
        {d = d;
            sum++;
        }
    else
        d = 0;
    if(e % 3 == 0 && e % 2 != 0)
        {e = e;
            sum++;
        }
    else
        e = 0;
    if(f % 3 == 0 && f % 2 != 0)
        {f = f;
            sum++;
        }
    else
        f = 0;
    if(sum != 0)
    {
        float average = 0;
        average = (a + b + c + d + e + f)/sum;
        cout<<fixed<<setprecision(4)<<average<<endl;
    }
    else
        cout<<"0.0000"<<endl;
    return 0;
}