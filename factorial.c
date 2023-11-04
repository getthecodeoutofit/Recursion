#include<stdio.h>

unsigned long long int facto(int n){
if(n<1){
    return 1;
}
return n* facto(n-1);
}
int main(){
int n;
scanf("%d",&n);
    unsigned long long int f = facto(n);
    printf("%llu",f);
    return 0;
}