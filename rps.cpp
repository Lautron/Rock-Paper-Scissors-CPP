#include <stdlib.h>
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
// TODO Make bot AI
// TODO Ask for player input
// TODO game logic
using namespace std;
string playerMove() {
    unordered_set<string> validMoves = {"R", "P", "S", "E"};
    string move;
    cout << "Choose a move. (R)ock, (P)apers, (S)cissors or (E)xit\n";
    cin >> move;
    cout << endl;
    if (validMoves.find(move) == validMoves.end()) {
	return "invalid move";	
    }
    return move;
}
string botMove(){
    int move = rand() % 4;    
    unordered_map<int, string> moveMap = {
	{1, "R"}, {2, "P"}, {3, "S"}
    };
    return moveMap[move];
}

string game(string player, string bot){
    unordered_map<string,string> longName = {
	{"R", "Rock"},
	{"P", "Paper"},
	{"S", "Scissors"},
    };
    cout << longName[player] + " vs " + longName[bot] << endl;
    unordered_map<string, unordered_map<string, string> > results = {
	{"R", {
	    {"R", "Tie"}, {"P", "Lose"}, {"S", "Win"}
	  }},
	{"P", {
	    {"R", "Win"}, {"P", "Tie"}, {"S", "Lose"}
	  }},
	{"S", {
	    {"R", "Lose"}, {"P", "Win"}, {"S", "Tie"}
	  }},
    };
    return results[player][bot];
}
int main(){
    string player;
    while (true) {
	player = playerMove();
	if (player == "invalid move") continue;
	if (player == "E") break;
	string result = game(
		    player,
		    botMove()
		);
	cout << result << "\n\n";
    }
    return 0;
}
