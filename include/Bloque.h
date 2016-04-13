#ifndef BLOQUE_H
#define BLOQUE_H
typedef unsigned long u32
class Bloque
{
    public:
        Bloque();
        Bloque(u32, int, int);
        virtual ~Bloque();

    protected:

    private:
        int blocksize;
        bool valid;
        int taglen;
        int indexlen;
        int blockoffsetlen;
        u32 address;
        int getoffset(int);

};

#endif // BLOQUE_H
