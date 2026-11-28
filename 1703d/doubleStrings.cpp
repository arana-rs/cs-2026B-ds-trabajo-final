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
			t.insert(strings[j]);
		}
		string res = "";
		for(int j = 0; j < n; j++){
			char ok = '0';
			for(string &p : t.allPrefixOf(strings[j])){
				if(p.size() < strings[j].size() && t.contains(strings[j].substr(p.size()))){
					ok = '1';
					break;
				}
			}
			res += ok;
		}
		results.push_back(res);
	}
	for(int i = 0; i < t; i++){
		cout<<results[i]<<endl;
	}
	return 0;
}
