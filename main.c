#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "functii.h"


int main()
{
    int x=1,afis;
    numar m[9][9];
    struct fisier nerezolvate,rezolvate;


    nerezolvate.f=fopen("fisier1","r");
    rezolvate.f=fopen("fisier2","w");

    //while(x<=NR_SUD)
     // {
          citire(m,nerezolvate);
          afis=rezolvare(m);
          tipar(m,rezolvate,afis);
          x++;
      //}

    fclose(rezolvate.f);
    fclose(nerezolvate.f);

  return 0;
}

