#pragma once
#include "Direction.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

namespace ariel
{
    const unsigned int FIVE = 5;
    const std::string USI_ERROR =  "unsgined int range";
    class Board
    {
    public:
        Board();
        void post(unsigned int row, unsigned int col, ariel::Direction direc,const std::string advertis);
        std::string read(unsigned int row, unsigned int col, ariel::Direction direc, unsigned int adv_len);
        void show();

    private:
         std::unordered_map<std::string, char> board;
        unsigned int left_lim;
        unsigned int right_lim;
        unsigned int up_lim;
        unsigned int low_lim;
        void post_to_board(unsigned int row, unsigned int col, ariel::Direction direc, const std::string advertis);
        std::string read_from_board(unsigned int row, unsigned int col, ariel::Direction direc, unsigned int adv_len);
        void update_limits(unsigned int row, unsigned int col, ariel::Direction direc, const unsigned int size);
         int check_in_range(unsigned int row, unsigned int col, ariel::Direction direc, const unsigned int size);
    };

}
