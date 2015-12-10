#include<stdio.h>
#include<math.h>
#define max 20

void input();
void tampil();
void proses();
void input1();

int i, pilih, j, k=0,t, l, m, n, a, b, pro, request[max][max], P[max], hasil[max], re[max], all[max][max], avail[max], maks[max][max], need[max][max]; 
char jwb;

main(){
	input();
	tampil();
	proses();
	do{
		input1();
		tampil();
		proses();
		printf("\nIngin Mengulangi Lagi ?? ");
		scanf("%c",&jwb);
	}while(jwb=='y'||jwb=='Y');
	printf("\nTekan ENTER untuk keluar !!\n");
}

void input(){
	printf("\nMasukkan jumlah resource : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		avail[i]=0;
		printf("\t%c = ",(i+97));
		scanf("%d",&re[i]);
	}
	printf("\nMasukkan jumlah proses : ");
	scanf("%d",&pro);
	printf("\nMasukkan Allocation Matriks : \n");
	for(i=0;i<pro;
	i++){
		P[i] = i;
		printf("P[%d] : ",i);
		for(j=0;j<3;j++){
			scanf("%d, ",&all[i][j]);
			avail[j] = avail[j] + all[i][j];
		}
	}
	printf("\nMasukkan Max Matriks : \n");
	for(i=0;i<pro;i++){
		avail[i] = re[i] - avail[i];
		printf("P[%d] : ",i);
		for(j=0;j<n;j++){
			scanf("%d, ",&maks[i][j]);
		}
	}
}

void tampil(){
	printf("\nAllocation\tMaks\tNeed\tAvailable\n");
	printf("  ");
	for(i=0;i<(n+1);i++){
		for(j=0;j<n;j++){
			printf("%-2c",(j+97));
		}
		printf("\t");
	}
	puts("");
	for(i=0;i<pro;i++){
		printf("  ");
		for(j=0;j<n;j++){
			printf("%-2d",all[i][j]);
		}
		printf("\t");
		for(k=0;k<n;k++){
			printf("%-2d",maks[i][k]);
		}
		printf("\t");
		for(l=0;l<n;l++){
			need[i][l] = maks[i][l] - all[i][l];
			printf("%-2d",need[i][l]);
		}
		printf("\t");
		for(m=0;m<n;m++){
			if(i!=0){
				continue;
			}else{
				printf("%-2d",avail[m]);
			}
		}
		printf("\n");
	}
}

void proses(){
A: a=-1;
	for (i=0;i<pro;i++) {
		b=0;
		t = P[i];
		for (j=0;j<n;j++) {
			if(need[t][j]<=avail[j])
			 b++;
		}
		if(b==n) {
			hasil[k]=P[i];
			for (j=0;j<n;j++){
				avail[j]+=all[t][j];
			}
			k++;
		} else
		 P[++a]=P[i];
	}
	if(a!=-1) {
		pro=a+1;
		goto A;
	}else{
		printf("\nHasil : <");
		for(i=3;i<k;i++){
			printf("P[%d] ",hasil[i]);
		}
		printf(">\n\n");
	}
}

void input1(){
	k = pro;
	printf("Masukkan Request\n");
	printf("Pilih Proses : ");
	scanf("%d",&pilih);
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			if(pilih==i){
				printf("P[%d] : ",i);
				scanf("%d",&request[i][j]);
				if(request[i][j]<=avail[j]){
					all[i][j] = all[i][j] + request[i][j];
				}else{
					printf("\nRequest tidak bisa dilakukan\n\n");
				}
			}else{
				continue;
			}
		}
	}
}
