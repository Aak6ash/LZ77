#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<sstream>  					//for std::stringstream operation
#include "LZ77encoder.cpp"		//lab-look-ahead-buff
//#include "LZ77encoder.cpp"		//sb-search-buffer

using namespace std;

//string test="";
//string test="bccacbcccccccccccaccca";
//string test="mynameisaakashandimawesome";
//string test="abracadabrad";
/*int test_Len=test.size();
int const buf_Size=16;              //buf_size is length of window
char lab[(buf_Size/2)+1]="";            //equal length of sb and lab +1 for '\0'

char sb[(buf_Size/2)+1]="";
int len=0;
int mtch_Len;*/

//ofstream comp_File;



int main(){

    std::string open("original_file.txt");
    std::stringstream sstr;
    
    std::ifstream in( open.c_str(), std::ios::binary);
    
    sstr<< in.rdbuf();
    
    string v= sstr.str();
    test_Len=v.size();
    test=v;
    
    //cout<<test<<endl;
    encoder();
	//cout<<test<<endl;
}
