//100p n^2 Marius Nicoli
#include <stdio.h>
#define DIM 1002

int A[DIM][DIM], L[DIM][DIM], C[DIM][DIM], D[DIM][DIM];
int N, i, j, ii, a1, a2, a3, a4, b1, b2, b3, b4;

int min(int a, int b) {
	return a<b?a:b;
}

int main(){

	FILE *f = fopen("triunghi.in", "r");
	FILE *g = fopen("triunghi.out", "w");
	fscanf(f,"%d",&N);
	for (ii=1;ii<=N;ii++)
		for (j = 1, i = ii; i>=1; j++, i--) {
			fscanf(f,"%d",&A[i][j]);
			C[i][j] = C[i-1][j] + A[i][j];
			L[i][j] = L[i][j-1] + A[i][j];
		}
	for (i=1;i<=N;i++)
		D[i][N-i+1] = A[i][N-i+1];
	for (i=1;i<N;i++)
		D[i][N-i] = 2*A[i][N-i] + A[i][N-i+1] + A[i+1][N-i];
	for (ii=N-2;ii>=1;ii--){
		for (i=ii, j=1;i>=1;i--,j++) {

			D[i][j] = min(
				D[i+1][j] +
				(L[i][N-i] - L[i][j-1]) * (N-i+1 - j) +
				(L[i+1][N-(i+1)+1] - L[i+1][j-1])  * (N-i+1 - j)+
				2 * (L[i][N-i+1] - L[i][j-1]) - A[i][N-i+1] - A[i][j],

				D[i][j+1] +
				(C[N-j][j] - C[i-1][j])  * (N-i+1 - j)+
				(C[N-(j+1)+1][j+1] - C[i-1][j+1])  * (N-i+1 - j)+
				2 * (C[N-j+1][j] - C[i-1][j]) - A[N-j+1][j] - A[i][j]);
		}
	}

	fclose(f);

    /*for(int i=1;i<=N;++i)
    {
        for(j=1;j<=N-i+1; ++j) fprintf(g,"%d ",D[i][j]);
        fprintf(g,"\n");
    }*/

	fprintf(g,"%d",D[1][1]);
	fclose(g);
	return 0;
}
