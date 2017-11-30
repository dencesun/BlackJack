//
//  testCase.cpp
//  Blackjack
//
//  Created by dencesun on 30/11/2017.
//  Copyright © 2017 Sun. All rights reserved.
//

#include "testCase.hpp"
#include "blackjack.hpp"

void testBlackJack() {
    cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7) {
        cout << "How many players? (1-7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N') {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }
}
