#include <stdio.h>
int used[10][10];
int matr[10][10];

int check(int a, int b, int k){
	int i, j;
	int a1=(a-1)/3, b1=(b-1)/3;
	for(i=1;i<=9;i++)
		if(matr[i][b]==k || matr[a][i]==k)
			return 0;
	a1*=3,b1*=3;
	for(i=a1+1;i<=a1+3;i++)
		for(j=b1+1;j<=b1+3;j++)
			if(matr[i][j]==k)
				return 0;
	return 1;
}

void sudoku(int lev){
	int i, j, k, a, b;
	if(lev==81){
		for (i=1;i<=9;i++){
			for (j=1;j<=9;j++)
				printf ("%d ", matr[i][j]);
			printf("\n");
		}
		return;
	}
	else{
		for(i=1;i<=9;i++)
			for(j=1;j<=9;j++)
				if(used[i][j]==0){
					a=i;
					b=j;
				}
		for(k=1;k<=9;k++)
			if(check(a, b, k)==1){
				matr[a][b]=k;
				used[a][b]=1;
				sudoku(lev+1);
				matr[a][b]=0;
				used[a][b]=0;
			}
	}
}

int main(){
	int n=0, i, j;
	for (i=1;i<=9;i++)
		for (j=1;j<=9;j++){
			scanf ("%d", &matr[i][j]);
			if (matr[i][j]!=0)
				n++;
		}
	for (i=1;i<=9;i++)
		for (j=1;j<=9;j++)
			if (matr[i][j]!=0)
				used[i][j]=1;
	sudoku(n);
	return 0;
}
