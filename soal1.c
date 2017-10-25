#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
int main() {

        key_t key = 1234;
        int *JumlahSenjata;
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        JumlahSenjata = shmat(shmid, NULL, 0); 

        char NamaSenjata[6][10]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
        int in;
        printf ("\n1. Tambah stock senjata \n2. Lihat stock senjata \n3. Exit Menu.\n\n");
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
                        printf ("%s sudah menambah %d unit\n", senjata, nambah);
                        //printf ("%d %s", JumlahSenjata, NamaSenjata );
                }
                else if (in==2) {
                    for(int i=0;i<6;i++) {
                        printf("%s = %d\n", NamaSenjata[i], JumlahSenjata[i]);
                        }
                }
                else if (in==3){
                        break;
                }
                else {
                        printf("salah input");
                }

        printf ("\n1. Tambah stock senjata \n2. Lihat stock senjata \n3. Exit Menu.\n\n");

        }
        shmdt(JumlahSenjata);
        shmctl(shmid, IPC_RMID, NULL);
}
