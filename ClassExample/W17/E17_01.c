// E17_01
//
#include <stdio.h> 

unsigned getBits(unsigned x, int p, int n)
{
   return ( x >> (p-n) ) & ~( ~0 << n );  /* 取出 x 的第 p 位置起 n 個 bits */
}

unsigned invert( unsigned x, int p, int n )
{
   return  x ^ (~(~0 << n) << (p-n));
}

unsigned rightRotate( unsigned x, int n )
{
    // ( x & ~(~0 << n) ) << ( sizeof( x ) * 8 - n )
    // 這一串會將最右邊n位往左推到最左邊, sizeof( x ) * 8 - n位會全部超出去範圍, 不重要
    // x >> n
    // 這一串會將最右邊n去掉, 剩下的排在最右邊
    // AAAAAAB|C
    // C|AAAAAAB
    return ( ( x & ~(~0 << n) ) << ( sizeof( x ) * 8 - n ) ) | ( x >> n );
}

unsigned nextone( unsigned x )
// x = 38; // 00100110
// t = x & -x; // 00100110 & 11011010 -> 00000010 找出最右邊的 1
// y = t + x;  // 00000010 + 00100110 -> 00101000 設法讓x 最右邊的連續的 1 都變成 0，當作是下一個要考慮的數的起點，y 包含的 1 的數量一定會比 x 還少。接下來只要知道要替 y 補上幾個 1，就可以得到我們要的結果
// z = y ^ x;  // 00101000 ^ 00100110 -> 00001110 找出上一步哪些地方被改了
// z = (z/t)>>2; // (00001110 / 00000010) >> 2 -> 00000001 去掉最右邊的 0 然後忽略最左邊和最右邊（總共兩個）1，如此可以得到需要補的 1 有幾個
// x = y | z; //00101000 | 00000001 -> 00101001 把上缺的 1
{
    unsigned t, y, z;
    t = x & -x; 
    y = t + x;
    z = y ^ x; 
    z = (z/t)>>2;
    x = y | z;
    return x;
}

int main( void )
{
    unsigned test = 0x0111101e;
    // 0000 0001 0001 0001 0001 0000 0001 0001
    // 從右邊數來第24bit開始往後取8bit
    // p.s. p should >= n
    // test = getBits( test, 24, 8 );

    // test = invert( test, 12, 4 );
    // 從右邊數來第p個bit開始往後取n bit

    // test = rightRotate( test, 4 );

    test = nextone( test );o
    printf( "0x%08x\n", test );

    unsigned a = 0xA4;
    unsigned b = 0x1F;
    printf( "%08x\n", a + b );


    return 0;
}