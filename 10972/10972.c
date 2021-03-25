// https://acm.cs.nthu.edu.tw/problem/10972/
// 正常來說要用 tree，但是好像有點麻煩

#include <stdio.h>
#include <string.h>

int fakeStack[300];
int now = 0; // point out the next pos the stack can store

char S[300]; // store the user data
int B[300]; // store if the char in S[] can print out

int lastoneisp = 1; // if the last char is '(', then the flag turn to '0'
int firstp = 0; // if this is the first '(' in the expression, then the flag is '0'

int main()
{   
    scanf("%s", S);
    for(int i = 0; S[i]!='\0'; i++)
    {
        // if the char is Variable, then must change two flags
        if(S[i]=='A'||S[i]=='B'||S[i]=='C'||S[i]=='D')
        {
            B[i] = 1;
            lastoneisp = 1;
            firstp = 1;
        }
        // if the char is operator, then must change two flags
        else if(S[i]=='|'||S[i]=='&')
        {
            B[i] = 1;
            lastoneisp = 1;
            firstp = 1;
        }
        else if(S[i]=='(')
        {
            // detect () -> NULL
            if(S[i+1]==')')
            {
                B[i] = 0;
                fakeStack[now++] = 0; 
            }
            // detect (A) -> A
            else if((S[i+1]=='A'||S[i+1]=='B'||S[i+1]=='C'||S[i+1]=='D') && S[i+2]==')')
            {
                B[i] = 0;
                fakeStack[now++] = 0;   
            }
            // if '(' is in the first of the expression then won't print it
            else
            {
                B[i] = firstp*lastoneisp;
                fakeStack[now++] = firstp*lastoneisp;
                lastoneisp = 0;
            }
        }
        // Use fakeStack to check if the ')' can print out, depend on it's '('
        else if(S[i]==')')
        {
            B[i] = fakeStack[--now];
        }
    }

    // print out the char if it's B[i] not '0'
    for(int i = 0; S[i]!='\0'; i++)
    {
        if(B[i]!=0)printf("%c", S[i]);
    }
    return 0;
}