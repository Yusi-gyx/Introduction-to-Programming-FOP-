#include<fstream>  //ifstream , ofstream
#include<vector>   //vector
#include<string>  //string
#include<sstream>
using namespace std ;

bool check_inst (vector <string> limit_inst , string inst , int M , int N , int K)
{
    string str_1 ;
    istringstream iss(inst) ;
    iss >> str_1 ;
    double num = -1 ;

    int ifinclude = 1 ;   //先判断指令是否包含
    for(int i = 0 ; i < M ; i ++)
    {
        ifinclude = str_1.compare(limit_inst [i]) ;  //如果相等就返回0
        if(!ifinclude) break ;
    }
    if(ifinclude) return false ;

    if(str_1 == "inbox" || str_1 == "outbox")  //不能有指令数字的指令
    {
        string str_2 ;
        if(iss >> str_2)  return false ;
        return true ;
    }

    if(str_1 == "add" || str_1 == "sub" || str_1 == "copyto" || str_1 == "copyfrom")  //指令数字是空地的指令
    {
        if(!(iss >> num)) return false ;  //需要指令数字但是没有
        if((int)num != num) return false ; //数字不是整数
        if(num < 0 || num >= N) return false ; //空地超出界限
        double num_2 = 0 ;
        if(iss >> num_2) return false ; //指令数超过1
        return true ;
    }

    if(str_1 == "jump" || str_1 == "jumpifzero")
    {
        if(!(iss >> num)) return false ;  //需要指令数字但是没有
        if((int)num != num) return false ; //数字不是整数
        if(num < 1 || num > K) return false ; //指令数超出界限 
        double num_2 = 0 ;
        if(iss >> num_2) return false ; //指令数超过1
        return true ;
    }

    return false ;  //默认返回false，处理其他情况
}


int main ()
{
    ifstream fin("input.txt") ;
    ofstream fout("output.txt") ;

    int N , M ;  //N是空地，M是指令
    fin >> N >> M ;

    vector <string> limit_inst (M) ;
    for(int i = 0 ; i < M ; i ++)
    {
        fin >> limit_inst [i] ;
    }

    int K ;  //K是接下来的指令的行数
    fin >> K ;
    vector <bool> check (K) ;

    string temp ;
    getline (fin , temp) ; //消除第一个换行符

    for(int i = 0 ; i < K ; i ++)
    {
        string inst ;
        getline(fin , inst) ;
        check [i] = check_inst(limit_inst , inst , M , N , K) ;

        if(check [i]) fout << "OK" << endl ;
        else fout << "Error" << endl ;
    }

    fin.close() ;
    fout.close() ;

    return 0 ;
}