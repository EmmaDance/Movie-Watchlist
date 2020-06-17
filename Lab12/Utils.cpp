#include "Utils.h"
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> tokenize(const string & line, char separator)
{
	vector<string> res;
	stringstream ss(line);
	string token;

	while (getline(ss, token, separator))
		res.push_back(token);
	return res;
}
