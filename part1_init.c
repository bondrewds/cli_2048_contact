#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int grid [4][4];
    long current_score;
    int game_status;
    int available_tiles;
} game_state;

game_state game;

void initalize_game(){

    srand((unsigned)time(NULL));

    for (int row=0;row<4;++row){
        for (int col=0;col<4;++col){
            game.grid[row][col] = 0;
        }
    }

    game.current_score = 0;
    game.game_status = 0;
    game.available_tiles = 16;
}

int main(){
    initalize_game();
    printf("游戏初始化成功！");
    return 0;
}
