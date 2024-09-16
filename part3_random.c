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

void print_grid(){
    printf("当前网格：\n");
    for (int row=0;row<4;++row){
        for (int col=0;col<4;++col){
            printf("%4d",game.grid[row][col]);
        }
        printf("\n");
    }
}

void add_random_tile(){
    for (int i = 0;i < 2; ++i){
        if (game.available_tiles == 0){
        break;
        }
        do{
            int row = rand() % 4;
            int col = rand() % 4;
            //找到空白位置
            if (game.grid[row][col] == 0){
                game.grid[row][col] = (rand()%2+1) * 2;
                game.available_tiles--;
                break;
            }
        }while (i);
    }
}

int main(){
    initalize_game();
    printf("游戏初始化成功！\n");
    add_random_tile();
    print_grid();
    return 0;
}
