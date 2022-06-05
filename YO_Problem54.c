// 54
#include <stdio.h>
#include <string.h>

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

char map[100][100];
char actions[100]={};
int coin_amount = 0;

// tank's initial direction
char init_dir;
// tank's direction now
int dir_now;
// tank's center x and y
int center_x, center_y;

void decide_initial_direction(void)
{
    if(map[center_x-1][center_y-1]=='x'&&map[center_x-1][center_y+1]=='x') init_dir=NORTH;
    else if(map[center_x-1][center_y+1]=='x'&&map[center_x+1][center_y+1]=='x') init_dir=EAST;
    else if(map[center_x+1][center_y-1]=='x'&&map[center_x+1][center_y+1]=='x') init_dir=SOUTH;
    else if(map[center_x-1][center_y-1]=='x'&&map[center_x+1][center_y-1]=='x') init_dir=WEST;
    dir_now=init_dir;
}

int take_a_step(int row,int col)
{
    if (dir_now == NORTH){
        if(center_x>2){
            if (map[center_x-2][center_y-1]=='#'||map[center_x-2][center_y]=='#'||map[center_x-2][center_y+1]=='#')
                return 1;
            else if (map[center_x-2][center_y-1]=='^'||map[center_x-2][center_y]=='^'||map[center_x-2][center_y+1]=='^')
                return 1;
            else center_x--;
        }
    }else if (dir_now == SOUTH){
        if(center_x<row-1){
            if (map[center_x+2][center_y-1]=='#'||map[center_x+2][center_y]=='#'||map[center_x+2][center_y+1]=='#')
                return 1;
            else if (map[center_x+2][center_y-1]=='^'||map[center_x+2][center_y]=='^'||map[center_x+2][center_y+1]=='^')
                return 1;
            else center_x++;
        }
    }else if (dir_now == EAST){
        if(center_y<col-1){
            if (map[center_x-1][center_y+2]=='#'||map[center_x][center_y+2]=='#'||map[center_x+1][center_y+2]=='#')
                return 1;
            else if (map[center_x-1][center_y+2]=='^'||map[center_x][center_y+2]=='^'||map[center_x+1][center_y+2]=='^')
                return 1;
            else center_y++;
        }
    }else if (dir_now == WEST){
        if(center_y>2){
            if (map[center_x-1][center_y-2]=='#'||map[center_x][center_y-2]=='#'||map[center_x+1][center_y-2]=='#')
                return 1;
            else if (map[center_x-1][center_y-2]=='^'||map[center_x][center_y-2]=='^'||map[center_x+1][center_y-2]=='^')
                return 1;
            else center_y--;
        }
    }
    return 0;
}

int take_two_step(int row,int col){
    int cent_x=center_x,cent_y=center_y;
    if (dir_now == NORTH){
        if(center_x>2){
            if (map[center_x-2][center_y-1]=='#'||map[center_x-2][center_y]=='#'||map[center_x-2][center_y+1]=='#')
                return 1;
            else if (map[center_x-2][center_y-1]=='^'||map[center_x-2][center_y]=='^'||map[center_x-2][center_y+1]=='^')
                return 1;
            else cent_x--;
        }
    }else if (dir_now == SOUTH){
        if(center_x<row-1){
            if (map[center_x+2][center_y-1]=='#'||map[center_x+2][center_y]=='#'||map[center_x+2][center_y+1]=='#')
                return 1;
            else if (map[center_x+2][center_y-1]=='^'||map[center_x+2][center_y]=='^'||map[center_x+2][center_y+1]=='^')
                return 1;
            else cent_x++;
        }
    }else if (dir_now == EAST){
        if(center_y<col-1){
            if (map[center_x-1][center_y+2]=='#'||map[center_x][center_y+2]=='#'||map[center_x+1][center_y+2]=='#')
                return 1;
            else if (map[center_x-1][center_y+2]=='^'||map[center_x][center_y+2]=='^'||map[center_x+1][center_y+2]=='^')
                return 1;
            else cent_y++;
        }
    }else if (dir_now == WEST){
        if(cent_y>2){
            if (map[center_x-1][center_y-2]=='#'||map[center_x][center_y-2]=='#'||map[center_x+1][center_y-2]=='#')
                return 1;
            else if (map[center_x-1][center_y-2]=='^'||map[center_x][center_y-2]=='^'||map[center_x+1][center_y-2]=='^')
                return 1;
            else cent_y--;
        }
    }
        if (dir_now == NORTH){
        if(cent_x>2){
            if (map[cent_x-2][cent_y-1]=='#'||map[cent_x-2][cent_y]=='#'||map[cent_x-2][cent_y+1]=='#')
                return 1;
            else if (map[cent_x-2][cent_y-1]=='^'||map[cent_x-2][cent_y]=='^'||map[cent_x-2][cent_y+1]=='^')
                return 1;
            else cent_x--;
        }
    }else if (dir_now == SOUTH){
        if(center_x<row-1){
            if (map[cent_x+2][cent_y-1]=='#'||map[cent_x+2][cent_y]=='#'||map[cent_x+2][cent_y+1]=='#')
                return 1;
            else if (map[cent_x+2][cent_y-1]=='^'||map[cent_x+2][cent_y]=='^'||map[cent_x+2][cent_y+1]=='^')
                return 1;
            else cent_x++;
        }
    }else if (dir_now == EAST){
        if(center_y<col-1){
            if (map[cent_x-1][cent_y+2]=='#'||map[cent_x][cent_y+2]=='#'||map[cent_x+1][cent_y+2]=='#')
                return 1;
            else if (map[cent_x-1][cent_y+2]=='^'||map[cent_x][cent_y+2]=='^'||map[cent_x+1][cent_y+2]=='^')
                return 1;
            else cent_y++;
        }
    }else if (dir_now == WEST){
        if(center_y>2){
            if (map[cent_x-1][cent_y-2]=='#'||map[cent_x][cent_y-2]=='#'||map[cent_x+1][cent_y-2]=='#')
                return 1;
            else if (map[cent_x-1][cent_y-2]=='^'||map[cent_x][cent_y-2]=='^'||map[cent_x+1][cent_y-2]=='^')
                return 1;
            else cent_y--;
        }
    }
    return 0;
}

void pick_the_coins(void)
{
    int j, k;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            if(map[j][k]=='$'){
                coin_amount++;
                map[j][k]='=';
            }
        }
    }
}

void turn_right(void)
{
    dir_now++;
    dir_now%=4;
}

void turn_left(void)
{   
    dir_now+=3;
    dir_now%=4;
}

int main()
{
    int i, j, k, rows, cols;
    int actions_number;
    int component = 0;
    scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
    while (getchar() != '\n');
    for (i = 0; i < actions_number; i++){
        scanf("%c", &actions[i]);
    }
    for (i = 1; i <= rows; i++){
        while (getchar() != '\n');
        for (j = 1; j <= cols; j++){
            scanf("%c", &map[i][j]);
            if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
                component++;
                if (component == 5){
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }
    decide_initial_direction();
    for (i = 0; i < actions_number; i++){
        if (actions[i] == 'F'){
            take_a_step(rows,cols);
            pick_the_coins();
        }
        else if (actions[i] == 'J'){
            if(take_two_step(rows,cols)==0){
                take_a_step(rows,cols);
                pick_the_coins();
                take_a_step(rows,cols);
                pick_the_coins();
            }
        }else{
            if (actions[i] == 'R'){
                turn_right();
            }
            if (actions[i] == 'L'){
                turn_left();
            }
        }
    }
    printf("%d\n", coin_amount);

    return 0;
}