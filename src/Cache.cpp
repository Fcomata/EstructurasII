#include "Cache.h"
Cache::Cache(){
	this->blockamm =0;
	this->sets =0;
	this->blocksize =0;
}
Cache::Cache(int set, int blocks, int blocksizes){
	this->blockamm = blocks;
	this->sets = set;
	this->blocksize = blocksize;
	vector<Bloque> setdir (this->sets, Bloque(this->blocksize,this->sets));
	vector< vector<Bloque> > precache (blockamm, setdir);
	this->cache = precache;
}



