#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define EAST ( 0 )
#define SOUTH ( 1 )
#define WEST ( 2 )
#define NORTH ( 3 )

char map[ 100 ][ 100 ];
char actions[ 100 ] = {};
int coin_amount = 0;

// tank's initial direction
char init_dir;
// tank's direction now
int dir_now;
// tank's center x and y
int center_x, center_y;

int rows, cols;

void pick_the_coins( void )
{
    int j, k;
    for( j = center_x - 1; j <= center_x + 1; j++ ) {
        for( k = center_y - 1; k <= center_y + 1; k++ ) {
            /// determine whether there are coins under the tank
            if( map[ j ][ k ] == '$' ) {
                coin_amount++;
                map[ j ][ k ] = '=';
            }
        }
    }
}

bool detect_wall( const int x, const int y )
{
    switch( dir_now ) {
    case NORTH:
    default:
        for( int i = 0; i < 3; i++ ) {
            if( map[ x - 2 ][ y - 1 + i ] == '#' ) {
                return true;
            }
        }
        return false;

    case EAST:
        for( int i = 0; i < 3; i++ ) {
            if( map[ x - 1 + i ][ y + 2 ] == '#' ) {
                return true;
            }
        }
        return false;
    
    case SOUTH:
        for( int i = 0; i < 3; i++ ) {
            if( map[ x + 2 ][ y - 1 + i ] == '#' ) {
                return true;
            }
        }
        return false;
    
    case WEST:
        for( int i = 0; i < 3; i++ ) {
            if( map[ x - 1 + i ][ y - 2 ] == '#' ) {
                return true;
            }
        }
        return false;
    }
}

bool detect_hill( const int x, const int y )
{
    switch( dir_now ) {
    case NORTH:
    default:
        for( int i = 0; i < 3; i++ ) {
            if( map[ x - 2 ][ y - 1 + i ] == '^' ) {
                return true;
            }
        }
        return false;

    case EAST:
        for( int i = 0; i < 3; i++ ) {
            if( map[ x - 1 + i ][ y + 2 ] == '^' ) {
                return true;
            }
        }
        return false;
    
    case SOUTH:
        for( int i = 0; i < 3; i++ ) {
            if( map[ x + 2 ][ y - 1 + i ] == '^' ) {
                return true;
            }
        }
        return false;
    
    case WEST:
        for( int i = 0; i < 3; i++ ) {
            if( map[ x - 1 + i ][ y - 2 ] == '^' ) {
                return true;
            }
        }
        return false;
    }
}

void decide_initial_direction( void )
{
    /// Decide tank's initial direction
    /// Using init_dir
    /// To determine dir_now
    // 3 0
    // 2 1
    // 0:e 1:s 2:w 3:n
    int nHead[ 4 ] = { -1 };
    if( map[ center_x - 1 ][ center_y - 1 ] == 'x' ) {
        nHead[ 3 ] = 1;
    }
    if( map[ center_x + 1 ][ center_y - 1 ] == 'x' ) {
        nHead[ 2 ] = 1;
    }
    if( map[ center_x + 1 ][ center_y + 1 ] == 'x' ) {
        nHead[ 1 ] = 1;
    }
    if( map[ center_x - 1 ][ center_y + 1 ] == 'x' ) {
        nHead[ 0 ] = 1;
    }

    for( int i = 0; i < 4; i++ ) {
        int j = i;
        int k = ( i + 1 ) % 4;
        if( nHead[ j ] * nHead[ k ] == 1 ) {
            dir_now = j;
            break;
        }
    }
}

bool take_a_step( int x, int y, int *ax, int *ay )
// Return Value: 
// true: you can take a step
// false: cannot
{
    if( dir_now == NORTH ) {
        if( center_x > 2 ) {
            /// Detect wall first
            if( detect_wall( x, y ) == true ) {
                return false;
            }
            /// And then detect hill
            else if( detect_hill( x, y ) == true ) {
                return false;
            }
            /// If there is no obstacle, take a step
            else {
                *ax = x - 1;
                *ay = y;
                return true;
            }
        }
    }
    else if( dir_now == SOUTH ) {
        if( center_x < rows - 1 ) {
            /// Detect wall first
            if( detect_wall( x, y ) == true ) {
                return false;
            }
            /// And then detect hill
            else if( detect_hill( x, y ) == true ) {
                return false;
            }
            /// If there is no obstacle, take a step
            else {
                *ax = x + 1;
                *ay = y;
                return true;
            }
        }
    }
    else if( dir_now == EAST ) {
        if( center_y < cols - 1 ) {
            /// Detect wall first
            if( detect_wall( x, y ) == true ) {
                return false;
            }
            /// And then detect hill
            else if( detect_hill( x, y ) == true ) {
                return false;
            }
            /// If there is no obstacle, take a step
            else {
                *ax = x;
                *ay = y + 1;
                return true;
            }
        }
    }
    else if( dir_now == WEST ) {
        if( center_y > 2 ) {
            /// Detect wall first
            if( detect_wall( x, y ) == true ) {
                return false;
            }
            /// And then detect hill
            else if( detect_hill( x, y ) == true ) {
                return false;
            }
            /// If there is no obstacle, take a step
            else {
                *ax = x;
                *ay = y - 1;
                return true;
            }
        }
    }

    return false;
}

void take_two_step( void )
{
    int step_1_x, step_1_y;
    bool bSuccess = take_a_step( center_x, center_y, &step_1_x, &step_1_y );
    if( bSuccess == false ) {
        return;
    }

    int step_2_x, step_2_y;
    bSuccess = take_a_step( step_1_x, step_1_y, &step_2_x, &step_2_y );
    if( bSuccess == false ) {
        return;
    }

    // OK
    center_x = step_1_x;
    center_y = step_1_y;
    pick_the_coins();
    center_x = step_2_x;
    center_y = step_2_y;
    pick_the_coins();
}

void turn_right()
{
    /// Change direction depending on dir_now
    dir_now = ( dir_now + 1 ) % 4;
}

void turn_left()
{
    /// Change direction depending on dir_now
    dir_now = ( dir_now + 4 - 1 ) % 4;
    // dir_now = ( dir_now - 1 ) % 4; // noted that -1 % 4 = -1 not 3
}

int main()
{
    int i, j, k;
    int actions_number;
    int component = 0;

    /// Raed problem's input
    scanf( "%d %d %d %c", &rows, &cols, &actions_number, &init_dir );
    while( getchar() != '\n' );

    for( i = 0; i < actions_number; i++ ) {
        scanf( "%c", &actions[ i ] );
    }

    /// Read map
    for( i = 1; i <= rows; i++ ){
        while( getchar() != '\n' );

        for( j = 1; j <= cols; j++ ){
            scanf( "%c", &map[ i ][ j ] );

            /// Find tank's center x and y
            if( ( ( map[ i ][ j ] ) == 'x' ) || ( ( map[ i ][ j ] ) == 'o' ) || ( ( map[ i ][ j ] )  == 'O' ) ) {
                component++;
                if( component == 5 ) {
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }

    decide_initial_direction();

    for( i = 0; i < actions_number; i++ ) {
        if( actions[ i ] == 'F' ) {
            int nextx = center_x;
            int nexty = center_y;
            bool bSuccess = take_a_step( center_x, center_y, &nextx, &nexty );
            if( bSuccess == false ) {
                continue;
            }
            center_x = nextx;
            center_y = nexty;
            pick_the_coins();
        }
        /* TODO : Implement the instruction "J" here */
        else if( actions[ i ] == 'J' ) {
            take_two_step();
        }         
        else {
            if( actions[ i ] == 'R' ) {
                turn_right();
            }
            if( actions[ i ] == 'L' ){
                turn_left();
            }
        }
    }

    printf( "%d\n", coin_amount );

    return 0;
}