#include<stdio.h>

int main(){
	long long int sum = 0;
	long long int tmp = 1;
	int A = 0;
	int K = 0;
	

	scanf("%d %d", &A, &K);
	for(int i = K; i > 0; i--){
		sum += A*i*tmp;
		tmp *= 10;
	}

	printf("%lld\n", sum);
	return 0;
}
