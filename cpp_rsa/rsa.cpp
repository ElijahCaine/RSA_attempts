///////////////////////////////
// FileName: rsa.cpp
// Author: Elijah Voigt
// Description: A crude implementation of RSA in C++ for educational purposes only
// Date: 04.20.2014
///////////////////////////////
// Preample:
//      > This is another failed attempt at creating an implementation of RSA, 
//      this time in C++ instead of Lua (The Lua file is in the repo as well,
//      if you're interested). 
//      > As in Lua I came across the problem of generating numbers which went 
//      past what the langaugae could handle. I attempted to use some libraries
//      from the internet, but again, I didn't have the time or the patients to 
//      install them correctly.
//
// Thank's for reading,
// Enjoy,
// Elijah
///////////////////////////////

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){

    // Hardcoding variables.
    int p = 61;
    int q = 53; 
    int n = p*q;
    int t = (p-1)*(q-1);
    int e = 17;
    int d;

    // Generating a 'd' value for decryption
    for(int i = 2; true; i++){
        if (((e*i) % t) == (1 % t)){
            d = i;
            break;
        }
    }

    // Displaying variable to user
    cout << "p " << p << endl;
    cout << "q " << q << endl;
    cout << "n " << n << endl;
    cout << "t " << t << endl;
    cout << "e " << e << endl;
    cout << "d " << d << endl;

    // an array of characters for the user's input
    char msg[100];
    // An array of numbers to store ascii values
    // I wasn't sure what I was doing. Don't judge me.
    int num_msg[100];
    cout << "Please enter a message less than 100 characters: ";
    cin >> msg;
    
    int i;
    for(i = 0; msg[i] != '\0'; i++){
        num_msg[i] = msg[i];
        cout << msg[i] << " " << num_msg[i] << endl;
    }
    num_msg[i] = '\0';

    // This block allegedly enrypts the user's input
    cout << "encrypting" << endl;
    long long int c_num[100];
    for(i = 0; num_msg[i] != '\0'; i++){
        c_num[i] = fmod(pow(num_msg[i], e),n);
    }
    c_num[i] = '\0';

    // This block supposidly prints out the encrpyted message
    for(i = 0; c_num[i] != '\0'; i++){
        cout << c_num[i] << " ";
    } 
    cout << endl;

    // This block says it decrypts the message
    cout << "Decrypting" << endl;
    long long int m_num[100];
    for(i = 0; c_num[i] != '\0'; i++){
        cout << "c_num^d " << pow(c_num[i], d) << endl;
        m_num[i] = fmod(pow(c_num[i], d), n);
        cout << m_num[i] << " ";
    }
    m_num[i] = '\0';

    // cout << endl << "m_num" << endl;
    // This block claims to print the decrypted message
    for(i = 0; m_num[i] != 0; i++){
        cout << m_num[i] << " ";
        cout << endl;
    } 
    cout << endl;

    return 0;
}
