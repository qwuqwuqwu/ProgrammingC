#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct object {
    int nX;
    int nY;
    int nHP;
    int nAttack;
} Obj;

typedef struct status {
    int nMonsterCount;
    bool bMonsters[ 25 ];
    Obj Hero;
    Obj Monsters[ 25 ];
} Status;

Status g_Status;

int g_x_inc[ 4 ] = { 1, -1, 0, 0 };
int g_y_inc[ 4 ] = { 0, 0, 1, -1 };

bool g_map[ 6 ][ 6 ];

bool fight( int nMonIdx, Status *pStatus )
{
    // time to kill monster
    int nCountKillMonster = ( int )ceil( ( float )pStatus->Monsters[ nMonIdx ].nHP / pStatus->Hero.nAttack );
    // time to kill hero
    int nCountKillHero = ( int )ceil( ( float )pStatus->Hero.nHP / pStatus->Monsters[ nMonIdx ].nAttack );

    if( nCountKillMonster <= nCountKillHero ) {
        pStatus->Hero.nHP -= ( nCountKillMonster - 1 ) * ( pStatus->Monsters[ nMonIdx ].nAttack );
        pStatus->bMonsters[ nMonIdx ] = false;
        return true;
    }
    return false;
}

int checkPosition( int nX, int nY, Status status )
{
    for( int i = 0; i < 25; i++ ) {
        if( status.bMonsters[ i ] == true && 
            status.Monsters[ i ].nX == nX &&
            status.Monsters[ i ].nY == nY ) {
                return i;
            }
    }
    return -1;
}

bool BoundaryCheck( int nX, int nY )
{
    // exceed range
    if( nX <= 0 || nX >= 6 || nY <= 0 || nY >= 6 ) {
        return false;
    }

    // stand before
    if( g_map[ nX ][ nY ] == true ) {
        return false;
    }
    return true;
}

bool gogogo( int nX, int nY, Status status )
{
    //
    int nMonIdx = checkPosition( nX, nY, status );
    if( nMonIdx != -1 ) {
        if( fight( nMonIdx, &status ) == false ) {
            // lose
            return false;
        }
        else {
            // win
            // do nothing
        }
    }
    if( nX == 5 && nY == 5 ) {
        return true;
    }

    // try next step in four direction
    
    bool bWin = false;
    for( int i = 0; i < 4; i++ ) {
        int nX_next = nX + g_x_inc[ i ];
        int nY_next = nY + g_y_inc[ i ];
        if( BoundaryCheck( nX_next, nY_next ) == true ) {
            g_map[ nX ][ nY ] = true;
            if( gogogo( nX_next, nY_next, status ) ) { return 1; };
            g_map[ nX ][ nY ] = false;
        }
    }

    return bWin;
}

int main( void )
{
    scanf( "%d%d%d", &g_Status.Hero.nHP, &g_Status.Hero.nAttack, &g_Status.nMonsterCount );

    int nMonsterCount = g_Status.nMonsterCount;
    for( int i = 0; i < nMonsterCount; i++ ) {
        scanf( "%d%d", &g_Status.Monsters[ i ].nHP, &g_Status.Monsters[ i ].nAttack );
        scanf( "%d%d", &g_Status.Monsters[ i ].nX, &g_Status.Monsters[ i ].nY );
        g_Status.bMonsters[ i ] = true;
    } 
    g_Status.nMonsterCount = nMonsterCount;

    bool bWin = gogogo( 1, 1, g_Status );
    if( bWin == true ) {
        printf( "HEIR OF FIRE DESTROYED\n" );
    }
    else {
        printf( "YOU DIED\n" );
    }
    return 0;
}