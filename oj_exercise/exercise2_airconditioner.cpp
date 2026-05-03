#include<iostream>
using namespace std;

int main()
{
    for(int A = 1;A <= 5;A++)
    {
        for(int B = 1;B <= 5;B++)
        {
            if(A != B)
            {
                for(int C = 1;C <= 5;C++)
                {
                    if((C != A) && (C != B))
                    {
                        for(int D = 1;D <= 5;D++)
                        {
                            if((D != A) && (D != B) && (D != C))
                            {
                                for(int E = 1;E <= 5;E++)
                                {
                                    if((E != A) && (E != B) && (E != C) && (E != D) && (E != 2) && (E != 3))
                                    {
                                        bool c1 = (E == 1);
                                        bool c2 = (B == 2);
                                        bool c3 = (A == 5);
                                        bool c4 = (C != 1);
                                        bool c5 = (D == 1);

                                        int sum = 0;
                                        if((A == 1) || (A == 2)) {if(c1) sum++;}
                                        else if(c1) continue;
                                        if((B == 1) || (B == 2)) {if(c2) sum++;}
                                        else if(c2) continue;
                                        if((C == 1) || (C == 2)) {if(c3) sum++;}
                                        else if(c3) continue;
                                        if((D == 1) || (D == 2)) {if(c4) sum++;}
                                        else if(c4) continue;
                                        if((E == 1) || (E == 2)) {if(c5) sum++;}
                                        else if(c5) continue;
                                        if(sum == 2)
                                        {
                                            cout<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<E<<endl;
                                            return 0;
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