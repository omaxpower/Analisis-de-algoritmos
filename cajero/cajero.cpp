#include <stdio.h>
#include <stdlib.h>
#define BILLETES  5
 
int denom[] = {200,100,50,20,10};
 
int solucion[BILLETES];
 
int main ()
{
   int i, devolucion;
 
   printf("devolucion: "); 
   scanf ("%d",&devolucion);
   //inicializacion de vector solucion
   for (i = 0; i < BILLETES; i++){
   		solucion[i] =0;
   }
   //-- bucle voraz
   for (i = 0; i < BILLETES; i++){
   	while (devolucion >= denom[i])
      {
         solucion[i]++;
         devolucion-= denom[i];
      }      
   //-- fin del bucle voraz
   }
                    
   if (devolucion!=0) // !0
      printf ("No hay Billetes para devolver\n");
   else 
      //mostramos la solucion
      for (i = 0; i < BILLETES; i++)
    	if (solucion[i])
            printf ("%d Billetes de %d\n", solucion[i], denom[i]);
   system ("pause");
   return 0;
}
