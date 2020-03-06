#include <map>
#include <string>

using namespace std;

#pragma once

class WordChecker
{
public:

	/**
	  * Class constructor
	  *
	  * @param word A string with a word
	 */
	WordChecker(const string word);

	/**
	  * Returns if the word is in the numbers list
	 */
	bool isNumber() const;

	/**
	  * Returns if the word is in the splitter list
	 */
	bool isSplitter() const;
	
	/**
	  * Returns the word converter into a number (from string to unsigned long long)
	 */
	unsigned long long toNumber();

	/**
	  * Returns if the word has a hyphen
	 */
	bool hasHyphen();

	/**
	  * Returns if the word is the string "and"
	 */
	bool isAnd();

	/**
	  * Returns if the word is a non alphanumeric character
	 */
	bool isNonAlpha() const;

	/**
	  * Returns if the word has a character that is non alphanumeric
	 */
	static bool hasNonAlphabethicalCharacter(string word);

protected:

	/**
	  * Class constructor
	 */
	WordChecker();

	/**
	  * Struct that saves the properties of a word
	 */
	struct WordProperties
	{
		string word;
		bool isSplitter;
		bool isNumber;
		unsigned long long number;
		bool isNonAlpha;

		WordProperties() :
			word(""),
			isSplitter(false),
			isNumber(false),
			number(0),
			isNonAlpha(false)
		{

		}
	};
	
	/**
	  * Word with properties
	 */
	WordProperties wordWithProperties;

	/**
	  * Number's dictionary
	 */
	map<string, unsigned long long>allNumbers;

	/**
	  * Splitter's dictionary
	 */
	map<string, unsigned long long>numberSplitters;

	/**
	  * Sets the word's properties. Checks if it is a word (no numeric) or the word is a number or a splitter. 
	  * It also checks if the word has alphanumeric characters
	 */
	void setWordProperties(const string word);

	/**
	  * Checks if the word is a number and fills the corresponding properties
	 */
	void checkNumber();

	/**
	  * Checks if the word is a splitter and fills the corresponding properties
	 */
	void checkSplitter();

	/**
	  * Splits the number with hyphen in two numbers and computes the final result (i.e.: twenty-two = 22)
	 */
	long long computeNumberWithHyphen();

	/**
	  * Searches the number in the dictionary and converts the obtained number into a integer
	  *
	  * @param number The number as a string
	  * @return The number as an integer
	 */
	long long calculateNumber(const string number);

	/**
	  * Transform all the character of an string into lowercase characters
	  *
	  * @param stringToTranform The input string
	  * @return The input string in lowercase
	 */
	string toLowerCase(string stringToTranform);
};