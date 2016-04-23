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
	cache.settag(2,1,2);
	cout<<"TAG:"<<cache.gettag(2,1)<<endl;
	cout<<"Valid:"<<cache.getvalid(2,1)<<endl;
	cache.setvalid(2,1,1);
	cout<<"Valid:"<<cache.getvalid(2,1)<<endl;
	return 0;
	
}
