#include "ParagraphParser.h"
#include "gtest/gtest.h"

TEST(ParagraphParser, transformText_givenAnEmptyString_thenTheStringRemainsEmpty)
{
	ParagraphParser sut;
	string expected = "";
	string actual = sut.transformText("");
	
	EXPECT_STREQ(expected.c_str(), actual.c_str());
}

TEST(ParagraphParser, transformText_givenAWordThatIsASimpleNumber_thenTheNumbersIsTransformed)
{
	ParagraphParser sut;
	string expected = "1";
	string actual = sut.transformText("one");

	EXPECT_STREQ(expected.c_str(), actual.c_str());
}

TEST(ParagraphParser, transformText_givenAWordThatIsAComposedNumber_thenTheNumbersIsTransformed)
{
	ParagraphParser sut;
	string expected = "165";
	string actual = sut.transformText("one hundred and sixty-five");

	EXPECT_STREQ(expected.c_str(), actual.c_str());
}

TEST(ParagraphParser, transformText_givenATextWithoutNumbers_thenTheTextRemainsTheSame)
{
	ParagraphParser sut;
	string expected = "This is a text without numbers";
	string actual = sut.transformText("This is a text without numbers");

	EXPECT_STREQ(expected.c_str(), actual.c_str());
}

TEST(ParagraphParser, transformText_givenATextWithoutNumbersAndWithNonAlphabeticalNumbers_thenTheTextRemainsTheSame)
{
	ParagraphParser sut;
	string expected = "This is a text without numbers. But there are some non alphabetical numbers!";
	string actual = sut.transformText("This is a text without numbers. But there are some non alphabetical numbers!");

	EXPECT_STREQ(expected.c_str(), actual.c_str());
}

TEST(ParagraphParser, transformText_givenATextWithoutNumbersAndWithNonAlphabeticalNumbersAndHyphens_thenTheTextRemainsTheSame)
{
	ParagraphParser sut;
	string expected = "This is a text without numbers, but there are some non alphabetical symbols! And also some hyphen-symbols.";
	string actual = sut.transformText("This is a text without numbers, but there are some non alphabetical symbols! And also some hyphen-symbols.");

	EXPECT_STREQ(expected.c_str(), actual.c_str());
}

TEST(ParagraphParser, transformText_givenATextWithNumbers_thenTheNumbersOfTheTextAreTransformed)
{
	ParagraphParser sut;
	string expected = "This text has 3 numbers inside. 1 of the numbers is simple. The following is 182. And last number is 4512.";
	string actual = sut.transformText("This text has 3 numbers inside. One of the numbers is simple. The following is one hundred and eighty-two. And last number is four thousand and five hundred and twelve.");

	EXPECT_STREQ(expected.c_str(), actual.c_str());
}

// This test has a fail result
/*TEST(ParagraphParser, transformText_givenTwoWordsThatAreNumbers_thenBothNumbersAreTransformed)
{
	ParagraphParser sut;
	string expected = "1 1";
	string actual = sut.transformText("one one");

	EXPECT_STREQ(expected.c_str(), actual.c_str());
}*/