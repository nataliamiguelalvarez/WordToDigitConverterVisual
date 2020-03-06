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

TEST(WordChecker, isNumber_givenAnyStringThatIsNotAlphanumeric_thenThereIsNotAnyNumber)
{
	WordChecker sut("\n");

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

TEST(WordChecker, isNumber_givenAStringThatIsANumberCharacter_thenThereIsNotANumber)
{
	WordChecker sut("45");

	EXPECT_FALSE(sut.isNumber());
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

TEST(WordChecker, hasHyphen_givenAnEmptyString_thenTheWordHasNoHyphen)
{
	WordChecker sut("");

	EXPECT_FALSE(sut.hasHyphen());
}


TEST(WordChecker, hasHyphen_givenAStringWithoutHyphen_thenTheWordHasNoHyphen)
{
	WordChecker sut("word");

	EXPECT_FALSE(sut.hasHyphen());
}

TEST(WordChecker, hasHyphen_givenAStringWithHyphen_thenTheWordHasHyphen)
{
	WordChecker sut("word-word");

	EXPECT_TRUE(sut.hasHyphen());
}

TEST(WordChecker, hasHyphen_givenAStringWithMoreThanOneHyphen_thenTheWordHasHyphen)
{
	WordChecker sut("word-word-word");

	EXPECT_TRUE(sut.hasHyphen());
}

TEST(WordChecker, isAnd_givenAnEmptyString_thenTheWordIsNotAnAnd)
{
	WordChecker sut("");

	EXPECT_FALSE(sut.isAnd());
}

TEST(WordChecker, isAnd_givenAnyStringWithoutAnd_thenTheWordIsNotAnAnd)
{
	WordChecker sut("word");

	EXPECT_FALSE(sut.isAnd());
}

TEST(WordChecker, isAnd_givenAnyStringThatContainsAnAnd_thenTheWordIsNotAnAnd)
{
	WordChecker sut("wordand");

	EXPECT_FALSE(sut.isAnd());
}

TEST(WordChecker, isAnd_givenAnyStringThatContainsAnAndAndAHyphen_thenTheWordIsNotAnAnd)
{
	WordChecker sut("word-and");

	EXPECT_FALSE(sut.isAnd());
}

TEST(WordChecker, isAnd_givenAnyStringThatIsAnAndInLowerCase_thenTheWordIsAnAnd)
{
	WordChecker sut("and");

	EXPECT_TRUE(sut.isAnd());
}

TEST(WordChecker, isAnd_givenAnyStringThatIsAnAndWithSomeUpperCase_thenTheWordIsAnAnd)
{
	WordChecker sut("And");

	EXPECT_TRUE(sut.isAnd());
}

TEST(WordChecker, isNonAlpha_givenAnEmptyString_thenIsNotAnAlphaNumericString)
{
	WordChecker sut("");

	EXPECT_FALSE(sut.isNonAlpha());
}

TEST(WordChecker, isNonAlpha_givenAnAlphanumericString_thenItIsAlphaNumericString)
{
	WordChecker sut("word");

	EXPECT_FALSE(sut.isNonAlpha());
}

TEST(WordChecker, isNonAlpha_givenAnNonAlphanumericString_thenItIsNotAnAlphaNumericString)
{
	WordChecker sut(".");

	EXPECT_TRUE(sut.isNonAlpha());
}

TEST(WordChecker, isNonAlpha_givenAStringThatContainsAnAlphanumericString_thenItIsNotAnAlphaNumericString)
{
	WordChecker sut("word.");

	EXPECT_TRUE(sut.isNonAlpha());
}

TEST(WordChecker, hasNonAlphabethicalCharacter_givenAnEmptyString_thenItHasOnlyAlphaNumericCharacter)
{
	EXPECT_FALSE(WordChecker::hasNonAlphabethicalCharacter(""));
}

TEST(WordChecker, hasNonAlphabethicalCharacter_givenAStringOnlyWithAlphabeticalCharacters_thenItHasOnlyAlphaNumericCharacter)
{
	EXPECT_FALSE(WordChecker::hasNonAlphabethicalCharacter("word"));
}

TEST(WordChecker, hasNonAlphabethicalCharacter_givenAStringOnlyANonAlphabeticalCharacters_thenItHasSomeNoneAlphaNumericCharacter)
{
	EXPECT_TRUE(WordChecker::hasNonAlphabethicalCharacter("word."));
}

TEST(WordChecker, hasNonAlphabethicalCharacter_givenAStringOnlyAnyNonAlphabeticalCharacters_thenItHasSomeNoneAlphaNumericCharacter)
{
	EXPECT_TRUE(WordChecker::hasNonAlphabethicalCharacter("word.word-word"));
}

TEST(WordChecker, hasNonAlphabethicalCharacter_givenAStringWithAHyphen_thenItHasOnlyAlphaNumericCharacter)
{
	EXPECT_FALSE(WordChecker::hasNonAlphabethicalCharacter("word-word"));
}
