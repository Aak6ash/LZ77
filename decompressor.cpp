#include<iostream>          //testcases from LZ77-JensMueller.pdf
#include<fstream>
#include<conio.h>
#include<string.h>
//#include "LZ77decoder.h"
#include "decompression.cpp"


using namespace std;

ifstream iFile;

//string test;

int main(){

    iFile.open("compressed_file.txt");
    if(iFile){
        //infile>>test;
        iFile>>test;
        iFile.close();
    }
    else{
        cout<<"File error !!!";
    }

    decoder();
    ofstream oFile;
    oFile.open("decompressed_file.txt");
    oFile<<output;
    oFile.close();


}



