// demonstrate insertion and remove opeartion on an array

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


// this class will help demonstrate various operations on an array
class GameEntry
{
    private:
        string name;    // player's name
        int score;  // player's score

    public:
        GameEntry(const string& n="", int s=0); // ctor
        string getName() const; // get player name
        int getScore() const; // get player's score
};


// class to store high scores of players
class Scores
{
    private:
        int maxEntries; // maximum number of high score entries
        int numEntries; // actual  number of score entries
        GameEntry* entries; // array of game entries

    public:
        Scores(int maxEnt = 10);
        ~Scores();

        void add(const GameEntry& e);
        GameEntry remove(int i);
        void print() const;
};


int main()
{
    GameEntry mike("Mike", 1105);
    GameEntry rob("Rob", 750);
    GameEntry paul("Paul", 720);
    GameEntry anna("Anna", 660);

    Scores highScores(10);
    highScores.add(mike);
    highScores.add(rob);
    highScores.add(paul);
    highScores.add(anna);

    highScores.print();
    cout << endl;

    GameEntry jill("Jill", 740);
    highScores.add(jill);

    highScores.print();
    cout << endl;

    GameEntry removed = highScores.remove(3);
    highScores.print();
    cout << removed.getName() << " is removed" << endl;

    return 0;
}

// Game Entry Class

GameEntry::GameEntry(const string& n, int s) : name(n), score(s) {}

string GameEntry::getName() const
{
    return name;
}

int GameEntry::getScore() const
{
    return score;
}

// Scores Class

Scores::Scores(int maxEnt)
{
    maxEntries = maxEnt;
    numEntries = 0;
    entries = new GameEntry[maxEntries];
}

Scores::~Scores()
{
    delete[] entries;
}


// Inserting in an array in sorted manner
void Scores::add(const GameEntry& e)
{
    // get the new Score to add
    int eScore = e.getScore();

    // check if array is full
    if (numEntries == maxEntries)
    {
        if (eScore <= entries[maxEntries - 1].getScore())
            return; // not enough high score to be added to list
    }
    else
        // if not full then increment number of entries otherwise we will overwrite the last entry
        numEntries++;

    // find postion for e in entries according to score
    int i = numEntries - 2;
    while(i >= 0 && eScore > entries[i].getScore())
    {
        entries[i + 1] = entries[i];    // shift right objects
        i--;
    }

    // add e to postion
    entries[i + 1] = e;
}

GameEntry Scores::remove(int index)
{
    // check bounds
    if (index < 0 || index > numEntries)
    {
        throw out_of_range("index out of range");
    }

    // save object to return after deletion
    GameEntry toRemove = entries[index];

    // shift left objects above target object
    for(int i = index; i < numEntries - 1; i++)
    {
        entries[i] = entries[i + 1];
    }

    // decreament number of entries
    numEntries--;

    return toRemove;
}


void Scores::print() const
{
    for (int i = 0; i < numEntries; i++)
    {
        cout << entries[i].getName() << ", " << entries[i].getScore() << endl;
    }
}