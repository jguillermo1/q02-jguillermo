#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    
    turn = X;
/*
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            
        }
    }
  */  
    board.resize(BOARD_ROWS,std::vector<Piece>(BOARD_COLS,Blank));
  
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(int i = 0; i < BOARD_COLS; i++){
        for(int j = 0; j < BOARD_ROWS;i++){
                board[i][j] = Blank;
        }
    }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    if(column < 0 || column > BOARD_COLS  ){
        if(turn == X){
            turn = O;
        }
        else{turn = X;}
        return Invalid;
    }
    for(int i = 0; i < BOARD_ROWS  ; i++){
        if(board[i][column] == Blank){
            board[i][column] = turn;
                if(turn == X){
                turn = O;
                return X;
                }
                else{turn = X;} 
                return O;
            }
        }
    if(turn == X){
        turn = O;
    }
    else{turn = X;}
    return Blank;
}


/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row < 0 || row > 2   || column < 0 || column > 3) return Invalid;
    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int ocount = 0, xcount = 0, omax = 0, xmax = 0;
    Piece prev, cur;
    for(int i = 0; i < BOARD_COLS ;i++){
        xcount = 0;
        ocount = 0;
        for(int j = 0; j < BOARD_ROWS ; j++){
            cur = board[i][j];
            if(cur==Blank) return Invalid;
            if(!prev) prev = cur;
            else if(cur == X){
                if(cur == prev) xcount++;
                if(xcount > xmax) xmax = xcount;
            } 
            else if(cur == O){
                if(cur == prev) ocount++;
                if(ocount > omax) omax = ocount;
            }
            prev = cur;
        }      
    }
    
    Piece prev2,cur2;
    for(int i = 0; i < BOARD_ROWS;i++){
        xcount = 0;
        ocount = 0;
        for(int j = 0; j < BOARD_COLS; i++){
            cur2 = board[i][j];
            if(cur==Blank) return Invalid;
            if(!prev2) prev2 = cur2;
            else if(cur2 == X){
                if(cur2 == prev2) xcount++;
                if(xcount > xmax) xmax = xcount;
            } 
            else if(cur2 == O){
                if(cur2 == prev) ocount++;
                if(ocount > omax) omax = ocount;
            }
            prev2 = cur2;
        }      
    }
    if(xmax > omax) return X;
    else if( xmax < omax) return O;
    else{
        return Blank;
    }
}


