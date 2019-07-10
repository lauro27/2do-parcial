#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pelicula.h"
#include "parser.h"

void printList(LinkedList*);
void depurarPeliculas(LinkedList* this);
LinkedList* buscarPorGenero(LinkedList* this, LinkedList*);
int filtrarPelicula(ePelicula* this);

char generoFiltro[50];

int main()
{
    int opcion;
    LinkedList* movieList = ll_newLinkedList();
    LinkedList* newMovieList = ll_newLinkedList();
    char filename[50];
    while(opcion != 0)
    {
        printf("1- cargar archivo\n2- mostrar lista\n3- ordenar lista por ID\n4- depurar peliculas\n5- filtrar por genero\n6- mostrar peliculas filtradas\n7- generar depurado.csv\n8- generar filtrado.csv\n0- salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("\nIngrese nombre de archivo: ");
                fflush(stdin);
                gets(filename);

                FILE* fl = openFILE(filename);
                parser_movieFromText(fl,movieList);
                fclose(fl);
                break;
            case 2:
                printList(movieList);
                break;
            case 3:
                ll_sort(movieList,movie_sortById, 1);
                break;
            case 4:
                depurarPeliculas(movieList);
                break;
            case 5:
                newMovieList = buscarPorGenero(movieList, newMovieList);
                printf("\nFiltrado\n\n");
                break;
            case 6:
                printList(newMovieList);
                break;
            case 7:
                depurarPeliculas(movieList);
                FILE* fl2 = openFILEwrite("depurado.csv");
                parser_MovieListToText(fl2,movieList);
                fclose(fl2);
                printf("\nArchivo Generado!\n\n");
                break;
            case 8:
                if(newMovieList->pFirstNode == NULL)
                {
                    printf("No se encuentra lista filtrada.\n\nGenerando nueva lista");
                    newMovieList = buscarPorGenero(movieList,newMovieList);
                }
                FILE* fl3 = openFILEwrite("filtrado.csv");
                parser_MovieListToText(fl3,newMovieList);
                fclose(fl3);
                printf("\nArchivo Generado!\n\n");
                break;
        }
    }
    return 0;
}

void printList (LinkedList* this)
{
    if (this!=NULL)
    {
        int i;
        ePelicula* temp;
        for (i=0;i<ll_len(this);i++)
        {
            temp =(ePelicula*)ll_get(this,i);
            movie_print(temp);
        }
    }
}


void depurarPeliculas(LinkedList* this)
{
    if (this!=NULL)
    {
        int i,j;
        ePelicula* temp;
        ePelicula* tempTwo;
        char auxGenre[50], auxGenreTwo[50];
        int aux1, aux2;
        for (i=0;i<ll_len(this);i++)
        {
            temp =(ePelicula*)ll_get(this,i);
            movie_get_id(temp, &aux1);
            for(j = ll_indexOf(this,temp)+1;j<ll_len(this);j++)
            {
                tempTwo=(ePelicula*)ll_get(this,j);
                movie_get_id(tempTwo, &aux2);
                if(aux1 == aux2)
                {
                    movie_get_genre(temp,auxGenre);
                    movie_get_genre(tempTwo,auxGenreTwo);
                    strcat(auxGenre," | ");
                    strcat(auxGenre,auxGenreTwo);
                    movie_set_genre(temp,auxGenre);
                    ll_remove(this,j);
                    j--;

                }
            }
        }
    }
}

LinkedList* buscarPorGenero(LinkedList* this, LinkedList* newList)
{
    printf("\nIngrese genero: ");
    fflush(stdin);
    gets(generoFiltro);
    newList = ll_filter(this, filtrarPelicula);
    return newList;
}

int filtrarPelicula(ePelicula* this)
{
    char aux[50];
    movie_get_genre(this,aux);
    char *auxChar;
    auxChar = strstr(aux,generoFiltro);
    if(auxChar != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
