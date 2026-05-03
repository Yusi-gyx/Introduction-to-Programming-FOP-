#include<fstream>  //ifstream , ofstream
#include<cstdint>  //uint16_t , uint32_t
using namespace std ;
#pragma pack(push, 1)
struct WAVHeader {
    char riff [4] ;
    uint32_t size ;
    char wave [4] ;
    char fmt [4] ;
    uint32_t fmt_size ;
    uint16_t audio_fmt ;
    uint16_t channels ;
    uint32_t sample_rate ;
    uint32_t byte_rate ;
    uint16_t block_align ;
    uint16_t bits_per_sample ;
    char data [4] ;
    uint32_t data_size ;
} ;
#pragma pack(pop)
int main ()
{
    ifstream fin ("input.wav" , ios::binary) ;
    WAVHeader phead ;
    fin.read((char*)&phead , sizeof(WAVHeader)) ;
    short* pdata = new short[phead.data_size / sizeof(short)] ;  //读取音频数据
    fin.read((char*)pdata , phead.data_size) ;
    fin.close() ;
    int num_samples = phead.data_size / 2 ;
    int k = num_samples % 6 ;

    switch(k)
    {
        case 0 :{             //剪切
        if(num_samples < 1001) ;    //采样点不足，什么都不做
        else if(num_samples < 3001)  //部分剪切
        {
            short* new_data = new short[1000] ;
            for(int i = 0 ; i < 1000 ; i ++)
            new_data [i] = pdata [i] ;
            delete [] pdata ;
            pdata = new_data ;
            num_samples = 1000 ;
        }
        else  
        {
            short* new_data = new short[num_samples - 2001];
            for(int i = 0 ; i < 1000 ; i ++)
            {
                new_data [i] = pdata [i] ;
            }
            for(int i = 3001 ; i < num_samples ; i ++)
            {
                new_data [i - 2001] = pdata [i] ;
            }
            delete [] pdata ;
            pdata = new_data ;
            num_samples -= 2001 ;
        }
        break ;
        }
        case 1 :{                 //中心削波
            int cnt = 0 ;
            int k = 0 ;
            for(int i = 0 ; i < num_samples ; i ++)  //先计数有多少个需要删除，便于计算采样点
            {
                if(pdata [i] > -800 && pdata [i] < 800)
                cnt ++ ;
            }
            short* new_data = new short [num_samples - cnt] ;
            for(int i = 0 ; i < num_samples ; i ++)
            {
                if(pdata [i] <= -800 && pdata [i] >= 800)
                {
                    new_data [k] = pdata [i] ;
                    k ++ ;
                }
                else continue ;
            }
            num_samples -= cnt ;
            delete [] pdata ;
            pdata = new_data ;
            break ;
        }
        case 2 :{                  //强制静音
        if(num_samples < 2001) ;  //采样点不足，什么都不做
        else if(num_samples < 4001)
        {
            short* new_data = new short [num_samples] ;
            for(int i = 0 ; i < 2000 ; i ++)
            new_data [i] = pdata [i] ;
            for(int i = 2000 ; i < num_samples ; i ++)
            new_data [i] = 0 ;
            delete [] pdata ;
            pdata = new_data ;
        }
        else
        {
        short* new_data = new short[num_samples] ;
        for(int i = 0 ; i < 2000 ; i ++)
        {
            new_data [i] = pdata [i] ;
        }
        for(int i = 2000 ; i < 4001 ; i ++)
        {
            new_data [i] = 0 ;
        }
        for(int i = 4001 ; i < num_samples ; i ++)
        {
            new_data [i] = pdata [i] ;
        }
        delete [] pdata ;
        pdata = new_data ;
        }
        break ;
        }
        case 3 :{                      //片段求逆
        if(num_samples < 501) ;  //采样点不足
        else if(num_samples < 2501)  //在区间内的部分求逆
        {
            short* new_data = new short [num_samples] ;
            for(int i = 0 ; i < 500 ; i ++)
            new_data [i] = pdata [i] ;
            int begin = 500 , end = num_samples - 1 ;
            for(int i = 0 ; i < num_samples ; i ++)
            {
                if(begin >= end) break ;
                new_data [begin] = pdata [end] ;
                new_data [end] = pdata [begin] ;
                begin ++ ;
                end -- ;
            }
            delete [] pdata ;
            pdata = new_data ;
        }
        else
        {
            short* new_data = new short [num_samples] ;
            for(int i = 0 ; i < 500 ; i ++)
            {
                new_data [i] = pdata [i] ;
            }
            for(int i = 500 ; i < 2501 ; i ++)
            {
                new_data [i] = pdata [3000 - i] ;
            }
            for(int i = 2501 ; i < num_samples ; i ++)
            {
                new_data [i] = pdata [i] ;
            }
            delete [] pdata ;
            pdata = new_data ;
        }
        break ;
        }
        case 4 :{                         //截顶处理
        short* new_data = new short [num_samples] ;
        for(int i = 0 ; i < num_samples ; i ++)
        {
            if(pdata [i] > 1000) new_data [i] = 1000 ;
            else if(pdata [i] < -1000) new_data [i] = -1000 ;
            else new_data [i] = pdata [i] ;
        }
        delete [] pdata ;
        pdata = new_data ;
        break ;
        }
        case 5 :{                        //加噪声
        short* new_data = new short [num_samples] ;
        int cnt = 1000 ;
        for(int i = 0 ; i < num_samples ; i ++)
        {
            int m = 1000 - (i % 2001) ;
            if(m < 0) m = -m ;
            new_data [i] = pdata [i] + m ;
        }
        delete [] pdata ;
        pdata = new_data ;
        break ;
    }
    }
    phead.data_size = 2 * num_samples ;
    phead.size = 4 + (8 + phead.fmt_size) + (8 + phead.data_size) ;
    ofstream fout ("output.wav" , ios::binary) ;
    fout.write((char*)&phead , sizeof(WAVHeader)) ;
    fout.write((char*)pdata , sizeof(short) * num_samples) ;
    fout.close() ;
    delete [] pdata ;
    return 0 ;
}