#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <bitset>
#include <climits>


using namespace std;

unsigned int newline_TAG;
unsigned int newline_INDEX;


const char* hex_char_to_bin(char c)
{
 
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

string HEXtoBIN(const string&  hex)
{
    string bin;
    for(int i = 0; i < sizeof(hex); i++){
       bin += hex_char_to_bin(hex[i]);
	}
    return bin;
}

unsigned int toInt(const std::string &s)
{
    unsigned int n = 0;

    for (int i = 0; i < s.size(); i++) {
	if(s[i]=='1' || s[i]=='0'){
        n <<= 1;
        n |= s[i] - '0';}
    }

    return n;
}


int main()
{
    	ifstream myfile;
    	string line; //linea leida
    	char HEX[13]; //Linea en Hexadecimal
    	char Accion; // Si es S o L
    	char dir[8]; //los 8bits hex de la dir
    	char DIR[32]; //los bits (binario) de la dir


    	
    	int length_INDEX=10;
    	int length_OFFSET=4;
	int length_TAG=32 - (length_INDEX + length_OFFSET);
    	char TAG[length_TAG];
    	string Stag;
    	char INDEX[length_INDEX];
    	string Sindex;

	//for(cada linea!)
 
	string s = ""; 
        myfile.open("./../aligned.trace");
        cout << endl;
        getline (myfile, line);
	strcpy(HEX, line.c_str());

	//for(int i=0;i<13;i++){
    	//	cout << i << " : "<< HEX[i] << endl;
	//}

	Accion = HEX[12];
	//cout << Accion <<endl;
	
	
	for(int i=0;i<8;i++)
	{
    		dir[i]=HEX[i];
	}

	s = string(dir);
	//cout << "s: " << s <<endl;
	string BIN =HEXtoBIN(s);
	strcpy(DIR, BIN.c_str());

	
	for(int i=0; i<=32; i++){

	if(i <= length_OFFSET){}
	if(i <= length_OFFSET+length_INDEX && i> length_OFFSET) {
		INDEX	[i-length_OFFSET] 		 = DIR[i];
		//cout << "INDEX ["<<i-length_OFFSET<<"]: "<< DIR[i]<<endl;
		}
	if(i > length_OFFSET+length_INDEX){
		TAG	[i-(length_OFFSET+length_INDEX)] = DIR[i];
		}
		
	}

	Stag = TAG;
	cout << "Stag:" << Stag << endl;
        Sindex = INDEX;
	cout << "Sindex:" << Sindex<<  endl;	
	//Tag?//Index?
	newline_TAG = toInt(Stag); 
	cout << "newline_TAG: " << newline_TAG <<endl;
	newline_INDEX = toInt(Sindex); 
	cout << "newline_INDEX: " << newline_INDEX <<endl;

	//newline_TAG
	//newline_INDEX

	



    return 0;
}


