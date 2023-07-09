#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution2 {
public:
    map<int,int> data;
    int dfs(TreeNode* root,int lvl){
        int llongest,rlongest;
        if (root->left){
            llongest = dfs(root->left,lvl+1);
        } else {
            llongest = 0;
        }
        if (root->right){
            rlongest = dfs(root->right,lvl+1);
        } else {
            rlongest = 0;
        }
        data[root->val] = llongest + rlongest;
        return (llongest > rlongest) ? llongest + 1 : rlongest + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root,0);
        int min = 0;
        for (auto i = data.begin();i != data.end();i++){
//            cout << i->first << " " << i->second << endl;
            if (i->second > min){
//                cout << i->second << endl;
                min = i->second;
            }
        }
        return min;
    }
};

class Solution {
    int ans;
    int depth(TreeNode *rt){
        if (rt == NULL) {
            return 0;
        }
        int L = depth(rt->left);
        int R = depth(rt->right);
        ans = max(ans,L + R + 1);
        return max(L,R)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};
int main(){
    auto *node4 = new TreeNode(4);
    auto *node5 = new TreeNode(5);
    auto *node3 = new TreeNode(3);
    auto *node2 = new TreeNode(2,node4,node5);
    auto *node1 = new TreeNode(1,node2,node3);
    Solution t;
    int a = t.diameterOfBinaryTree(node1);
    cout << a;
}




