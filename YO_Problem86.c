// Problem 86
// Unlimited Triangle Work
#include <stdio.h>

int main( void )
{
    size_t n, A, B, C, D;
    size_t result;
    scanf( "%lu", &n );

    for( size_t x = 0; x < n; x++ ) {
        scanf( "%lu%lu%lu%lu", &A, &B, &C, &D );
        result = 0;
        
        size_t e1_min;
        for( size_t i = C; i <= D; i++ ) {
            /* 最長邊超過第二長與第三長的最大值總和, 在往上增加最長邊邊長也不會成立 */
            if( i >= C + B ) {
                break;
            }
            for( size_t j = B; j <= C; j++ ) {
                /* e1 + e2 > e3 ->  e1 > e3 - e2 
                ** e1範圍A~B, 如果需要的最小值比B大, 代表沒有適合的e1 
                ** 如果需要的最小值小於等於A, 代表所有的e1都滿足
                */
                e1_min = i - j + 1;
                if (B < e1_min) {
                    /* 當e1選擇最大值B也不滿足時, 須直接調整e2到能滿足的條件 */
                    int dif = e1_min - B;
                    if (j + dif > C)
                        break;
                    else
                        j += (dif - 1); /* 因為j會++ */
                } else if (A > e1_min) {
                    /* 當e1需要的最小值小於A時, 所有e1都滿足, 且e2遞增, 後續的迴圈必定都滿足 */
                    result += ( ( B - A + 1 ) * ( C - j + 1 ) );
                    break;
                } else {
                    /* e1_min = i - j + 1, 此迴圈中j遞增, e1_min為遞減,
                    ** 累加可透過等差級數公式計算, 但當e1_min <= A 時, 為另一個關係式計算
                    ** ((a1 + an) * n) / 2, n取決於j先碰到上限C, 還是e1_min先碰到下限A
                    ** 
                    */
                    //result += (B - e1_min + 1);
                    
                    size_t e2diff = C - j + 1; // 後面的e2總共有這麼多, e2會越來越小, 直到e2 = j = C
                    size_t e1diff = e1_min - A + 1; // 後面的e1總共有這麼多, e1會越來越大, 直到e1_min = A
                    size_t n = e2diff < e1diff ? e2diff: e1diff; 
                    size_t add = ( B - e1_min + 1 ) * n;
                    
                    if (n & 1)
                        add += ((n-1)/2*n);
                    else
                        add += (n/2*(n-1));
                    //printf("i:%ld j:%ld, e2diff = %ld, e1diff =%ld ,e1_min:%ld ,result:%ld, add = %ld\n", i, j, e2diff, e1diff, e1_min, result, add);
                    result += add;
                    j += (n - 1);
                }
            }
        }
        printf("%lu\n", result);
    }
    return 0;
}