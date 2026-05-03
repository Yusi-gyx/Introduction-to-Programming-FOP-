#include <iostream>
using namespace std;

int main()
{
    int M = 0, N = 0, K = 0;
    cin >> M >> N >> K;
    int cnt = 0;
    for (char num = M; num < N; num++)
    {
        if(cnt == K) 
        {
            cout << endl ;
            cnt = 0 ;
        }
        cout << num ;
        cnt ++ ;
    }
    return 0;
}