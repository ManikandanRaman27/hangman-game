#include<bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

char chooseOne();

char chooseOne()
{
    char chr;
    do
    {
        cout<<"Choose:\nvegetables -> v\nanimals -> a\nkitchenObjects -> k\nChoice : ";
        cin>>chr;
    }
    while(chr!='v'&&chr!='a'&&chr!='k');
    return chr;
}

int main()
{
    srand(time(nullptr));

    vector<string> vegetables = {"corn", "tomato", "potato", "peas", "root"};
    vector<string> animals = {"lion","tiger","bear","fox","dog"};
    vector<string> kitchenObjects = {"stove","gas","spoon","knife","fork"};
    char chr = chooseOne();
    int random_index = rand() % 5;
    string secret_word;
    switch(chr)
    {
    case 'v':
        cout<<"Guess The Vegetable : \n";
        secret_word = vegetables[random_index];
        break;
    case 'a':
        cout<<"Guess The Animal : \n";
        secret_word = animals[random_index];
        break;
    case 'k':
        cout<<"Guess The Kitchen Object : \n";
        secret_word = kitchenObjects[random_index];
        break;
    }

    int guesses_remaining = 7;
    string guessed_letters = "";
    string displayed_word(secret_word.size(), '-');

    while (guesses_remaining > 0 && displayed_word != secret_word)
    {
        cout << "You have " << guesses_remaining << " guesses remaining." << endl;
        cout << "Word: " << displayed_word << endl;

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;
        guess = tolower(guess);

        if (guessed_letters.find(guess) != string::npos)
        {
            cout << "You already guessed '" << guess << "'." << endl;
            continue;
        }

        guessed_letters += guess;

        bool correct_guess = false;
        for (int i = 0; i < secret_word.length(); ++i)
        {
            if (secret_word[i] == guess)
            {
                displayed_word[i] = guess;
                correct_guess = true;
            }
        }

        if (correct_guess)
        {
            cout << "Correct guess!" << endl;
        }
        else
        {
            guesses_remaining--;
            cout << "Incorrect guess." << endl;
        }
        cout<<endl;
    }

    if (guesses_remaining > 0)
    {
        cout << "Congratulations! You guessed the word: " << secret_word << endl;
    }
    else
    {
        cout << "Game over! The word was: " << secret_word << endl;
    }

    return 0;
}

