#include "Bloque.h"
Bloque::Bloque(){
	this->blocksize = 0;
	this->setamm = 0;
	this->valid = 0;
	this->tag =0;
	this->index =0;
	this->offset =0;
}
Bloque::Bloque(int tamano, int setammount){
	this->blocksize = tamano;
	this->setamm = setammount;
	this->valid = 0;
	this->tag =0;
	this->index =0;
	this->offset =0;
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
