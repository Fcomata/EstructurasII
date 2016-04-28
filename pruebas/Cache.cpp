#include "Cache.h"
#include <iostream>
#include <bitset>
using namespace std;
Cache::Cache(){
	this->blockamm =0;
	this->sets =0;
	this->blocksize =0;
	vector<Bloque> setdir (this->sets, Bloque(this->blocksize,this->sets));
	vector< vector<Bloque> > precache (blockamm, setdir);
	this->cache = precache;
	this->blockquant =0;
	this->tagquant =0;
	this->indexquant =0;
	this->hits =0;
	this->misses =0;
}
Cache::Cache(int set, int blocks, int blocksizes){
	this->blockamm = blocks;
	this->sets = set;
	//cout << "sets: " << this->sets <<endl;
	this->blocksize = blocksizes;
	vector<Bloque> setdir (this->blockamm, Bloque(this->blocksize,this->sets));
	vector< vector<Bloque> > precache (this->sets, setdir);
	this->cache = precache;
	this->blockquant = log2(this->blocksize);
	this->indexquant = log2(sets);
	this->tagquant = 32 -blockquant - indexquant;
	//cout<<this->tagquant<<endl;
	this->hits =0;
	this->misses =0;
	
}
Cache::~Cache(){
	
}
void Cache::settag(u32 memaddress){
	//cout<<bitset<32>(memaddress)<<endl;
	bool miss = 1;
	u32 tag,index,temp;
	int set,assoc;
	//cout<<"1"<<endl;
	temp = blockquant+indexquant;
	//cout<<"2"<<endl;
 	tag = memaddress >> temp;
	//cout<<bitset<32>(tag)<<endl;
	//cout<<"3"<<endl;
	temp = tag << temp;
	//cout<<"4"<<endl;
	temp = memaddress - temp;
	//cout<<"5"<<endl;
	index = temp >> blockquant;
	//cout<<"6"<<endl;
	set = (int) index;
	//cout<< set<<endl;
	//cout<<"7"<<endl;
	for(int i = 0; i<this->blockamm;i++){
		//cout<<"for"<<endl;
		if(tag == this->gettag(set,i) && this->getvalid(set,i)){
		//	cout<<"entro"<<endl;
			miss = 0;
			this->hits++;
			break;
		}
	}
//	cout<<"salidelfor"<<endl;
	if(miss){
		assoc = this->getassoc(set);
		this->cache[set][assoc].settag(tag);
		this->setvalid(set,assoc,1);
		this->misses++;
	}
}

u32 Cache::gettag(int set, int assoc){
	return this->cache[set][assoc].gettag();	
}

void Cache::setvalid(int set, int assoc, bool valid){
	this->cache[set][assoc].setvalid(valid);
}
bool Cache::getvalid(int set, int assoc){
	return this->cache[set][assoc].getvalid();
}
int Cache::getassoc(int index){
	int randint;
	int notvalid[this->blockamm];
	int j =0;
	srand (time(NULL));
	for(int i =0; i < this->blockamm; i++){
				

		if(!this->getvalid(index,i)){ //Si es un bit invalido			
			notvalid[j] = i; //Guarda en un vector de no validos la posicion del bloque no valido
			j++;		
		}
				
	}
	if(j==0){// todos son validos
		randint = rand()%sets; //randomreplace en sets;
		return randint;
	}
	else{
		randint = rand()%j;//randomreplace con j
		return notvalid[randint];
	}		
}
int Cache::getmisses(){
	return this->misses;	
}
int Cache::gethits(){
	return this->hits;
}





