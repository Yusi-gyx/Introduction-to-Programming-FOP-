#include<iostream>
#include<string>
using namespace std ;

struct place {
    int x ;
    int y ;
}  ;

place findplace(int N)
{
    int col = 0 ;
    int row = 0 ;
    place cplace ;
    for(int i = 0 ; i < N * N ; i ++)
    {
        if(col % N == 0 && col != 0) 
        {
            col = 0 ;
            row ++ ;
        }
        char ch ;
        cin >> ch ;
        if(ch == '_') 
        {
            col ++ ;
            continue ;
        }
        else
        {
            cplace.x = row ;
            cplace.y = col ;
        }
    }
    return cplace ;
}

void output(place cplace , int N)
{
    int row = 0 ;
    int col = 0 ;
    for(int i = 0 ; i < N * N ; i ++)
    {
        if(col % N == 0 && col != 0) 
        {
            col = 0 ;
            row ++ ;
            cout << endl ;
        }
        if(row == cplace.x && col == cplace.y)
        {
            cout << "H " ;
            col ++ ;
        }
        else
        {
            cout << "_ " ;
            col ++ ;
        }
    }
    cout << endl ;
    cout << endl ;
}

place motion_w(place cplace , int N)
{
    if(cplace.x - 1 < 0) 
    {
        output(cplace , N) ;
    }
    else
    {
        cplace.x -- ;
        output(cplace , N) ;
    }
    return cplace ;
}

place motion_s(place cplace , int N)
{
    if(cplace.x + 1 >= N)
    {
        output(cplace , N) ;
    }
    else
    {
        cplace.x ++ ;
        output(cplace , N) ;
    }
    return cplace ;
}

place motion_a(place cplace , int N)
{
    if(cplace.y - 1 < 0)
    {
        output(cplace , N) ;
    }
    else
    {
        cplace.y -- ;
        output(cplace , N) ;
    }
    return cplace ;
}

place motion_d(place cplace , int N)
{
    if(cplace.y + 1 >= N)
    {
        output(cplace , N) ;
    }
    else
    {
        cplace.y ++ ;
        output(cplace , N) ;
    }
    return cplace ;
}


int main ()
{
    int N = 0 ;
    cin >> N ;
    place cplace = findplace(N) ;  //找到一开始H的位置
    string inst ;
    cin.ignore() ;
    getline(cin , inst) ;
    int len = inst.length() ;
    if(len == 0) 
    {
        output(cplace , N) ;
        return 0 ;
    }
    for(int i = 0 ; i < len ; i ++)
    {
        switch(inst [i]){
            case 'w' :{
                cplace = motion_w(cplace , N) ;
                break ;
            }
            case 's' :{
                cplace = motion_s(cplace , N) ;
                break ;
            }
            case 'a' :{
                cplace = motion_a(cplace , N) ;
                break ;
            }
            case 'd' :{
                cplace = motion_d(cplace , N) ;
                break ;
            }
        }
    }

    return 0 ;
}