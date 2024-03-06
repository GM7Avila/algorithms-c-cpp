#include <stdio.h>

void draw (int height){
    for(int i=0; i<height; i++){
        for(int j=0; j<i+1; j++){
            printf("[]");
        } printf("\n");
    }
}

int main() {
    
    printf("BRICK PYRAMID - iteration");

    int height;
    printf("Enter the height: ");
    scanf("%d", &height);

    draw(height);

    return 1;

}