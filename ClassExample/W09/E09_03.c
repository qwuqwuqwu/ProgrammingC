#include <stdio.h>
#include <ctype.h>

int Prefix( void )
{   
    int ans, op1, op2;
    char c = getchar();
    if( c == ' ' ) {
	    return Prefix();
    }
    else if ( isdigit( c ) ) {
        ungetc(c, stdin);
        scanf("%d", &ans);
        return ans;
    }
    
    // + is leading two number, so this is a prefix
    if( c == '+' ) {
        op1 = Prefix();
        op2 = Prefix();
		return op1 + op2;
	}
    else if( c == '-' ) {
        op1 = Prefix();
        op2 = Prefix();  
		return op1 - op2;
	}
    else if( c == '*' ) {
        op1 = Prefix();
        op2 = Prefix();
		return op1 * op2;
	}
    return 0;
}

int PrefixStringToInfixString()
{
    int ans, op1, op2;
    char c = getchar();
    if( c == ' ' ) {
	    return PrefixStringToInfixString();
    }
    else if ( isdigit( c ) ) {
        ungetc(c, stdin);
        scanf("%d", &ans);
        printf( "%d", ans );
        return ans;
    }
    
    // + is leading two number, so this is a prefix
    if( c == '+' ) {
        printf( " ( " );
        op1 = PrefixStringToInfixString();
        printf( " + " );
        op2 = PrefixStringToInfixString();
        printf( " ) " );
		return op1 + op2;
	}
    else if( c == '-' ) {
        printf( " ( " );
        op1 = PrefixStringToInfixString();
        printf( " - " );
        op2 = PrefixStringToInfixString();  
        printf( " ) " );
		return op1 - op2;
	}
    else if( c == '*' ) {
        printf( " ( " );
        op1 = PrefixStringToInfixString();
        printf( " * " );
        op2 = PrefixStringToInfixString();
        printf( " ) " );
		return op1 * op2;
	}
    return 0;
}

int main(void)
{
    //printf("%d\n", Prefix());
    printf(" = %d\n", PrefixStringToInfixString());
    return 0;
}