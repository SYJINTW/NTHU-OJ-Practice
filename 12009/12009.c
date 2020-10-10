#include<stdio.h>
int main()
{
    char a, b, c;
    long long int n;
    scanf("%c%c%c%lld",&a,&b,&c,&n);
    n = n%26;
    a+=n; b+=n; c+=n;
    if(a>90) a-=26;
    if(b>90) b-=26;
    if(c>90) c-=26;
    if(a<65) a+=26;
    if(b<65) b+=26;
    if(c<65) c+=26;
    printf("%c%c%c\n",a,b,c);
    return 0;
}