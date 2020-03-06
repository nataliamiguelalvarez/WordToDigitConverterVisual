#include "ParagraphParser.h"
#include <iostream>
#include <sstream>
#include <iterator>

ParagraphParser::ParagraphParser()
{

}

vector<string> ParagraphParser::splitText(const string& consoleText)
{
	stringstream consoleTextStream(consoleText);
	string textWord;
	vector<string>paragraphStrings;

	while (consoleTextStream >> textWord)
	{
		if (WordChecker::hasNonAlphabethicalCharacter(textWord))
		{
 			string tempWord("");
			for (string::iterator i = textWord.begin(); i != textWord.end(); i++)
			{
				char c = textWord.at(i - textWord.begin());

				if (!isalnum(c) && (c != '-'))
				{
					if (tempWord != "")
					{
						paragraphStrings.push_back(tempWord);
						tempWord = "";
					}
					string nonAlphabethicalCharacter;
					nonAlphabethicalCharacter.push_back(c);
					paragraphStrings.push_back(nonAlphabethicalCharacter);
				}
				else
				{
					tempWord.push_back(c);
				}
			}

			if (tempWord != "")
			{
				paragraphStrings.push_back(tempWord);
			}
		}
		else
		{
			paragraphStrings.push_back(textWord);
		}	
	}

	return paragraphStrings;
}

unsigned long long ParagraphParser::computePartialNumber(vector<WordChecker>partialNumber)
{
unsigned long long result = 0;
unsigned long long partialResult = 0;

for (unsigned int i = 0; i < partialNumber.size(); i++)
{
	WordChecker number = partialNumber[i];

	if (number.isSplitter())
	{
		if (partialResult == 0)
		{
			partialResult = number.toNumber();
		}
		else
		{
			result = partialResult * number.toNumber();
			partialResult = 0;
		}
	}
	else
	{
		if (number.isNumber())
		{
			if (partialResult == 0)
			{
				partialResult = number.toNumber();
			}
		}
	}
}

result += partialResult;

return result;
}

unsigned long long ParagraphParser::transformNumber(vector<WordChecker>numberInWords)
{
	unsigned long long result = 0;

	vector<WordChecker>partialNumber;

	for (unsigned int i = 0; i < numberInWords.size(); i++)
	{
		WordChecker word = numberInWords[i];

		if (word.isAnd())
		{
			result += computePartialNumber(partialNumber);
			partialNumber.clear();
		}
		else
		{
			partialNumber.push_back(word);
		}
	}

	result += computePartialNumber(partialNumber);

	return result;
}

string ParagraphParser::transformText(const string& consoleText)
{
	vector<string> paragraphStrings = splitText(consoleText);

	unsigned long long totalNumber = 0;
	vector<string> transformedText;
	vector<WordChecker>number;

	stringstream finalString;

	for (unsigned int i = 0; i < paragraphStrings.size(); i++)
	{
		string word = paragraphStrings[i];
		WordChecker wordChecker(word);

		// A number, splitter or an and
		if (wordChecker.isSplitter() || wordChecker.isNumber() || wordChecker.isAnd())
		{
			// The current number is always saved in number vector
			if (wordChecker.isAnd() && number.size() == 0)
			{
				finalString << " " << word;
			}
			else
			{
				number.push_back(wordChecker);
			}
		}
		else
		{
			// The following word is not a number. Then check if there are a number to process
			if (number.size() > 0)
			{
				finalString << " " << to_string(transformNumber(number));

				// Check if the last word was an "and" to saved it
				if (number[number.size() - 1].isAnd())
				{
					finalString << " " << paragraphStrings[i - 1];
				}
				number.clear();
			}

			if ((!wordChecker.isNonAlpha()) && (i > 0))
			{ 
				finalString << " ";
			}
			finalString << word;
		}
	}

	if (number.size() > 0)
	{
		finalString << to_string(transformNumber(number));
		number.clear();
	}

	return finalString.str();
}
