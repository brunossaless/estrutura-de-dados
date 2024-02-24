#include <iostream>
#include <sstream>
using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
  Node(int value = 0, Node *left = nullptr, Node *right = nullptr)
  {
    this->value = value;
    this->left = left;
    this->right = right;
  }
};

struct BTree
{
  Node *root{nullptr};
  BTree()
  {
  }

  void monta(stringstream &ss, Node *raiz[])
  {
    string value;
    ss >> value;
    if (value == "#")
      return;
    int num;
    stringstream(value) >> num;
    *raiz = new Node(num);
    monta(ss, &(*raiz)->left);
    monta(ss, &(*raiz)->right);
  }

  BTree(string serial)
  {
    stringstream ss(serial);
    monta(ss, &root);
  }

  void __destroy(Node *node)
  {
    if (node == nullptr)
      return;
    __destroy(node->left);
    __destroy(node->right);
    delete node;
  }

  ~BTree()
  {
    __destroy(this->root);
  }

  void show(Node *node, int nivel)
  {
    if (node == nullptr)
    {
      cout << string(nivel, '.') << "#\n";
      return;
    }
    show(node->left, nivel + 1);
    cout << string(nivel, '.') << node->value << "\n";
    if (node->left == nullptr && node->right == nullptr)
      return;
    show(node->right, nivel + 1);
  }

  void show()
  {
    show(root, 0);
  }

  void bshow()
  {
    __bshow(this->root);
  }

  void __bshow(Node *node, string heranca = "")
  {
    if (node != nullptr && (node->left != nullptr || node->right != nullptr))
      __bshow(node->left, heranca + "l");
    for (int i = 0; i < (int)heranca.size() - 1; i++)
      cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if (heranca != "")
      cout << (heranca.back() == 'l' ? "┌───" : "└───");
    if (node == nullptr)
    {
      cout << "#" << endl;
      return;
    }
    cout << node->value << endl;
    if (node != nullptr && (node->left != nullptr || node->right != nullptr))
      __bshow(node->right, heranca + "r");
  }

  void __show_in_order(Node *node)
  {
    if (node == nullptr)
      return;
    __show_in_order(node->left);
    cout << node->value << " ";
    __show_in_order(node->right);
  }

  void show_in_order()
  {
    cout << "[ ";
    __show_in_order(root);
    cout << "]\n";
  }
};

int main()
{
  string line;
  getline(cin, line);
  BTree bt(line);
  bt.show_in_order();
}