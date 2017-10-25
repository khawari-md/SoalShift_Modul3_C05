#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[100];

void* cari(void *ptr){
    char *N = (char*) ptr;
    FILE* fo;
    fo = fopen("Novel.txt","r");
    char buf[200];
    int n=0;
    while (fgets(buf, 200, fo)!=NULL)
    {
        if((strstr(buf,N)) !=NULL){
            n++;
        }
    }
    fclose(fo);
    printf("%s : %d\n",N,n);
    return NULL;
}

int main(int argc, char *argv[])
{
    
    int i=1,j,T;
    int err;
    T=argc;
    while(i<T)//looping membuat thread
    {
        err=pthread_create(&(tid[i]),NULL,&cari,(void *) argv[i]);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            //printf("\n create thread success");
        }
        pthread_join(tid[i],NULL);
        i++;
    }
    return 0;
}
