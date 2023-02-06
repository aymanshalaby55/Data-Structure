#include <iostream>
#include <vector>
#include <queue>
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
    int max_elment() // find max elment in tree
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
    int Count_nodes() // get all number of nodes in tree
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
    int count_leafs() // get number of leaf nodes
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
        res = max(res, res + 1);
        return res;
    }
    bool is_exist(int value) // search for value in tree
    {
        bool res = res == value;
        if (left && !res) // you don't need to search any more if you find the value
        {
            res = left->is_exist(value);
        }
        if (right && !res)
        {
            res = right->is_exist(value);
        }
        return res;
    }
    void level_order_Traversal() // Breadth : level by level
    {
        // complexity O(n)
        queue<tree *> q;
        q.push(this);
        while (!q.empty())
        {
            auto tmp = q.front();
            if (tmp->left)
            {
                q.push(tmp->left);
            }
            if (tmp->right)
            {
                q.push(tmp->right);
            }
            cout << q.front()->data << " ";
            q.pop();
        }
    }
    void level_order_Traversal2() // this function return the number of levels
    {
        // complexity O(n)
        queue<tree *> q;
        q.push(this);
        int level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            cout << "Level " << level << ":";
            while (sz--)
            {
                auto tmp = q.front();
                if (tmp->left)
                {
                    q.push(tmp->left);
                }
                if (tmp->right)
                {
                    q.push(tmp->right);
                }
                cout << q.front()->data << " ";
                q.pop();
            }
            level++;
            cout << endl;
        }
    }
};
int main()
{
    // cout << "hello github";
    tree t(0);
    t.add({4, 8}, {'L', 'L'});
    t.add({3, 5}, {'R', 'R'});
    t.add({3, 6}, {'R', 'L'});
    t.level_order_Traversal2();
    cout << endl;
    return 0;
}