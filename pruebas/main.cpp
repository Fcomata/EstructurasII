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
	cout<<cache.gettag(2,1)<<endl;
	
}
