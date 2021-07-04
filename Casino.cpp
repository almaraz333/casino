#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawLine(int n, char symbol);
void rules();

class Person {
public:
    string name;
    int guess = -1;
    int balance = 0;
    int riskLevel = 0;
    int bettingAmount = 0;
    int chanceToWin = 0;
    void win();
    void lose();
};

void Person::win() {
      balance = balance = (bettingAmount * riskLevel);
}

void Person::lose() {
    balance = balance - bettingAmount;
}

void drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
        cout << symbol;
    cout << "\n";
}

void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80, '-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80, '-');
    cout << "\t1. Choose any number between 1 to 2,5,10, and 100 depending on risk level\n";
    cout << "\t2. If you win you will win the ammount that was bet times the risk level\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80, '-');
}

int main()
{
    int dice;
    char choice;

    Person player;

    srand(time(0)); // seed random generator

    drawLine(60, '_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60, '_');

    cout << "\n\nEnter Your Name : ";
    cin >> player.name;

    cout << "\n\nEnter Deposit amount to play game : $";
    cin >> player.balance;

    bool validChoice { false };

    string riskChoice;

    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << player.balance << "\n";

        // Get player's betting amount
        
        do
        {

            cout << player.name << ", enter money to bet : $";
            cin >> player.bettingAmount;
            if (player.bettingAmount > player.balance)
                cout << "Your betting amount is more than your current balance\n"
                << "\nRe-enter data\n ";
        } while (player.bettingAmount > player.balance);
        // Get player's numbers
        do
        {
            do {
                cout << "1 - 2x (50% chance to win)\n";
                cout << "2 - 5x (20% chance to win)\n";
                cout << "3 - 10x (10% chance to win)\n";
                cout << "4 - 100x (1% chance to win)\n";

                cout << "What level of risk would you like? ";

                cin >> riskChoice;

                int riskChoiceInt = stoi(riskChoice);

                switch (riskChoiceInt) {
                case 1:
                    player.riskLevel = 2;
                    player.chanceToWin = 2;
                    break;
                case 2:
                    player.riskLevel = 10;
                    player.chanceToWin = 5;
                    break;
                case 3:
                    player.riskLevel = 20;
                    player.chanceToWin = 10;
                    break;
                case 4:
                    player.riskLevel = 100;
                    player.chanceToWin = 100;
                    break;
                default:
                    cout << "\nWrong\n";
                    break;

                } 

                if (player.riskLevel != 0) {
                    validChoice = true;
                }

            } while (!validChoice);
                


            cout << "Guess your number to bet between 1 to " << player.chanceToWin << ": ";
            cin >> player.guess;
            if (player.guess <= 0 || player.guess > player.chanceToWin)
                cout << "Please check the number!! should be between 1 to " << player.chanceToWin << "\n"
                << "\nRe-enter data\n ";
        } while (player.guess <= 0 || player.guess > player.chanceToWin);

        dice = rand() % player.chanceToWin + 1;

        if (dice == player.guess)
        {
            cout << "\n\nYou won! " << player.bettingAmount * player.riskLevel;
            player.win();
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ " << player.bettingAmount << "\n";
            player.lose();
        }

        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n" << player.name << ", You have $ " << player.balance << "\n";
        if (player.balance == 0)
        {
            cout << "You have no money to play ha";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "\n\n\n";
    drawLine(70, '=');
    cout << "\n\nThanks for playing game. Your balance amount is $ " << player.balance << "\n\n";
    drawLine(70, '=');

    return 0;
}