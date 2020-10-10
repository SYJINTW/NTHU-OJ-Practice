#include <stdio.h>

int main(){
	long long int ans = 0;
	long long int i;
	int	j, n, carrier, count;

	while(scanf("%d", &n) != EOF){
		ans = 0;
		i = 1;
		j = 0;
		carrier = 1;
		count = 0;
		do{
			if((n >> j) & carrier){
				count++;
			}
			else{
				carrier = 0;
			}
			ans = ans + (((n+1) >> j) & 1) * i;
			i *= 10;
			j++;
		} while((n+1) >> j);

		printf("%lld %d\n", ans, count);
	}

	/*
	int i = 0;
	int n = 0;
	int count = 0;
	int carrier = 1;

	scanf("%d", &n);

	do{
		if((n >> i) & carrier) count++;
		else carrier = 0;
	}while((n+1) >> ++i);
	n++;
	for(i--; i >= 0; i--){
		if((n >> i) & 1) printf("1");
		else printf("0");
	}
	printf(" %d", count);
	*/
}
