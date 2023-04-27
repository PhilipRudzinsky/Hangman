#include <string>
#include <time.h>
#include <iostream>
#include <vector>
#include <locale.h>
#include <fstream>
#include <Windows.h>
using namespace std;
class Hangman
{
public:
    string line;
    string pass;
    void random();
    void hangman();
};
void Hangman::random()
{
    srand(time(NULL));
    vector<string> lines;
    ifstream file("hasla.txt");

    int total_lines = 0;
    while (getline(file, line))
    {
        total_lines++;
        lines.push_back(line);
    }
    pass = lines[rand() % total_lines];
    cout << pass << endl;
}
void Hangman::hangman()
{

    cout << "Twoje słowo ma " << pass.length() << " liter" << endl;
    vector<string> empty;
    int lifepoints = 10;
    string result;
    string wynik;
    int licznik = 0;
    for (int i = 0; i < pass.length(); i++)
    {
        empty.push_back("_");
    }
    while (lifepoints != 0)
    {
        
        result = "";
        cout << "Liczba żyć: " << lifepoints<<endl;
        for (int j = 0; j < empty.size(); j++)
        {
            cout << empty[j];
        }
        
        cout << "Podaj literkę: ";
        cin >> result;
        for (int k = 0; k < empty.size(); k++)
        {
            if (pass[k] == result[0])
            {
                empty[k].swap(result);
            }
            
            
                             
        }
        for (auto i : empty)
        {
            wynik = i;
        }
        cout << endl << "WYNIK!!!!!!!  " << wynik;

        lifepoints--;
    }
    cout << wynik;
}
int main()
{
    setlocale(LC_CTYPE, "Polish");
    Hangman human;
    human.random();
    human.hangman();
}
