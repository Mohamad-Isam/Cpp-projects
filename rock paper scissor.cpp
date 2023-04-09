#include<bits/stdc++.h>
using namespace std;

int randomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void gameResult(int wins, int draws, int losses)
{
        cout << "\t\t\t___________________________________________________\n\n";
        cout << "\t\t\t\t\t +++ G a m e  O v e r +++\n\n";
        cout << "\t\t\t____________________________________________________\n\n";
        cout << "\t\t\t_______________[Game Results]_______________________\n\n";
        cout << "\t\t\tGame Rounds\t\t: " << wins + draws + losses << '\n';
        cout << "\t\t\tPlayer won times\t: " << wins << '\n';
        cout << "\t\t\tComputer won times\t: " << losses << '\n';
        cout << "\t\t\tDraw times\t\t: " << draws << '\n';
        cout << "\t\t\tFinal Winner\t\t: " << (wins > losses ? "Player\n" : wins == losses ? "No winner\n" : "Computer\n") << '\n';
        cout << "\t\t\t______________________________________________\n\n";
}
int readHowManyRounds()
{
    int n;
    cout << "How many rounds do you want to play : ";
    cin >> n;

    return n;
}

void showRoundResult(int i, int playerChoice, int computerChoice, string winner)
{
    vector<string> v = {"Stone", "Paper", "Scissors"};
    cout << "____________Round [" << i++ << "]_____________\n\n";
    cout << "Player Choice : " << v[playerChoice - 1];
    cout << "\nComputer Choice : " << v[computerChoice - 1];
    cout << "\nRound winner : " << winner << "\n";
    cout << "____________________________________________\n\n\n";
}

int readPlayerChoice()
{
    int playerChoice;
    cout << "Your choice : [1]:Stone, [2]:Paper, [3]:Scissors ? ";
    cin >> playerChoice;
    
    return playerChoice;
}
void startGame()
{

    char choice;
    int playerChoice, computerChoice;

    do
    {
        system("cls");
        system("color 0F");

        int i = 1, draws = 0, losses = 0, wins = 0;

        int n = readHowManyRounds();
        int x = n;
        while(x--)
        {
            cout << "\nRound [" << i << "] begins:\n\n";
            playerChoice = readPlayerChoice();
            string winner;
            computerChoice = randomNumber(1, 3);
            if(playerChoice == computerChoice)
            {
                winner = "[No Winner]";
                draws++;
                system("color 8F");
            }
            else if((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2))
            {
                winner = "[Player]";
                wins++;
                system("color 2F");
            }
            else
            {
                winner = "[Computer]";
                losses++;
                system("color 4F");
            }
            showRoundResult(i++, playerChoice, computerChoice, winner);

        }
        gameResult(wins, draws, losses);

        cout << "Do you want to play again ? Y/N?";
        cin >> choice;

    }while(choice == 'y' || choice == 'Y');
}


int main()
{
    srand((unsigned) time(NULL));
    startGame();
    return 0;
}
