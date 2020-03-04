#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include "header.h"

void citire(numar a[9][9],struct fisier fisier1)
{
    int i,j;

    for(i=0; i<9 ;i++)
      for(j=0; j<9; j++)
       {
           fscanf(fisier1.f,"%d",&a[i][j].val);

         if(a[i][j].val)
           a[i][j].obl='y';
         else
           a[i][j].obl='n';

       }

}

int succesor(int *a)
{
    if(*a<9)
    {
        *a++;
        return true;
    }
    return false;
}

int verifC(numar b[9][9],int i,int j)
{
   int r=0,v[9],k;

   for(k=0; k<9 ;k++)
        v[k]=0;

   for(k=0 ;k<9 && !r;k++)
       {
        v[b[k][j].val]++;

        if(v[b[k][j].val]>1)
         r++;
        }
    if(r)
        return false;
    else
        return true;

}

int verifL(numar b[9][9],int i,int j)
{
    int r=0,v[9],k;

    for(k=0;k<9;k++)
        v[k]=0;

    for(k=0 ; k<9 && !r ;k++)
       {
        v[b[i][k].val]++;

        if(v[b[i][j].val]>1)
            r++;
       }

    if(r)
      return false;
    else
      return true;


}

int verif3x3(numar b[9][9],int i,int j)
{
    int r=0,v[9],k;

    for(k=0;k<9;k++)
        v[k]=0;

   if(i<3)
        {
            if(j<3)
               {
                for(i=0;i<3;i++)
                 for(j=0;j<3;j++)
                   v[b[i][j].val]++;
               }
            if(j>=3&&j<6)
               {
               for(i=0;i<3;i++)
                    for(j=3;j<6;j++)
                     v[b[i][j].val]++;
               }
            if(j>=6)
            {
                for(i=0;i<3;i++)
                    for(j=6;j<9;j++)
                     v[b[i][j].val]++;
            }
        }
        if(i>=3&&i<6)
            {
            if(j<3)
               {
                for(i=3;i<6;i++)
                 for(j=0;j<3;j++)
                   v[b[i][j].val]++;
               }
            if(j>=3&&j<6)
               {
                for(i=3;i<6;i++)
                    for(j=3;j<6;j++)
                     v[b[i][j].val]++;
               }
            if(j>=6)
              {
                  for(i=3;i<6;i++)
                    for(j=6;j<9;j++)
                     v[b[i][j].val]++;
              }
           }
        if(i>=6)
            {
            if(j<3)
               {
                for(i=6;i<9;i++)
                 for(j=0;j<3;j++)
                   v[b[i][j].val]++;
               }
            if(j>=3&&j<6)
               {
                for(i=6;i<9;i++)
                    for(j=3;j<6;j++)
                     v[b[i][j].val]++;
               }
            if(j>=6)
               {
                for(i=6;i<9;i++)
                    for(j=6;j<9;j++)
                     v[b[i][j].val]++;
               }
           }

    for(i=1;i<=9;i++)
        if(v[i]>1)
            r++;

    if(r)
        return false;
    else
        return true;
}

int valid(numar a[9][9],int i,int j)
{

   if(verifC(a,i,j)+verif3x3(a,i,j)+verifL(a,i,j)==3)
        return true;
    else
        return false;
}

void tipar(numar a[9][9],struct fisier solved,int k)
{
    int i=0,j=0;
    if(k)
     for(i=0;i<9;i++)
     { fprintf(solved.f,"\n");
        for(j=0;j<9;j++)
           fprintf(solved.f,"%d%c",a[i][j].val,' ');
     }
     else
     {
           fprintf(solved.f,"nerezolvabil\n");
     }

}

int rezolvare(numar a[9][9])
{
    int i,j,gasit=0,as;

    for(i=0 ;i<9 && gasit ==0; i++)
        for(j=0; j<9 && gasit==0 ;j++)
          if(a[i][j].obl=='n')
             gasit=1;

    while(i<=9)
    {
        do as=succesor(&a[i][j].val);
        while(as && !valid(a,i,j));

        if(as)
          {if(i==9&&j==9)
              return true;

           else
           {
               do
               {
                   if(j==9)
                   {
                       i++;
                       j=0;
                   }
                   else
                       j++;

               }while(a[i][j].obl=='y');

               a[i][j].val=0;
            }
          }
        else
          {
            do{
              if(j==0)
                {
                    i--;
                    j=9;
                }
              else
                 j--;

             }while(a[i][j].obl=='y');

             a[i][j].val=0;
          }
     }

     if(i<0)
        return false;


}

#endif // FUNCTII_H_INCLUDED
