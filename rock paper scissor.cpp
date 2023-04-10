#include<bits/stdc++.h>
using namespace std;

enum enPlayingChoices {STONE = 1, PAPER = 2, SCISSOR = 3};
enum enBattleResult {WIN = 1, LOSS = 2, DRAW = 3};

struct stGameInfo{
    int wins;
    int losses;
    int draw;
};

struct stRoundInfo
{
    short numberOfRounds = 0;
    int playerChoice;
    int computerChoice;
    enBattleResult winner;
    string winnerName;
};

int randomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int readNumberOFBattles()
{
    int numBattles;
    do
    {
        cout << "Enter number of battles from 1 to 10 : ";
        cin >> numBattles;
    }while(numBattles < 1 || numBattles > 10);

    return numBattles;
}

int readPlayerChoice()
{
    int playerChoice;
        do
    {
        cout << "[1]: STONE, [2]: PAPER, [3]: SCISSOR ? ";
        cin >> playerChoice;
    }while(playerChoice < 1 || playerChoice > 3);

    return playerChoice;
}

int readComputerChoice()
{
    return randomNumber(1, 3);
}

enBattleResult playBattle(stRoundInfo info)
{

    if(info.playerChoice == info.computerChoice)
        return enBattleResult::DRAW;
    switch(info.playerChoice)
    {
    case enPlayingChoices::PAPER:
    {
        if(info.computerChoice == enPlayingChoices::STONE)
            return enBattleResult::WIN;
    }
    case enPlayingChoices::SCISSOR:
        {
            if(info.computerChoice == enPlayingChoices::PAPER)
                return enBattleResult::WIN;
        }
    case enPlayingChoices::STONE:
        {
            if(info.computerChoice == enPlayingChoices::SCISSOR)
                return enBattleResult::WIN;
        }
    }
    //if you reach here it's mean you lose
    return enBattleResult::LOSS;
}

string choiceToString(int choice)
{
    vector<string> v = {"stone", "paper", "scissor"};
    return v[choice - 1];
}

string resultToString(int result)
{
    vector<string> v = {"WIN", "LOSS", "DRAW"};
    return v[result - 1];
}

void showBattleResults(stRoundInfo roundInfo, enBattleResult result)
{

    cout << "Player choice : " << choiceToString(roundInfo.playerChoice) << '\n';
    cout << "Computer choice : " << choiceToString(roundInfo.computerChoice) << '\n';
    cout << resultToString(result) << '\n';
}
void lossScreen()
{
    system("color 4F");
}

void winScreen()
{
    system("color 2F");
}
void drawScreen()
{
    system("color 6F");
}

stGameInfo startGame()
{
    stRoundInfo roundInfo;
    stGameInfo gameInfo;

    roundInfo.numberOfRounds = readNumberOFBattles();
    for(int i = 1; i <= roundInfo.numberOfRounds; i++)
    {
        cout << "\n\n_____________________Round[" << i << "]____________________________\n\n";
        roundInfo.playerChoice = readPlayerChoice();
        roundInfo.computerChoice = readComputerChoice();
        enBattleResult result = playBattle(roundInfo);
        showBattleResults(roundInfo, result);
        if(result == enBattleResult::WIN)
            {gameInfo.wins++;
            winScreen();}
        else if(result == enBattleResult::LOSS)
            {gameInfo.losses++;
            lossScreen();}
        else
            {gameInfo.draw++;
            drawScreen();}
    }

    return gameInfo;

}

void showGameResults(stGameInfo info)
{
    cout << "WINS : " << info.wins << '\n';
    cout << "LOSSES : " << info.losses << '\n';
    cout << "DRAWS : " << info.draw << '\n';
}
void showGameOver()
{
    cout << "\n\t\t_________________________________________Game Over___________________________________\n\n";
    cout << "\t\t\t\t\t\t G a m e O v e r\n\n";
    cout << "\n\t\t_________________________________________Game Over___________________________________\n\n";
}

void clearScreen()
{
    system("cls");
    system("color 0F");
}


void playGame()
{

    char choice = 'y';
    do
    {
        clearScreen();
        stGameInfo info = startGame();
        showGameResults(info);
        showGameOver();
        cout << "Do you want to play again ? y or n ? ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');
}

int main()
{
    srand((unsigned) time(NULL));
    playGame();
    return 0;
}
