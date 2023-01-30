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
    int max_Hight() // to find max hight of B_tree
    {
        int res = 0;
        if (left)
        {
            res = left->max_Hight() + 1;
        }
        if (right)
        {
            res = max(res, right->max_Hight() + 1);
        }
        return res;
    }
    int Count_nodes()
    {
        int res = 0;
        if (left)
        {
            res += left->Count_nodes() + 1;
        }
        if (right)
        {
            res += right->Count_nodes() + 1;
        }
        return res;
    }
    int count_leafs()
    {
        int res = 0;
        if (left)
        {
            left->Count_nodes();
        }
        if (right)
        {
            right->Count_nodes();
        }
        res = max(res,res+1);
        return res;
    }
};
int main()
{
    // cout << "hello github";
    tree t(0);
    t.add({1}, {'L'});
    t.add({2}, {'R'});
    t.print_inorder();
    cout << endl;
    cout << t.count_leafs() << endl;
    return 0;
}