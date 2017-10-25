#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
int nomor;
 
void* satu(void *arg)
{
    status = 0;
    char nama1[100];
    printf("masukkan nama player 1 : \n");
    scanf("%[^\n]",nama1);
    getchar();
    printf("%s\n", nama1);
    status = 1;
 
    return NULL;
}


void* dua(void *arg)
{
    while(status != 1)
    {

    }
    char nama2[100];
    printf("masukkan nama player 2 : \n");
    scanf("%[^\n]",nama2);
    getchar();
    printf("%s\n", nama2);
    status=0;
}
 
int main(void)
{

    pthread_create(&(tid1), NULL, &satu, NULL);//(void*) argv1);
    pthread_create(&(tid2), NULL, &dua, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
