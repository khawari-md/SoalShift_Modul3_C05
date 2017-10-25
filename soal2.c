#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
 
pthread_t tid1;
pthread_t tid2;
int status,win=0;
int nomor;
int skor1=0,skor2=0;
 
void* satu(void *arg)
{
    status = 0;
    int x,y,z;
    char nama[100];
    bool lubang[16]={false,0};
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
        printf("giliran %s\n berapa lubang yang ingin kamu isi : ",nama);
        scanf("%d",&x);
        for(int i=0;i<x;i++){
            printf("lubang yang ingin kamu isi bom : ");
            scanf("%d",&y);
            lubang[y-1]=true;
        }
        //skor1++;
        status=1;
        if(skor1==10 || skor2==10) break;

        while(status != 0)
        {

        }

        printf("giliran %s\n lubang mana saja yang berisi bom\n",nama);
        for(int i=0;i<4;i++){
            printf("pilih lubang : ");
            scanf("%d",&z);
            if(lubang[z-1]==true) printf("benar\n");
            else printf("salah\n");
        }

        status=1;
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
    bool lubang[16]={false,0};
    int x,y,z;
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
        printf("giliran %s\n lubang mana saja yang berisi bom\n",nama);
        for(int i=0;i<4;i++){
            printf("pilih lubang : ");
            scanf("%d",&z);
            if(lubang[z-1]==true) printf("benar\n");
            else printf("salah\n");
        }

        status=0;
        
        while(status != 1)
        {

        }

        if(skor2==10 || skor1==10) break;
        printf("giliran %s\n berapa lubang yang ingin kamu isi : ",nama);
        scanf("%d",&x);
        for(int i=0;i<x;i++){
            printf("lubang yang ingin kamu isi bom : ");
            scanf("%d",&y);
            lubang[y-1]=true;
        }
        status=0;
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
