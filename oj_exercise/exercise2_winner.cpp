#include<iostream>
using namespace std;

int main()
{
    for(int A = 1;A <= 5;A++)
    {
        for(int B = 1;B <= 5;B++)
        {
            if(A == B) continue;
            for(int C = 1;C <= 5;C++)
            {
                if((C == A) || (C == B)) continue;
                for(int D = 1;D <= 5;D++)
                {
                    if((D == C) || (D == B) || (D == A)) continue;
                    for(int E = 1;E <= 5;E++)
                    {
                        if((E == D) || (E == C) || (E == B) || (E == A)) continue;

                        int c1 = (B == 5) + (D == 3);
                        int c2 = (A == 1) + (E == 3);
                        int c3 = (C == 4) + (D == 2);
                        int c4 = (B == 3) + (E == 5);

                        if((c1 == 1) && (c2 == 1) && (c3 == 1) && (c4 == 1))
                        {
                            if(A == 1) cout<<"百米"<<" ";
                            if(A == 2) cout<<"四百米"<<" ";
                            if(A == 3) cout<<"跳高"<<" ";
                            if(A == 4) cout<<"跳远"<<" ";
                            if(A == 5) cout<<"三级跳"<<" ";
                            if(B == 1) cout<<"百米"<<" ";
                            if(B == 2) cout<<"四百米"<<" ";
                            if(B == 3) cout<<"跳高"<<" ";
                            if(B == 4) cout<<"跳远"<<" ";
                            if(B == 5) cout<<"三级跳"<<" ";
                            if(C == 1) cout<<"百米"<<" ";
                            if(C == 2) cout<<"四百米"<<" ";
                            if(C == 3) cout<<"跳高"<<" ";
                            if(C == 4) cout<<"跳远"<<" ";
                            if(C == 5) cout<<"三级跳"<<" ";
                            if(D == 1) cout<<"百米"<<" ";
                            if(D == 2) cout<<"四百米"<<" ";
                            if(D == 3) cout<<"跳高"<<" ";
                            if(D == 4) cout<<"跳远"<<" ";
                            if(D == 5) cout<<"三级跳"<<" ";
                            if(E == 1) cout<<"百米"<<" ";
                            if(E == 2) cout<<"四百米"<<" ";
                            if(E == 3) cout<<"跳高"<<" ";
                            if(E == 4) cout<<"跳远"<<" ";
                            if(E == 5) cout<<"三级跳"<<" ";
                            return 0;
                        }
                    }
                }
            }
        }
    }
}