#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool is_logged_in()
{
  string username, password, un, pw;

  cout << "Enter username: ";
  cin >> username;

  cout << "Enter password: ";
  cin >> password;

  ifstream read(username + ".txt");
  getline(read, un);
  getline(read, pw);

  if (un == username && pw == password)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int user_choice;

  cout << "1: Register\n2: Login\nYour Choice: ";
  cin >> user_choice;

  if (user_choice == 1)
  {
    string username, password;
    cout << "select a username: ";
    cin >> username;
    cout << "select a password: ";
    cin >> password;

    ofstream file;
    file.open(username + ".txt");
    file << username << endl;
    file << password;
    file.close();

    main();
  }
  else if (user_choice == 2)
  {
    bool status = is_logged_in();

    if (!status)
    {
      cout << "False Login!" << endl;
      system("PAUSE");
      return 0;
    }
    else
    {
      cout << "Successfully logged in!" << endl;
      system("PAUSE");
      return 1;
    }
  }
}
