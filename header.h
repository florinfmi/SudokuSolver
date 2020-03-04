#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#define NR_SUD 50

enum{false,true};

typedef struct
{
    // val este valoarea propriu-zisa a casutei iar obl specifica daca poate fi schimbata sau nu
    int val ;
    char obl;
}numar;

struct fisier
{
    char nume[20];
    FILE *f;
    long int dim;

};

#endif // HEADER_H_INCLUDED
