// Problem 14
// Grade report(different order)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// from OJ
typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;
void sortGrade(Grade *gList, int n, char *order);

int main(){
    int n, i;
    char order[20];
    Grade gradeList[1000];
    scanf("%d%s", &n, order);
    for(i = 0; i < n; i++)
        scanf("%d%d%d%d%d", &gradeList[i].ID, &gradeList[i].Chinese,&gradeList[i].English, &gradeList[i].math, &gradeList[i].science);
    sortGrade(gradeList, n, order);
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", gradeList[i].ID, gradeList[i].total,gradeList[i].Chinese, gradeList[i].English,gradeList[i].math, gradeList[i].science);
    return 0;
}
//

int CompAscending( const void *lhs, const void *rhs )
{
    Grade *LHS = ( Grade * )lhs;
    Grade *RHS = ( Grade * )rhs;

    if( LHS->total == RHS->total ) {
        if( LHS->Chinese == RHS->Chinese ) {
            if( LHS->English == RHS->English ) {
                if( LHS->math == RHS->math ) {
                    if( LHS->science == RHS->science ) {
                        if( LHS->ID == RHS->ID ) {
                            return 0;
                        }
                        else {
                            return LHS->ID - RHS->ID;
                        }
                    }
                    else {
                        return LHS->science - RHS->science;
                    }
                }
                else {
                    return LHS->math - RHS->math;
                }
            }
            else {
                return LHS->English - RHS->English;
            }
        }
        else {
            return LHS->Chinese - RHS->Chinese;
        }
    }
    else {
        return LHS->total - RHS->total;
    }
}

int CompDescending( const void *lhs, const void *rhs )
{
    Grade *LHS = ( Grade * )lhs;
    Grade *RHS = ( Grade * )rhs;

    if( LHS->total == RHS->total ) {
        if( LHS->Chinese == RHS->Chinese ) {
            if( LHS->English == RHS->English ) {
                if( LHS->math == RHS->math ) {
                    if( LHS->science == RHS->science ) {
                        if( LHS->ID == RHS->ID ) {
                            return 0;
                        }
                        else {
                            return ( LHS->ID - RHS->ID ); // ID still from low to high
                        }
                    }
                    else {
                        return -( LHS->science - RHS->science );
                    }
                }
                else {
                    return -( LHS->math - RHS->math );
                }
            }
            else {
                return -( LHS->English - RHS->English );
            }
        }
        else {
            return -( LHS->Chinese - RHS->Chinese );
        }
    }
    else {
        return -( LHS->total - RHS->total );
    }
}

void sortGrade(Grade *gList, int n, char *order)
{
    // sum total
    for( int i = 0; i < n; i++ ) {
        gList[ i ].total = gList[ i ].Chinese + gList[ i ].English + gList[ i ].math + gList[ i ].science;
    }

    // ascending
    if( !strcmp( order, "ascending" ) ) {
        qsort( gList, n, sizeof( Grade ), CompAscending );
    }
    // descending
    else {
        qsort( gList, n, sizeof( Grade ), CompDescending );
    }
}