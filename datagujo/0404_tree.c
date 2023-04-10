
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

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct Snode {
	struct node* data;
	struct Snode* next;
};
struct node* root = 0;
struct Snode* head = 0;

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

void traversal_inorder(struct node* _cur) {

	if (_cur == 0) {
		return;
	}

	traversal_inorder(_cur->left);
	printf("%d ", _cur->data);
	traversal_inorder(_cur->right);
	return;
}

// traversal (�湮)
// 3���� ����� �ִ� ����Ʈ���� ��ȸ
// 1. pre-order traversal
// 2. in-oder traversal
// 3. post-order traversal
// stack �Ǵ� ����Լ� ���.
void push(struct node* _v) {
	struct Snode* _new = (struct Snode*)malloc(sizeof(struct Snode));
	_new->data = _v;
	_new->next = 0;

	if (head == 0) {
		head = _new;
		return;
	}
	_new->next = head;
	head = _new;
	return;
}

struct node* pop() {
	if (head) {
		struct node* rtn = head->data;
		struct Snode* spear = head;
		head = head->next;
		free(spear);
		return rtn;
	}
	return 0;
}

// ���� ����. ���� ��
void traversal_inorder_norecursion(struct node* _cur) {

	while (1) {
		while (_cur) {
			push(_cur);
			_cur = _cur->left;
		}
		_cur = pop();
		if (_cur == 0) {
			break;
		}
		printf("%d ", _cur->data);
		_cur = _cur->right;
	}
	return;
}

void traversal_preorder(struct node* _cur) {

	if (_cur == 0) {
		return;
	}

	printf("%d ", _cur->data);
	traversal_inorder(_cur->left);
	traversal_inorder(_cur->right);
	return;
}

void traversal_postorder(struct node* _cur) {

	if (_cur == 0) {
		return;
	}

	traversal_inorder(_cur->left);
	traversal_inorder(_cur->right);
	printf("%d ", _cur->data);
	return;
}

// ���� ��ȸ
// level order
// queue ���
void enqueue(struct node* _v) {
	struct Snode* _new = (struct Snode*)malloc(sizeof(struct Snode));
	_new->data = _v;
	_new->next = 0;
	if (head) {
		struct Snode* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = _new;
		return;
	}
	head = _new;
	return;
}

struct node* dequeue() {
	if (head == 0) {
		return 0;
	}
	struct node* rtn = head->data;
	struct Snode* spear = head;
	head = head->next;
	free(spear);
	return rtn;
}

void level_order(struct node* _cur) {
	enqueue(_cur);
	while (head) {
		_cur = dequeue();
		printf("%d ", _cur->data);
		if (_cur->left) {
			enqueue(_cur->left);
		}
		if (_cur->right) {
			enqueue(_cur->right);
		}
	}
	return;
}

// ���� ���ϱ�
int which_is_bigger(int a, int b) {
	return a < b ? b : a;
}

int get_height(struct node* _cur) {

	if (_cur == 0) {
		return 0;
	}

	return (1 + which_is_bigger(get_height(_cur->left), get_height(_cur->right)));
}

// ��� ���� ���ϱ�
int get_node_count(struct node* _cur) {
	if (_cur == 0) {
		return 0;
	}
	return (1 + get_node_count(_cur->left) + get_node_count(_cur->right));
}

// �ܸ���� ���� ���ϱ�
int get_terminalnode_count(struct node* _cur) {
	if (_cur == 0) {
		return 0;
	}
	if (_cur->left == 0 && _cur->right->right == 0) {
		return 1;
	}
	return (get_terminalnode_count(_cur->left) + get_terminalnode_count(_cur->right));
}

// Ʈ���� ����: ���� ó�� Ʈ��

int main() {

	addToBST(20);
	addToBST(10);
	addToBST(30);
	addToBST(40);
	addToBST(5);
	// skewed: ������� �߰��ϸ� Ʈ���� ���������� �������
	//printf("%d\n", (root->data == 20));
	//printf("%d\n", (root->left->data == 10));
	//printf("%d\n", (root->right->data == 30));
	//printf("%d\n", (root->left->right->data == 15));
	struct node* spear = root;
	traversal_inorder(spear);
	printf("\n");
	traversal_inorder_norecursion(spear);
	printf("\n");
	traversal_preorder(spear);
	printf("\n");
	traversal_postorder(spear);
	printf("\n");
	level_order(spear);
	printf("\n");

	return 0;
}