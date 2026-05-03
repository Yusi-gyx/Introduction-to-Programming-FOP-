#include<iostream>
using namespace std;

int main()
{
    for(int dong = 1;dong <= 4;dong++)
    {
        for(int hong = 1;hong <= 4;hong++)
        {
            if(dong != hong)
            {
                for(int po = 1;po <= 4;po++)
                {
                    if((po != dong) && (po != hong))
                    {
                        for(int tai = 1;tai <= 4;tai++)
                        {
                            if((tai != po) && (tai != hong) && (tai != dong))
                            {
                                int c1 = (dong == 1) + (hong == 4) + (po == 3);
                                int c2 = (hong == 1) + (dong == 4) + (po == 2) + (tai == 3);
                                int c3 = (hong == 4) + (dong == 3);
                                int c4 = (po == 1) + (tai == 4) + (hong == 2) + (dong == 3);

                                if((c1 == 1) && (c2 == 1) && (c3 == 1) && (c4 == 1))
                                {
                                    if(dong == 1) cout<<"洞庭湖"<<" ";
                                    if(hong == 1) cout<<"洪泽湖"<<" ";
                                    if(po == 1) cout<<"鄱阳湖"<<" ";
                                    if(tai == 1) cout<<"太湖"<<" ";
                                    if(dong == 2) cout<<"洞庭湖"<<" ";
                                    if(hong == 2) cout<<"洪泽湖"<<" ";
                                    if(po == 2) cout<<"鄱阳湖"<<" ";
                                    if(tai == 2) cout<<"太湖"<<" ";
                                    if(dong == 3) cout<<"洞庭湖"<<" ";
                                    if(hong == 3) cout<<"洪泽湖"<<" ";
                                    if(po == 3) cout<<"鄱阳湖"<<" ";
                                    if(tai == 3) cout<<"太湖"<<" ";
                                    if(dong == 4) cout<<"洞庭湖"<<" ";
                                    if(hong == 4) cout<<"洪泽湖"<<" ";
                                    if(po == 4) cout<<"鄱阳湖"<<" ";
                                    if(tai == 4) cout<<"太湖"<<" ";
                                    break;
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