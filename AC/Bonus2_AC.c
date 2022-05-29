#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Guard
{
    int l;
    int r;
} guard_t;

guard_t guard[5005];
int a[5005];
int t[5005];
int solo_guard[5005];
int cmp(const void *a, const void *b);
int helper(int section, int soldier);

int main (void) {
    int test_num, section, soldier, res;
    scanf("%d", &test_num);
    for (int i = 0; i < test_num; ++i) {
        res = 0;
        if (i)
            memset(a, 0, sizeof(int) * 5005);

        scanf("%d%d", &section, &soldier );
        for (int j = 0; j < soldier; ++j) {
            scanf("%d%d", &guard[j].l, &guard[j].r);
            for (int k = guard[j].l; k <= guard[j].r; ++k) {
                a[k]++; // 算入全部士兵的話, 每個section的守兵數量
            }
        }

        int total_guard = 0;
        for (int j = 0; j <= section; j++) {
            if (a[j])
                total_guard++; // 全部有被守住的section數量
        }

        /*
        // 暴搜的做法是, 雙重for-loop, 選兩個不一樣的士兵, 重新計算t[ k ]
        // 這個會TLE
        int nNum = 0;
        for( int j = 0; j < soldier; j++ ) {
            for( int k = 0; k < soldier; k++ ) {
                if( j == k ) {
                    continue;
                }
                // init
                for( int k1 = 0; k1 <= section; k1++ ) {
                    t[ k1 ] = a[ k1 ];
                }
                nNum = 0;
                for( int k1 = guard[ j ].l; k1 <= guard[ j ].r; k1++ ) {
                    t[ k1 ]--;
                }
                for( int k1 = guard[ k ].l; k1 <= guard[ k ].r; k1++ ) {
                    t[ k1 ]--;
                }

                for( int k1 = 0; k1 <= section; k1++ ) {
                    if( t[ k1 ] >= 1 ) {
                        nNum++;
                    }
                }
                if( nNum > res ) {
                    res = nNum;
                }
            }
        }
        */

        // 先扣除第一個士兵
        for (int j = 0; j < soldier; j++) {
            int now_guard = total_guard;
            for (int k = 0; k <= section; k++)
                t[k] = a[k];

            // 扣除第一個士兵後, 更新每個section的守兵數量
            for (int k = guard[j].l; k <= guard[j].r; ++k) {
                t[k]--;
                if(t[k] == 0)
                    now_guard--; // 更新有守兵的section數量
            }

            // 計算solo_guard, solo_guard[ i ]表示從第1~i個section中, 只有一個守兵的section數量
            for (int k = 1; k <= section; k++) {
                if (t[k] == 1)
                    solo_guard[k] = solo_guard[k-1] + 1;
                else
                    solo_guard[k] = solo_guard[k-1];
            }

            // 扣除第二個士兵的防守範圍
            for (int k = 0; k < soldier; k++) {
                if (k != j) { // 第一個士兵 != 第二個士兵
                    int now_l = guard[k].l;
                    int now_r = guard[k].r;
                    int real_now_guard = now_guard;
                     // 在這個範圍內的solo_guard勢必為第二個士兵, 因此可以把他造成的solo_guard扣掉, 就是剩餘的"有守兵section數量"
                    real_now_guard -= solo_guard[now_r] - solo_guard[now_l-1];
                    if (real_now_guard > res)
                        res = real_now_guard;
                }
            }
        }
        
        printf("%d\n", res);
    }
    return 0;
}