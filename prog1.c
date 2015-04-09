﻿#include <stdio.h>
#include <stdlib.h>
#define clrscr() system("clear")
int* cargar(int* U,int* conj);
void imprimir(int * conj);
void uni(int * conj1, int * conj2);
void impe(int * conj);
void card(int * conj);
int i;
#define inn 10
int main()
{
    int* U=malloc(inn*sizeof(int));
    for(i=0;i<inn;i++) //{a,b,c,d,e,f,g} //{0,1,2,3,4,5,6,7,8,9}
	U[i]=1;
    int* A=malloc(inn*sizeof(int));
    int* B=malloc(inn*sizeof(int));
    clrscr();
    printf("Cargando el Conjunto A\n");
    A=cargar(U,A);
    imprimir(A);
    printf("Cargando el Conjunto B\n");
    B=cargar(U,B);
    imprimir(A);
    imprimir(B);
    uni(A,B);
    return 0;
}
int * cargar(int * U,int* conj) //Ver como se trabaja con U. FIXME: U no es usado...
{
    int j;
    char * numero=malloc(sizeof(char));
    char * res=malloc(sizeof(char));
    for (i=0;i<inn;i++)
    {
	conj[i]=0;
    }
    do
    {
        do
	{
	    printf("Ingrese un elemento (Del 0 al 9): ");
	    scanf("%s",numero);
	    j=atoi(numero);
	} while(j<0 || j>9);
	conj[j]=1;
	impe(conj);
	printf("\nContinuar ingresando (S/n/b (para borrar el ultimo ingresado)): "); //Opción borrar por si hay equivocaciones. Como un char. Bug as feature xD.
	scanf("%s",res); //Se está leyendo con string, porque char causa problemas. 
        if (res[0]=='b' || res[0]=='B')
	{
	    conj[j]=0;
	    printf("Elemento Borrado: %d\n",j);//FIXME: No debería leer de nuevo un elemento, debería preguntar si continuar ingresando.
	    impe(conj);
	}
    } while(res[0]=='s' || res[0]=='S'|| res[0]=='b' || res[0]=='B');
    return conj;
}
void imprimir(int * conj) //TODO: Esto se quitará en un futuro, no debemos imprimir lo que se trabaja internamente.
{
    int emp=0;
    for (i=0;i<inn;i++)
    {
	if (conj[i] == 0)
	    emp=1;
	else
	{
	    emp=0;	
	    break;
	}
    }
    if (emp == 1)
	printf("{}\n");
    else
    {
    	printf("{");
    	for(i=0;i<inn;i++)
    	{
	    printf("%d,",conj[i]);
    	}
    	printf("\b}\n");
    }
    printf("==============================\n");
    impe(conj);
    printf("==============================\n");
}
void impe(int * conj)
{
    int emp=0;
    for (i=0;i<inn;i++)
    {
	if (conj[i] == 0)
	    emp=1;
	else
	{
	    emp=0;	
	    break;
	}	
    }
    if (emp == 1)
	printf("{}\n");
    else
    {
    	printf("{");
    	for(i=0;i<inn;i++)
    	{
    	    if (conj[i] == 1)
	    {
	    	printf("%d,",i);
	    }
    	}
    	printf("\b}\n");
    }
} 
void uni(int * conj1, int * conj2)
{
    int* unio=malloc(inn*sizeof(int));
    for (i=0;i<inn;i++)
    {
	unio[i]=0;
    }
    for (i=0;i<inn;i++)
    {
	if ( unio[i]== 0)
        {
	    unio[i]=conj1[i];
	}
        if (unio[i]==0)
        {
	    unio[i]=conj2[i];
        }
    }
    imprimir(unio);
}
void card (int * conj)
{
//This is a comment
//This is of user121
}
