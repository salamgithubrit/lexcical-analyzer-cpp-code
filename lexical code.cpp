#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;
int i = 0, id = 0, kw = 0, num = 0, op = 0;
void iskeyword(char* p) {
    char keywords[32][10] = { "auto","break","case","char","const","continue","default",
                              "do","double","else","enum","extern","float","for","goto",
                              "if","int","long","register","return","short","signed",
                              "size of","static","struct","switch","typedef","union",
                              "unsigned","void","volatile","while" };
    int k, flag = 0;
    for (k = 0; k <= 31; k++) {
        if (strcmp(keywords[k], p) == 0) {
            cout << p << " is a keyword\n";
            kw++;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        if (isdigit(p[0])) {
            cout << p << " is a number\n";
            num++;
        }
        else
        {
            if (p[0] != '\0')
            {
                cout << p << " is an identifier\n";
                id++;
            }
        }
    }
    i = -1;
}
int main() {
    char ch, str[25], seps[16] = " \t\n,;(){}[]#\"<>", oper[] = "!%^&*-+=~|.<>/?";
    int j;
    char fname[50];
    cout << " enter the path of file (C:\\fold\\filename)\n";
    ifstream myfile("input.txt");
    if (!myfile.is_open()) {
        cout << "error while opening the file\n";
        exit(0);
    }
    while (!myfile.eof()) {
        ch = myfile.get();
        for (j = 0; j <= 14; j++){
            if (ch == oper[j])
            {
                cout << ch << " is an operator\n";
                op++;
                str[i] = '\0';
                iskeyword(str);
            }
        }
        for (j = 0; j <= 14; j++){
            if (i == -1)
                break;
            if (ch == seps[j]){
                if (ch == '#')
                {
                    while (ch != '>')
                    {
                        cout << ch;
                        ch = myfile.get();
                    }
                        cout << ch << "%c is a header file\n";
                        i = -1;
                        break;
                    
                }
                if (ch == '"')
                {
                    do
                    {
                        ch = myfile.get();
                        cout << ch ;
                    } while (ch != '"');
                    cout << "\b is an argument\n";
                    i = -1;
                    break;
                }
                str[i] = '\0';
                iskeyword(str);
            }
        }
        if (i != -1)
        {
            str[i] = ch;
            i++;
        }
        else
            i = 0;
    }
    cout << "Keywords:" << kw << endl;
    cout << "Identifiers:" << id << endl;
    cout << "Operators:" << op << endl;
    cout<<"Numbers:" << num<< endl;
    }



