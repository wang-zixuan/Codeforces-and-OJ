#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
	char input_str[100];
	gets(input_str);

	for (int i = 0; i < strlen(input_str); i++) {
		if (input_str[i] == 'A' || input_str[i] == 'E' || input_str[i] == 'Y' || input_str[i] == 'I' || input_str[i] == 'O' || input_str[i] == 'U' || input_str[i] == 'a' || input_str[i] == 'e' || input_str[i] == 'y' || input_str[i] == 'i' || input_str[i] == 'o' || input_str[i] == 'u')
			continue;
		cout << ".";
		if (input_str[i] < 'a')
			input_str[i] += 32;
		cout << input_str[i];
	}
	cout << endl;
	return 0;
}