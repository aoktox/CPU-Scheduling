#include<stdio.h>
#include<math.h>
#define max 20

void input();
void prem();

double pro, at[max], bst[max], sisa[max], ses[max], wait[max], temp[max];
int i, j, k, l, m, b;

main(){
	printf("\nCPU SCHEDULLING\n");
	printf("METODE SJF - PREEMPTIVE\n\n");
	input();
	prem();
}

void input(){
	printf("Masukkan jumlah proses : ");
	scanf("%lg",&pro);
	printf("Masukkan arriving time : \n");
	for(i=0;i<pro;i++){
		ses[i] = ses[i-1]+1;
		printf("arrival time ke -%lg: ",ses[i]);
		scanf("%lg",&at[i]);
	}
	printf("Masukkan burst time : \n");
	for(j=0;j<pro;j++){
		printf("Burst time ke -%d : ",j+1);
		scanf("%lg",&bst[j]);
	}
}

void prem(){
	double swap, swap1, end=0,awal, jumlah=0, a, swap2;
	for(i=0;i<(pro-1);i++){
		for(j=0;j<(pro-i-1);j++){
			if(at[j] > at[j+1]){
				swap = at[j];
				swap1 = bst[j];
				swap2 = ses[j];
				at[j] = at[j+1];
				bst[j] = bst[j+1];
				ses[j] = ses[j+1];
				at[j+1] = swap;
				bst[j+1] = swap1;
				ses[j+1] = swap2;
			}
		}
	}

	puts("");
	printf("\nGhantt Chart\n\n");
	sisa[0]=0;
	for(i=0;i<pro;i++){
		for(j=0;j<pro;j++){
			if(j==0 && i==0){
				a = bst[j]+end;
				if(a > at[j+1]){
					if(end > at[j]){
						awal = end;
						end = end + at[j+1];
					}else{
						awal = at[j];
						end = 0;
						end = end + (at[j+1]);
					}
				}else{
					if(end > at[j]){
						awal = end;
						end = end + bst[j];
					}else{
						awal = at[j];
						end = 0;
						end = end + (at[j]+bst[j]);

					}
				}
			}else{
				if(bst[j]==0){
					continue;
				}else{
					if(bst[j-1]<bst[j]){
						a = bst[i-1]+end;
						if(a > at[j]){
							if(end > at[j]){
								awal = end;
								end = end + bst[j];
							}else{
								awal = at[j];
								end = 0;
								end = end + (at[j]);
							}
						}else{
							if(end > at[j]){
								awal = end;
								end = end + bst[j];
							}else{
								awal = at[j];
								end = 0;
								end = end + (at[j-1]+bst[j-1]);

							}
						}
					}else{
						a = bst[i]+end;
						if(a >= at[j+1]){
							if(end > at[j]){
								awal = end;
								end = end + bst[j+1];
							}else{
								awal = at[j];
								end = 0;
								end = end + (at[j+1]);
							}
						}else{
							if(end > at[j+1]){
								awal = end;
								end = end + bst[j+1];
							}else{
								awal = at[j+1];
								end = 0;
								end = end + (at[j+1]+bst[j+1]);

							}
						}
					}
				}
			}
			sisa[j]= bst[j]-(end-awal);
			end = awal + (bst[j]-sisa[j]);
			bst[j] = sisa[j];
			b = ses[j];
			
			if(i==0 || temp[b]==0){
				wait[j] = awal-at[j];
			}else{
				wait[j] = awal-temp[b];
			}

			temp[b]=end;
			printf("Proses ke [%lg]\tstart : %-6lgend : %-6lgwait : %-6lg\n",ses[j],awal,end,wait[j]);
			jumlah = jumlah + (wait[j]);
			if(bst[j]==0){
				break;
			}
		}
		for(k=0;k<(pro-1);k++){
			for(l=0;l<(pro-k-1);l++){
				if(bst[l] > bst[l+1]){
					swap = at[l];
					swap1 = bst[l];
					swap2 = ses[l];
					at[l] = at[l+1];
					bst[l] = bst[l+1];
					ses[l] = ses[l+1];
					at[l+1] = swap;
					bst[l+1] = swap1;
					ses[l+1] = swap2;
				}
			}
		}
	}
	printf("\nAvg Waiting Time = %lg\n\n",jumlah/pro);
}
