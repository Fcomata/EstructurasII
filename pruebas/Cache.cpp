#include "Cache.h"
Cache::Cache(){
	this->blockamm =0;
	this->sets =0;
	this->blocksize =0;
	vector<Bloque> setdir (this->sets, Bloque(this->blocksize,this->sets));
	vector< vector<Bloque> > precache (blockamm, setdir);
	this->cache = precache;
}
Cache::Cache(int set, int blocks, int blocksizes){
	this->blockamm = blocks;
	this->sets = set;
	this->blocksize = blocksize;
	vector<Bloque> setdir (this->sets, Bloque(this->blocksize,this->sets));
	vector< vector<Bloque> > precache (blockamm, setdir);
	this->cache = precache;
}
Cache::~Cache(){
	
}
void Cache::settag(int set, int assoc, u32 tag){
	this->cache[set][assoc].settag(tag);
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






