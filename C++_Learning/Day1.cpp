#include <iostream>
using namespace std;

namespace first
{
  int x = 1;
}

namespace second
{
  int x = 2;
}

// typedef string str;

using str = string;

str firstName = "Birat";

int main()
{
  using namespace first;
  std::cout << x << std::endl;

  cout << "Name " << firstName << endl;

  // Explicit Type Conversion

  int correct = 8;
  int questions = 10;
  double score = correct / questions * 100;

  cout << "% = " << score << endl;
}