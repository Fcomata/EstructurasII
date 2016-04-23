#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <sstream>
#include <bitset>
#include <climits>
#include <math.h>

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

void Get_Data(string line, int length_INDEX, int length_OFFSET){

	int length_TAG=32 - (length_INDEX + length_OFFSET);
	char HEX[13]; //Linea en Hexadecimal
    	char Accion; // Si es S o L
    	char dir[8]; //los 8bits hex de la dir
    	char DIR[32]; //los bits (binario) de la dir
    	char TAG[length_TAG];
    	char INDEX[length_INDEX];
    	string Sindex;
	string Stag;
	string s; 
	

	strcpy(HEX, line.c_str());
	Accion = HEX[12];
		
	for(int i=0;i<8;i++)
	{
    		dir[i]=HEX[i];
	}

	s = string(dir);
	string BIN =HEXtoBIN(s);
	strcpy(DIR, BIN.c_str());

	
	for(int i=0; i<=32; i++){

	if(i <= length_OFFSET){}
	if(i <= length_OFFSET+length_INDEX && i> length_OFFSET) {
		INDEX	[i-length_OFFSET] = DIR[i];

		}
	if(i > length_OFFSET+length_INDEX){
		TAG	[i-(length_OFFSET+length_INDEX)] = DIR[i];
		}
		
	}

	Stag = TAG;
        Sindex = INDEX;	
	//Tag?//Index?
	newline_TAG = toInt(Stag); 
	newline_INDEX = toInt(Sindex); 
	

}



int main()
{

	int HIT;
	int MISS;
	double MISS_RATE;

	//cache[N_way][Cache_size][Block_size]
	int Block_size = 32; 		//8B, 16B, 32B, 64B
	int N_way = 4; 			//1, 2, 4
	int Cache_size = 8*1024; 	//8KB, 16KB, 32KB, 64KB
	bool flag=0;

	int Bits_block = ceil(log2(Cache_size/ (Block_size * N_way)));
	int Bits_offset = ceil(log2(Block_size));
	int Index_block = pow(2,ceil(log2(Cache_size/ (Block_size * N_way))));

	//new Cache (Index_block, N_way) --> Cantidad de sets, # de bloque por set
	

    	ifstream myfile;
    	string line; //linea leida

	string s = ""; 
        myfile.open("./../aligned.trace");
        
	//for(cada linea!){
		getline (myfile, line);
		flag=0;
		Get_Data(line, Bits_block, Bits_offset); //linea, #bits bloque, #bits offset
	
	    	cout << "newline_TAG: " << newline_TAG <<endl;
		cout << "newline_INDEX: " << newline_INDEX <<endl;

		/*

		for(n=0; n < N_way; n++){ //recorre la asociatividad
			if(Cache[newline_Index][n].tag == newline_TAG){ //Busca a ver si hay un TAG igual
				HIT++;
			} 
			else{
				MISS++; 
			
				//Politica de Reemplazo

				for(n=0; n < N_way; n++){
					if(Cache[newline_Index][n].bit_valid == 0){
						if(flag==0){ //just modified one
							Cache[newline_Index][n].tag = newline_TAG; //set tag
							Cache[newline_Index][n].bit_valid = 1; //set bit
							flag=1;
						}

					}
				}

				if(flag==0){ //if all valid, random replace
					int rand = rand() % (N_way-1); //da algun valor aleatorio entre los bloques
					Cache[newline_Index][rand].tag = newline_TAG;
				}

			}

		}


		}//end for(cada linea!)


	MISS_RATE = MISS /(MISS+HIT);




	*/


    return 0;
}


