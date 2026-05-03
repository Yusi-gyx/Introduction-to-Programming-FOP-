#include<iostream>
using namespace std;

int main ()
{
    int sum_a = 0,sum_b = 0,sum_c = 0;
    char L,M,S;
    for(int A = 0;A <= 2;A++)
        for(int B = 0;B <= 2;B++)
            for(int C = 0;C <= 2;C++)
            {
                sum_a = 0,sum_b = 0,sum_c = 0;
                if(B > A) sum_a++;
                if(C == A) sum_a++;
                if(A > B) sum_b++;
                if(A > C) sum_b++;
                if(C > B) sum_c++;
                if(B > A) sum_c++;
                if(((B > A) == (sum_b < sum_a))&&((C > A) == (sum_c < sum_a))&&(B > C) == (sum_b < sum_c))
                {
                    if(A >= B)
                    {
                        if(A > C) 
                        {
                            L = 'A';
                            if(B > C) 
                            {
                            M = 'B';
                            S = 'C';
                            }
                            else 
                            {
                            M = 'C';
                            S = 'B';
                            }
                        }
                        else
                        {
                            L = 'C';
                            M = 'A';
                            S = 'B';
                        }
                    }
                    else
                    {
                        if(B > C) 
                        {
                            L = 'B';
                            if(A > C)
                            {
                                M = 'A';
                                S = 'C';
                            }
                            else
                            {
                                M = 'C';
                                S = 'A';
                            }
                        }
                        else{
                            L = 'C';
                            M = 'B';
                            S = 'A';
                        }
                    }
                    if((A != B)&&(B != C)&&(A != C))
                    {
                    cout<<L<<" "<<M<<" "<<S<<endl;
                    }
                }
            }
    return 0;
}