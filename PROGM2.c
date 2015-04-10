#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define clrscr() system("clear")
#define getch() system("echo ")
int* cargar(int* U,int* conj);
void menup ();
void menuop ();
void presentacion();
void imprimir(int * conj);
void uni(int * conj1, int * conj2);
void impe(int * conj);
void card(int * conj);
void inter(int *r, int *t);
void relativo(int *e, int *s);
void absoluto(int *uni, int *c, int *p);
void simetrica(int *w, int *y);
int i;
#define inn 10
int main()
{
    menup();
    return 0;
}
void menup()
{
    int op, cont=1;
    char * opp=malloc(sizeof(char));
    do
    {
	clrscr();
	printf("\t\t\tMENU PRINCIPAL\n");
	printf("1. Presentacion\n");
	printf("2. Operaciones\n");
	printf("3. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%s",opp);
	op=atoi(opp);
	switch (op)
	{
	    case 1: presentacion();break;
	    case 2: menuop(); break;
	    case 3: cont=0; break;
	    default: printf("Escriba una opcion correcta.\n"); break;
	}
    } while( cont );
}

void presentacion()
{
	printf("\n                      Universidad Tecnol¢gica de Panama \n");
	printf("            Facultad de Ingenier°a en Sistemas Computacionales\n");
	printf("           Departamento de Computaci¢n y Simulaci¢n de Sistemas\n\n");
	printf("                            Estructuras Discretas\n\n");
	printf("                               Laboratorio n¯1\n");
	printf("                        Ingeniera Jacqueline De Ching\n\n");
	printf("                                   Grupo: \n");
	printf("                          Espinosa, Angel  8-905-1352    \n"); //colocar cedula
    printf("                             Miranda, Heidys  4-777-1525\n\n");
	printf("                                   1IL-121\n");
	getch();
}
void menuop()
{
    int* U=malloc(inn*sizeof(int));
    int* A=malloc(inn*sizeof(int));
    int* B=malloc(inn*sizeof(int));
    int op, cont=1, carr=0, lmp=1;
    char * opp=malloc(sizeof(char));
    clrscr();
    for(i=0;i<inn;i++) //{0,1,2,3,4,5,6,7,8,9}
	U[i]=1;
    do
    {
	if (lmp)
            clrscr();
    	printf("\t\t\tOPERACIONES\n");
    	printf("1. Cargar\n"); 
    	printf("2. Union\n"); 
    	printf("3. Interseccion\n");
    	printf("4. Complemento relativo\n"); //TODO: Under construction
    	printf("5. Complemento absoluto\n"); //TODO: Under construction
    	printf("6. Diferencia Simetrica\n"); //TODO: Under construction
	printf("7. Retornar al menu principal\n");
    	printf("Ingrese una opcion: ");
    	scanf("%s",opp);
        op=atoi(opp);
    	switch (op)
    	{
	    case 1: 
		    printf("Cargando el conjunto A: "); 
		    A=cargar(U,A); 
		    printf("Cargando el conjunto B: "); 
		    B=cargar(U,B);
    		    impe(A);
    		    impe(B);
		    carr=1;
		    lmp=0;
		    getch();
		    break;
	    case 2: 
		    if (carr)
		    {
			uni(A,B);
			lmp=0;
		    }
		    else
			printf("No ha cargado los arreglos");
			//cargar(A,B);
		    getch();
		    break;
	    case 3: 
		    if (carr)
		    {
			inter(A,B);
			lmp=0;
		    }
		    else
			printf("No ha cargado los arreglos");
			//cargar(A,B);
		    getch();
		    break;
	    case 4: 
		    if (carr)
		    {
                        relativo(A,B);
		        lmp=0;
		    }
		    else
			printf("No ha cargado los arreglos");
		    getch();
		    break;
	    case 5: 
		    if (carr)
		    {
                    	absoluto(U,A,B);
		    	lmp=0;
		    }
		    else
			printf("No ha cargado los arreglos");
		    getch();
		    break;
	    case 6: 
		    if (carr)
		    {
                   	simetrica(A,B);
		    	lmp=0;
		    }
		    else
			printf("No ha cargado los arreglos");
		    getch();
		    break;
	    case 7: cont=0; break;
	    default: printf("Escriba una opcion correcta.\n"); break;
    	}
    } while( cont );

}
int * cargar(int * U,int* conj) //Ver como se trabaja con U. FIXME: U no es usado...
{
    int j;
    char * numero=malloc(sizeof(char));
    char * res=malloc(sizeof(char));
    clrscr();
    U[0]=1;
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
	printf("\nContinuar ingresando (S/n/b (para borrar el ultimo ingresado)): "); //Opci√≥n borrar por si hay equivocaciones. Como un char. Bug as feature xD.
	scanf("%s",res); //Se est√° leyendo con string, porque char causa problemas.
	if (res[0]=='b' || res[0]=='B')
	{
	    conj[j]=0;
	    printf("Elemento Borrado: %d\n",j);//FIXME: No deber√≠a leer de nuevo un elemento, deber√≠a preguntar si continuar ingresando.
	    impe(conj);
	}
    } while(res[0]=='s' || res[0]=='S'|| res[0]=='b' || res[0]=='B');
    return conj;
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
    card(conj);
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
    clrscr();
    printf("La union es: ");
    impe(unio);
}

void inter(int *r,int *t)
{
     int* unio=malloc(inn*sizeof(int));
     printf("La interseccion es: \n");
     for(i=0;i<inn;i++)
     {	
	unio[i]=0;
     }
     for(i=0;i<inn;i++)
     {
	if(r[i]==t[i])
	{
	     unio[i]=r[i];

	}		       	
     }
     clrscr();
     impe(unio);
     getch();
}
void relativo(int *e, int *s)
{
    int m=0;
    int* unio=malloc(inn*sizeof(int));
    printf("A-B\n");
    for(i=0;i<inn;i++)
    {
	for(m=0;m<inn;m++)
	{
	    unio[i]=0;
	    unio[m]=0;
	}
    }
    for(i=0;i<inn;i++)
    {
	if (e[i]!=s[i])
	{
	    unio[i]=e[i];
	}
    }
    clrscr();
    impe(unio);
    getch();
}
void card(int * conj)
{
    int count=0;
    for (i=0;i<inn;i++)
    {
        if(conj[i] == 1)
        {
            count++;
        }
    }
    printf("La cardinalidad es de %d\n",count);
}
void absoluto(int *uni,int *c, int *p)
{
    int n;
    int val=1;
    int* unio=malloc(inn*sizeof(int)); 
    do
    {
	printf("\n            MENU DE COMPLEMENTO ABSOLUTO\n\n");
     	printf("1. Complemento de A\n");
     	printf("2. Complemento de B\n");
     	printf("3. Volver al menu de operaciones\n");
	printf("Escriba la opciÛn: ");
     	scanf("%d", &n);
	switch(n)
	{
		case 1:
			for(i=0;i<inn;i++)
     		    	{
     			    unio[i]=0;
     		    	}
     		    	printf("EL complemento del conjunto A es: \n");
     		    	for(i=0;i<inn;i++)
     		    	{
     			    if(uni[i]!=c[i])
     			    {
      			    	unio[i]=uni[i];
      			    }
      		    	}
      		    	impe(unio);
		    	getch();
		    	break;
		case 2:
			for(i=0;i<inn;i++)
     			{
     			    unio[i]=0;
     			}
     			printf("El complemento del conjunto B es: \n");
      			for(i=0;i<inn;i++)
      			{
      			    if(uni[i]!=p[i])
      			    {
				unio[i]=uni[i];
       			    }
       			}
       			impe(unio);
       			getch();
       			break;
       		case 3: val=0;break;
      	}
    }while(val==1);
}
void simetrica(int *w, int *y)
{
    int* unio=malloc(inn*sizeof(int));
    int* unio1=malloc(inn*sizeof(int));
    for(i=0;i<inn;i++)
    {
	unio[i]=0;
    }
    for(i=0;i<inn;i++)
    {
   	if(w[i]!=y[i])
   	{
    	     unio[i]=w[i];
    	     unio1[i]=y[i];
    	}
    }
    printf("La diferencia simetrica de A y B es: \n");
    impe(unio);
    impe(unio1);
    getch();
}
