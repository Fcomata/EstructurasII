/*  
    This file is part of EstructurasII.

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
#include<math.h>
#ifndef BLOQUE_H
#define BLOQUE_H
typedef unsigned long u32;
using namespace std;
class Bloque{
    public:
        Bloque();
        Bloque(int);
	Bloque(const Bloque&);
	Bloque &operator=(const Bloque&);
        virtual ~Bloque();
	void settag(u32);
	u32 gettag(void);
	bool getvalid(void);
	void setvalid(bool);
    protected:

    private:
        int blocksize;
        bool valid;
        u32 tag;
        u32 index;
        u32 offset;
        int getoffset(int);

};

#endif // BLOQUE_H
