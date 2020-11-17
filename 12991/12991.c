#include <stdio.h>
#include <stdlib.h>

int step = 0;
int height[17] = {0};
int color[17] = {0};


int* jump(int n, int s, int t, int* flag){
	int h = 0;
	int a[2] = {0}, b[2] = {0}, c[2] = {0};
	int color_max[2] = {0};
	int x[2] = {0, 1};

	flag[s] = 1;
	// 到達終點
	if(s == t){
		return x;
	}
	// 尚未到達
	else{
		// left
		if(flag[s-1] == 0 && s-1 > 0){
			h = height[s] - height[s-1];
			a[0] = abs(h) + jump(n, s-1, t, flag)[0];
			a[1] = a[1] + 1;
		} else;

		// right
		if(flag[s+1] == 0 && s+1 < n+1){
			h = height[s] - height[s+1];
			b[0] = abs(h) + jump(n, s+1, t, flag)[0];
			b[1] = b[1] + 1;
		} else;

		// same color
		for(int i = 1; i <= n; i++){
			if(flag[i] == 0 && color[s] == color[i]){
				h = height[s] - height[i];
				c[0] = abs(h)*abs(s-i) + jump(n, i, t, flag)[0];
				c[1] = c[1] + 1;
			} else;
			if(c[0] > color_max[0]){
				color_max[0] = c[0];
				color_max[1] = c[1];
			} else;
		}

		// return the biggest solution
		if(a[0] > b[0]){
			if(a[0] > color_max[0]) return a;
			else return color_max;
		}
		else{
			if(b[0] > color_max[0]) return b;
			else return color_max;
		}
	}
}


int main(){
	int n, s, t;
	int sum[2] = {0};
	int flag[17] = {0};

	scanf("%d %d %d", &n, &s, &t);
	for(int i = 1; i <= n; i++){
		scanf("%d", &height[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &color[i]);
	}

	flag[s] = 1;
	sum = jump(n, s, t, flag);
	printf("%d %d\n", sum[0], sum[1]);

}