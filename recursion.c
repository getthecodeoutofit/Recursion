#include<stdio.h>
//we will create the function for recursion
void recur(){
    static int i =0; 
    if (i==10){
        return;
    }
    i++;
    recur();
    i--;
    printf("%d ",i);
}
int main(){
recur();
}