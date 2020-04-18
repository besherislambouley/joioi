/*
 * we notice that the component is  increasing prefixes / decreasing prefixes / increasing suffixes / decreasing suffixes from the rows 
 * the maximum number in the array is always a side of a component value , we use binary search on answer trying to build the maximum number's component in one of the four previous shapes
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , m , I , J ;
pair < int , pi > MX ;
int a [2009][2009] , done [2009][2009] ;
int yes ( int x ) {
	int mn = 1e9 , mx = -1e9 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			if ( done [i][j] ) C ;
			mn = min ( mn , a [i][j] ) ;
			mx = max ( mx , a [i][j] ) ;
		}
	}
	return ( mx - mn <= x ) ;
}
int check1 ( int x ) {
	mem ( done , 0 ) ;
	int last = 1e9 , mx = MX.fi , mn = 1e9 ;	
	for ( int i = 0 ; i < n ; i ++ ) {
		int crnt = 0 ;
		for ( int j = 0 ; j < m ; j ++ ) {
			if ( crnt == last ) break ;
			int MN  = min ( mn , a [i][j] ) ;
			if ( mx - MN > x ) {
				last = crnt ;
				break ;
			}
			mn = MN ;
			crnt ++ ;
			done [i][j] = 1 ;
		} 
		if ( i == I ) {
			if ( crnt < J+1 ) return 0 ;
		}
	}
	return yes ( x ) ;
}
int check2 ( int x ) {
	mem ( done , 0 ) ;
	int last = 1e9 , mx = MX.fi , mn = 1e9 ;
	for ( int i = n-1 ; i >=0 ; i -- ) {
		int crnt = 0 ;
		for ( int j = 0 ; j < m ; j ++ ) {
			if ( crnt == last ) break ;
			int MN = min ( mn , a [i][j] ) ;
			if ( mx - MN > x ) {
				last = crnt ;
				break ;
			}
			mn = MN ;
			crnt ++ ;
			done [i][j] = 1 ;
		}
		if ( i == I ) {
			if ( crnt < J+1 ) return 0 ;
		}
	}
	return yes ( x ) ;
}
int check3 ( int x ) {
	mem ( done , 0 ) ;
	int last = 1e9 , mx = MX.fi , mn = 1e9 ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int crnt = 0 ;
		for ( int j = m -1 ; j >= 0 ; j -- ) {
			if ( crnt == last ) break ; 
			int MN = min ( mn , a [i][j] ) ;
			if ( mx - MN > x ) {
				last = crnt ;
				break ;
			}
			mn = MN ;
			crnt ++ ;
			done [i][j] = 1 ;
		}
		if ( i == I ) {
			if ( crnt < m - J ) return 0 ;
		}
	}
	return yes ( x )  ;
}
int check4 ( int x ) {
	mem ( done , 0 ) ;
	int last = 1e9 , mx = MX.fi , mn = 1e9 ;
	for ( int i = n-1 ; i >=0 ; i -- ) {
		int crnt = 0 ;
		for ( int j = m -1 ; j >= 0 ; j -- ) {
			if ( crnt == last ) break ;
			int MN = min ( mn , a [i][j] ) ;
			if ( mx - MN > x ) {
				last = crnt ;
				break ; 
			}
			mn = MN ;
			crnt ++ ;
			done [i][j] = 1 ;
		}
		if ( i == I ) {
			if ( crnt < m - J ) return 0 ;
		}
	}
	return yes ( x )  ;
}
int main () {
	cin >> n >> m ;
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 0 ; j < m ; j ++ ) {
			cin >> a [i][j] ;
			MX = max ( MX , { a[i][j] , { i , j } } ) ;
		}
	}
	I = MX.se.fi ;
	J = MX.se.se ;
	int l = -1 , r = 2e9 ;
	while ( r - l > 1 ) {
		if ( check1 ( mid ) || check2 ( mid ) || check3 ( mid ) || check4 ( mid ) ) r = mid ;
		else l = mid ;
	}
	cout << r << endl ; 
}
