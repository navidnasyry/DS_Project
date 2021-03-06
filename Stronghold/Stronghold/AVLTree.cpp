#include <cmath>
#include "AVLTree.h"
#include "Castle.h"
#include "Map.h"

#define max(a,b) a>b?a:b



AVLTree::AVLTree()
{
	this->root = nullptr;
}


AVLTree::~AVLTree()
{
	distructor(root);
	delete root;
}

void AVLTree::distructor(AVLNode* r)
{
	while (r)
	{
		distructor(r->left);
		distructor(r->right);
		r->~AVLNode();
		r = nullptr;
		delete r;
	}

}

int AVLTree::height(AVLNode* r)
{
	return (r == nullptr ? -1 : r->height);
}

AVLNode* AVLTree::rightRotate(AVLNode*& t)
{
	AVLNode* n = t->left;
	t->left = n->right;
	n->right = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	n->height = max(height(n->left), t->height) + 1;
	return n;

}
AVLNode* AVLTree:: leftRotate(AVLNode*& t)
{
	AVLNode* n = t->right;
	t->right = n->left;
	n->left = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	n->height = max(height(n->right), t->height) + 1;
	return n;

}

AVLNode* AVLTree::doubleLeftRotate(AVLNode*& t)
{
	t->right = rightRotate(t->right);
	return leftRotate(t);
}


AVLNode* AVLTree::doubleRightRotate(AVLNode*& t)
{
	t->right = leftRotate(t->left);
	return rightRotate(t);
}

AVLNode* AVLTree::insert(Soldier new_s , AVLNode* t)
{
	int p = new_s.power;
	if (this->root == nullptr)
	{
		t = new AVLNode();
		t->key = p;
		t->data = new_s;
		t->height = 0;
		t->left = t->right = nullptr;
		this->root = t;
		return t;
	}
	if (t == nullptr)
	{
		t = new AVLNode();
		t->key = p;
		t->data = new_s;
		t->height = 0;
		t->left = t->right = nullptr;
		//this->root = t;
	}
	else if (p < t->key)
	{
		t->left = insert(new_s, t->left);
		if (height(t->left) - height(t->right) == 2)
		{
			if (p < t->left->key)
				t = rightRotate(t);
			else
				t = doubleRightRotate(t);
		}

	}
	else if (p >= t->key)
	{
		t->right = insert(new_s, t->right);
		if (height(t->right) - height(t->left) == 2)
		{
			if (p > t->right->key)
				t = leftRotate(t);
			else
				t = doubleLeftRotate(t);
		}
	}
	else if (p == t->key) return t;

	t->height = max(height(t->left), height(t->right)) + 1;
	return t;

}

AVLNode* AVLTree::remove(int p, AVLNode* t)
{
	AVLNode* temp;
	if (t == nullptr)
	{
		return nullptr;
	}
	else if (p < t->key)
		t->left = remove(p, t->left);
	else if (p > t->key)
		t->right = remove(p, t->right);

	else if (t->left && t->right)
	{
		temp = findMin(t->right);
		t->key = temp->key;
		t->right = remove(t->key, t->right);
	}
	else
	{
		temp = t;
		
		if (t->left == nullptr)
			t = t->right;
		else if (t->right == nullptr)
			t = t->left;
		delete temp;
		temp = nullptr;
	}
	if (t == nullptr)
		return nullptr;

	//if (t != nullptr) {
		t->height = max(height(t->left), height(t->right)) + 1;

		if (height(t->left) - height(t->right) == 2)
		{
			if (t->left)
			{
				if (height(t->left->left) - height(t->left->right) == 1)
					return rightRotate(t);
			}

			return doubleRightRotate(t);
		}
		else if (height(t->right) - height(t->left) == 2)
		{
			if (t->right)
			{
				if (height(t->right->right) - height(t->right->left) == 1)
					return leftRotate(t);

			}
			return doubleLeftRotate(t);
		}
	//}
	//else
		return t;
}

Soldier AVLTree::removeSoldier(int power)
{
	Soldier s = remove(power, root)->data;
	
	return s;
}

void AVLTree::insertSoldier(Soldier new_s)
{
	this->root = insert(new_s, root);
	return;
}

AVLNode* AVLTree::findMin(AVLNode* t)
{
	if (t == nullptr)
		return nullptr;
	else if (t->left == nullptr)
		return t;
	else
		return findMin(t->left);
}


AVLNode* AVLTree::findMax(AVLNode* t)
{
	if (t == nullptr)
		return nullptr;
	else if (t->right == nullptr)
		return t;
	else
		return findMax(t->right);
}

void AVLTree::inorder(AVLNode* t)
{
	if (t==nullptr)
		return;
	inorder(t->left);
	cout << t->key << " ";
	inorder(t->right);
}

void AVLTree::inorderPassToFT(AVLNode* t, int index)
{
	if (t == nullptr)
		return;
	inorder(t->left);
	Soldier a = t->data;
	/////////////////////////////////////////////////////////////big bug

	inorder(t->right);
}

void AVLTree::fillFTree(int index)
{
	inorderPassToFT(root,  index);
	return;
}

void AVLTree::inorderUpdate(AVLNode* t)
{
	if (t == nullptr)
		return;
	inorderUpdate(t->left);
	if (t->height == 0)
	{
		leaves.add_front(*t);
	}
	inorderUpdate(t->right);
}

void AVLTree::display()
{
	inorder(root);
	cout << endl;
	return;
}

bool AVLTree::isLeavesIsEmpty()
{
	if (leaves.isEmpty())
	{
		return true;
	}
	return false;
}

void AVLTree::updateLeavese()
{
	inorderUpdate(root);
	return;
}

Soldier AVLTree::popLeaf()
{
	int pop_power = leaves.Top().key;
	leaves.pop_back();
	Soldier s = this->removeSoldier(pop_power);
	return s;
}

Soldier AVLTree::findDefender(int attacker_power)
{
	AVLNode* temp = this->root;
	int def = abs(root->key - attacker_power);
	while (temp)
	{
		if (abs(temp->key - attacker_power) < def)
		{
			def = abs(temp->key - attacker_power);
		}
		else
			break;
		if (attacker_power > temp->key)
		{
			temp = temp->right;
		}
		else if (attacker_power < temp->key)
		{
			temp = temp->left;
		}
		else
		{
			return temp->data;
		}
	}

	return temp->data;

}

