
//
// 지금까지 배운 자료구조는 선형이다.
// 
// 트리는 계층적 구조를 표현하는 대표적 데이터 구조
// 
// Node
// Root Node
// 
// parent node
// child node
// sibling node
// 
// sub-tree 서브트리
// 
// terminal node 
// non-terminal node
// child node 유무 차이
// 
// degree 차수
// 
// degree of a tree 
// max(degree of a node)
// 
// height of a tree
// max(level)
// level 레벨
// 
// forest 
//  set of trees
// 
// 트리의 종류
//  degree of a tree가 2인 트리
//  이진트리
// 
// left subtree, right subtree
// 
// node가 n개 있다면, edge는 n-1개 있다.
// 모든 노드는 부모로 가는 edge가 있다.
// root node 빼고..
// 
// 높이가 h인 이진트리에는 노드가 최소h개 있고
// 최대 2^h -1 만큼 있다.
// 
// n개의 노드가 있는 이진트리의 높이는
// 최대 n이거나
// 최소 log_2(n+1)
// 
// 이진트리의 분류
//  full binary tree
//  complete binary tree
// 
// tree, binary tree, bnary search tree
// 
// 
// traversal (방문)
// 3가지 방법이 있는 이진트리의 순회
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

// _v 값을 가지는 노드를 만들고 BST에 추가
void addToBST(int _v) {
	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->left = _new->right = 0;

	// BST가 비어있을 때
	if (root == 0) {
		root = _new;
		return;
	}

	// BST가 비어있지 않을 때
	struct node* spear = root;
	// terminal node까지 가야하므로 반복
	while (1) {
		// 우선은 모든 data가 다르다고 하자.
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
	// skewed: 순서대로 추가하면 트리가 선형적으로 만들어짐
	printf("%d\n", (root->data == 20));
	printf("%d\n", (root->left->data == 10));
	printf("%d\n", (root->right->data == 30));
	printf("%d\n", (root->left->right->data == 15));

	return 0;
}