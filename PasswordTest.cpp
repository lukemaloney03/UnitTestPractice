/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(Password_CountLeadingCharacters, ReturnsZeroForEmptyString)
{
    Password my_password;
    int actual = my_password.count_leading_characters("");
    ASSERT_EQ(0, actual);
}

TEST(Password_CountLeadingCharacters, ReturnsOneForSingleSpace)
{
    Password my_password;
    int actual = my_password.count_leading_characters(" ");
    ASSERT_EQ(1, actual);
}

TEST(Password_CountLeadingCharacters, CountsLeadingSpaces)
{
    Password my_password;
    int actual = my_password.count_leading_characters("   Z");
    ASSERT_EQ(3, actual);
}

TEST(Password_CountLeadingCharacters, ReturnsOneForSingleCharacter)
{
    Password my_password;
    int actual = my_password.count_leading_characters("Z");
    ASSERT_EQ(1, actual);
}

TEST(Password_CountLeadingCharacters, CountsConsecutiveCharacters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("AAAxyz");
    ASSERT_EQ(3, actual);
}

TEST(Password_CountLeadingCharacters, ReturnsOneForMixedCharacters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("ABC");
    ASSERT_EQ(1, actual);
}

TEST(Password_HasMixedCase, ReturnsTrueForMixedCase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("Zz");
    ASSERT_EQ(true, actual);
}

TEST(Password_HasMixedCase, ReturnsFalseForAllUppercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("ZZ");
    ASSERT_EQ(false, actual);
}

TEST(Password_HasMixedCase, ReturnsFalseForAllLowercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("zz");
    ASSERT_EQ(false, actual);
}

TEST(Password_HasMixedCase, ReturnsTrueForLongerMixedCaseStrings)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("AbCdEfG");
    ASSERT_EQ(true, actual);
}

TEST(Password_HasMixedCase, ReturnsTrueForMixedCaseWithNumbers)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("123Aa456");
    ASSERT_EQ(true, actual);
}

TEST(Password_HasMixedCase, ReturnsFalseForNoAlphabetCharacters)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("123456");
    ASSERT_EQ(false, actual);
}

TEST(Password_HasMixedCase, ReturnsFalseForSpecialCharactersOnly)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("!@#$%");
    ASSERT_EQ(false, actual);
}

TEST(Password_HasMixedCase, ReturnsFalseForEmptyString)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("");
    ASSERT_EQ(false, actual);
}
