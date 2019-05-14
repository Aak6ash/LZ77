#include<iostream>          //testcases from LZ77-JensMueller.pdf
#include<fstream>
#include<conio.h>
#include<string.h>
#include<math.h>

#include "LZ77decoder.h"

using namespace std;
	
string test;

string output="";

void output_generator(string offset1,string length1,char ch){
		
		int offset=0;
		int length=0; 
	
		for(int i=0;i<offset1.size();i++){
			offset=offset+(offset1[i]-'0')*(pow(10,(offset1.size()-1)-i));
		}
		
		for(int i=0;i<length1.size();i++){
			length=length+(length1[i]-'0')*(pow(10,(length1.size()-1)-i));
		}
		
		//cout<<offset<<','<<length<<','<<ch<<endl;
	
	
		if(offset==0){					//if offset is 0
            output.push_back(ch);       //then ch= last unmatched character
        }
        
        else{						//updating the decoded string using the input tuple
            int output_len=output.size();
            int n;
            for(n=0;n<length;n++){
                //output[output_len+n]=output[output_len-offset+n];
                output.push_back(output[output_len-offset+n]);
            }
            //output[output_len+n+1]=output[output_len+n+1]+ch;
            output.push_back(ch);
        }
}

void decoder(){					//decoding the input sequence of tuples to the original text
    int test_Len=test.size();
    char ch;                    //the character to be added to be added to the decoded sequence	
    
    output.push_back(test[0]);
	
    for(int i=2;i<test_Len;){	//starting from i=2 as the 1st 2 char have been dealt with above
    
	    string offset="";
	    string offlen_luc="";
	    string length="";
	    char luc;
	    
	    int flag=0;
	    
    	if(test[i+1]=='|'){
    		offset="0";
    		length="0";
    		luc=test[i];
    		i=i+2;
		}
		else{
			int temp=i;
			
			while(test[temp]!='|'){
				if(test[temp]==','){
					flag=1;
					temp=0;
					break;
				}
				else{
					temp=temp+1;
				}
			}
			
			//cout<<flag<<endl;
			
			if(flag==1){
				while(test[i]!=','){
					offset=offset+test[i];
					i=i+1;
				}
				i=i+1;
				while(test[i]!='|'){
					offlen_luc=offlen_luc+test[i];
					i=i+1;				
					} 
				i=i+1;
				luc=offlen_luc[offlen_luc.length() - 1];
				length=offlen_luc.substr(0, offlen_luc.size()-1);
			}
			else{
				while(test[i]!='|'){
					offlen_luc=offlen_luc+test[i];
					i=i+1;
				}
				i=i+1;
				luc=offlen_luc[offlen_luc.length() - 1];
				offset=offlen_luc.substr(0, offlen_luc.size()-1);
				length="1";
			}
		}
		
		
		//cout<<offset<<','<<length<<','<<ch<<endl;
		
		output_generator(offset,length,luc);
		
		
	}	
	
}

