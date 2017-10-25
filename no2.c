#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status,win=0;
int nomor;
int skor1=0,skor2=0;
 
void* satu(void *arg)
{
    status = 0;
    char nama[100];
    int lubang[16];
    printf("masukkan nama player 1 : \n");
    scanf("%[^\n]",nama);
    getchar();
    printf("%s\n", nama);
    status = 1;
    while(1)
    {
        while(status != 0)
        {

        }
        if (win==1) break;
        printf("giliran %s\n",nama);
        skor1++;
        status=1;
        if(skor1==10 || skor2==10) break;
    }
    if (win==0) {
        win=1;
        printf("pemenangnya %s\n",nama);
    }
    return NULL;
}


void* dua(void *arg)
{
    while(status != 1)
    {

    }
    char nama[100];
    printf("masukkan nama player 2 : \n");
    scanf("%[^\n]",nama);
    getchar();
    printf("%s\n", nama);
    status=0;
    while(1)
    {
        while(status != 1)
        {

        }
        if (win==1) break;
        printf("giliran %s\n",nama);
        skor2++;
        status=0;
        if(skor2==10 || skor1==10) break;
    }
    if (win==0) {
        win=1;
        printf("pemenangnya %s\n",nama);
    }
    return NULL;
}
 
int main(void)
{

    pthread_create(&(tid1), NULL, &satu, NULL);//(void*) argv1);
    pthread_create(&(tid2), NULL, &dua, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}
