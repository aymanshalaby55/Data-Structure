#include <iostream>
#include <vector>
using namespace std;
/*
1- max elment in tree []
2-

*/
class tree
{
private:
    int data{};
    tree *left{};
    tree *right{};
    int max_value = 0;

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
    /*
    int max_val()
    {
        max_value = max(data,max_value);
        if(left)
        {
            max_value = max(data,leftmax_val);
        }
        if(right)
        {
            right->max_val();
        }
        return max_value;
    }
    */
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
};
int n = 7;
int maxx(int *a, int m)
{
    int ma = a[m];
    if (m == n - 1)
    {
        return ma;
    }
    ma = max(ma, maxx(a, m + 1));
}
int main()
{

int a[] = {1,2,3,4,5,5};
cout << count(a,0);
    cout << endl;
    // cout << t.max_val();
    return 0;
}