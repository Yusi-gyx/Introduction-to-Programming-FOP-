#include <iostream>
using namespace std;


int** transposeMatrix (int** a ,int b , int c)
{
    int** d ;
    d = new int* [c] ;
    for(int i = 0 ; i < c ; i ++)
    d [i] = new int [b] ; 
    for(int i = 0 ; i < b ; i ++)
    {
        for(int j = 0 ; j < c ; j ++)
        {
            d [j][i] = a [i][j] ;
        }
    }
    return d ;
}



/// 实现transposeMatrix函数
int main() {
    int M, N;
    cin >> M >> N;

    /// 声明指针original、transposed
    int **original ;
    int **transposed ;



    /// 动态分配原始矩阵original
    original = new int* [M] ;
    for(int i = 0 ; i < M ; i ++)
    original [i] = new int [N] ;




// 输入原始矩阵
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> original[i][j];
        }
    }

    /// transposeMatrix 对传入矩阵做转置操作并返回结果
    transposed = transposeMatrix(original, M, N);

    // 输出转置矩阵
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    // 释放动态分配的原始矩阵
    for (int i = 0; i < M; i++) {
        delete[] original[i];
    }
    delete[] original;

    // 释放动态分配的转置矩阵
    for (int i = 0; i < N; i++) {
        delete[] transposed[i];
    }
    delete[] transposed;

    return 0;
}