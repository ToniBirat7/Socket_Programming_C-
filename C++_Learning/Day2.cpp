#include <iostream>

using namespace std;

void typeCasting()
{
  // Explicit Type Conversion

  int correct = 8;
  int questions = 10;
  double score = correct / (double)questions * 100;

  cout << "% = " << score << endl;
}

void userInput()
{

  string name;

  cout << "Enter your Name : ";
  getline(cin, name);

  cout << "Your Name is : " << name << endl;
}

int main()
{
  userInput();

  return 0;
}
