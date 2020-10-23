#include<stdio.h>

int r,c,t;
char arr[101][101]={'0'};

int main()
{
	
	scanf("%d %d %d\n", &r, &c, &t);
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c+1; j++){
			scanf("%c", &arr[i][j]);
		}
	}

	printf("\n");

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			printf("%c", arr[i][j]);
		}
		//printf("\n");
	}

	return 0;
}