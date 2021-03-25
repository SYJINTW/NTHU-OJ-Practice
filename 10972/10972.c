// https://acm.cs.nthu.edu.tw/problem/10972/
// 正常來說要用 tree，但是好像有點麻煩

#include <stdio.h>
#include <string.h>

int fakeStack[300];
int now = 0;

char S[300];
char B[300];

int lastoneisp = 1;
int firstp = 0;

int main()
{   
    scanf("%s", S);
    for(int i = 0; S[i]!='\0'; i++)
    {
        if(S[i]=='A'||S[i]=='B'||S[i]=='C'||S[i]=='D')
        {
            B[i] = 1;
            lastoneisp = 1;
            firstp = 1;
        }
        else if(S[i]=='|'||S[i]=='&')
        {
            B[i] = 1;
            lastoneisp = 1;
            firstp = 1;
        }
        else if(S[i]=='(')
        {
            if(S[i+1]==')')
            {
                B[i] = 0;
                fakeStack[now++] = 0; 
            }
            else if((S[i+1]=='A'||S[i+1]=='B'||S[i+1]=='C'||S[i+1]=='D') && S[i+2]==')')
            {
                B[i] = 0;
                fakeStack[now++] = 0;   
            }
            else
            {
                B[i] = firstp*lastoneisp;
                fakeStack[now++] = firstp*lastoneisp;
                //printf("%d\n", fakeStack[now-1]); 
                lastoneisp = 0;
            }
        }
        else if(S[i]==')')
        {
            //printf("%d\n", fakeStack[now-1]);
            B[i] = fakeStack[--now];
        }
    }

    for(int i = 0; S[i]!='\0'; i++)
    {
        if(B[i]!=0)printf("%c", S[i]);
    }
    //printf("\n");
}