#pragma once

#include <memory>
#include <vector>
#include <queue>
#include <stack>

namespace BinaryTreeSnippets
{
	template <typename T>
	class BinaryNode
	{
	public:
		T Value;
		std::shared_ptr<BinaryNode<T>> Left;
		std::shared_ptr<BinaryNode<T>> Right;

		BinaryNode() = delete;
		BinaryNode(const BinaryNode<T>& value) = delete;
		BinaryNode& operator=(const BinaryNode<T>& other) = delete;

		BinaryNode(T value) : Value(value), Left(nullptr), Right(nullptr) { }

		BinaryNode(BinaryNode<T>&& other)
		{
			if (&other != this)
			{
				Value = std::move(other.Value);
				Left = std::move(other.Left);
				Right = std::move(other.Right);
			}
		}

		BinaryNode& operator=(BinaryNode<T>&& other)
		{
			if (&other != this)
			{
				Value = std::move(other.Value);
				Left = std::move(other.Left);
				Right = std::move(other.Right);
			}
			return *this;
		}

		~BinaryNode() = default;
	};

	template <typename T>
	class BinaryTree
	{
	public:
		std::shared_ptr<BinaryNode<T>> Root;
		BinaryTree(const BinaryNode<T>& value) = delete;
		BinaryTree(const BinaryNode<T>&& value) = delete;
		BinaryTree& operator=(const BinaryNode<T>& other) = delete;
		BinaryTree(std::vector<T>&& initializer_list);
		BinaryTree& operator=(BinaryNode<T>&& other) = delete;
		~BinaryTree() = default;

#pragma warning(push)
#pragma warning(disable:4661)
		void printPreorder();
		void printPostorder();
		void printInorder();
		void traceDepthFirstSearch(T value);
		void traceBreadthFirstSearch(T value);
#pragma warning(pop)
	};

#pragma warning(push)
#pragma warning(disable:4661)
	template BinaryTree<char>;
#pragma warning(pop)

}