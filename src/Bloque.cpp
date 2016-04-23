#include "Bloque.h"
Bloque::Bloque(){
    this->address = 0;
    this->blocksize = 0;
    this->blockoffsetlen = 0;
    this->indexlen = 0;
    this->taglen = 0;
    this->valid = 0;
}
Bloque::Bloque(u32 direccion, int tamano, int setammount){
    this->address = direccion;
    this->blocksize = tamano;
    this->blockoffsetlen = getoffset(tamano);
    this->indexlen = getoffset(setammount);
    this->taglen = 32 - this->blockoffsetlen -this->indexlen;
    this->valid = 1;
}
int Bloque::getoffset(int value){
    return log2(value);
}
Bloque::~Bloque()
{
    //dtor
}
