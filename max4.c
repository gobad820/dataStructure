#include <stdio.h>

int max4(int a, int b, int c, int d){
    int max = a;
    if(b > max)
        max = b;
    if(c > max)
        max = c;
    if(d > max)
        max = d;
  return max;
}

int min3(int a, int b, int c){
    int min = a;
    if( b < min)
        min = b;
    if(c < min)
        min = c;
    return min;
}

int min4(int a, int b, int c,int d){
    int min = a;
    if( b < min)
        min = b;
    if(c < min)
        min = c;
    if(d < min)
        min = d;
    return min;
}

int main(int argc, char const *argv[])
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d\n",max4(a,b,c,d));
    printf("%d\n",min3(a,b,c));
    printf("%d",min4(a,b,c,d));
    
    return 0;
}
