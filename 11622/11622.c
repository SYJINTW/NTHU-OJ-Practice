#include <stdio.h>
#include <ctype.h>

char card[3];
int check[14];

int main(){
	int n, k, flag;

	scanf("%d", &n);
	while(n--){
		//init check
		for(int i = 0; i < 14; i++){
			check[i] = 0;
		}
		flag = 0;

		//user input
		for(int i = 0; i < 5; i++){

			scanf("%s", card);

			if(isdigit(card[0])){
				k = (int)card[0] - 48;
			}
			else if(card[0] == 'A'){
				k = 10;
			}
			else if(card[0] == 'J'){
				k = 11;
			}
			else if(card[0] == 'Q'){
				k = 12;
			}
			else if(card[0] == 'K'){
				k = 13;
			} else;

			check[k]++;

			if(check[k] >= 3){
				flag+=2;
			}
			else if(check[k] >= 2){
				flag++;
			} else;
		}

		if(flag == 4)printf("YES\n");
		else printf("NO\n");

	}
	
}