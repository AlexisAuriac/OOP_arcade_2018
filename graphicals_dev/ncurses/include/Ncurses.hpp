/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines a graphical library for ncurses.
*/

#ifndef NCURES_HPP
#define NCURSES_HPP

#include <string>
#include <unordered_map>
#include <ncurses.h>
#include "IGraphicLib.hpp"

namespace arc::gl {
    class Ncurses : public IGraphicLib {
    private:
        const int CONNECT_COLORS[NB_COLORS] = {
            [BLACK] = COLOR_BLACK,
            [BLUE] = COLOR_BLUE,
            [GREEN] = COLOR_GREEN,
            [CYAN] = COLOR_CYAN,
            [RED] = COLOR_RED,
            [MAGENTA] = COLOR_MAGENTA,
            [WHITE] = COLOR_WHITE + 8,
            [GRAY] = COLOR_WHITE,
            [YELLOW] = COLOR_YELLOW,
        };

        const std::unordered_map<int, arc::gl::event_t> CONNECT_EVENTS = {
            {'A', A},
            {'B', B},
            {'C', C},
            {'D', D},
            {'E', E},
            {'F', F},
            {'G', G},
            {'H', H},
            {'I', I},
            {'J', J},
            {'K', K},
            {'L', L},
            {'M', M},
            {'N', N},
            {'O', O},
            {'P', P},
            {'Q', Q},
            {'R', R},
            {'S', S},
            {'T', T},
            {'U', U},
            {'V', V},
            {'W', W},
            {'X', X},
            {'Y', Y},
            {'Z', Z},
            {'a', A},
            {'b', B},
            {'c', C},
            {'d', D},
            {'e', E},
            {'f', F},
            {'g', G},
            {'h', H},
            {'i', I},
            {'j', J},
            {'k', K},
            {'l', L},
            {'m', M},
            {'n', N},
            {'o', O},
            {'p', P},
            {'q', Q},
            {'r', R},
            {'s', S},
            {'t', T},
            {'u', U},
            {'v', V},
            {'w', W},
            {'x', X},
            {'y', Y},
            {'z', Z},
            {'0', Num0},
            {'1', Num1},
            {'2', Num2},
            {'3', Num3},
            {'4', Num4},
            {'5', Num5},
            {'6', Num6},
            {'7', Num7},
            {'8', Num8},
            {'9', Num9},
            {27, Escape},
            {'[', LBracket},
            {']', RBracket},
            {';', Semicolon},
            {',', Comma},
            {'.', Period},
            {'\'', Quote},
            {'/', Slash},
            {'\\', Backslash},
            {'~', Tilde},
            {'=', Equal},
            {'-', Hyphen},
            {' ', Space},
            {'\n', Enter},
            {KEY_BACKSPACE, Backspace},
            {'\t', Tab},
            {KEY_NPAGE, PageUp},
            {KEY_PPAGE, PageDown},
            {KEY_END, End},
            {KEY_HOME, Home},
            {KEY_IC, Insert},
            {KEY_DC, Delete},
            {'+', Add},
            {'-', Subtract},
            {'*', Multiply},
            {'/', Divide},
            {KEY_LEFT, Left},
            {KEY_RIGHT, Right},
            {KEY_UP, Up},
            {KEY_DOWN, Down},
            {KEY_F(1), F1},
            {KEY_F(2), F2},
            {KEY_F(3), F3},
            {KEY_F(4), F4},
            {KEY_F(5), F5},
            {KEY_F(6), F6},
            {KEY_F(7), F7},
            {KEY_F(8), F8},
            {KEY_F(9), F9},
            {KEY_F(10), F10},
            {KEY_F(11), F11},
            {KEY_F(12), F12},
            {KEY_F(13), F13},
            {KEY_F(14), F14},
            {KEY_F(15), F15}
        };

        public:
            void openWindow() override;
            void closeWindow() override;
            void display() override;
            void clear() override;
            int getCols() override;
            int getLines() override;
            void printText(
                const std::string &str,
                const textParams_t &params) override;
            event_t getEvent() override;
            void drawSquare(int x, int y, color_t color) override;
    };
}

#endif