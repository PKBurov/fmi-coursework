#include <iostream>
#include <list>
#include <queue>

// General Tree, Left Child - Right Sibling representation
template<typename T>
struct Node
{
	T data;
	Node<T> *child, *sibling;

	Node(const T& value) : data(value), child(NULL), sibling(NULL)
	{}
};

template<typename T>
Node<T>* addChild(Node<T>* node, const T& value)
{
	if (!node) return NULL;
	if (!node->child)
	{
		// единствено дете
		node->child = new Node<T>(value);
		return node->child;
	}
	else
	{
		// добавяме в дясно; тъсим посления възел, чието дясно е празно
		node = node->child;
		while (node->sibling)
		{
			node = node->sibling;
		}

		node->sibling = new Node<T>(value);
		return node->sibling;

		//return addSibling(node->child, value);
	}
}

template<typename T>
Node<T>* addSibling(Node<T>* node, const T& value)
{
	if (!node) return NULL;

	while (node->sibling)
	{
		node = node->sibling;
	}

	node->sibling = new Node<T>(value);
	return node->sibling;
}

template<typename T>
std::list< Node<T>* > findAllChildren(Node<T>* node)
{
	std::list< Node<T>* > children;
	if (!node || !node->child)
		return children;

	node = node->child;
	while (node)
	{
		children.push_back(node);
		node = node->sibling;
	}

	return children;
}

// print level by level
template<typename T>
void printTree(Node<T>* node)
{
	if (!node) return;

	std::queue< Node<T>* > levels;
	levels.push(node);

	while (!levels.empty())
	{
		size_t count = levels.size();
		while (count)
		{
			Node<T>*& currentNode = levels.front();
			levels.pop();

			std::cout << currentNode->data << " ";

			std::list< Node<T>* > children = findAllChildren(currentNode);
			for (Node<T>* child : children)
			{
				levels.push(child);
			}
			--count;
		}
		std::cout << std::endl;
	}

	//printTree(node->child);
	//printTree(node->sibling);
}

template<typename T>
void printKChild(Node<T>* node, size_t k)
{
	if (!node) return;

	Node<T>* child = node->child;
	size_t step = 1;
	while (child && step < k)
	{
		++step;
		child = child->sibling;
	}

	if (!child)
	{
		std::cout << "No " << k << "-th child!" << std::endl;
	}
	else
	{
		std::cout << k << "-th child is: " << child->data << std::endl;
	}
}

template<typename T>
void deleteTree(Node<T>*& node)
{
	if (!node) return;

	deleteTree(node->child);
	deleteTree(node->sibling);
	
	delete node;
	node = NULL;
}

template<typename T>
bool deleteNodeInTree(Node<T>*& root, const T& value)
{
	if (!root) return false;
	
	if (root->data == value)
	{
		deleteTree(root);
		return true;
	}

	return deleteNode(root, value);
}

template<typename T>
bool deleteNode(Node<T>*& parent, const T& value)
{
	if (!parent || !parent->child) return false;

	if (parent->child->data == value)
	{
		Node<T>* child = parent->child;
		Node<T>* forDel = child;

		parent->child = child->sibling;
		child->sibling = NULL;

		deleteTree(forDel);
		return true;
	}

	Node<T>* previous = parent->child;
	Node<T>* child = previous->sibling;

	// търсим стойността сред преките наследници
	bool found = false;
	while (child && child->data != value)
	{
		child = child->sibling;
		previous = previous->sibling;
	}

	if (child)
	{
		std::cout << child->data << " will be deleted!" << std::endl;
		previous->sibling = child->sibling;
		child->sibling = NULL;

		deleteTree(child);
		return true;
	}
	else
	{
		// няма го сред преките наследници
		previous = parent->child;
		while (previous)
		{
			if (deleteNode(previous, value))
				return true;

			previous = previous->sibling;
		}
	}

	return false;
}

template<typename T>
bool searchFor(Node<T>* node, const T& value)
{
	if (!node) return false;

	if (node->data == value) return true;
	
	return searchFor(node->child, value) || searchFor(node->sibling, value);
}

int main()
{
	Node<char>* root = new Node<char>('A');

	Node<char>* nodeB = addChild(root, 'B');
	Node<char>* nodeF = addChild(nodeB, 'F');
	Node<char>* nodeG = addSibling(nodeF, 'G');
	Node<char>* nodeH = addSibling(nodeF, 'H');
	
	Node<char>* nodeC = addChild(root, 'C');
	Node<char>* nodeD = addChild(root, 'D');

	Node<char>* nodeE = addSibling(nodeD, 'E');
	Node<char>* nodeI = addChild(nodeE, 'I');
	Node<char>* nodeJ = addChild(nodeE, 'J');

	printTree(root);

	std::cout << "\nChildren of A: ";
	std::list< Node<char>* > childrenA = findAllChildren(root);
	for (Node<char>* child : childrenA)
	{
		std::cout << child->data << ' ';
	}
	std::cout << std::endl;

	printKChild(root, 5);

	char value = 'K';
	std::cout << "Is " << value << " in the tree? " << std::boolalpha << searchFor(root, value) << std::endl;

	std::cout << "After deleting node " << value << ": " << std::endl;
	deleteNodeInTree(root, value);
	printTree(root);
	std::cout << std::endl;

	deleteTree(root);
}