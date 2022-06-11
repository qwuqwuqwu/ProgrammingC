// Problem 60
// more simple exercise of pointer on array
void array_exchanger(int* array_a, int* array_b, int length)
{
  for( int i = 0; i < length; i++ ) {
  	int nTemp = array_a[ i ];
    array_a[ i ] = array_b[ i ];
    array_b[ i ] = nTemp;
  }
}