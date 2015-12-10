#include<stdio.h>
#include<math.h>
#define max 20

void input();
void fcfs();

double pro, at[max], bst[max];
int i, j;

main(){
	printf("\nCPU SCHEDULLING\n");
	printf("METODE FCFS\n\n");
	input();
	fcfs();
}

void input(){
	printf("Masukkan jumlah proses : ");
	scanf("%lg",&pro);
	printf("Masukkan arriving time : \n");
	for(i=0;i<pro;i++){
		printf("arrival time ke -%d : ",i+1);
		scanf("%lg",&at[i]);
	}
	printf("Masukkan burst time : \n");
	for(j=0;j<pro;j++){
		printf("Burst time ke -%d : ",j+1);
		scanf("%lg",&bst[j]);
	}
}

void fcfs(){
	double swap, swap1, end=0, awal, jumlah=0;
	for(i=0;i<(pro-1);i++){
		for(j=0;j<(pro-i-1);j++){
			if(at[j] > at[j+1]){
				swap = at[j];
				swap1 = bst[j];
				at[j] = at[j+1];
				bst[j] = bst[j+1];
				at[j+1] = swap;
				bst[j+1] = swap1;
			}
		}
	}
	puts("");
	printf("\nGhantt Chart\n\n");
	for(i=0;i<pro;i++){
		if(end > at[i]){
			awal = end;
			end = end + bst[i];
		}else{
			awal = at[i];
			end = 0;
			end = end + (at[i]+bst[i]);
		}
		printf("start : %-6lgend : %-6lgwait : %lg \n",awal,end,awal-at[i]);
		jumlah = jumlah + (awal-at[i]);
	}
	printf("\nAvg Waiting Time = %lg\n\n",jumlah/pro);
}