#include <iostream>

using namespace std;

void checkStringMethods(string fn)
{
  if (fn.empty())
  {
    cout << "Please Enter Something" << endl;
  }

  cout << "Length : " << fn.length() << endl;
}

int main()
{
  string name;

  cout << "Enter Your Name : ";

  getline(cin, name);

  checkStringMethods(name);

  return 0;
}