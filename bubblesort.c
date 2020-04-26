#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>
#include<string.h>

double a[150000];   

int main(void) 
{ 
    int i,j,xp,yp,temp;
    int n=150000;
    int thread_num;
    double wtime;
    
    printf("\n");
    printf("BubbleSort em OpenMP\n");    
    printf("Ordem da matriz: %d\n",n);
    thread_num = omp_get_max_threads ( );
    printf("Threads Ativas: %d\n", thread_num );
    printf("Calculando...\n");
    wtime =omp_get_wtime ( );
# pragma omp parallel shared (a,n) private (i,j)
{
    //preencher o vetor A    
    # pragma omp for
    for (i=n;i>=0;i--)
    {   
        a[i]=2*i;
    }
    //

    //ordenar
    #pragma omp for 
    for (i = 0; i < n-1; i++)
    {        
        for (j = 0; j < n-i-1; j++)  
        {    if (a[j] > a[j+1]) 
            {
                temp = xp; 
                xp = yp; 
                yp = temp;      
            }
        }
    }        
}
    wtime= omp_get_wtime ( ) - wtime;
    printf("tempo utilizado: %g \n", wtime);

    FILE * fp =NULL;
    fp = fopen ("result.txt","a+");
    fprintf (fp, "%g\n",wtime);      
    fclose (fp);

} 