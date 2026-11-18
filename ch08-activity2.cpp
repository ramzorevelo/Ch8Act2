// Activity 2: my number tree in code.
// The program builds a binary tree from 6 digits, level by level, left to right,
// and prints four traversals. Make two edits: TODO 1 (your digits) and TODO 2
// (write postorder). Run it, then compare each printed line with your drawing.
#include <iostream>
#include <queue>

template <typename T>
struct TreeNode
{
    T data;
    TreeNode* left{ nullptr };
    TreeNode* right{ nullptr };
};

// Puts value at the first free place in level order.
void insertLevelOrder(TreeNode<int>*& root, int value)
{
    TreeNode<int>* newNode{ new TreeNode<int>{ value } };
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    std::queue<TreeNode<int>*> waiting;
    waiting.push(root);
    while (!waiting.empty())
    {
        TreeNode<int>* current{ waiting.front() };
        waiting.pop();
        if (current->left == nullptr)
        {
            current->left = newNode;
            return;
        }
        if (current->right == nullptr)
        {
            current->right = newNode;
            return;
        }
        waiting.push(current->left);
        waiting.push(current->right);
    }
}

void preorder(const TreeNode<int>* t)
{
    if (t != nullptr)
    {
        std::cout << t->data << ' ';    // visit
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(const TreeNode<int>* t)
{
    if (t != nullptr)
    {
        inorder(t->left);
        std::cout << t->data << ' ';    // visit
        inorder(t->right);
    }
}

void postorder([[maybe_unused]] const TreeNode<int>* t)
{
    // TODO 2: copy preorder's body here, change its two calls to postorder,
    //         then move the // visit line to after the two calls
}

void levelOrder(const TreeNode<int>* root)
{
    std::queue<const TreeNode<int>*> waiting;
    if (root != nullptr)
    {
        waiting.push(root);
    }
    while (!waiting.empty())
    {
        const TreeNode<int>* current{ waiting.front() };
        waiting.pop();
        std::cout << current->data << ' ';          // visit
        if (current->left != nullptr)
        {
            waiting.push(current->left);
        }
        if (current->right != nullptr)
        {
            waiting.push(current->right);
        }
    }
}

// Frees every node: both subtrees first, then the node itself.
void destroy(TreeNode<int>* t)
{
    if (t != nullptr)
    {
        destroy(t->left);
        destroy(t->right);
        delete t;
    }
}

int main()
{
    int digits[]{ 0, 0, 0, 0, 0, 0 }; // TODO 1: the 6 digits of your student ID (S123456 -> 1, 2, 3, 4, 5, 6)

    TreeNode<int>* root{ nullptr };
    for (int digit : digits)
    {
        insertLevelOrder(root, digit);
    }

    std::cout << "preorder: ";
    preorder(root);
    std::cout << "\ninorder: ";
    inorder(root);
    std::cout << "\npostorder: ";
    postorder(root);
    std::cout << "\nlevel order: ";
    levelOrder(root);
    std::cout << '\n';

    destroy(root);
}
