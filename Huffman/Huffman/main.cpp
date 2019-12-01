#include"huffman.h"

int main()
{
	vector<pair<string, int>> frequency;
	frequency.push_back(make_pair("A", 60));
	frequency.push_back(make_pair("B", 45));
	frequency.push_back(make_pair("C", 13));
	frequency.push_back(make_pair("D", 69));
	frequency.push_back(make_pair("E", 14));
	frequency.push_back(make_pair("F", 5));
	frequency.push_back(make_pair("G", 3));
	huffman T(frequency);
	T.get_code(T.get_root());
	map<string, string>::iterator iter;
	for (iter = T.str_code.begin(); iter != T.str_code.end(); iter++)
	{
		cout << iter->first << ":" << iter->second << endl;
	}
	return 0;
}