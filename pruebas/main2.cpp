#include "Cache.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	string aux, str;
	u32 auxi;
	int argvi[3];
	Cache my_cache;
	if(argc !=4){
		cout<<"Invalid Argument."<< endl;
		return 0;
	}
	for(int i =0; i<3; i++){
		//cout<<"for " << i<< endl;
		argvi[i] = atoi(argv[i+1]);
		//cout<<argvi[i]<<endl;
	}
	//cout<<"Se creará el cache"<<endl;
	my_cache = Cache(argvi[1],argvi[0],argvi[2]);
	//cout<<"Se creo el cache"<<endl;
	//cout<<"Se cargará el archivo memoria"<<endl;
	ifstream file("aligned.trace");
	//cout<<"Se cargó el archivo en memoria"<<endl;
	while(getline(file,str)){
	//	cout<<"While"<< endl;
		aux = "0x" + str.substr(0,8); // toma los 8 primeros caracteres.
	//	cout<<"Se toman los 8 primeros caracteres"<<endl;
		auxi = stoul(aux,nullptr,16);
	//	cout<<"Se convierte en u32"<<endl;
		//cout<<auxi<<endl;
		my_cache.settag(auxi);
	//	cout<<"Se guarda en el cache"<<endl;
		//cout<<"Misses: "<< my_cache.getmisses() << endl;
		//cout<<"Hits: " << my_cache.gethits() <<endl;
	}
	cout<<"Misses: "<< my_cache.getmisses() << endl;
	cout<<"Hits: " << my_cache.gethits() <<endl;

}
