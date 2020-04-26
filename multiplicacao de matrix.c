#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

int main(void);

double a[1500][1500];   
double b[1500][1500];
double c[1500][1500];

int main (void)
{      
    int i,k,j;
    int n = 1500;
    int thread_num;
    double wtime;

    printf("\n");
    printf("Multiplicação de Matrizes em OpenMP\n");    
    printf("Ordem da matriz: %d\n",n);
    thread_num = omp_get_max_threads ( );
    printf("Threads Ativas: %d\n", thread_num );
    printf("Calculando...\n");
    wtime =omp_get_wtime ( );

// cria A.
# pragma omp parallel shared (a,b,c,n) private ( i,j,k)
{
    # pragma omp for 
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {

            a[i][j] = i*n+j+1;
        }
    }

    //copiar A para B

# pragma omp for
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j] = a[i][j];
        }
    }

// loop para calcular C

#pragma omp for 

    for (i=0;i<n; i++)
    {
        for (j=0;j<n;j++)
        {
            c[i][j] = 0.0;
            for (k=0;k<n;k++)
            {
                c[i][j] = c[i][j] + a[i][k] *b[k][j];
            }
        }
    }

}    

    wtime= omp_get_wtime ( ) - wtime;
    printf("tempo utilizado: %g \n", wtime);
    return 0;
}
