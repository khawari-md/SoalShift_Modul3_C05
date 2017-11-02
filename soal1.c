#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
int main() {

        key_t key1 = 1250,key2 = 1200,key3 = 1300;
        int *JumlahSenjata;
        char *namaPenjual,*namaPembeli=NULL;
        int shmid1 = shmget(key1, sizeof(int), IPC_CREAT | 0666);
        JumlahSenjata = shmat(shmid1, NULL, 0);
        int shmid2 = shmget(key2, sizeof(int), IPC_CREAT | 0666);
        namaPenjual = shmat(shmid2, NULL, 0);
        int shmid3 = shmget(key3, sizeof(int), IPC_CREAT | 0666);
        namaPembeli = shmat(shmid3, NULL, 0); 

        printf("masukkan nama penjual : ");
        scanf("%[^\n]",namaPenjual);

        char NamaSenjata[6][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
        int in;

        printf("\nselamat datang di toko %s\n",namaPenjual);
        printf ("Menu : \n1. Tambah stock senjata \n2. Lihat stock senjata \n3. Exit Menu\n4. Lihat Pembeli\n");
        while (scanf ("%d", &in)) {

                if (in==1) {

                        printf ("Jenis senjata yang ada MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE\n\n");

                        int nambah;char senjata[100];

                        scanf("%s %d", senjata,&nambah);

                        if(strcmp(senjata,"MP4A1")==0) {

                                JumlahSenjata[0] += nambah;
                        }
                        if(strcmp(senjata,"PM2-V1")==0) {

                                JumlahSenjata[1] += nambah;
                        }
                        if(strcmp(senjata,"SPR-3")==0) {

                                JumlahSenjata[2] += nambah;
                        }
                        if(strcmp(senjata,"SS2-V5")==0) {

                                JumlahSenjata[3] += nambah;
                        }
                        if(strcmp(senjata,"SPG1-V3")==0) {

                                JumlahSenjata[4] += nambah;
                        }
                        if(strcmp(senjata,"MINE")==0) {

                                JumlahSenjata[5] += nambah;
                        }
                        printf ("%s sudah bertambah %d unit\n", senjata, nambah);
                }
                else if (in==2) {
                    for(int i=0;i<6;i++) {
                        printf("%s = %d\n", NamaSenjata[i], JumlahSenjata[i]);
                        }
                }
                else if (in==3){
                    break;
                }
                else if (in==4){
                    if(namaPembeli==NULL) printf("tidak ada pembeli\n");
                    else printf("pembeli : %s\n",namaPembeli);
                }
                else {
                    printf("salah input\n");
                }

        printf ("\n1. Tambah stock senjata \n2. Lihat stock senjata \n3. Exit Menu\n4. Lihat Pembeli\n");

        }
        shmdt(JumlahSenjata);
        shmctl(shmid1, IPC_RMID, NULL);
        shmdt(namaPenjual);
        shmctl(shmid2, IPC_RMID, NULL);
        shmdt(namaPembeli);
        shmctl(shmid3, IPC_RMID, NULL);
}
