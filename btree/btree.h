/**
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of a Generic B-Tree.
 *
 * The btree is a linked structure which operates much like
 * a binary search tree, save the fact that multiple client
 * elements are stored in a single node. Whereas a single element
 * would partition the tree into two ordered subtrees, a node
 * that stores m client elements partition the tree
 * into m + 1 sorted subtrees.
 */

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <cstddef>
#include <utility>
#include <vector>
#include <memory>
#include <set>
#include <queue>
#include <algorithm>
#include "btree_iterator.h"

//forward declaration for the non-template friend function operator<<
template <typename T> class btree;
template <typename T>
std::ostream& operator<<(std::ostream& os, const btree<T>& tree);

template <typename T> class btree {
public:
	//define some useful aliases for the iterators
	using iterator = btree_iterator<T>;
	using const_iterator = btree_iterator<T, true>;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	//make the iterator classes friends
	friend iterator;
	friend const_iterator;
	friend reverse_iterator;
	friend const_reverse_iterator;

	/**
	 * Constructs an empty btree.
	 *
	 * The elements stored in the btree must
	 * have a well-defined zero-arg constructor,
	 * copy constructor, operator= and destructor.
	 * The elements must also implement operator<
	 * and operator== for the purposes of ordering.
	 *
	 * @param max_elems the maximum number of elements
	 *        that can be stored in each btree node
	 */
	btree(size_t max_elems = 40) : node_size{max_elems} { }

	/**
	 * Copy constructor.
	 * Creates a new btree as a copy of original.
	 *
	 * @param original a const lvalue reference to a btree object
	 */
	btree(const btree<T>& original);

	/**
	 * Move constructor.
	 * Creates a new btree by "stealing" from original.
	 *
	 * @param original an rvalue reference to a btree object
	 */
	btree(btree<T>&& original) noexcept = default;

	/**
	 * Copy assignment operator.
	 * Replaces the contents of this object with a copy of rhs.
	 *
	 * @param rhs a const lvalue reference to a btree object
	 */
	btree<T>& operator=(const btree<T>& rhs);

	/**
	 * Move assignment operator.
	 * Replaces the contents of this object with the "stolen"
	 * contents of rhs.
	 *
	 * @param rhs a const reference to a btree object
	 */
	btree<T>& operator=(btree<T>&& rhs) noexcept = default;

	/**
	 * Puts a breadth-first traversal of the btree onto the output
	 * stream os. Elements must, in turn, support the output operator.
	 * Elements are separated by spaces. No newline is output.
	 *
	 * @param os a reference to an output stream
	 * @param tree a const reference to a btree
	 * @return a reference to os
	 */
	friend std::ostream& operator<<<T>(std::ostream& os, const btree<T>& tree);

	/**
	 * Returns an iterator positioned at the first element.
	 */
	iterator begin();

	/**
	 * Returns an iterator positioned at one past the last element.
	 */
	iterator end() { return iterator(nullptr, 0, &*root); }

	/**
	 * Returns a const iterator positioned at the first element.
	 */
	const_iterator begin() const;

	/**
	 * Returns a const iterator positioned at one past the last element.
	 */
	const_iterator end() const { return const_iterator(nullptr, 0, &*root); }

	/**
	 * Returns a const iterator positioned at the first element.
	 */
	const_iterator cbegin() const;

	/**
	 * Returns a const iterator positioned at one past the last element.
	 */
	const_iterator cend() const { return const_iterator(nullptr, 0, &*root); }

	/**
	 * Returns an iterator positioned at the last element.
	 */
	auto rbegin() { return std::reverse_iterator<iterator>(end()); }

	/**
	 * Returns an iterator positioned at one before the first element.
	 */
	auto rend() { return std::reverse_iterator<iterator>(begin()); }

	/**
	 * Returns a const iterator positioned at the last element.
	 */
	auto crbegin() { return std::reverse_iterator<const_iterator>(cend()); }

	/**
	 * Returns a const iterator positioned at one before the first element.
	 */
	auto crend() { return std::reverse_iterator<const_iterator>(cbegin()); }

	/**
	 * Returns an iterator to the matching element, or whatever
	 * the non-const end() returns if the element could
	 * not be found.
	 *
	 * Requires T's operator< and operator== methods to be defined
	 * so that elem can be compared to elements in the btree.
	 *
	 * @param elem the client element to search for
	 * @return an iterator to the matching element, or whatever the
	 *         non-const end() returns if no such match is found
	 */
	iterator find(const T& elem);

	/**
	 * Identical in functionality to the non-const version of find,
	 * save the fact that what's pointed to by the returned iterator
	 * is deemed as const and immutable.
	 *
	 * @param elem the client element to search for
	 * @return an iterator to the matching element, or whatever the
	 *         const end() returns if no such match is found
	 */
	const_iterator find(const T& elem) const;

	/**
	 * Inserts the specified element into the btree.
	 *
	 * If the element does not already exist, it is inserted, effectively
	 * increasing the size of the btree by one and a pair containing an
	 * iterator to the inserted element and true is returned.
	 *
	 * If a matching element already exists in the btree, nothing
	 * is added at all, and the size of the btree stays the same. The
	 * returned pair still contains an iterator to the matching element
	 * but the second field of the returned pair will store false.
	 *
	 * Requires T's zero-arg constructor, operator= method, operator==
	 * method and operator< method to be defined.
	 *
	 * @param elem the element to be inserted in the btree
	 * @return a pair whose first field is an iterator positioned at
	 *         the matching element in the btree, and whose second field
	 *         stores true if and only if the element was actually added
	 */
	std::pair<iterator, bool> insert(const T& elem);

	/**
	 * Disposes of all internal resources, which includes
	 * the disposal of any client objects previously
	 * inserted using the insert operation.
	 */
	~btree() = default;

private:
	class node;
	using node_ptr = std::unique_ptr<node>;
	node_ptr root{nullptr}; //a btree has a pointer to the root node
	size_t node_size; //and a value representing the maximum size of nodes

	//traverse from the root to the start of the left-most child node
	auto traverseToLeftMostChild() const;

	class node {
	public:
		//make btree and the iterators friends
		friend class btree;
		friend btree::iterator;
		friend btree::const_iterator;
		friend btree::reverse_iterator;
		friend btree::const_reverse_iterator;

		//constructor for a node
		node(const T& elem, node *parent, size_t position, btree *tree);

		//inserts elem into the appropriate node of the btree
		std::pair<iterator, bool> insert(const T& elem, node *parent);

		//displays the keys in the node and its children in level order
		void show();

	private:
		//a node consists of a collection of keys
		std::set<T> keys;

		//a vector of pointers to its children nodes
		std::vector<node_ptr> children;

		//a (non-owning) pointer to its parent node
		node *parent;

		//an index indicating which child of the parent this node is
		size_t position;

		//and a (non-owning) pointer to the btree
		btree *tree;
	};

};

template <typename T>
btree<T>::node::node(const T& elem, node *parent, size_t position, btree *tree) :
	parent{parent}, position{position}, tree{tree} {
	keys.insert(elem);
	children.resize(tree->node_size + 1);
	std::fill(children.begin(), children.begin() + tree->node_size + 1, nullptr);
}

template <typename T>
std::pair<typename btree<T>::iterator, bool> btree<T>::insert(const T& elem) {
	if (root == nullptr) {
		node n{elem, nullptr, 0, this};
		root = std::make_unique<node>(std::move(n));
		iterator it(&*root, 0, &*root);
		return std::make_pair(it, true);
	} else {
		node *p = &*root;
		return root->insert(elem, p);
	}
}

template <typename T>
std::pair<typename btree<T>::iterator, bool>
btree<T>::node::insert(const T& elem, node *parent) {
	if (keys.size() < tree->node_size) {
		//insert in current node if not yet full
		auto res = keys.insert(elem);
		return std::make_pair(tree->find(elem), res.second);
	} else if (keys.find(elem) != keys.end()) {
		//do not re-insert element
		return std::make_pair(tree->find(elem), false);
	} else {
		size_t i = 0;
		for (const auto& k: keys) {
			if (elem < k) break; //find the relevant child branch
			++i;
		}
		if (children[i] == nullptr) {
			//insert new node at child branch if not there
			node n{elem, parent, i, tree};
			auto child = std::make_unique<node>(std::move(n));
			children[i] = std::move(child);
			return std::make_pair(tree->find(elem), true);
		} else {
			//recursively find the right child branch
			return children[i]->insert(elem, &*children[i]);
		}
	}
	iterator it(nullptr, 0, nullptr);
	return std::make_pair(it, false);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const btree<T>& tree) {
	if (tree.root != nullptr) {
		tree.root->show();
	}
	return os;
}

template <typename T>
void btree<T>::node::show() {
	std::queue<node*> q;
	node *n = this;
	q.push(n);
	bool first = true;
	while (!q.empty()) {
		auto values = q.front()->keys;

		//enqueue all children nodes of the current node
		for (const auto& child: q.front()->children) {
			n = &*child;
			if (child != nullptr) q.push(n);
		}
		q.pop();

		//print all values in the current node
		for (const auto& v: values) {
			if (first == true) {
				first = false;
				std::cout << v;
			} else {
				std::cout << " " << v;
			}
		}
	}
}

template <typename T>
auto btree<T>::traverseToLeftMostChild() const {
	if (root == nullptr) {
		return std::pair<node*, node*>(&*root, &*root);
	} else {
		//traverse until the left-most node
		node *curr = &*root;
		while (&*curr->children[0] != nullptr) {
			curr = &*curr->children[0];
		}
		return std::pair<node*, node*>(curr, &*root);
	}
}

template <typename T>
typename btree<T>::iterator btree<T>::begin() {
	auto ret = traverseToLeftMostChild();
	return iterator(ret.first, 0, ret.second);
}

template <typename T>
typename btree<T>::const_iterator btree<T>::begin() const {
	auto ret = traverseToLeftMostChild();
	return const_iterator(ret.first, 0, ret.second);
}

template <typename T>
typename btree<T>::const_iterator btree<T>::cbegin() const {
	auto ret = traverseToLeftMostChild();
	return const_iterator(ret.first, 0, ret.second);
}

template <typename T>
typename btree<T>::iterator btree<T>::find(const T& elem) {
	return std::find_if(this->begin(), this->end(), [&elem] (const T& curr) {
		return curr == elem;
	});
}

template <typename T>
typename btree<T>::const_iterator btree<T>::find(const T& elem) const {
	return std::find_if(this->begin(), this->end(), [&elem] (const T& curr) {
		return curr == elem;
	});
}

#endif
