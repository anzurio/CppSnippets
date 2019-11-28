#include "BinaryTreeSnippets.h"
#include <iostream>
using namespace BinaryTreeSnippets;

template <typename T>
void depthFirstSearch(const std::shared_ptr<BinaryNode<T>>& headPtr, T value)
{
	std::stack<std::shared_ptr<BinaryNode<T>>> stack;
	stack.push(headPtr);

	while (!stack.empty())
	{
		auto current = stack.top();
		stack.pop();
		if (current->Value == value)
		{
			std::cout << current->Value;
		}
		else
		{
			std::cout << current->Value << " -> ";
		}

		if (current->Right != nullptr)
		{
			stack.push(current->Right);
		}
		if (current->Left != nullptr)
		{
			stack.push(current->Left);
		}
	}
	std::cout << "End";
}

template <typename T>
void breadthFirstSearch(const std::shared_ptr<BinaryNode<T>>& headPtr, T value)
{
	std::queue<std::shared_ptr<BinaryNode<T>>> queue;
	queue.push(headPtr);

	while (!queue.empty())
	{
		auto current = queue.front();
		queue.pop();
		if (current->Value == value)
		{
			std::cout << current->Value;
		}
		else
		{
			std::cout << current->Value << " -> ";
		}

		if (current->Left != nullptr)
		{
			queue.push(current->Left);
		}
		if (current->Right != nullptr)
		{
			queue.push(current->Right);
		}
	}
	std::cout << "End";
}

template<typename T>
void preorderTraversal(const std::shared_ptr<BinaryNode<T>>& headPtr)
{
	if (headPtr != nullptr)
	{
		std::cout << headPtr->Value << ' ';
		preorderTraversal(headPtr->Left);
		preorderTraversal(headPtr->Right);
	}
}

template<typename T>
void inorderTraversal(const std::shared_ptr<BinaryNode<T>>& headPtr)
{
	if (headPtr != nullptr)
	{
		inorderTraversal(headPtr->Left);
		std::cout << headPtr->Value << ' ';
		inorderTraversal(headPtr->Right);
	}
}

template<typename T>
void postorderTraversal(const std::shared_ptr<BinaryNode<T>>& headPtr)
{
	if (headPtr != nullptr)
	{
		postorderTraversal(headPtr->Left);
		postorderTraversal(headPtr->Right);
		std::cout << headPtr->Value << ' ';
	}
}

template<typename T>
std::shared_ptr<BinaryNode<T>> constructBinaryTree(const std::vector<T>& v)
{
	std::vector<std::shared_ptr<BinaryNode<T>>> queue;
	using size_type = typename decltype(queue)::size_type;
	for (auto value : v)
	{
		queue.emplace_back(std::make_shared<BinaryNode<T>>(value));
	}

	auto headPtr = queue[0];


	for (size_type i = 0; i < queue.size(); i++)
	{
		if ((i * 2) + 1 < queue.size())
		{
			queue[i]->Left = queue[(i * 2) + 1];
		}
		if ((i * 2) + 2 < queue.size())
		{
			queue[i]->Right = queue[(i * 2) + 2];
		}
	}

	return headPtr;
}

template<typename T>
BinaryTreeSnippets::BinaryTree<T>::BinaryTree(std::vector<T>&& initializer_list) : Root(constructBinaryTree(initializer_list))
{
}

template<typename T>
void BinaryTreeSnippets::BinaryTree<T>::printPreorder()
{
	preorderTraversal(Root);
	std::cout << std::endl;
}

template<typename T>
void BinaryTreeSnippets::BinaryTree<T>::printPostorder()
{
	postorderTraversal(Root);
	std::cout << std::endl;
}

template<typename T>
void BinaryTreeSnippets::BinaryTree<T>::printInorder()
{
	inorderTraversal(Root);
	std::cout << std::endl;
}

template<typename T>
void BinaryTreeSnippets::BinaryTree<T>::traceDepthFirstSearch(T value)
{
	depthFirstSearch(Root, value);
	std::cout << std::endl;
}

template<typename T>
void BinaryTreeSnippets::BinaryTree<T>::traceBreadthFirstSearch(T value)
{
	breadthFirstSearch(Root, value);
	std::cout << std::endl;
}
