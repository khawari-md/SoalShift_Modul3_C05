#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
 
pthread_t tid1;
pthread_t tid2;
int status,win=0;
int skor1=0,skor2=0;
bool lubang1[16],lubang2[16];
 
void* satu(void *arg)
{
    status = 0;
    int x,y,z;
    char nama[100];
    
    for(int b=0;b<16;b++) lubang1[b]=false;
    printf("masukkan nama player 1 : \n");
    scanf("%[^\n]",nama);
    getchar();
    printf("%s\n", nama);
    status = 1;
    while(1)
    {
        while(status != 0)
        {
            if(skor1>10 || skor2>10) break;
        }
        
        if (win==1) break;
        if(skor1>10 || skor2>10) break;

//CHECK SCORE
        char check;
        printf("giliran %s, apakah anda ingin mengecek skor? (y/n)\n",nama);
        scanf("%c",&check);
        if(check=='y') {
            printf("skor %s : %d\n",nama,skor1);
        }

//TURN
        printf("giliran %s\n berapa lubang yang ingin kamu isi : ",nama);
        scanf("%d",&x);
        while(x<1 || x>4){
                printf("jumlah mengisi lubang harus berada diantara 1 sampai 4 : ");
                scanf("%d",&x);
            }
        for(int i=0;i<x;i++){
            printf("lubang yang ingin kamu isi bom : ");
            scanf("%d",&y);

            while(y<1 || y>16){
                printf("lubang hanya berjumlah 16, isi lubang antara 1 sampai 16 : ");
                scanf("%d",&y);
            }

            while(lubang1[y-1]){
                printf("lubang telah terisi, coba masukkan kedalam lubang yang lain : ");
                scanf("%d",&y);
            }
            lubang1[y-1]=true;
        }
        status=1;

        while(status != 0)
        {
            if(skor1>10 || skor2>10) break;
        }

//ANSWER
        if(skor1>10 || skor2>10) break;
        printf("giliran %s\n lubang mana saja yang berisi bom\n",nama);
        for(int i=0;i<4;i++){
            printf("pilih lubang : ");
            scanf("%d",&z);
            if(lubang2[z-1]) skor1++;
            else skor2++;
            if(skor1>10 || skor2>10) break;
        }
        getchar();
        if (win==1) break;
        if(skor1>10 || skor2>10) break;

    }
    if (win==0 && skor1>10) {
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
    bool lubang2[16];
    for(int b=0;b<16;b++) lubang2[b]=false;
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
            if(skor1>10 || skor2>10) break;
        }

        if (win==1) break;
        if(skor1>10 || skor2>10) break;

//ANSWER
        printf("giliran %s\n lubang mana saja yang berisi bom\n ",nama);
        for(int i=0;i<4;i++){
            printf("pilih lubang : ");
            scanf("%d",&z);
            if(lubang1[z-1]) skor2++;
            else skor1++;
            if(skor1>10 || skor2>10) break;
        }

        if (win==1) break;
        if(skor2>10 || skor1>10) break;

//CHECK SCORE
        char check2;
        printf("giliran %s, apakah anda ingin mengecek skor? (y/n)\n",nama);
        getchar();
        scanf("%c",&check2);
        if(check2=='y') {
            printf("skor %s : %d\n",nama,skor2);
        }

//TURN
        printf("giliran %s\n berapa lubang yang ingin kamu isi : ",nama);
        scanf("%d",&x);
        while(x<1 || x>4){
                printf("jumlah mengisi lubang harus berada diantara 1 sampai 4 : ");
                scanf("%d",&x);
            }
        for(int i=0;i<x;i++){
            printf("lubang yang ingin kamu isi bom : ");
            scanf("%d",&y);

            while(y<1 || y>16){
                printf("lubang hanya berjumlah 16, isi lubang antara 1 sampai 16 : ");
                scanf("%d",&y);
            }

            while(lubang2[y-1]){
                printf("lubang telah terisi, coba masukkan kedalam lubang yang lain : ");
                scanf("%d",&y);
            }
            lubang2[y-1]=true;
        }

        status=0;
    }
    if (win==0 && skor2>10) {
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
