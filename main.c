#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define K 10
#define Q 10
#define J 10

int player;
int dealer;

int Deck[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K};


int drawacard() {
    int number = Deck[rand() % 13];
    return number;
}

bool busted(int a) {
    if (a < 22)
        return true;
    else
        return false;
}


int start() {
    int firstone = drawacard();
    int secondone = drawacard();
    int thirdone = drawacard();
    int forthone = drawacard();


    printf("You drawed %d and %d\n", firstone, secondone);
    printf("Dealer has a %d and a closed card.\n", thirdone);

    player = (firstone + secondone);
    dealer = (thirdone + forthone);
}

int isitvalid() {
    int a;
    do {
        printf("1:Hit, 2:Stay\n");
        scanf("%d", &a);
        if(a==2){
            break;
        }
        if (a == 1) {
            int drawencard = drawacard();
            printf("You drawed %d.\n", drawencard);
            player += drawencard;
            printf("Your hand is %d.\n", player);
        } else
            return isitvalid();
    } while (busted(player) && a != 2);
    return 0;
}

int dealersHand() {
    if (dealer == 21)
        printf("The Dealer BlackJacked\n");
    else
        do {
            if (dealer < 17) {
                printf("The Dealers Hand is %d.\n", dealer);
                printf("Dealer draws another card.\n");
                int drawencard = drawacard();
                printf("The drawen card is %d.\n", drawencard);
                dealer += drawencard;
            } else {
                printf("The Dealers Hand is %d.\n", dealer);
                return 0;
            }
        } while (dealer < 22);

    if (dealer > 21)
        printf("Dealer has busted with %d.\n", dealer);
    else
        printf("Dealer's hand is %d.\n", dealer);
}

int body() {

    isitvalid();

    if(busted(player)==false)
        return 0;

    printf("The player's hand is %d\n", player);
    printf("The dealer's hand is %d\n", dealer);

    dealersHand();

}

void winner() {
    if (busted(player) == false || busted(dealer) == false) {
        if (busted(player) == false)
            printf("The winner is dealer.\n");
        else
            printf("The winner is Player.\n");
        return;
    } else {
        if (player <= dealer)
            printf("The winner is dealer.\n");
        else
            printf("The winner is Player.\n");
    }
}

void blackjack() {
    start();
    body();
    winner();
}

int main() {
    srand(time(NULL));
    blackjack();
    return 0;
}
