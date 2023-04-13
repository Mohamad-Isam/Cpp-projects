#include<bits/stdc++.h>
using namespace std;

enum enMathOperation {ADD = 1, SUB = 2, MUL = 3, DIV = 4, MIX = 5};
enum enDifficultyLevel {EASY = 1, MEDIUM = 2, HARD = 3, MIX = 4};

struct stPlayerChoices{
int level;
int mathOp;
int numberOfQuestions;

};

struct stQuestionElements{
int number1;
int number2;

char op;
};

stPlayerChoices readPlayingChoices()
{
    stPlayerChoices choices;
    cout << "Enter number of questions you want to answer : ";
    cin >> choices.numberOfQuestions;
    cout << "Enter questions level : [1] easy, [2] medium, [3] hard, [4] mix ?  ";
    cin >> choices.level;
    cout << "Enter operation type : [1] add, [2] sub, [3] mul, [4] div, [5] mix ? ";
    cin >> choices.mathOp;
    
    return choices;
}
int randomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

stQuestionElements generateQuestions(stPlayerChoices choices)
{
    stQuestionElements question;
    //generate the first number & second number in case of easy, medium, hard, mix
    if(choices.level == enDifficultyLevel::EASY)
    {
        question.number1 = randomNumber(1, 10);
        question.number2 = randomNumber(1, 10);
    }
    else if(choices.level == enDifficultyLevel::MEDIUM)
    {
        question.number1 = randomNumber(10, 100);
        question.number2 = randomNumber(10, 100);
    }
    else if(choices.level == enDifficultyLevel::HARD)
    {
        question.number1 = randomNumber(100, 10000);
        question.number2 = randomNumber(100, 10000);
    }
    else if(choices.level == enDifficultyLevel::MIX)
    {
        question.number1 = randomNumber(1, 10000);
        question.number2 = randomNumber(1, 10000);
    }
    //generate the operation based on the mathOp choice(add, sub, mul, div, mix)
    vector<char> v = {'+', '-', '*', '/'};
    if(choices.mathOp == enMathOperation::ADD)
        question.op = '+';
    else if(choices.mathOp == enMathOperation::SUB)
        question.op = '-';
    else if(choices.mathOp == enMathOperation::MUL)
        question.op = '*';
    else if(choices.mathOp == enMathOperation::DIV)
        question.op = '/';
    else if(choices.mathOp == enMathOperation::MIX)
        question.op = v[randomNumber(0, 3)];
    
    return question;
    
}

int correctAnswerOfQuestion(stQuestionElements question)
{
    switch(question.op)
    {
    case '+':
        return question.number1 + question.number2;
    case '-':
        return question.number1 - question.number2;
    case '*':
        return question.number1 * question.number2;
    case '/':
        return question.number1 / question.number2;
    }
    //for unknown operation just return int_min by default:
    return INT_MIN;
}

void viewQuestion(stQuestionElements question)
{
    cout << '\n' << question.number1 << '\n';
    cout << question.number2 << '\t' << question.op << '\n';
    cout << "___________\n";
}

int readPlayerAnswer()
{
    int answer;
    cin >> answer;
}


string resultToString(int result)
{
    vector<string> v = {"WIN", "LOSS", "DRAW"};
    return v[result - 1];
}

void lossScreen()
{
    system("color 4F");
}

void winScreen()
{
    system("color 2F");
}

void clearScreen()
{
    system("cls");
    system("color 0F");
}

int main()
{
    srand((unsigned) time(NULL));
    playGame();
    return 0;
}
