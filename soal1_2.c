#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main()
{
    key_t key = 1234;
    int *JumlahSenjata;
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
    JumlahSenjata = shmat(shmid, NULL, 0);

    int in;
    const char* NamaSenjata[6]={"MP4A1", "PM2-V1" , "SPR-3", "SS2-V5", "SPG1-V3", "MINE"};
    printf("Menu : \n1. Lihat Stock\n2. Beli Senjata\n");

    while(scanf("%d", &in)) {
                if(in==1){
                        for(int i=0;i<6;i++){
                                printf("%s :%d\n", NamaSenjata[i], JumlahSenjata[i]);
                        }
                }
                if (in==2){

                        printf("Barang yang ingin dibeli: \n");
                        printf("1. MP4A1\n2. PM2-V1\n3. SPR-3\n4. SS2-V5\n5. SPG1-V3\n6. MINE\n");
                        char Senjata[100]; int beli;

                        scanf("%s %d", Senjata, &beli);

                        if(strcmp(Senjata, "MP4A1")==0) {
                                if((JumlahSenjata[0]-beli)<0) {
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[0]);
                                        JumlahSenjata[0]=0;
                                }
                                else{JumlahSenjata[0]=JumlahSenjata[0]-beli;}
                        }
                        if(strcmp(Senjata, "PM2-V1")==0) {
                                if((JumlahSenjata[1]-beli)<0) {
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[1]);
                                        JumlahSenjata[1]=0;
                                }
                                else{JumlahSenjata[1]=JumlahSenjata[1]-beli;}
                        }
                        if(strcmp(Senjata, "SPR-3")==0) {
                                if((JumlahSenjata[2]-beli)<0) {
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[2]);
                                        JumlahSenjata[2]=0;
                                }
                                else{JumlahSenjata[2]=JumlahSenjata[2]-beli;}
                        }
                        if(strcmp(Senjata, "SS2-V5")==0) {
                                if((JumlahSenjata[3]-beli)<0) {
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[3]);
                                        JumlahSenjata[3]=0;
                                }
                                else{JumlahSenjata[3]=JumlahSenjata[3]-beli;}
                        }
                        if(strcmp(Senjata, "SPG1-V3")==0) {
                                if((JumlahSenjata[4]-beli)<0) {
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[4]);
                                        JumlahSenjata[4]=0;
                                }
                                else{JumlahSenjata[4]=JumlahSenjata[4]-beli;}
                        }
                        if(strcmp(Senjata, "MINE")==0) {
                                if((JumlahSenjata[5]-beli)<0) {
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[5]);
                                        JumlahSenjata[5]=0;
                                }
                                else{JumlahSenjata[5]=JumlahSenjata[5]-beli;}
                        }
                }
                printf("\nMenu : \n1. Lihat Stock\t 2. Beli Senjata\n");
        }
    shmdt(JumlahSenjata);
    shmctl(shmid, IPC_RMID, NULL);
}
