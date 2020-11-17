#include <stdio.h>
#include <ctype.h>

int pos = 0;

float prefix(){
	char arr[100];
	scanf("%s", arr);

	if(isdigit(arr[0])){
		float num = 0;
		int pos = 0;

		// 檢查幾位數
		if(isdigit(arr[pos])){
			num = num*10 + (arr[pos]-48);
			pos++; // 指向下一個位置
		} else;

		// 檢查是整數還是小數
		if(num - (int)num > 0){
			printf("%.1f ", num);
		}
		else{
			printf("%d ", (int)num);
		}

		return num; 
	}
	else if(arr[0] == '+'){
		pos++;
		printf("( ");
		float num1 = prefix();
		printf("+ ");
		float num2 = prefix();
		printf(") ");
		return num1 + num2; 
	}
	else if(arr[0] == '-'){
		pos++;
		printf("( ");
		float num1 = prefix();
		printf("- ");
		float num2 = prefix();
		printf(") ");
		return num1 - num2; 
	}
	else if(arr[0] == '*'){
		pos++;
		printf("( ");
		float num1 = prefix();
		printf("* ");
		float num2 = prefix();
		printf(") ");
		return num1 * num2; 
	}
	else if(arr[0] == '/'){
		pos++;
		printf("( ");
		float num1 = prefix();
		printf("/ ");
		float num2 = prefix();
		printf(") ");
		return num1 / num2; 
	} else;
}

int main(){
	int n = 0;
	scanf("%d\n", &n);
	while(n--){
		float ans = prefix();
		// 檢查是整數還是小數
		if(ans - (int)ans > 0){
			printf("= %.1f\n", ans);
		}
		else{
			printf("= %d\n", (int)ans);
		}
	}
	return 0;
}