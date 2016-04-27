#include "Bloque.h"
#include <vector>
#include <math.h>
#include <time.h>
#include <stdio.h>
#ifndef CACHE_H
#define CACHE_H
class Cache{
	public:
		Cache();
		Cache(int, int, int);
		virtual ~Cache();
		void settag(u32);
		u32 gettag(int, int);
		void setvalid(int, int, bool);
		bool getvalid(int, int);
		int getassoc(int);
	protected:
		
	private:
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


