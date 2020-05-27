#include <string>
#ifndef PLAYER_HH
#define PLAYER_HH
using namespace std;


class Player
{
public:
    Player(string name, int score = 0);
    string get_name();
    int get_points();
    void add_points(int pts);
    bool has_won();
private:
    std::string name;
    int score;

};

#endif // PLAYER_HH
