#include <stdio.h>

void draw(int n){

    // condição de parada
    if(n <= 0) {
        return;
    }

    draw(n - 1);

    for (int i = 0; i < n; i++) {
        printf("[]");
    }
    
    printf("\n");

}

int main(){
    draw(5);
}