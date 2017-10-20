/*
  Author: <Benjamin Gur>
  Course: {135,136}
  Instructor: <Prof. Pajela>
  Assignment: <Lab4 task 2>

  This program draws the a triangle constituting the northwestern half of a square.
*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

void rectangle(int w, int h);
//precondition: Give hight and width greater then 0
//postcondition: Will draw a rectangle given based on the arguments. 
void triangle(int side);
//precondition: Give a non negetive side length.
//postcondtion: Will draw a triangle base on the arguments.
void circle(int r);
//preconditon: Give a value greater then 0 for radius.
//postcondition: Willd draw a circle based on the arguments.

int main(){
    int w, h, side, r;
    string menu;
    while(true){ //Infinite loop.
        start:
        cout << "Enter (R)ectangle, (T)riangle, (C)ircle, or (E)nd.\n";
        cin >> menu;
        if (menu.length()>1){
            cerr << "ERROR. Input invalid.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this resets the stream.
            goto start; //goes back to prompt.
        }
        if (menu[0] == 'R' || menu[0] == 'r'){
            rstart:
            cerr << "How wide do you want your rectangular frame to be?\n";
            cin >> w;
            if (cin.fail()==true){
                cerr << "ERROR. Input invalid.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this resets the stream.
                goto rstart; //brings back to start of program.
            }
            cout << "How tall do you want your rectangular frame to be?\n"; 
            cin >> h;
            if (cin.fail()==true){
                cerr << "ERROR. Input invalid.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this resets the stream.
                goto rstart; //brings back to start of program
            }
            rectangle(w, h);
        }
        else if (menu[0] == 'T' || menu[0] == 't'){
            tstart:
            cerr << "This program will draw a triangle constituting the northwestern half of a square.\n"<< "Please enter the side lenght you wish for the triangle:\n";
            cin >> side;
            if (cin.fail()==true){
                cout << "ERROR. Input invalid.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this resets the stream.
                goto tstart; //allows reentry
            }             
            triangle(side);
        }
        else if (menu[0] == 'C' || menu[0] == 'c'){
            cstart:
            cerr << "What radius would you like your circle to be?\n";
            cin >> r;
            if (cin.fail()==true){
                cerr << "ERROR. Input invalid.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //this resets the stream.
                goto cstart; //Added a goto statment here inorder to reset cleanly.
            }
            circle(r);
        }
        else if (menu[0] == 'E' || menu[0] == 'e'){
            return 0; //ends program
        }
        else{
        cerr << "ERROR. Input invalid.\n";
        }
    }
}

void rectangle(int w, int h){
    int count = 0;
    while (count < w){
        cout << "*";
        count++;
    }
    cout << endl;
    if (h <=1){
        return; //this is for if the rectangle is only one line high.
    }
    int countTwo = 2; //countTwo = 2 becuse 2 lines will be full of *.
    int countThree = 2; //countThree = 2 becuse there are * on either end.
    while (countTwo < h){ //This while loop loops during the poi
        cout << "*";
        countTwo++;
        while (countThree < w){
            cout << " ";
            countThree++;
        }
        cout << "*" << endl;
        countThree = 2; //This resets the above while loop.
    }
    int countFour = 0;
    while (countFour < w){
        cout << "*";
        countFour++;
    }
    cout << endl;
    return;
}

void triangle(int side){
    int  count, countTwo;
    count = side;
    countTwo = side;
    while (countTwo > 0){
        while (count > 0){
            cout << "*";
            count--;
    }
        cout << endl;
        countTwo--;
        count = countTwo; //Becuse countTwo is decremented in the above line not only does it limit the loop but when count is eqalised to it it make the * per row one less.
    }
    return;
}

void circle(int r){ //I used internet code as I didnt make the circle in lab 4.
    float console_ratio = 4.0/3.0;
    float a = console_ratio*r;
    float b = r;

    for (int y = -r; y <= r; y++)
    {
        for (int x = -console_ratio*r; x <= console_ratio*r; x++)
        {
            float d = (x/a)*(x/a) + (y/b)*(y/b);
            if (d > 0.90 && d < 1.1)
            {
                cout << "*";
            }
            else
            {
                 cout << " ";
            }
        }
        cout << endl;
    }
    return;
}

/* Test Cases

Inputing letters, symbols, words, sentences , over-flowingly large positive or negative numbers, and decimals for w, h, r, and side all will output a error message clear the stream and allow for reentry.
Imputing characters other than r, t, c, or e will will output a error message and allow for reentry. Inputting words, sentences, or numbers, including decimals will output a error message clear the stream and allow for reentry.   */
