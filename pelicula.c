#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"
#include "LinkedList.h"

int movie_get_id (ePelicula* ptrmov,int* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrmov->id;
            ret = 0;
        }
    }
    return ret;
}

int movie_get_name (ePelicula* ptrmov,char* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrmov->nombre);
            ret = 0;
        }
    }
    return ret;
}

int movie_get_year (ePelicula* ptrmov,int* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrmov->anio;
            ret = 0;
        }
    }
    return ret;
}
int movie_get_genre (ePelicula* ptrmov,char* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrmov->genero);
            ret = 0;
        }
    }
    return ret;
}
int movie_set_id (ePelicula* ptrmov,int this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this>0)
        {
            ptrmov->id = this;
            ret = 0;
        }
    }
    return ret;
}
int movie_set_name (ePelicula* ptrmov,char* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrmov->nombre,this);
            ret = 0;
        }
    }
    return ret;
}
int movie_set_year (ePelicula* ptrmov,int this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this>0)
        {
            ptrmov->anio = this;
            ret = 0;
        }
    }
    return ret;
}
int movie_set_genre (ePelicula* ptrmov,char* this)
{
    int ret = -1;
    if (ptrmov!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrmov->genero,this);
            ret = 0;
        }
    }
    return ret;
}

int movie_sortById(void* ptrmov1 ,void* ptrmovTwo)
{
    if (ptrmov1!=NULL&&ptrmovTwo!=NULL)
    {
        ptrmov1 = (ePelicula*)ptrmov1;
        ptrmovTwo = (ePelicula*)ptrmovTwo;
        int idone  , idtwo;
        movie_get_id(ptrmov1, &idone);
        movie_get_id(ptrmovTwo, &idtwo);
        if(idone>idtwo)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
//int movie_filter (void* this);
//int movie_toString (ePelicula* this, char* retStr);

ePelicula* movie_new (void)
{
    ePelicula* ret = NULL;
    ret = (ePelicula*)malloc(sizeof(ePelicula));
    return ret;
}
ePelicula* movie_new_parameters (int id,char* name,int year,char* genre)
{
    ePelicula* ret = NULL;
    if (id>0)
    {
        if (name!=NULL)
        {
            if (genre!=NULL)
            {
                if (year > 0)
                {
                    ret = movie_new();
                    movie_set_id(ret,id);
                    movie_set_name(ret,name);
                    movie_set_genre(ret,genre);
                    movie_set_year(ret,year);
                }
            }
        }
    }
    return ret;
}

ePelicula* movie_new_text (char* id,char* name,char* year,char* genre)
{
    ePelicula* ret = NULL;
    if (id!=NULL&&name!=NULL&&genre!=NULL&&year!=NULL)
    {
        int inid , inyear;
        inid = atoi(id);
        inyear = atoi(year);
        ret = movie_new_parameters(inid,name,year,genre);
    }
    return ret;
}

void movie_print(ePelicula* this)
{
    if (this!=NULL)
    {
        int id , year;
        char temp [128];
        char temp2 [128];
        movie_get_id(this,&id);
        movie_get_name(this,temp);
        movie_get_genre(this,temp2);
        movie_get_year(this,&year);
        printf("| %d | %s | %d | %s |\n",id,temp,year,temp2);
    }
}


