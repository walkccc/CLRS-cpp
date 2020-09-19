#ifndef TreeNode_h
#define TreeNode_h

struct TreeNode {
  int key;
  TreeNode* left;
  TreeNode* right;
  TreeNode* p;
  TreeNode(int x) : key(x), left(nullptr), right(nullptr), p(nullptr){};
};

#endif