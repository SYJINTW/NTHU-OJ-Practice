#include<stdio.h>

int m, n, k, f;
int a, b, tmp;
int max_i, max_sum, sum;
int matrix[1001][1001] = {0};

int main(){
	scanf("%d%d%d", &m, &n, &k);

	//create matrix
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	while(k--){
		scanf("%d%d%d", &f, &a, &b);
		//switch
		if(f == 0){
			for(int j = 0; j < n; j++){
				tmp = matrix[a][j];
				matrix[a][j] = matrix[b][j];
				matrix[b][j] = tmp;
			}
		}
		//add
		else{
			for(int j = 0; j < n; j++){
				matrix[a][j] += matrix[b][j];
			}
		}
	}

	//find max
	for(int i = 0; i < m; i++){
		sum = 0;
		for(int j = 0; j < n; j++){
			sum += matrix[i][j]*matrix[i][j];
		}
		if(i == 0 || sum > max_sum){
			max_sum = sum;
			max_i = i;
		} else;
	}

	//print line i
	for(int j = 0; j < n; j++){
		printf("%d", matrix[max_i][j]);
		if(j == (n-1)) printf("\n");
		else printf(" ");
	}

	return 0;
}





