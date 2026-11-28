#include "../lib/trie.hpp"
using namespace std;

int main(){
	int t, n;

	cin >> t;
	vector<string> results;
	for(int i = 0; i < t; i++){
		cin >> n;
		vector<string> strings;
		for(int j = 0; j < n; j++){
			string s;
			cin >> s;
			strings.push_back(s);
		}
		Trie t;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				t.insert(strings[j] + strings[k]);
			}
		}
		string res = "";
		for(int j = 0; j < n; j++){
			if(t.contains(strings[j])) res += "1";
			else res += "0";
		}
		results.push_back(res);
	}
	for(int i = 0; i < t; i++){
		cout<<results[i]<<endl;
	}
	return 0;
}
