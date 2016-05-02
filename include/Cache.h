/*  This file is part of EstructurasII.

    EstructurasII is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/
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


