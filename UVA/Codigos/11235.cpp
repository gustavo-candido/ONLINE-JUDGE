#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector< vi > vii;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef map<int,string> mis;


#define pb push_back
#define MAX 200005
#define S 100000
#define MAX2 1000000

int N,Q;
int cnt[ MAX ];
int start[ MAX ];
int n[ MAX ];
int sTree[ MAX2 ];

void makeTree(int nodeNumber , int s, int e ){
if( s == e ) {
  sTree[ nodeNumber ] = cnt[ n[ s ] ];
  return ;
}
int md = ( s + e ) / 2;
int n1 = ( 2 * nodeNumber ) + 1;
int n2 = n1 + 1;
makeTree( n1, s , md ) ;
makeTree( n2, md + 1, e );
if( sTree[ n1 ] >= sTree[ n2 ] ) sTree[ nodeNumber ] = sTree[ n1 ];
else sTree[ nodeNumber ] = sTree[ n2 ];
}

int makeQuery( int nodeNumber, int s, int e, int r1, int r2 ) {
int ret ;
if( e < r1 || s > r2 ) return -1;
if( s >= r1 && e <= r2 ) return sTree[ nodeNumber ];
int n1 = ( 2 * nodeNumber ) + 1;
int n2 = ( 2 * nodeNumber ) + 2;
int md = ( s + e ) / 2;
int v1 = makeQuery( n1, s, md , r1, r2 );
int v2 = makeQuery( n2, md + 1, e, r1, r2 );
if( v1 == -1 ) ret = v2;
if( v2 == -1 ) ret = v1;
if( v1 >= v2 ) ret = v1;
else ret = v2;
return ret;
}

int main(){
// freopen("a.txt", "r", stdin);
int i,j;
while( scanf("%d", &N) == 1 ) {
  if( N == 0 ) break ;
  scanf("%d", &Q);
  memset( cnt, 0, sizeof( cnt ) );
  memset( start, -1, sizeof( cnt ) ) ;
  for( i = 0; i < N; i ++ ) {
   scanf("%d", &n[ i ] ) ;
   n[ i ] += S;
   cnt[ n[ i ]  ] ++ ;
   if( cnt[ n [ i ] ] == 1 ) start[ n[ i ] ] = i;
  
  }
  makeTree( 0, 0, N - 1 );
  int a,b;
  for( i = 0; i < Q; i ++ ) {
   scanf("%d %d", &a, &b);
   a -- ;
   b -- ;
   if( n[ a ] == n[ b ] ) {
    printf("%d\n", b - a + 1 );
    continue;
   }
  
   int ans ;
   int v1 = cnt[ n[ a ] ] - a + start[ n [ a ] ];
   int v2 = b - start[ n[ b ] ] + 1;
   if( v1 > v2 ) ans = v1;
   else ans = v2;
   int r1 = start[ n[ a ] ] + cnt[ n[ a ] ] ;
   int r2 = start[ n[ b ] ] - 1;
   if( r1 <= r2 ) {
    int var = makeQuery( 0, 0, N - 1, r1, r2 );
    if( var > ans ) ans = var ;
    
   }

   printf("%d\n", ans );

  }

}
return 0;
}

