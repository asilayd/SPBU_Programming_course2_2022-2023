#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
bool is_Same(string s1, string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	if (l1 != l2) { return false; }
	for (int i = 0; i < l1; ++i) {
		if (s1[i] != s2[i]) { return false; }
	}

	return true;
}
void translate(string input, int side)
{
	ifstream voc("voc.txt");
	string line;
	string word1;
	string word2;
	while (getline(voc, line)) {
		stringstream x;
		x << line;
		x >> word1;
		x >> word2;
		if (side == 0)
		{
			if ((is_Same(word2, input)||(is_Same(word1, input)))) 
			{
				cout << word1 << " ";
			}
		}
		else if (side == 1)
		{
			if (is_Same(word1, input) || (is_Same(word2, input))) {
				cout << word2 << " ";
			}
		}
	}

}
void text_translate(string name, int side)
{
	string line;
	string word;
	ifstream in(name);
	getline(in, line);

	stringstream x;
	x << line;

	while (x >> word)
	{
		translate(word, side);
	}

}

int main()
{
	string name = "text1.txt";
	text_translate(name, 1);
	
	return 0;
}