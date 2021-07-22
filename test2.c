#include <stdio.h>
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
int main() 
{
char str[1024],*s;
FILE *f; 
int **v=NULL,t,l;
size_t m,*n=NULL,i,j; 
int I,J; 

char name[256];
printf("enter file name:\n");
scanf("%s",name);
for(I=0;I<2;I++)
{ 
    f=fopen(name,"r"); 
    if(f==NULL)
    {
        printf("Can't open file '%s'\n",name);
        return -1;
    } 
    for(m=0;fgets(str,sizeof(str), f)!=NULL;m++) 
    if(I==1) 
    {
        //n[m], v[m] 
        for(J=0;J<2;J++)  
        {
            for(s=str,n[m]=0;sscanf(s,"%d%n",(J==0?&t:v[m]+n[m]),&l)==1;s+=l,n[m]++); 
            if(J==0) 
            {
                v[m]=(int*)malloc(n[m]*sizeof(v[0][0])); 
            }
        }
    }
    if(I==0) 
    {
        n=(size_t*)calloc(sizeof(size_t),m); 
        v=(int**)calloc(sizeof(int*),m); 
    }
    fclose(f); 
}
for(i=0;i<m;i++,printf("\n"))
for(j=0;j<n[i];j++)
printf("%d ",v[i][j]);


matr_mod(v, n, &m);
printf("Once transformated matrix:\n");
for(i = 0; i < m; i++,printf("\n"))
        for(j = 0; j < n [i]; j++)
        printf("%d ", v[i][j]);

matr_mod(v, n, &m);
printf("Twice transformated matrix:\n");
for(i = 0; i < m; i++,printf("\n"))
        for(j = 0; j < n [i]; j++)
        printf("%d ", v[i][j]);   


for (i=0; i<m; i++)
   free(v[i]);
free(v);
free(n);

return 0;
}
int matr_mod(int **array, int *n, int *m)
{
float sum;
float num;
sum=0;
num=0;
for (int i = 0; i < *m; i++)
    {
    num=num+n[i];
    for (int j = 0; j < n[i]; j++)
        sum += array[i][j];
    }
for (int i = 0; i < *m; i++)
    for (int j = 0; j < n[i]; j++)
        if (sum/num==array[i][j])
        {
            for (int k = i; k < *m-1; k++)
                {
                    array[k]=(int*) realloc (array[k], n[k+1]*sizeof(int));
                    for (int q=0; q<n[k+1]; q++)
                        array[k][q]=array[k+1][q];

                }
                for (int s = i; s < *m-1; s++)
                    n[s]=n[s+1];
                n=(int*) realloc (n, (*m-1)*sizeof(int));
                array=(int**) realloc (array, (*m-1)*sizeof(int*));
                *m=*m-1;
                return 0;     
        }  
    

return 0;
}
