#include <stdlib.h>
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <cstring>

using namespace std;
class RPS {
    private: 
	unordered_set<char> validMoves = {'R', 'P', 'S', 'E'};
	unordered_map<int, char> numToMove = {
	    {1, 'R'}, {2, 'P'}, {3, 'S'}
	};
	unordered_map<char,string> longName = {
	    {'R', "Rock"},
	    {'P', "Paper"},
	    {'S', "Scissors"},
	};
	unordered_map<char, unordered_map<char, string> > results = {
	    {'R', {
		{'R', "Tie"}, {'P', "Lose"}, {'S', "Win"}
	      }},
	    {'P', {
		{'R', "Win"}, {'P', "Tie"}, {'S', "Lose"}
	      }},
	    {'S', {
		{'R', "Lose"}, {'P', "Win"}, {'S', "Tie"}
	      }},
	};
	// methods
	char playerMove();
	char botMove();
    public:
	void play();
};
char RPS::playerMove() {
    char move;
    cout << "Choose a move. (R)ock, (P)apers, (S)cissors or (E)xit\n";
    cin >> move;
    move = toupper(move);
    cout << endl;
    if (validMoves.find(move) == validMoves.end()) {
	return 'I'; // Invalid move	
    }
    return move;
}
char RPS::botMove(){
    int move = rand() % 4;    
    return numToMove[move];
}

void RPS::play(){
    while (true) {
	char player = playerMove();
	char bot = botMove();
	if (player == 'I') continue; //Invalid move
	if (player == 'E') break;

	cout << longName[player] + " vs " + longName[bot] << endl;
	string result = results[player][bot];
	cout << result << "\n\n";
    }
}
int main(){
    RPS game;
    game.play();
    return 0;
}
