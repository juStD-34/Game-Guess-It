#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomNumber(int min=1,int max=100);
int getPlayerGuess();
void printAnswer(int guess, int secretNumber,int score );
void playGuessIt();
void gameLoop();

int main()
{
    std::string yourAnswer;
    std::cout<<"Do you want to play?   (yes/no)";
    std::cin>>yourAnswer;
    if (yourAnswer=="yes") playGuessIt();
}

void playGuessIt()
{
    int secretNumber=generateRandomNumber();
    int guess;
    int numGuess=0;
    int score=100;
    while (guess!=secretNumber)
    {
        guess=getPlayerGuess();
        printAnswer(guess,secretNumber,score);
        score=score-1;
        numGuess++;

    }
}

int generateRandomNumber(int min,int max)
{
    srand(time(NULL));
    return rand() %(max-min+1)+min;
}

int getPlayerGuess()
{
    int guess;
    std::cout<<"Enter your guess: (in range 1--100)";
    std::cin>>guess;
    return guess;
}

void printAnswer(int guess,int secretNumber,int score)
{
    if (guess==secretNumber)
    {
        std::cout<<"Congraduation!"<<std::endl;
        std::cout<<" Your score is: "<<score<<std::endl;
        std::cout<<std::endl;
        gameLoop();
    }
    else
    if (guess<secretNumber)
    {
        std::cout<<"Your number is too small "<<std::endl;
        std::cout<<"Your score is: "<<score-1<<std::endl;
    }
    else
    {
        std::cout<<"Your number is too big "<<std::endl;
        std::cout<<"Your score is: "<<score-1<<std::endl;
    }
}

void gameLoop()
{
    std::string yourAnswer;
    std::cout<<"Do you want to play again?   (yes/no)";
    std::cin>>yourAnswer;
    if (yourAnswer=="yes") playGuessIt();
}

