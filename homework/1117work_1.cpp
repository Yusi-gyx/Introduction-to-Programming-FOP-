#include<iostream>
#include<vector>
using namespace std ;

vector<int>& check_array (char m , vector<int> &A , vector<int> &B , vector<int> &C)
{
    if(m == 'A') return A ;
    else if(m == 'B') return B ;
    else return C ;
}
void output_1 (vector<int> A)
{
    for(int i = 0 ; i < A.size() ; i ++)
    {
        if(A [i] != 0) cout << A [i] << " " ;
        else break ;
    }
}
void output (vector<int> A , vector<int> B , vector<int> C)
{
    output_1(A) ; cout << endl ;
    output_1(B) ; cout << endl ;
    output_1(C) ; 
}

int main()
{
    int N = 0 ;
    cin >> N ;
    vector<int> A(N) , B , C ;
    for(int i = 0 ; i < N ; i ++)
    {
        cin >> A [i] ;
    }
    int M = 0 ;
    cin >> M ;
    char** inst = new char* [M] ;
    for(int i = 0 ; i < M ; i ++)
    {
        inst [i] = new char [2] ;
        cin >> inst [i][0] >> inst [i][1] ;
    }

    output(A , B , C) ;
    cout << endl ;
    vector<int> *from , *to ;
    for(int i = 0 ; i < M ; i ++)
    {
        if(A.size() == 0 && B.size() == 0) break ;
        from = &check_array(inst [i][0] , A , B , C) ;
        to = &check_array(inst [i][1] , A , B , C) ;
        if(from->size() == 0) 
        {
            cout << "ERROR" ;
            break ;
        }
        if(to->size() != 0)
        {
            if(from->back() > to->back()) 
            {
                cout << "ERROR" ;
                break ;
            }
        }
        to->push_back(from->back()) ;
        from->pop_back() ;
        output(A , B , C) ;
        if(i != M - 1) cout << endl ;
    }


    for(int i = 0 ; i < M ; i ++)
    {
        delete [] inst [i] ;
    }
    delete [] inst ;

    return 0 ;
}