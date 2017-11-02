#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main()
{
    key_t key1 = 1250,key2 = 1200,key3 = 1300;
    int *JumlahSenjata;
    char *namaPenjual,*namaPembeli;
    int shmid1 = shmget(key1, sizeof(int), IPC_CREAT | 0666);
    JumlahSenjata = shmat(shmid1, NULL, 0);
    int shmid2 = shmget(key2, sizeof(int), IPC_CREAT | 0666);
    namaPenjual = shmat(shmid2, NULL, 0);
    int shmid3 = shmget(key3, sizeof(int), IPC_CREAT | 0666);
    namaPembeli = shmat(shmid3, NULL, 0); 


    int in;
    const char* NamaSenjata[6]={"MP4A1", "PM2-V1" , "SPR-3", "SS2-V5", "SPG1-V3", "MINE"};
    printf("\nselamat datang di toko %s\n",namaPenjual);

    printf("masukkan nama pembeli : ");
    scanf("%[^\n]",namaPembeli);

    printf("Menu : \n1. Lihat Stock\n2. Beli Senjata\n3. Exit\n");

    while(scanf("%d", &in)) {
                if(in==1){
                        for(int i=0;i<6;i++){
                                printf("%s :%d\n", NamaSenjata[i], JumlahSenjata[i]);
                        }
                }
                else if (in==2){

                        printf("Barang yang ingin dibeli: \n");
                        printf("1. MP4A1\n2. PM2-V1\n3. SPR-3\n4. SS2-V5\n5. SPG1-V3\n6. MINE\n");
                        char Senjata[100]; int beli;

                        scanf("%s %d", Senjata, &beli);

                        if(strcmp(Senjata, "MP4A1")==0) {
                                if((JumlahSenjata[0]-beli)<0) {
                                        printf("barang di stock tidak cukup\n");
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[0]);
                                }
                                else{JumlahSenjata[0]=JumlahSenjata[0]-beli;}
                        }
                        else if(strcmp(Senjata, "PM2-V1")==0) {
                                if((JumlahSenjata[1]-beli)<0) {
                                        printf("barang di stock tidak cukup\n");
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[0]);
                                }
                                else{JumlahSenjata[1]=JumlahSenjata[1]-beli;}
                        }
                        else if(strcmp(Senjata, "SPR-3")==0) {
                                if((JumlahSenjata[2]-beli)<0) {
                                        printf("barang di stock tidak cukup\n");
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[0]);
                                }
                                else{JumlahSenjata[2]=JumlahSenjata[2]-beli;}
                        }
                        else if(strcmp(Senjata, "SS2-V5")==0) {
                                if((JumlahSenjata[3]-beli)<0) {
                                        printf("barang di stock tidak cukup\n");
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[0]);
                                }
                                else{JumlahSenjata[3]=JumlahSenjata[3]-beli;}
                        }
                        else if(strcmp(Senjata, "SPG1-V3")==0) {
                                if((JumlahSenjata[4]-beli)<0) {
                                        printf("barang di stock tidak cukup\n");
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[0]);
                                }
                                else{JumlahSenjata[4]=JumlahSenjata[4]-beli;}
                        }
                        else if(strcmp(Senjata, "MINE")==0) {
                                if((JumlahSenjata[5]-beli)<0) {
                                        printf("barang di stock tidak cukup\n");
                                        printf("Anda hanya bisa membeli %d\n", JumlahSenjata[0]);
                                }
                                else{JumlahSenjata[5]=JumlahSenjata[5]-beli;}
                        }
                        else printf("salah input\n");
                }
                else if (in==3){
                        break;
                }
                else {
                        printf("salah input");
                }
                printf("\nMenu : \n1. Lihat Stock\n2. Beli Senjata\n3. Exit\n");
        }
    shmdt(JumlahSenjata);
    shmctl(shmid1, IPC_RMID, NULL);
    shmdt(namaPenjual);
    shmctl(shmid2, IPC_RMID, NULL);
    shmdt(namaPembeli);
    shmctl(shmid3, IPC_RMID, NULL);
}
