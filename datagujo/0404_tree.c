
//
// ���ݱ��� ��� �ڷᱸ���� �����̴�.
// 
// Ʈ���� ������ ������ ǥ���ϴ� ��ǥ�� ������ ����
// 
// Node
// Root Node
// 
// parent node
// child node
// sibling node
// 
// sub-tree ����Ʈ��
// 
// terminal node 
// non-terminal node
// child node ���� ����
// 
// degree ����
// 
// degree of a tree 
// max(degree of a node)
// 
// height of a tree
// max(level)
// level ����
// 
// forest 
//  set of trees
// 
// Ʈ���� ����
//  degree of a tree�� 2�� Ʈ��
//  ����Ʈ��
// 
// left subtree, right subtree
// 
// node�� n�� �ִٸ�, edge�� n-1�� �ִ�.
// ��� ���� �θ�� ���� edge�� �ִ�.
// root node ����..
// 
// ���̰� h�� ����Ʈ������ ��尡 �ּ�h�� �ְ�
// �ִ� 2^h -1 ��ŭ �ִ�.
// 
// n���� ��尡 �ִ� ����Ʈ���� ���̴�
// �ִ� n�̰ų�
// �ּ� log_2(n+1)
// 
// ����Ʈ���� �з�
//  full binary tree
//  complete binary tree
// 
// tree, binary tree, bnary search tree
// 
// 
// traversal (�湮)
// 3���� ����� �ִ� ����Ʈ���� ��ȸ
// 1. pre-order traversal
// 2. in-oder traversal
// 3. post-order traversal
//

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct node* root = 0;;

// _v ���� ������ ��带 ����� BST�� �߰�
void addToBST(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->left = _new->right = 0;

	// BST�� ������� ��
	if (root == 0) {
		root = _new;
		return;
	}

	// BST�� ������� ���� ��
	struct node* spear = root;
	// terminal node���� �����ϹǷ� �ݺ�
	while (1) {
		// �켱�� ��� data�� �ٸ��ٰ� ����.
		if (spear->data < _new->data) {
			if (spear->right == 0) {
				spear->right = _new;
				return;
			}
			else {
				spear = spear->right;
			}
		}
		else {
			if (spear->left == 0) {
				spear->left = _new;
				return;
			}
			else {
				spear = spear->left;
			}
		}
	}

}

int main() {

	addToBST(20);
	addToBST(10);
	addToBST(30);
	addToBST(40);
	addToBST(15);
	// skewed: ������� �߰��ϸ� Ʈ���� ���������� �������
	printf("%d\n", (root->data == 20));
	printf("%d\n", (root->left->data == 10));
	printf("%d\n", (root->right->data == 30));
	printf("%d\n", (root->left->right->data == 15));

	return 0;
}