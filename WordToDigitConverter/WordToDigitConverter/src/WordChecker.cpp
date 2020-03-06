#include "WordChecker.h"
#include <sstream>

WordChecker::WordChecker()
{

}

WordChecker::WordChecker(const string word)
{
	allNumbers.insert({ "one", 1 });
	allNumbers.insert({ "two", 2 });
	allNumbers.insert({ "three", 3 });
	allNumbers.insert({ "four", 4 });
	allNumbers.insert({ "five", 5 });
	allNumbers.insert({ "six", 6 });
	allNumbers.insert({ "seven", 7 });
	allNumbers.insert({ "eight", 8 });
	allNumbers.insert({ "nine", 9 });
	allNumbers.insert({ "ten", 10 });
	allNumbers.insert({ "eleven", 11 });
	allNumbers.insert({ "twelve", 12 });
	allNumbers.insert({ "thirteen", 13 });
	allNumbers.insert({ "fourteen", 14 });
	allNumbers.insert({ "fifteen", 15 });
	allNumbers.insert({ "sixteen", 16 });
	allNumbers.insert({ "seventeen", 17 });
	allNumbers.insert({ "eighteen", 18 });
	allNumbers.insert({ "nineteen", 19 });
	allNumbers.insert({ "twenty", 20 });
	allNumbers.insert({ "thirty", 30 });
	allNumbers.insert({ "forty", 40 });
	allNumbers.insert({ "fifty", 50 });
	allNumbers.insert({ "sixty", 60 });
	allNumbers.insert({ "seventy", 70 });
	allNumbers.insert({ "eighty", 80 });
	allNumbers.insert({ "ninety", 90 });
	allNumbers.insert({ "hundred", 100 });
	allNumbers.insert({ "thousand", 1000 });
	allNumbers.insert({ "million", 1000000 });
	allNumbers.insert({ "billion", 1000000000 });
	allNumbers.insert({ "trillion", 1000000000000 });

	numberSplitters.insert({ "hundred", 100 });
	numberSplitters.insert({ "thousand", 1000 });
	numberSplitters.insert({ "million", 1000000 });
	numberSplitters.insert({ "billion", 1000000000 });
	numberSplitters.insert({ "trillion", 1000000000000 });

	setWordProperties(word);
}

void WordChecker::setWordProperties(const string word)
{
	wordWithProperties.word = word;
	checkNumber();
	checkSplitter();

	if (hasNonAlphabethicalCharacter(wordWithProperties.word))
	{
		wordWithProperties.isNonAlpha = true;
	}
}

void WordChecker::checkNumber()
{
	long long number = 0;
	
	if (hasHyphen())
	{
		number = computeNumberWithHyphen();
	}
	else
	{
		number = calculateNumber(toLowerCase(wordWithProperties.word));
	}

	if (number != -1)
	{
		wordWithProperties.number = static_cast<unsigned long long>(number);
		wordWithProperties.isNumber = true;
	}
	else
	{
		wordWithProperties.isNumber = false;
	}
}

long long WordChecker::computeNumberWithHyphen()
{
	// Parsear el string hasta el guion. mirar si es numero. si lo es, me lo guardo y sigo parseando, sino pongo isNumber a false
	string word = toLowerCase(wordWithProperties.word);
	size_t found = word.find("-");
	
	string partialNumber = toLowerCase(word.substr(0, found));

	long long result = calculateNumber(partialNumber);
	
	if (result != -1)
	{
		partialNumber = toLowerCase(word.substr(found + 1));

		unsigned long long partialResult = calculateNumber(partialNumber);

		if (partialResult != -1)
		{
			result += partialResult;
		}

		return result;
	}

	return -1;
}

long long WordChecker::calculateNumber(const string number)
{
	map<string, unsigned long long>::iterator itAllNumbers = allNumbers.find(number);

	if (itAllNumbers != allNumbers.end())
	{
		return itAllNumbers->second;
	}

	return -1;
}

void WordChecker::checkSplitter()
{
	string wordToLowerCase = toLowerCase(wordWithProperties.word);

	map<string, unsigned long long>::iterator itSplitter = numberSplitters.find(wordToLowerCase);

	if (itSplitter != numberSplitters.end())
	{
		wordWithProperties.number = itSplitter->second;
		wordWithProperties.isSplitter = true;
	}
	else
	{
		wordWithProperties.isSplitter = false;
	}
}

bool WordChecker::hasNonAlphabethicalCharacter(string word)
{
	for (string::iterator i = word.begin(); i != word.end(); i++)
	{
		char c = word.at(i - word.begin());

		if (!isalnum(c) && (c != '-'))
		{
			return true;
		}
	}
	return false;
}

bool WordChecker::isNumber() const
{
	return wordWithProperties.isNumber;
}

bool WordChecker::isSplitter() const
{
	return wordWithProperties.isSplitter;
}

unsigned long long WordChecker::toNumber()
{
	return wordWithProperties.number;
}

bool WordChecker::isNonAlpha() const
{
	return wordWithProperties.isNonAlpha;
}

bool WordChecker::isAnd()
{
	string word = toLowerCase(wordWithProperties.word);
	
	if (word.compare("and") == 0)
		return true;

	return false;
}

bool WordChecker::hasHyphen()
{
	string word = wordWithProperties.word;

	if (word.find("-") != string::npos)
	{
		return true;
	}

	return false;
}

string WordChecker::toLowerCase(string stringToTranform)
{
	string stringToLowerCase;

	for (string::iterator i = stringToTranform.begin(); i != stringToTranform.end(); i++)
	{
		char c = stringToTranform.at(i - stringToTranform.begin());

		stringToLowerCase.push_back(tolower(c));
	}

	return stringToLowerCase;
}