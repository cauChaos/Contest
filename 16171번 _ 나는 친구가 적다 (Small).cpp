#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using LL = long long;

int str_search(const char*, const char*);

int main() {
	char source[200001] = { 0, };
	char deleted[200001] = { 0, };
	char keyword[200001] = { 0, };

	scanf("%s", source);
	scanf("%s", keyword);

	//Delete All Number from source
	int cursor = 0;
	for (int pos = 0; pos < strlen(source); pos++) {
		if (source[pos] <= '9' && source[pos] >= '0') {
			continue;
		}
		else {
			deleted[cursor] = source[pos];
			cursor++;
		}
	}

	//Find Keyword from Deleted Source String
	int result = str_search(deleted, keyword);

	printf("%d", result);
	return 0;
}


//Bruteforce Search
/*
abcdefgh
abcd
 abcd
  abcd
   abcd
    abcd
*/
int str_search(const char* _dest, const char* _keyword) {
	int result = 1;

	for (int i = 0; i < strlen(_dest)-strlen(_keyword)+1; i++) {
		result = 1;
		for (int j = 0; j < strlen(_keyword); j++) {
			if (_dest[i+j] != _keyword[j]) {
				result = 0;
				break;
			}
		}
		if (result == 1) {
			return result;
		}
	}
	return result;
}
