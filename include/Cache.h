#include "Bloque.h"
#include <vector>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef CACHE_H
#define CACHE_H
class Cache{
	public:
		Cache();
		Cache(int, int, int);
		virtual ~Cache();
		void settag(u32);
		u32 gettag(int, int);
		u32 gettag(u32);
		int getmisses();
		int gethits();
	protected:
		
	private:
		int getassoc(int);
		void setvalid(int, int, bool);
		bool getvalid(int, int);
		int blockquant;
		int indexquant;
		int tagquant;
		int blockamm;
		int sets;
		int blocksize;
		vector< vector<Bloque> > cache;
		int misses;
		int hits;
};

#endif //CACHE_H


