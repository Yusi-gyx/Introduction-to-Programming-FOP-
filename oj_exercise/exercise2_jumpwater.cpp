#include<iostream>
using namespace std;

int main()
{
    for(int A = 1;A <= 5;A++){
        for(int B = 1;B <= 5;B++)
        {
            if(A != B)
            {
                for(int C = 1;C <= 5;C++)
                {
                    if((C != A)&&(C !=B))
                    {
                        for(int D = 1;D <= 5;D++)
                        {
                            if((D != C)&&(D != B)&&(D != A))
                            {
                                for(int E = 1;E <= 5;E++)
                                {
                                    if((E != D)&&(E != C)&&(E != B)&&(E != A))
                                    {
                                        int cc1 = (B == 2) + (A == 3);
                                        int cc2 = (B == 2) + (E == 4);
                                        int cc3 = (C == 1) + (D == 2);
                                        int cc4 = (C == 5) + (D == 3);
                                        int cc5 = (E == 4) + (A == 1);
                                        if((cc1 == 1)&&(cc2 == 1)&&(cc3 == 1)&&(cc4 == 1)&&(cc5 == 1))
                                        {
                                            for(int i = 1;i <= 5;i++)
                                            {
                                                if(A == i) cout<<"A"<<" ";
                                                if(B == i) cout<<"B"<<" ";
                                                if(C == i) cout<<"C"<<" ";
                                                if(D == i) cout<<"D"<<" ";
                                                if(E == i) cout<<"E"<<" ";
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}