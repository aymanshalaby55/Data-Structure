#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Trie
{
private:
    Trie *child[26];
    bool isleaf = false;

public:
    Trie()
    {
        memset(child, 0, sizeof(child));
    }
    void insert(string word, int index)
    {
        if (index == (int)word.size())
        {
            isleaf = 1;
        }
        else
        {
            /*
            lets break down what's going here:
            - first search for the index of the letter.
            - then look if it exsist > then create new trie for it comming letter
            */
            int current = word[index] - 'a';
            if (child[current] == 0)         // if null
                child[current] = new Trie(); // insert new
            insert(word, index + 1);
        }
    }

    // search for a complete word
    bool isexsist(string word, int index = 0)
    {
        if (index == (int)word.size())
            return isleaf;

        int letter = word[index] - 'a';
        if (!child[letter])
        {
            return false;
        }
        return isexsist(word, index + 1);
    }

    // search for perfix word
    bool isexsist(string word, int index = 0)
    {
        if (index == (int)word.size())
            return true; // minor change

        int letter = word[index] - 'a';
        if (!child[letter])
        {
            return false;
        }
        return isexsist(word, index + 1);
    }
};

int main()
{
    cout << "hello" << endl;
    return 0;
}