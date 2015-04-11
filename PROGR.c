#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#define clrscr() system("clear")
//#define getch() system("echo ")
int* cargar(int* U,int* conj);
void menup ();
void menuop ();
void presentacion();
void uni(int * conj1, int * conj2, int isu);
void impe(int * conj);
void card(int * conj);
void inter(int *r, int *t);
void relativo(int *e, int *s);
void relmenu(int *conj1, int * conj2);
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
    int op, cont=1, lmp=1;
    char * opp=malloc(sizeof(char));
    do
    {
	if (lmp)
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
	    case 1: presentacion();		    
		    lmp=0;
		    break;
	    case 2: menuop(); break;
	    case 3: cont=0; break;
	    default: printf("Escriba una opcion correcta.\n"); break;
	}
    } while( cont );
}

void presentacion()
{
	clrscr();
	printf("\n                      Universidad Tecnol¢gica de Panama \n");
	printf("            Facultad de Ingenier¡a en Sistemas Computacionales\n");
	printf("           Departamento de Computaci¢n y Simulaci¢n de Sistemas\n\n");
	printf("                            Estructuras Discretas\n\n");
	printf("                               Laboratorio nø1\n");
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
    	printf("4. Complemento relativo\n"); 
    	printf("5. Complemento absoluto\n"); 
    	printf("6. Diferencia Simetrica\n"); 
	printf("7. Retornar al menu principal\n");
    	printf("Ingrese una opcion: ");
    	scanf("%s",opp);
        op=atoi(opp);
    	switch (op)
    	{
	    case 1: 
		    clrscr(); 
		    printf("Cargando el conjunto A: \n");
		    A=cargar(U,A); 
		    clrscr(); 
		    printf("Cargando el conjunto B: \n"); 
		    B=cargar(U,B);
		    printf("El conjunto A es: ");
    		    impe(A);
		    printf("El conjunto B es: ");
    		    impe(B);
		    carr=1;
		    lmp=0;
		    getch();
		    break;
	    case 2: 
		    if (carr)
		    {
			uni(A,B,1);
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
                        relmenu(A,B);
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
	printf("\nContinuar ingresando (S/n/b (para borrar el ultimo ingresado)): "); //OpciÃ³n borrar por si hay equivocaciones. Como un char.
	scanf("%s",res); //Se estÃ¡ leyendo con string, porque char causa problemas.
	if (res[0]=='b' || res[0]=='B')
	{
	    conj[j]=0;
	    printf("Elemento Borrado: %d\n",j);
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
void uni(int * conj1, int * conj2, int isu)
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
    if (isu)
    {
        clrscr();
    	printf("La union es: ");
    }
    impe(unio);
}

void inter(int *r,int *t)
{
     int* intter=malloc(inn*sizeof(int));
     for(i=0;i<inn;i++)
     {	
	intter[i]=0;
     }
     for(i=0;i<inn;i++)
     {
	if(r[i]==t[i])
	{
	     intter[i]=r[i];

	}		       	
     }
     clrscr();
     printf("La interseccion es: \n");
     impe(intter);
     getch();
}
void relativo(int *e, int *s) //TODO: Submenu de relativo.
{
    int m=0;
    int* rel=malloc(inn*sizeof(int));
    for(i=0;i<inn;i++)
    {
	for(m=0;m<inn;m++)
	{
	    rel[i]=0;
	    rel[m]=0;
	}
    }
    for(i=0;i<inn;i++)
    {
	if (e[i]!=s[i])
	{
	    rel[i]=e[i];
	}
    }
    impe(rel);
    getch();
}
void relmenu(int *conj1, int * conj2)
{
    int op, cont=1, lmp=1;
    char * opp=malloc(sizeof(char));
    do
    {
	if (lmp)
            clrscr();
	printf("\t\t\tMENU DE COMPLEMENTO RELATIVO\n");
	printf("1. A-B\n");
	printf("2. B-A\n");
	printf("3. Retornar al menu de operaciones\n");
	printf("Ingrese una opcion: ");
	scanf("%s",opp);
	op=atoi(opp);
	switch (op)
	{
	    case 1: 
		    printf("El Complemento relativo A-B es: ");
		    relativo(conj1,conj2);		    
		    lmp=0;
		    break;
	    case 2:
		    printf("El Complemento relativo B-A es: ");
		    relativo(conj2,conj1);		    
		    lmp=0;
		    break;
	    case 3: cont=0; break;
	    default: printf("Escriba una opcion correcta.\n"); break;
	}
    } while( cont );
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
    int* cmp=malloc(inn*sizeof(int)); 
    char * opp=malloc(sizeof(char));
    do
    {
	printf("\n            MENU DE COMPLEMENTO ABSOLUTO\n\n");
     	printf("1. Complemento de A\n");
     	printf("2. Complemento de B\n");
     	printf("3. Volver al menu de operaciones\n");
	printf("Escriba la opción: ");
     	scanf("%s", opp);
	n=atoi(opp);
	switch(n)
	{
		case 1:
			for(i=0;i<inn;i++)
     		    	{
     			    cmp[i]=0;
     		    	}
     		    	printf("El complemento del conjunto A es: \n");
     		    	for(i=0;i<inn;i++)
     		    	{
     			    if(uni[i]!=c[i])
     			    {
      			    	cmp[i]=uni[i];
      			    }
      		    	}
      		    	impe(cmp);
		    	getch();
		    	break;
		case 2:
			for(i=0;i<inn;i++)
     			{
     			    cmp[i]=0;
     			}
     			printf("El complemento del conjunto B es: \n");
      			for(i=0;i<inn;i++)
      			{
      			    if(uni[i]!=p[i])
      			    {
				cmp[i]=uni[i];
       			    }
       			}
       			impe(cmp);
       			getch();
       			break;
       		case 3: val=0;break;
      	}
    }while(val==1);
}
void simetrica(int *w, int *y)
{
    int* sim=malloc(inn*sizeof(int));
    int* sim1=malloc(inn*sizeof(int));
    int* simm=malloc(inn*sizeof(int));
    for(i=0;i<inn;i++)
    {
	sim[i]=0;
	sim1[i]=0;
	simm[i]=0;
    }
    for(i=0;i<inn;i++)
    {
   	if(w[i]!=y[i])
   	{
    	     sim[i]=w[i];
    	     sim1[i]=y[i];
    	}
    }
    clrscr();
    printf("La diferencia simetrica de A y B es: \n");
    uni(sim,sim1,0);
    getch();
}
