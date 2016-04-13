#include "Bloque.h"

Bloque::Bloque(u32 direccion, int tamaño, int setammount){
    this->address = direccion;
    this->blocksize = tamaño;
    this->blockoffset = getoffset(tamaño);
    this->indexlen = getoffset(setammount);
    this->taglen = 32 - this->blockoffset -this->indexlen;
    this->valid = 1;
}
int Bloque::getoffset(int value){
    return log2(value);
}
Bloque::~Bloque()
{
    //dtor
}
