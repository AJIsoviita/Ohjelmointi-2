#include "player.hh"
#include <iostream>
#include <string>
using namespace std;

Player::Player(string name, int score):
    name(name), score(score)
{
}

string Player::get_name(){
    return name;
}
int Player::get_points(){
    return score;
}
bool Player::has_won()
{
    if(score==50)
        return true;
    else
        return false;
}
void Player::add_points(int pts)
{
    score += pts;
    if (score > 50)
    {
        score = 25;
        cout << get_name() << "gets penalty points!" << endl;
    }
}
