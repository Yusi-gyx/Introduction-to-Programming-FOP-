#include<fstream>
#include<algorithm>
#include<cstdint>
#include<cmath>
#include<iostream>
using namespace std ;

#pragma pack(push , 1)
typedef struct{
    uint16_t signature ;
    uint32_t file_size ;
    uint16_t reserved1 ;
    uint16_t reserved2 ;
    uint32_t data_offset ;
} BMPFileHeader ;

typedef struct {
    uint32_t biSize ;
    int32_t biWidth ;
    int32_t biHeight ;
    uint16_t biPlanes ;
    uint16_t biBitCount ;
    uint32_t biCompression ;
    uint32_t biSizeImage ;
    int32_t biXPelsPerMeter ;
    int32_t biYPelsPerMeter ;
    uint32_t biClrUsed ;
    uint32_t biClrImportant ;
}BMPInfoHeader ;
#pragma pack(pop)

int main()
{
    ifstream fin("image.bmp" , ios::binary) ;
    BMPFileHeader fileheader ;
    BMPInfoHeader infoheader ;
    fin.read((char*)&fileheader , sizeof(BMPFileHeader)) ;
    fin.read((char*)&infoheader , sizeof(BMPInfoHeader)) ;
    int w = 500 , h = infoheader.biHeight ;
    uint8_t*** color = new uint8_t** [h] ;
    for(int i = 0 ; i < h ; i ++)
    {
        color [i] = new uint8_t* [500] ;
        for(int k = 0 ; k < 500 ; k ++)
        {
            color [i][k] = new uint8_t [3] ;
            fin.read((char*)color[i][k] , 3) ;
        }
    }
    switch(h){
        case 100 :{
            for(int i = 0 ; i < h ; i ++)
                for(int j = 0 ; j < 500 ; j ++)
                {
                    if(pow(i - 50 , 2) + pow(j - 250 , 2) > pow(50 , 2))
                    {
                        for(int k = 0 ; k < 3 ; k ++)
                        color [i][j][k] = 0 ;
                    }
                }
            break ;
        }
        case 200 :{
            for(int i = 0 ; i < h ; i ++)
                for(int j = 0 ; j < 500 ; j ++)
                {
                    if(pow(i - 100 , 2) + pow(j - 250 , 2) <= pow(100 , 2))
                    {
                        for(int k = 0 ; k < 3 ; k ++)
                        color [i][j][k] = 0 ;
                    }
                }
            break ;
        }
        case 300 :{
            for(int i = 0 ; i < h ; i ++)
                for(int j = 0 ; j < 500 ; j ++)
                {
                    if(!(j >= 250 && j <= 500 && i >= 150 && i <= 300))
                    {
                        for(int k = 0 ; k < 3 ; k ++)
                        color [i][j][k] = 0 ;
                    }
                }
            break ;
        }
        case 400 :{
            for(int i = 0 ; i < h ; i ++)
                for(int j = 0 ; j < 500 ; j ++)
                {
                    if(!(j >= 125 && j <= 375 && i >=100 && i <= 300))
                    {
                        for(int k = 0 ; k < 3 ; k ++)
                        color [i][j][k] = 0 ;
                    }
                }
            break ;
        }
        case 500 :{
            for(int i = 0 ; i < h ; i ++)
                for(int j = 0 ; j < 500 ; j ++)
                {
                    if(abs(i - j) / sqrt(2) > 25)
                    {
                        for(int k = 0 ; k < 3 ; k ++)
                        color [i][j][k] = 0 ;
                    }
                }
            break ;
        }
    }

    ofstream fout("output.bmp" , ios::binary) ;
    fout.write((char*)&fileheader , sizeof(BMPFileHeader)) ;
    fout.write((char*)&infoheader , sizeof(BMPInfoHeader)) ;
    for(int i = 0 ; i < h ; i ++)
    {
        for(int j = 0 ; j < 500 ; j ++)
        {
            for(int k = 0 ; k < 3 ; k ++)
            fout.write((char*)&color[i][j][k] , 1) ;
        }
    }

    fout.close() ;
    for(int i = 0 ; i < h ; i ++)
    {
        for(int k = 0 ; k < 500 ; k ++)
        {
            delete [] color [i][k] ;
        }
        delete [] color [i] ;
    }
    delete [] color ;

    return 0 ;
}