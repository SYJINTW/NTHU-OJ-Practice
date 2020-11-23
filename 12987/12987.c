#include <stdio.h>
#include <string.h>
#include <math.h>

char S[21];
char P[21];
int K[21] = {0};
int hack = 0; // 確定是否有解的 flag

void check(int s_now, int p_now, int k_now){
	// 如果 S 和 P 都走到底了，代表有解
	if(S[s_now] == '\0' && P[p_now] == '\0'){
		hack = 1; // 至少有一個解
		int i = 0; // K[] 的 index
		int s = 0; // S[] 的 index
		int flag = 0; // 確定是否需要空格的 flag
		while(K[i] != '\0'){
			if(P[i] == '#'){
				int n = K[i];
				if(flag == 0) flag = 1;
				else printf(" ");
				for(int j = 0; j < n; j++){
					printf("%c", S[s]);
					s++;
				}
				i++;
			} 
			else{
				i++;
				s++;
			}
		}
		printf("\n");
		flag = 0;
		return;
	} else;

	// 還沒找到解，執行下面
	// word -> word
	if(S[s_now] == P[p_now]){
		K[k_now] = 1;
		check(s_now+1, p_now+1, k_now+1);
	}
	else if(P[p_now] == '#' && S[s_now] != '\0'){
		int num = 0;
		while(S[s_now+num] != '\0'){
			K[k_now] = num+1;
			check(s_now+num+1, p_now+1, k_now+1);
			num++;
		}
	} else;
	K[k_now] = 0;
}

int main(){
	scanf("%s", S);
	scanf("%s", P);
	check(0, 0, 0);
	if(hack == 0){
		printf("What the hack!?\n");
	} else;

}