
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
	int m,n;
	vector<int> a[5];
	while( n--){
		cin>>m;		
		if(m>=90){
			a[0].push_back(m);
		}else if( m>=80){
			a[1].push_back(m);
		}else if( m>=70){
			a[2].push_back(m);
		}else if( m>=60){
			a[3].push_back(m);
		}else {
			a[4].push_back(m);
		}
	}
	int maxn=a[0].size(), idx=0;
	cout<< a[0].size()<< ' '; 
	for(int i=1; i<5; i++){
		cout<< a[i].size()<< ' ';
		if( a[i].size() > maxn){
			maxn = a[i].size();
			idx = i;
		}
	}
	cout<< '\n'<< maxn<< '\n';
	sort( a[idx].begin(), a[idx].end());
	for(int i = a[idx].size()-1; i >= 0; i--) cout<< a[idx][i]<< ' ';
	return 0;
}

