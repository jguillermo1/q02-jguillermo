/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};
/*
TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/
TEST(PiezasTest, dropPiece1){
	Piezas board;
	ASSERT_EQ(board.dropPiece(0),X);
}
TEST(PiezasTest, dropPiece2){
	Piezas board;
	ASSERT_EQ(board.dropPiece(0),X);
	ASSERT_EQ(board.dropPiece(1),O);
}
TEST(PiezasTest, dropPiece3){
	Piezas board;
	ASSERT_EQ(board.dropPiece(6),Invalid);
}
TEST(PiezasTest, dropPiece4){
	Piezas board;
	ASSERT_EQ(board.dropPiece(0),X);
	ASSERT_EQ(board.dropPiece(0),O);
	ASSERT_EQ(board.dropPiece(0),X);
	ASSERT_EQ(board.dropPiece(0),Blank);
}
TEST(PiezasTest,dropPiece5){
	Piezas board;
	ASSERT_EQ(board.dropPiece(4),Invalid);
}
TEST(PiezasTest,pieceAt1){
	Piezas board;
	board.dropPiece(0);
	ASSERT_EQ(board.pieceAt(0,0),X);
}
TEST(PiezasTest,pieceAt2){
	Piezas board;
	ASSERT_EQ(board.pieceAt(0,5),Invalid);
}
TEST(PiezasTest,pieceAt3){
	Piezas board;
	board.dropPiece(1);
	board.dropPiece(1);
	ASSERT_EQ(board.pieceAt(1,1),O);
}

TEST(PiezasTest,winner1){
	Piezas board;
    board.dropPiece(0);    
    board.dropPiece(0);    
    board.dropPiece(1); 
    board.dropPiece(0); 
    board.dropPiece(2); 
    board.dropPiece(1); 
    board.dropPiece(3); 
    board.dropPiece(1); 
    board.dropPiece(2); 
    board.dropPiece(3); 
    board.dropPiece(2); 
    board.dropPiece(3); 
    ASSERT_EQ(board.gameState(), X);
}


TEST(PiezasTest, gameTie)
{
 Piezas board;

 board.dropPiece(0); 
 board.dropPiece(0); 
 board.dropPiece(0); 
 board.dropPiece(1); 
 board.dropPiece(1); 
 board.dropPiece(1);
 board.dropPiece(2); 
 board.dropPiece(3); 
 board.dropPiece(2);
 board.dropPiece(3); 
 board.dropPiece(3); 
 board.dropPiece(2); 
 EXPECT_EQ(board.gameState(),Blank);
}

