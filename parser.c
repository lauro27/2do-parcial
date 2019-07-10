#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "LinkedList.h"
#include "pelicula.h"

FILE* openFILE (char* filename)
{
    FILE* ret = NULL;
    if (filename!=NULL)
    {
        ret = fopen(filename,"r");
    }
    return ret;
}
FILE* openFILEwrite(char* filename)
{
    FILE* ret = NULL;
    if (filename!=NULL)
    {
        ret = fopen(filename,"w");
    }
    return ret;
}
int parser_movieFromText(FILE* pFile , void* this)
{
    int retVal = 0;
    if (pFile!=NULL&&this!=NULL)
    {
        this = (LinkedList*)this;
        char buffer [6][128];
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        while (!feof(pFile))
        {
            ePelicula* new_movie;
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);// "%[^,],%[^,],%[^,],%[^\n]\n"
            new_movie = movie_new_text(buffer[0],buffer[1],buffer[2],buffer[3]);
            if (new_movie!=NULL)
            {
                ll_add(this,new_movie);
                retVal++;
            }
        }
    }
    return retVal;
}

int parser_MovieListToText (FILE* pFile, void* this)
{
    int retVal = 0;
    if (pFile!=NULL&&this!=NULL)
    {
        this = (LinkedList*)this;
        char name[128] , genre[128];
        int id , year;
        ePelicula* auxmov;
        int i;
        fprintf(pFile,"id,nombre,año,genero\n");
        for (i=0;i<ll_len(this);i++)
        {
            auxmov = (ePelicula*)ll_get(this,i);
            if (auxmov!=NULL)
            {
                movie_get_id(auxmov,&id);
                movie_get_name(auxmov,name);
                movie_get_genre(auxmov,genre);
                movie_get_year(auxmov,&year);
                fprintf(pFile,"%d,%s,%d,%s\n",id,name,year,genre);
            }
        }
        retVal = 0;
    }
    return retVal;
}
