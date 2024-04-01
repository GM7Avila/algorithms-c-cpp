#include <stdio.h>

    /*
    int labirinto[8][8] = {
        {1,0,1,0,0,1,0,0},
        {1,0,1,0,0,1,0,0},
        {1,1,1,0,1,1,1,0},
        {0,1,0,0,1,0,1,0},
        {0,1,0,0,1,0,1,0},
        {0,1,1,1,1,0,1,0},
        {0,0,1,0,0,0,1,0},
        {1,1,1,0,0,0,2,0},
    };
    */

    /* MAPA DO LABIRINTO (8x8)
        ⬛🟩⬛🟩🟩⬛🟩🟩
        ⬛🟩⬛🟩🟩⬛🟩🟩
        ⬛⬛⬛🟩⬛⬛⬛🟩
        🟩⬛🟩🟩⬛🟩⬛🟩
        🟩⬛🟩🟩⬛🟩⬛🟩
        🟩⬛⬛⬛⬛🟩⬛🟩
        🟩🟩⬛🟩🟩🟩⬛🟩
        ⬛⬛⬛🟩🟩🟩🟪🟩

        - A saída é o roxo
        - A entrda é em i=0, j=0 - M(0,0)

    */

int main(){

    /* MAPA DO LABIRINTO (3X3)
        ⬛🟩🟩
        ⬛⬛🟩
        🟩🟪🟩
        

        - 1 2 3
        1 x
        2 x x
        3   x

        - A saída é o roxo
        - A entrda é em i=0, j=0 - M(0,0)    

        0 = parede
        1 = caminho
    */

    int init_pos[2] = {0,0};  /* Posição Inicial */
    int map_size = 3;  /* Tamanho do mapa (quadrado) */

    int labirinto[3][3] = {
        {1,0,0},
        {1,1,0},
        {0,2,0},
    };

    // Convertendo a matriz para um ponteiro de ponteiros
    int *map[3];
    for(int i=0; i<3; i++){
        map[i] = labirinto[i];
    }
    
    set_start(map, init_pos, map_size);

}

void imprimirLabirinto(int **map, int map_size) {

    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (map[i][j] == 1) {
                printf("\U00002B1B"); // Emoji preto (parede)
            } else if (map[i][j] == 0) {
                printf("\U0001F7E9"); // Emoji verde (caminho)
            } else if (map[i][j] == 2) {
                printf("\U0001F7EA"); // Emoji roxo (saída)
            }
        }
        printf("\n");
    }
}
