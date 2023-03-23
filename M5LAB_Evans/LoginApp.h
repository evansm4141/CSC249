#ifndef LOGIN_APP_H
#define LOGIN_APP_H

#include <iostream>
#include <map>
using namespace std;
/*
LoginApp - contains all the actual program logic
(main still contains the basic UI)

This is a simple demo of separating UI from business logic
(Note we don't include iostream -- we can't use cin or cout here.)
*/

// User struct
struct User {
  string username;
  string password;
};

// LoginApp object, used to store:
// - all necessary data
// - all functions needed
class LoginApp {
  public:
    LoginApp();
    ~LoginApp();
    void menu();      // entry point to app

    // member functions
    User login(string name, string password);
    User register_account(string name, string password);    // register is a reserved word in c++
    User change_password(User acct, string new_password);
    // unimplemented
    // void save_data();
    // void load_data();

  private:
    // member variables
    map <string, User> user_map;

};

LoginApp::LoginApp() {
    //start with demo user

}

LoginApp::~LoginApp() {

}

User LoginAPP::login(string name, string password) {
    //input: name, password
    //output: User object (empty if login failed)
    User dummy = User();
    //test code
    if (name == "admin" && password == "password") {
        User good_user = User();
        good_user.username = "admin";
        good_user.password = "password";
        return good_user;
    }
    else {
        return dummy;
    }
}
#endif // LOGIN_APP_H
