#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int a[11] = {4,9,5,6,3,2,1,0,9,8,7};
    int n = 8;    
    int i = 0;
    int x;

    x = fork();    
    
    if(x!=0){//Parent
        wait(NULL);
        printf("Child finished!\n");
            for(i = 6; i < 11; i++){
                if(a[i] == n){
                    printf("I'm parent My pid is: %d, and the index is: %d\n", getpid(), i);
                    
                 }
            }
    }
    if(x == 0)//Child    
        for(i = 0; i < 6; i++){
            if(a[i] == n){
                printf("I'm child My pid is: %d, and the index is: %d\n", getpid(), i);
                kill (getppid(), 9);
                exit(0);
             }
        }
    

    return 0;
}
