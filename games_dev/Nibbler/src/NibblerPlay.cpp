/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Defines the Nibbler's class methods relative to interactions.
*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "Nibbler.hpp"

void arc::game::Nibbler::posFruit(int flag)
{
    int x = _tail.back().first;
    int y = _tail.back().second;

    if (_tail.size() <= 3 && flag == 1) {
        _fruit.first = rand()%((_col - 4) - 4) + 4;
        _fruit.second = rand()%((_row - 4) - 4) + 4;
        return;
    }
    else
        _tail.push_back(std::make_pair(x, y));
    _fruit.first = rand() % ((_col - 4) - 4) + 4;
    _fruit.second = rand() % ((_row - 4) - 4) + 4;
    if (_tail.size() < _tabScore.size())
        _index += 1;
    else {
        _tabScore[_index].first -= 75;
        _tabScore[_index].second += 500;
    }
}

void arc::game::Nibbler::manageHit()
{
    if ((_tail[0].first < 4 || _tail[0].first > (_col - 5))
        || _tail[0].second < 4 || _tail[0].second > (_row - 5)) {
        _run = 0;
    }
    for (unsigned int i = 1 ; i < _tail.size() ; ++i) {
        if (_tail[i].first == _tail[0].first
            && _tail[i].second == _tail[0].second) {
            _run = 0;
            return;
        }
    }
    if (_tail[0].first == _fruit.first
        && _tail[0].second == _fruit.second)
        posFruit(2);
}

void arc::game::Nibbler::moveSnake()
{
    std::pair<int, int> save(_tail[0].first, _tail[0].second);
    std::pair<int, int> tmp(0, 0);

    _tail[0].first += _movx;
    _tail[0].second += _movy;
    for (unsigned int i = 1 ; i < _tail.size() ; ++i) {
        tmp = _tail[i];
        _tail[i] = save;
        save = tmp;
        manageHit();
        usleep(_tabScore[_index].first);
    }
}

void arc::game::Nibbler::dirSnake(gl::event_t event)
{
    if (_movy == -1 || _movy == 1) {
        if (event == gl::Right)
            _movx = _movy * -1;
        else
            _movx = _movy * 1;
        _movy = 0;
    } else {
        if (event == gl::Right)
            _movy = _movx * 1;
        else
            _movy = _movx * -1;
        _movx = 0;
    }
}

void arc::game::Nibbler::manageEvent(gl::event_t event)
{
    if (event == gl::Right)
        dirSnake(event);
    else if (event == gl::Left)
        dirSnake(event);
}

std::pair<arc::game::state, int> arc::game::Nibbler::play(gl::event_t event)
{
    moveSnake();
    manageEvent(event);
    if (_run == 0)
        return std::make_pair(OVER, 0);
    return std::make_pair(PLAYING, 0);
}
