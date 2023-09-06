#include<stdio.h>

int exgcd(int a, int b, int &x, int &y) {
    if(!b) {
        x=1, y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}

int main()
{
    int a = 9,b = 15, x,y;
    exgcd(a,b,x,y);
    printf("%d,%d",x,y);
}
