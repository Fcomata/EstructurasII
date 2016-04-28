#include<math.h>
#ifndef BLOQUE_H
#define BLOQUE_H
typedef unsigned long u32;
using namespace std;
class Bloque{
    public:
        Bloque();
        Bloque(int, int);
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
	int setamm;
        u32 tag;
        u32 index;
        u32 offset;
        int getoffset(int);

};

#endif // BLOQUE_H
