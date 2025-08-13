#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    int target = n + 1;
    
    vector<bool> my_cards(n + 1, false);
    vector<bool> pending_cards(n + 1, false);

    for (int i = 0; i < n / 3; i++) {
        my_cards[cards[i]] = true;
    }

    int round = 1;
    int card_idx = n / 3;

    while (card_idx < n) {

        int c1 = cards[card_idx];
        int c2 = cards[card_idx + 1];
        pending_cards[c1] = true;
        pending_cards[c2] = true;

        bool passed_round = false;


        for (int i = 1; i <= target / 2; i++) {
            if (my_cards[i] && my_cards[target - i]) {
                my_cards[i] = false;       
                my_cards[target - i] = false;
                passed_round = true;
                break; 
            }
        }

        
        if (!passed_round && coin >= 1) {
            for (int i = 1; i <= n; i++) {
                if (my_cards[i] && pending_cards[target - i]) {
                    coin--;
                    my_cards[i] = false;
                    pending_cards[target - i] = false;
                    passed_round = true;
                    break;
                }
            }
        }

        if (!passed_round && coin >= 2) {
            for (int i = 1; i <= target / 2; i++) {
                if (pending_cards[i] && pending_cards[target - i]) {
                    coin -= 2;
                    pending_cards[i] = false;
                    pending_cards[target - i] = false;
                    passed_round = true;
                    break;
                }
            }
        }

        if (passed_round) {
            round++;
            card_idx += 2;
        } else {

            break;
        }
    }

    return round;
}