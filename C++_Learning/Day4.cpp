#include <iostream>
using namespace std;

int getName()
{
  string fName;

  cout << "Enter First Name: ";

  getline(cin, fName);

  if (!fName.empty())
  {
    cout << "Your Name is " << fName;
    return 1;
  }

  cout << "Name Cannot be Empty" << endl;

  return 0;
}

int main()
{
  getName();
  return 0;
}