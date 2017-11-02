#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

int stats[2];
void *kepiting () {
	while (1) {
		if (stats[0]<=0) {
		stats [0]=0;
		}
		else if (stats[0]>100) {
		stats [0]=0;
		}
		else {
		sleep(20);
		stats[0] -= 10;
		}
		/*if (stats[0]<=0) {
		stats [0]=0;
		}
		else if (stats[0]>100) {
		stats [0]=0;
		}
		else if (stats[1] == 0 && stats [0] == 0) {
			exit(EXIT_FAILURE);
		}*/
	}
}
void *lohan () {
	while (1) {
		if (stats[0]<=0) {
		stats [0]=0;
		}
		else if (stats[0]>100) {
		stats [0]=0;
		}
		else {
		sleep(10);
		stats[1] -= 15;
	}
		/*if (stats[1]<=0){
			stats [1]=0;
		}
		else if (stats[1]>100){
			stats [1]=0;
		}
		else if (stats[1] == 0 && stats [0] == 0) {
				exit(EXIT_FAILURE);
		}*/
	}
}
void makan () {
	printf("hewan yang di berimakan\n1. kepiting\n2. Lohan\n");
	int a;
	scanf ("%d", &a);
		
		if (a==1) {
			stats [0]+=10;
			printf("Status kepiting bertambah, menjadi %d\n", stats[0]);
		}
		else if (a==2) {
			stats [1]+=10;
			printf("Status lohan bertambah, menjadi %d\n", stats[1]);
		}
}
	
int main () 	{
	stats [0]=100;
	stats [1]=100;
	pthread_t kepiting_t, lohan_t;
	pthread_create (&kepiting_t,NULL,&kepiting,NULL);	
	pthread_create (&lohan_t,NULL,&lohan,NULL);

	while (1) {
		int pil;
		if( stats[1] == 0 && stats [0] == 0 ) {
			printf("Status kepiting = %d\n", stats[0]);
			printf("Status lohan = %d\n", stats[1]);
			printf("GAME OVER\n");
			exit(EXIT_FAILURE);
		}
		else {
			printf("1. Lihat status\n2. Berimakan\n");
			scanf ("%d",&pil);

			if (pil==1) {
				printf("Status Kepiting: %d\n", stats[0]);
				printf("Status Lohan: %d\n", stats[1]);
			}
			else if (pil==2) {
				makan();
			}
		}
	}
}
