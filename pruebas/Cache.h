#include "Bloque.h"
#include <vector>
#ifndef CACHE_H
#define CACHE_H
class Cache{
	public:
		Cache();
		Cache(int, int, int);
		virtual ~Cache();
		void settag(int, int, u32);
		u32 gettag(int, int);
	protected:
		
	private:
		int blockamm;
		int sets;
		int blocksize;
		vector< vector<Bloque> > cache;
};

#endif //CACHE_H


