#include "BinaryTree.hpp"
BinaryTree::BinaryTree(const BinaryTree& temp) {
	root = NULL;
	if(temp.root)
		root = copyNode(temp.root, root);
}
void assign(BinaryTree::Node* root, char ele) {
	std::queue<BinaryTree::Node*>  unvisited;
	unvisited.push(root);
	BinaryTree::Node* current = NULL;
	while (!unvisited.empty()) {
		current = unvisited.front();
		if (current->val == EMPTY_ELE) {
			unvisited.pop();
			continue;
		}
		if (current->left != NULL)
			unvisited.push(current->left);
		else break;
		if (current->right != NULL)
			unvisited.push(current->right);
		else break;
		unvisited.pop();
	}
	if (current->left == NULL)
		current->left = new BinaryTree::Node(ele);
	else if (current->right == NULL)
		current->right = new BinaryTree::Node(ele);
}
BinaryTree::Node * BinaryTree::copyNode(Node * oldNode, Node * newNode) {
	std::queue<Node*> _queue;
	std::queue<Node*> new_queue;
	new_queue.push(oldNode);
	_queue.push(oldNode);
	newNode = new Node(oldNode->val);
	while (!_queue.empty()) {
		Node* p = _queue.front();
		if (p->left != NULL) {
			_queue.push(p->left);
			new_queue.push(p->left);
		}
		if (p->left == NULL && p->right != NULL) {
			Node* temp = new Node(EMPTY_ELE);
			new_queue.push(temp);
		}
		if (p->right != NULL) {
			_queue.push(p->right);
			new_queue.push(p->right);
		}
		if (p->left != NULL && p->right == NULL) {
			Node* temp = new Node(EMPTY_ELE);
			new_queue.push(temp);
		}
		_queue.pop();
	}
	new_queue.pop();
	while (!new_queue.empty()) {
		assign(newNode, new_queue.front()->val);
		if (new_queue.front()->val == EMPTY_ELE) {
			Node* p = new_queue.front();
			delete p;
		}
		new_queue.pop();
	}

	return newNode;
}
BinaryTree::BinaryTree(std::vector<char>& tree) {
	root = NULL;
	if (tree.size()) {
		root = new Node(tree[0]);
		for (int n = 1; n < tree.size(); n++) {
			assign(root, tree[n]);
		}
	}
}
BinaryTree::Node* Buildtree(int* pre, int* ino, int len) {
	BinaryTree::Node* root = new BinaryTree::Node(pre[0]);
	int subtreelen = 0;
	while (subtreelen < len && ino[subtreelen] != pre[0])
		++subtreelen;
	if (subtreelen > 0) {
		root->left = Buildtree(pre + 1, ino, subtreelen);
	}
	if (len - subtreelen - 1 > 0) {
		root->right = Buildtree(pre + 1 + subtreelen, ino + 1 + subtreelen, len - subtreelen - 1);
	}
	return root;
}
// created by preorder and inorder
BinaryTree::BinaryTree(const std::vector<char>& preOrder,
	const std::vector<char>& inOrder) {
	if (preOrder.size() == 0) {
		root = NULL;
		return;
	}
	int* pre = new int[preOrder.size()];
	int* ino = new int[inOrder.size()];
	for (int n = 0; n < preOrder.size(); n++) {
		pre[n] = preOrder[n];
		ino[n] = inOrder[n];
	}
	root = Buildtree(pre, ino, preOrder.size());
	delete[] pre;
	delete[] ino;
}
BinaryTree::~BinaryTree() {
	if(root != NULL)
		clear();
}
BinaryTree& BinaryTree::operator=(const BinaryTree& temp) {
	if (temp.root) {
		if (this == &temp)return *this;
		root = new Node(temp.root->val);
		copyNode(temp.root, root);
	}
	else
		root = NULL;
	return *this;
}

BinaryTree::Node* BinaryTree::getRoot() const { return root; }

void deleteNode(BinaryTree::Node* root) {
	if (root != NULL) {
		deleteNode(root->left);
		deleteNode(root->right);
		delete root;
	}
}
void BinaryTree::clear() {
	deleteNode(root);
	root = NULL;
}

void BinaryTree::preOrder(void(*visite)(BinaryTree::Node* temp), 
	Node* _temp) {
	if (_temp != NULL && _temp->val != EMPTY_ELE) {
		visite(_temp);
		preOrder(*visite, _temp->left);
		preOrder(*visite, _temp->right);
	}
}
void BinaryTree::inOrder(void(*visite)(BinaryTree::Node* temp), 
	Node* _temp) {
	if (_temp != NULL && _temp->val != EMPTY_ELE) {
		inOrder(*visite, _temp->left);
		visite(_temp);
		inOrder(*visite, _temp->right);
	}
}
void BinaryTree::postOrder(void(*visite)(BinaryTree::Node* temp), 
	Node* _temp) {
	if (_temp != NULL && _temp->val != EMPTY_ELE) {
		postOrder(*visite, _temp->left);
		postOrder(*visite, _temp->right);
		visite(_temp);
	}
}

