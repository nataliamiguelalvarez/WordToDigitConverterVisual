#include "WordChecker.h"
#include "gtest/gtest.h"

TEST(WordChecker, isNumber_givenAnEmptyString_thenThereIsNotAnyNumber)
{
	WordChecker sut("");

	EXPECT_FALSE(sut.isNumber());
}

TEST(WordChecker, isNumber_givenAnyStringThatIsNotInNumberList_thenThereIsNotAnyNumber)
{
	WordChecker sut("e");

	EXPECT_FALSE(sut.isNumber());
}

TEST(WordChecker, isNumber_givenAStringThatIsInNumberList_thenThereIsANumber)
{
	WordChecker sut("twenty");

	EXPECT_TRUE(sut.isNumber());
}

TEST(WordChecker, isNumber_givenAStringThatIsANumberAndASplitter_thenThereIsANumber)
{
	WordChecker sut("thousand");

	EXPECT_TRUE(sut.isNumber());
}

TEST(WordChecker, isSplitter_givenAnEmptyString_thenThereIsNotAnySplitter)
{
	WordChecker sut("");

	EXPECT_FALSE(sut.isSplitter());
}

TEST(WordChecker, isSplitter_givenAnyStringThatIsNotInNumberList_thenThereIsNotAnySplitter)
{
	WordChecker sut("e");

	EXPECT_FALSE(sut.isSplitter());
}

TEST(WordChecker, isSplitter_givenAStringThatIsInSplitterList_thenThereIsASplitter)
{
	WordChecker sut("thousand");

	EXPECT_TRUE(sut.isSplitter());
}

TEST(WordChecker, isSplitter_givenAStringThatIsInNumberList_thenThereIsNotASplitter)
{
	WordChecker sut("twenty");

	EXPECT_FALSE(sut.isSplitter());
}

TEST(WordChecker, toNumber_givenAnEmptyString_thenThereIsNoNumber)
{
	WordChecker sut("");

	EXPECT_EQ(sut.toNumber(), 0);
}

TEST(WordChecker, toNumber_givenAnyStringThatIsNotANumber_thenThereIsNoNumber)
{
	WordChecker sut("e");

	EXPECT_EQ(sut.toNumber(), 0);
}

TEST(WordChecker, toNumber_givenAnyStringThatIsANumber_thenTheNumberAsAnInteger)
{
	WordChecker sut("forty");

	EXPECT_EQ(sut.toNumber(), 40);
}

TEST(WordChecker, toNumber_givenAnyStringThatIsANumberWithHyphen_thenTheNumberAsAnInteger)
{
	WordChecker sut("forty-three");

	EXPECT_EQ(sut.toNumber(), 43);
}

TEST(WordChecker, toNumber_givenAnyStringThatIsALargeNumber_thenTheNumberAsAnInteger)
{
	WordChecker sut("trillion");

	EXPECT_EQ(sut.toNumber(), 1000000000000);
}