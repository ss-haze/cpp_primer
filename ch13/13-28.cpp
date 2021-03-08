#include <string>
#include <memory>

class TreeNode
{
public:
TreeNode ()
:
value(std::string()),
count (new int(1)),
left(nullptr),
right(nullptr)
{}

TreeNode (const TreeNode& rhs)
:
value(rhs.value),
count(rhs.count),
left(rhs.left),
right(rhs.right)
{++*count;}

~TreeNode()
{
  if (--count==0)
  {
    delete count;
    delete left;
    delete right;
  }
}

TreeNode& operator= (const TreeNode& rhs)
{
  ++*rhs.count;
  if (--count == 0)
  {
    delete count;
    delete left;
    delete right;
  }
  count = rhs.count;
  left=rhs.left;
  right=rhs.right;
  value=rhs.value;
  return *this;
}

  private:
  std::string value;
  int *count;
  TreeNode *left;
  TreeNode *right;
};

class BinTree
{
BinTree()
:
root (new TreeNode())
{}

BinTree (const BinTree& rhs)
:
root (new TreeNode(*rhs.root))
{
}

~BinTree()
{
  delete root;
}

BinTree& operator= (const BinTree& rhs)
{
  auto temp= new TreeNode(*rhs.root);
  delete root;
  root=temp;
  return *this;
}
  private:
  TreeNode *root;
};


int main()
{
  return 0;
}


