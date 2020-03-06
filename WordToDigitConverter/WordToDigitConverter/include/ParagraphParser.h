#include <vector>
#include <string>
#include "WordChecker.h"

using namespace std;

#pragma once
class ParagraphParser
{
public:
	ParagraphParser();

	string transformText(const string& consoleText);

protected:
	unsigned long long computePartialNumber(vector<WordChecker>partialNumber);

	vector<string> splitText(const string& consoleText);

	unsigned long long transformNumber(vector<WordChecker>numberInWords);
};

