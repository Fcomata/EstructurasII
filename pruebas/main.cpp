#include "Cache.h"
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

int main(){
	Cache cache(3,8,3);
	cout<<"Aun no se lee/escribe nada, solo se inicializo el cache"<<endl;
	cout<<"Misses: "<<cache.getmisses()<<endl;
	cout<<"Hits: "<<cache.gethits()<<endl;
	cout<<"Se le lee/escribe una direccion de memoria de 4294967"<<endl;
	cache.settag(4294967);
	cout<<"Misses: "<<cache.getmisses()<<endl;
	cout<<"Hits: "<<cache.gethits()<<endl;
	cout<<"Se lee/escribe una direccion de memoria de 4294967(de nuevo)"<<endl;
	cache.settag(4294967);
	cout<<"Misses: "<<cache.getmisses()<<endl;
	cout<<"Hits: "<<cache.gethits()<<endl;
	cout<<"Se lee/escribe una direccion de memoria de 4294966"<<endl;
	cache.settag(4294966);
	cout<<"Misses: "<<cache.getmisses()<<endl;
	cout<<"Hits: "<<cache.gethits()<<endl;
	cout<<"Se lee/escribe una direccion de memoria de 1231231"<<endl;
	cache.settag(1231231);
	cout<<"Misses: "<<cache.getmisses()<<endl;
	cout<<"Hits: "<<cache.gethits()<<endl;
	return 0;
	
}
