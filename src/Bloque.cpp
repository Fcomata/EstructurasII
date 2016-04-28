#include "Bloque.h"
Bloque::Bloque(){
	this->blocksize = 0;
	this->valid = 0;
	this->tag =0;
	this->index =0;
	this->offset =0;
}
Bloque::Bloque(const Bloque& other){
	this->blocksize = other.blocksize;
	this->valid = other.valid;
	this->tag = other.tag;
	this->index = other.index;
	this->offset = other.offset;
}
Bloque::Bloque(int tamano){
	this->blocksize = tamano;
	this->valid = 0;
	this->tag =0;
	this->index =0;
	this->offset =0;
}

Bloque &Bloque::operator=(const Bloque& other){
	if(this!= &other){
		this->blocksize = other.blocksize;
		this->valid = other.valid;
		this->tag = other.tag;
		this->index = other.index;
		this->offset = other.offset;
	}
	return *this;
}
int Bloque::getoffset(int value){
    return log2(value);
}
void Bloque::settag(u32 tag){
	this->tag = tag;
}

u32 Bloque::gettag(void){
	return this->tag;
}
bool Bloque::getvalid(void){
	return this->valid;
}
void Bloque::setvalid(bool valid){
	this->valid = valid;
}

Bloque::~Bloque()
{
    //dtor
}
