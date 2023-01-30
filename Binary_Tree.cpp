#include <iostream>
#include <vector>
using namespace std;
/*
1- max elment in tree [T]
2- hight of tree []

*/
class tree
{
private:
    int data{};
    tree *left{};
    tree *right{};

public:
    tree(int data)
    {
        this->data = data;
    }
    void print_inorder()
    {

        if (left)
        {
            left->print_inorder();
        }
        cout << data << " ";
        if (right)
        {
            right->print_inorder();
        }
    }
    void add(vector<int> values, vector<char> letters)
    {
        tree *tmp = this; // (this) mean the root of the tree
        for (int i = 0; i < values.size(); i++)
        {
            if (letters[i] == 'L')
            {
                if (!tmp->left) // if left is not NULL
                {
                    tmp->left = new tree(values[i]);
                }
                tmp = tmp->left;
            }
            else
            {
                if (!tmp->right) // if right  is not NULL
                {
                    tmp->right = new tree(values[i]);
                }
                tmp = tmp->right;
            }
        }
    }
    int max_elment()
    {
        int res = data;
        if (left)
        {
            res = max(res, left->max_elment());
        }
        if (right)
        {
            res = max(res, right->max_elment());
        }
        return res;
    }
    int max_Hight()
    {
        int res = 0;
        if (left)
        {
            res = max(res, left->max_elment() + 1);
        }
        if (right)
        {
            res = max(res, right->max_elment() + 1);
        }
        return res;
    }
};
int main()
{
    tree t(0);
    t.add({1, 2, 3, 4}, {'L', 'R', 'L', 'R'});
    t.print_inorder();
    cout << endl;
    cout << t.max_Hight() << endl;
    ;
    return 0;
}