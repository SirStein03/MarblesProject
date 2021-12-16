#include <iostream>
#include <string>
#include <vector>
using namespace std;

string anyKey; //string instead of char so accidental multiple chars don't break the program

void DiffModifier(int diffChoice, int& marbleCountPlayer, int&      marbleCountCPU){
    if(diffChoice == 1 || diffChoice == 1){ //difficult
      marbleCountPlayer = 10;
      marbleCountCPU = 20;
      }
    else if(diffChoice == 2 || diffChoice == 2){ //easy
      marbleCountPlayer = 20;
      marbleCountCPU = 10;
      }
    else if(diffChoice == 3 || diffChoice == 3){ //medium
      marbleCountPlayer = 20;
      marbleCountCPU = 20;
    }

      }
void DifficultyLoader(int marbleCountPlayer, int marbleCountCPU, vector<int>& CPUMarbles, vector<int>& playerMarbles ){
  for (int i=0; i < marbleCountCPU; ++i){
  CPUMarbles.push_back(0);
    }
  for (int i=0; i < marbleCountPlayer; ++i){
  playerMarbles.push_back(0);
    }
  cout << ">> Marbles Loaded" << endl << endl;
  }
void PlayerTurn(vector <int> &CPUMarbles, vector <int> &playerMarbles){
  int playerChoice;
  int CPUChoice;
  int playerEvenOrOdd;
  srand((unsigned)time(0));
  if (playerMarbles.size() > CPUMarbles.size()){ 
     CPUChoice = (rand() % CPUMarbles.size());
  }
  else if (playerMarbles.size() <= CPUMarbles.size()){
     CPUChoice = (rand() % playerMarbles.size());
  }
  
  int CPUEvenOrOdd = CPUChoice % 2;
  do{ 
    cout << "It is your turn to guess if Gganbu has chosen an even or odd number of marbles to wager." << endl << "\n --- 0 for even --- \n --- 1 for odd ---\n" << "Enter selection: ";
    cin >> playerChoice;
    cout << "\n...You guessed...";
    if (playerChoice == 0){
      cout << "Even. \n";
      cout << "Enter any letter to continue: ";
        cin >> anyKey;
        cout << endl << "****************************************************************" << endl << endl;
    }
    else {
      cout << "Odd. \n";
      cout << "Enter any letter to continue: ";
        cin >> anyKey;
        cout << endl << "****************************************************************" << endl << endl;
    }
    if(playerChoice == 0 || playerChoice == 1 ){
      break;
    }
    } 
    while(playerChoice != 1 || playerChoice != 0);
    cout << ">> Your opponent reveals " << CPUChoice << " marble(s)"<< endl << endl;
    playerEvenOrOdd = playerChoice % 2;
      if (playerEvenOrOdd == CPUEvenOrOdd){
        for(int i = 0; i < CPUChoice; ++ i){
          playerMarbles.push_back(0);
          CPUMarbles.pop_back();
        }
        cout << "Congratulations, you were correct!!" << endl;
        cout << "Your opponent hands over: " << CPUChoice << " Marble(s)" << endl << endl;
      }
      else if (playerEvenOrOdd != CPUEvenOrOdd){
        for(int i = 0; i < CPUChoice; ++ i){
          playerMarbles.pop_back();
          CPUMarbles.push_back(0);
        }
        cout << "Sorry, you were incorrect!!" << endl << endl;
        cout << "You hand over: " << CPUChoice << " Marbles." << endl;
      }
}
void CPUTurn(vector <int> &CPUMarbles, vector <int> &playerMarbles){
  string EvenOrOdd;
  int playerChoice;
  int playerEvenOrOdd;
  srand((unsigned)time(0));
  int CPUChoice = (rand() % playerMarbles.size());
  int CPUEvenOrOdd = CPUChoice % 2;
  if (CPUEvenOrOdd == 1){ 
    EvenOrOdd = "odd";
  }
  else if (CPUEvenOrOdd == 0){
    EvenOrOdd = "even";
  }
  do{ 
    cout << "It is your opponents turn to guess," << endl;
    cout << "Please enter how many marbles you would like to wager: ";
    cin >> playerChoice;
    cout << endl;
     if(playerChoice > playerMarbles.size()){//prevents floating point error from out of bounds array call
     while (playerChoice > playerMarbles.size()){
      cout << "Cannot wager amount larger than  or equal to your opponents hand!" << endl;
      cout << "Please enter how many marbles you would like to wager: ";
      cin >> playerChoice;
      cout << endl;
      }
    }
    if(playerChoice > CPUMarbles.size()){//prevents floating point error from out of bounds array call
     while (playerChoice < CPUMarbles.size()){
      cout << "Cannot wager amount larger than or equal to your own hand!" << endl;
      cout << "Please enter how many marbles you would like to wager: ";
      cin >> playerChoice;
      cout << endl;
      }
    }   
    if(playerChoice < playerMarbles.size() || playerChoice < CPUMarbles.size()){
    break;
    } 
    } 
    while(playerChoice != playerMarbles.size());
    cout << ">> Your opponent guesses " << EvenOrOdd << endl;
    playerEvenOrOdd = playerChoice % 2;
      if (playerEvenOrOdd != CPUEvenOrOdd){ // if guess is wrong
        for(int i = 0; i < playerChoice; ++ i){
          playerMarbles.push_back(0);
          CPUMarbles.pop_back();
        }
        cout << "Your opponent guessed wrong!" << endl;
        cout << "Enter any letter to continue: ";
        cin >> anyKey;
        cout << endl << "******************************************************************" << endl;
        cout << "Your opponent hands over: " << playerChoice << " marble(s)" << endl << endl;
      }
      else if (playerEvenOrOdd == CPUEvenOrOdd){ // if guess is right
        for(int i = 0; i < playerChoice; ++ i){
          playerMarbles.pop_back();
          CPUMarbles.push_back(0);
        }
        cout << "Your opponent guessed correctly!" << endl;
        cout << "Enter any letter to continue: ";
        cin >> anyKey;
        cout << endl << "******************************************************************" << endl << endl;
        cout << "You hand over: " << playerChoice << " Marble(s)" << endl << endl;
      }
}

int main (){

vector<int> CPUMarbles;
vector<int> playerMarbles;
int marbleCountPlayer;
int marbleCountCPU;
int diffChoicePlayer;
int diffChoiceCPU;
int diffChoice;
string yesOrNo; // string to prevent user errors

//intro text
cout << endl << endl <<
"********** Welcome to Gganbu's epic marble showdown! **********" << endl << endl <<
"Your best friend, Gganbu, has challenged you to a game of marbles. The winner gets $40,000,000 USD!!!!" << endl << endl << 
"What's that? What happens if you lose? Oh don't worry about that, it's just a friendly game of marbles..." << endl << endl;
cout << "Do you accept the challenge...?" << endl <<
"To continue, type 'y' or 'n', then press enter: ";
  cin >> yesOrNo;
  cout << endl << "****************************************************************" << endl << endl << endl;

  if(yesOrNo == "y" || yesOrNo == "Y"){
    cout << ">> Fantastic!" << endl << endl;
  }
  else{
    cout << "G A M E * O V E R"; 
    exit(0);  //exits program
  }

//menu
cout << "Now, tell us, are you a...?" << endl << endl <<
"1) Marble Master" << endl << 
"2) Marble Disaster" << endl <<
"       Or" << endl <<
"3) I don't know, let's find out." << endl << endl <<
"To make a selection, type 1, 2 or 3 on your keyboard, then press enter: ";

cin >> diffChoice; 
cout << endl;

if(diffChoice == 1 ){ //difficult
      cout << ">> Aha! You think you can best Gganbu?!" << endl << endl << "To view the rules, type any letter, then press enter:";
       cin >> anyKey;
       cout << endl << endl;
      }
    else if(diffChoice == 2 ){  //easy
      cout << ">> I can see you're shaking in your boots already!" << endl << "To view the rules, type any key, then press enter:";
       cin >> anyKey;
       cout << endl << endl;
      }
    else if(diffChoice == 3){ //medium
      cout << ">> This will be a true test of your skills." << endl << "To view the rules, type any key, then press enter:";
        cin >> anyKey;
        cout << endl << endl;
    }

cout <<
"**************************** RULES ******************************" << endl << endl <<
"1)Take turns choosing how many marbles you want to wager against your oppononent." << endl <<
"3)You cannot wager more marbles than you or your opponent have in their hand." << endl <<
"4)You cannot wager the full amount of marbles in you or your opponents hand in one turn." << endl <<
"5)Each player has to guess whether their opponent has chosen an even or odd amount of marbles to wager." << endl <<
"6)If your opponent guesses correctly, you have to give him as many marbles as you chose to wager! If he guesses wrong, he has to give you the same amount of marbles." << endl <<
"7)Whoever collects all of their opponents marbles first, wins!" << endl << endl <<
"To begin, type any key, then press enter:";
cin >> anyKey;
cout << endl << "******************************************************************";
cout << endl << endl;

//marble loader
DiffModifier(diffChoice, marbleCountPlayer, marbleCountCPU);
DifficultyLoader( marbleCountPlayer, marbleCountCPU, CPUMarbles, playerMarbles);
cout << "Your opponent is given: " << CPUMarbles.size()  << " Marbles "<< endl;
cout << "You are given: " << playerMarbles.size() << " Marbles" << endl << endl;
while(CPUMarbles.size() > 0 || playerMarbles.size() > 0){
  PlayerTurn(CPUMarbles, playerMarbles);
  cout << "You now have " << playerMarbles.size() << " marble(s)"<< endl << "They now have " <<   CPUMarbles.size() << endl;
  CPUTurn(CPUMarbles, playerMarbles);
  cout << "You now have " << playerMarbles.size() << " marble(s)"<< endl << "They now have " <<   CPUMarbles.size() << endl;
  if (playerMarbles.size()<= 0){
    cout << "Your have been eliminated!!" << endl;
    continue;
  }if (CPUMarbles.size()<= 0){
    cout << "Your opponent has been eliminated!!" << endl;
    continue;
  }
  continue;
}




return 0;
}