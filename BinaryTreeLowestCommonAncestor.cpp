#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	int getNodesDistance(TreeNode * root, TreeNode * node1, TreeNode * node2)
	{
		TreeNode * lca = LCA(root, node1, node2);
		vector<TreeNode *> path1;
		vector<TreeNode *> path2;
		findPathToNode(lca, node1, path1);
		findPathToNode(lca, node2, path2);

		return path1.size() + path2.size() - 2;
	}
	
	TreeNode * LCA(TreeNode * root, TreeNode * node1, TreeNode * node2)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root == node1 || root == node2)
		{
			return root;
		}
		auto leftFind = LCA(root->left, node1, node2);
		auto rightFind = LCA(root->right, node1, node2);
		if (leftFind && rightFind)
		{
			return root;
		}
		return (leftFind != nullptr ? leftFind : rightFind);
	}

	TreeNode * LCA2(TreeNode * root, TreeNode * node1, TreeNode * node2)
	{
		vector<TreeNode *> path1;
		vector<TreeNode *> path2;
		findPathToNode(root, node1, path1);
		findPathToNode(root, node2, path2);
		TreeNode * lca = nullptr;
		for (int i = 0; i < min(path1.size(), path2.size()); i++)
		{
			if (path1[i] == path2[i])
			{
				lca = path1[i];
			}
			else
			{
				break;
			}
		}
		return lca;
	}
private:
	bool findPathToNode(TreeNode * root, TreeNode * node, vector<TreeNode *>& path)
	{
		if (root == nullptr)
		{
			return false;
		}
		path.push_back(root);
		if (root == node)
		{
			return true;
		}
		bool find = findPathToNode(root->left, node, path) || findPathToNode(root->right, node, path);
		if (!find)
		{
			path.pop_back();
			return false;
		}
		return true;
	}
};

int main()
{
	TreeNode n0(0);
	TreeNode n100(100);
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	TreeNode n7(7);
	TreeNode n8(8);

	n0.left = &n1;
	n0.right = &n100;

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;
	n6.right = &n8;
	
	Solution s;
	TreeNode * root = &n0;
	cout << "find 4, 5 LCA : " << (s.LCA(root, &n4, &n5))->val << endl;
	cout << "find 4, 6 LCA : " << (s.LCA(root, &n4, &n6))->val << endl;
	cout << "find 5, 8 LCA : " << (s.LCA(root, &n5, &n8))->val << endl;
	cout << "try it another way..." << endl;
	cout << "find 4, 5 LCA : " << (s.LCA2(root, &n4, &n5))->val << endl;
	cout << "find 4, 6 LCA : " << (s.LCA2(root, &n4, &n6))->val << endl;
	cout << "find 5, 8 LCA : " << (s.LCA2(root, &n5, &n8))->val << endl;
	cout << "find 5, 8 LCA : " << (s.LCA2(root, &n5, &n100))->val << endl;

	cout << "nodes distance between n2 and n7 = " << s.getNodesDistance(root, &n2, &n7) << endl;
	cout << "nodes distance between n4 and n5 = " << s.getNodesDistance(root, &n4, &n5) << endl;
	cout << "nodes distance between n4 and n6 = " << s.getNodesDistance(root, &n4, &n6) << endl;
	cout << "nodes distance between n3 and n4 = " << s.getNodesDistance(root, &n3, &n4) << endl;
	cout << "nodes distance between n2 and n4 = " << s.getNodesDistance(root, &n2, &n4) << endl;
	cout << "nodes distance between n8 and n5 = " << s.getNodesDistance(root, &n8, &n5) << endl;
	return 0;
}