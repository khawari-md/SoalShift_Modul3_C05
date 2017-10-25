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

void* faktorial(void *ptr){
    int i;
    long long int f;
    int N=(int) ptr;
    f=1;
    for(i=2;i<=N;i++){
        f=f*i;
    }
    printf ("faktorial %d : %lld\n",N,f);
    return NULL;
}

int main(int argc, char *argv[])
{
    
    int i=1,j,T,N[100];
    int err;
    T=argc;
    while(i<T)//looping membuat thread
    {
        err=pthread_create(&(tid[i]),NULL,&faktorial,(void *) N[i]);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            //printf("\n create thread success");
        }
        i++;
    }
    i=0;
    while(i<T){
        pthread_join(tid[i],NULL);
        i++;
    }
    return 0;
}