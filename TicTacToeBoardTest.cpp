/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(TicTacToeBoardTest, invalidPlacement)
{
  TicTacToeBoard testBoard;
  ASSERT_EQ(testBoard.placePiece(3,1),Invalid);
}

TEST(TicTacToeBoardTest, checkToggleTurnFirst)
{
  TicTacToeBoard testBoard;
	EXPECT_EQ(testBoard.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, checkToggleTurnDouble)
{
  TicTacToeBoard testBoard;
  testBoard.toggleTurn();
  EXPECT_EQ(testBoard.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, checkToggleTurnOdd)
{
  TicTacToeBoard testBoard;
  testBoard.toggleTurn();
  testBoard.toggleTurn();
  testBoard.toggleTurn();
  testBoard.toggleTurn();
  EXPECT_EQ(testBoard.toggleTurn(), O);
}


TEST(TicTacToeBoardTest, checkStartingWinner)
{
  TicTacToeBoard testBoard;
  EXPECT_EQ(testBoard.getWinner(), Invalid);
}


TEST(TicTacToeBoardTest, checkPlacingWinner)
{
  TicTacToeBoard testBoard;
  ASSERT_EQ(testBoard.getWinner(), testBoard.placePiece(1,1));
}

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
