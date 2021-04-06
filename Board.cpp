#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <climits>
using ariel::Direction;
using namespace std;
using ariel::Board;

namespace ariel
{

    int Board::check_in_range(unsigned int row, unsigned int col, Direction direc, const unsigned int size)
    {
        /* this function checks if the word that will be inserted to the board will fit 
           in the unsigned int range
         depend on the length of the word and the position in the board
           return 1 if will not fit , if fit return 0 */ 
        int err = 0;
        if (direc == Direction::Horizontal)
        {
            if (UINT_MAX- size <= col)
            {
                err = 1;
            }
        }
        else
        {
            if (UINT_MAX - size <= row)
            {
                err = 1;
            }
        }
        return err;
    }
    void Board::update_limits(unsigned int row, unsigned int col, Direction direc, const unsigned int size)
    {
          /* this function update the limits of the board
          this function help calculate the burders of the board for the show function*/ 
        if (row < left_lim)
        {
            left_lim = row;
        }
        if (col < up_lim)
        {
            up_lim = col;
        }
        if (direc == Direction::Horizontal)
        {
            if (col + size-1 > right_lim)
            {
                right_lim = col + size-1;
            }
            if(row > low_lim)
            {
                low_lim = row;
            }
        }
        else
        {
            if (row + size-1 > low_lim)
            {
                low_lim = row + size-1;
            }
            if(col > right_lim)
            {
                right_lim = col;
            }
        }
    }
    void Board::post_to_board(unsigned int row, unsigned int col, Direction direc, const string advertis)
    {
        /* this function insert a word to the board depends on the row, col and direc
        the function gets*/ 
        string key;
        unsigned int i = 0;
        if (direc == Direction::Horizontal)
        {
            for (i = 0; i < advertis.length(); i++)
            {
                key = to_string(row) + "," + to_string(col);
                board[key] = advertis[i];
                col++;
            }
        }
        else
        {
            for (i = 0; i < advertis.length(); i++)
            {
                key = to_string(row) + "," + to_string(col);
                board[key] = advertis[i];
                row++;
            }
        }
    }
    string Board::read_from_board(unsigned int row, unsigned int col, Direction direc, unsigned int adv_len)
    {
         /* this function return the sequence of chars by the position determined by the row , col
         and direc
         if the board contain a char in the position add the char to the string 
         else add "_" to the string returned*/ 
        string key;
        size_t i = 0;
        string adver;
        if (direc == Direction::Horizontal)
        {
            for (i = 0; i < adv_len; i++)
            {
                key = to_string(row) + "," + to_string(col);
                if (board.find(key) == board.end())
                {
                    adver += '_';
                }
                else
                {
                    adver += board[key];
                }
                col++;
            }
        }
        else
        {
            for (i = 0; i < adv_len; i++)
            {
                key = to_string(row) + "," + to_string(col);
                if (board.find(key) == board.end())
                {
                    adver += '_';
                }
                else
                {
                        adver+=board[key];
                }
                row++;
            }
        }
        return adver;
    }

    Board::Board()
    {
        left_lim = UINT_MAX;
        right_lim = 0;
        up_lim = UINT_MAX;
        low_lim = 0;
    }

    void Board::post(unsigned int row, unsigned int col, Direction direc, const string advertis)
    {
        /* this function insert a word to the board depends on the row, col and direc
        the function gets
        first the function determine if the word will not get out of the board range
        after update the limits for the show functions*/ 

        if (check_in_range(row, col, direc, advertis.length()) == 1)
        {
            throw out_of_range(ariel::USI_ERROR);
        }
        update_limits(row, col, direc, advertis.length());
        post_to_board(row, col, direc, advertis);
    }

    string Board::read(unsigned int row, unsigned int col, Direction direc, unsigned int adv_len)
    {   
         /* this function read a word from board depends on the row, col  direc
        and size of word to read,the function gets
        first the function determine if the size will not get out of the board range
        by the position
        then return the string that got from the position*/ 
        if (check_in_range(row, col, direc, adv_len) == 1)
        {
            throw out_of_range(ariel::USI_ERROR);
        }
        return (read_from_board(row, col, direc, adv_len));
    }

    void Board::show()
    {
       /* this function print to the screen the board ny the board limits
       the function will only print the part of the board that contain advertise in it */ 
        string key;
        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int row_lim = ariel::FIVE;
        unsigned int col_lim = ariel::FIVE;
        if (left_lim != UINT_MAX)
        {
            i = up_lim;
            j = left_lim;
            row_lim = low_lim;
            col_lim = right_lim;
        }
        for (; i <= row_lim; i++)
        {
            for (unsigned int k = j; k <= col_lim; k++)
            {
                key = to_string(i) + "," + to_string(k);
                if (board.find(key) == board.end())
                    {cout << '_';}
                else
                    {cout << board[key];}
            }
            cout << "\n";
        }
        cout <<" "<< endl;
    }

}
