#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
	vector<int> arr={12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
	int n = 7;

	sort(arr.begin(),arr.end());
	int ans=INT_MAX;

	for(int i=0;i<arr.size();i++){
		if(i == (arr.size()-n)){
			ans = min(ans, (arr[i+n-1] - arr[i]));
			break;
		}

		ans = min(ans, (arr[i+n-1] - arr[i]));
	}

	cout<<ans<<endl;
    
	return 0;
}
