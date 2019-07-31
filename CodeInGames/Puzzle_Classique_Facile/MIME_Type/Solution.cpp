#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main()
{
	int N; // Number of elements which make up the association table.
	cin >> N; cin.ignore();
	int Q; // Number Q of file names to be analyzed.
	cin >> Q; cin.ignore();

	std::map<string, string>EXT_MT;
	for (int i = 0; i < N; i++) {
		string EXT; // file extension
		string MT; // MIME type.    
		cin >> EXT >> MT; cin.ignore();
		std::transform(EXT.begin(), EXT.end(), EXT.begin(), [](unsigned char c) { return std::tolower(c); });
		EXT_MT.insert({ EXT,MT });
	}
	string extension;
	for (int i = 0; i < Q; i++) {
		string FNAME;
		getline(cin, FNAME);

		std::string::size_type idx;
		idx = FNAME.rfind('.');
		if (idx != std::string::npos)
		{
			std::string extension = FNAME.substr(idx + 1);
			std::transform(extension.begin(), extension.end(), extension.begin(), [](unsigned char c) { return std::tolower(c); });
			auto check = EXT_MT.find(extension);
			if (check != EXT_MT.end())
				std::cout << check->second << std::endl;
			else
				std::cout << "UNKNOWN" << std::endl;
			extension.clear();
		}
		else
			std::cout << "UNKNOWN" << std::endl;
	}
}