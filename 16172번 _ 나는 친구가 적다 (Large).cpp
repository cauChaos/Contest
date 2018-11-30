#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using LL = long long;

void computeLPSArray(char* pat, int M, int* lps);
void KMPSearch(char* pat, char* txt);

int res = 99;

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
	KMPSearch(keyword, deleted);
	printf("%d", res);

	return 0;
}


//Bruteforce Search

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	res = 0;
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int* lps = (int*)malloc(sizeof(int)*M);

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			res = 1;
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

				// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
