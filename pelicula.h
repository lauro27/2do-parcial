#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    int anio;
    char genero[50];
}ePelicula;

#endif // PELICULA_H_INCLUDED


int movie_get_id (ePelicula* ptrmov,int* this);
int movie_get_name (ePelicula* ptrmov,char* this);
int movie_get_year (ePelicula* ptrmov,int* this);
int movie_get_genre (ePelicula* ptrmov,char* this);

int movie_set_id (ePelicula* ptrmov,int this);
int movie_set_name (ePelicula* ptrmov,char* this);
int movie_set_year (ePelicula* ptrmov,int this);
int movie_set_genre (ePelicula* ptrmov,char* this);

int movie_sortById(void* ptrmov1 ,void* ptrmovTwo);
//int movie_filter (void* this);
//int movie_toString (ePelicula* this, char* retStr);

ePelicula* movie_new (void);
ePelicula* movie_new_parameters (int,char*,int,char*);
ePelicula* movie_new_text (char* id,char* name,char* year,char* genre);

void movie_print(ePelicula*);


