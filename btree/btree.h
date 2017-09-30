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
	//make the iterator classes friends
	friend class btree_iterator<T>;
	friend class const_btree_iterator<const T>;

	//define some useful aliases for the iterators
	using iterator = btree_iterator<T>;
	using const_iterator = const_btree_iterator<const T>;

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
	 * The copy constructor and assignment operator.
	 * They allow us to pass around B-Trees by value.
	 * Although these operations are likely to be expensive
	 * they make for an interesting programming exercise.
	 * Implement these operations using value semantics and
	 * make sure they do not leak memory.
	 */

	/**
	 * Copy constructor
	 * Creates a new B-Tree as a copy of original.
	 *
	 * @param original a const lvalue reference to a B-Tree object
	 */
	btree(const btree<T>& original);

	/**
	 * Move constructor
	 * Creates a new B-Tree by "stealing" from original.
	 *
	 * @param original an rvalue reference to a B-Tree object
	 */
	btree(btree<T>&& original) noexcept;

	/**
	 * Copy assignment
	 * Replaces the contents of this object with a copy of rhs.
	 *
	 * @param rhs a const lvalue reference to a B-Tree object
	 */
	btree<T>& operator=(const btree<T>& rhs);

	/**
	 * Move assignment
	 * Replaces the contents of this object with the "stolen"
	 * contents of original.
	 *
	 * @param rhs a const reference to a B-Tree object
	 */
	btree<T>& operator=(btree<T>&& rhs) noexcept;

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
	iterator begin() const;

	/**
	 * Returns an iterator positioned at one past the last element.
	 */
	iterator end() const;

	/**
	 * Returns an iterator positioned at the last element.
	 */
	iterator rbegin() const;

	/**
	 * Returns an iterator positioned at one before the first element.
	 */
	iterator rend() const;

	/**
	 * Returns a const iterator positioned at the first element.
	 */
	const_iterator cbegin() const;

	/**
	 * Returns a const iterator positioned at one past the last element.
	 */
	const_iterator cend() const;

	/**
	 * Returns a const iterator positioned at the last element.
	 */
	const_iterator crbegin() const;

	/**
	 * Returns a const iterator positioned at one before the first element.
	 */
	const_iterator crend() const;

	/**
	 * Returns an iterator to the matching element, or whatever
	 * the non-const end() returns if the element could
	 * not be found.
	 *
	 * @param elem the client element we are trying to match. The elem,
	 *        if an instance of a true class, relies on the operator< and
	 *        and operator== methods to compare elem to elements already
	 *        in the btree. You must ensure that your class implements
	 *        these things, else code making use of btree<T>::find will
	 *        not compile.
	 * @return an iterator to the matching element, or whatever the
	 *         non-const end() returns if no such match was ever found.
	 */
	iterator find(const T& elem);

	/**
	 * Identical in functionality to the non-const version of find,
	 * save the fact that what's pointed to by the returned iterator
	 * is deemed as const and immutable.
	 *
	 * @param elem the client element we are trying to match.
	 * @return an iterator to the matching element, or whatever the
	 *         const end() returns if no such match was ever found.
	 */
	const_iterator find(const T& elem) const;

	/**
	 * Inserts the specified element into the btree.
	 *
	 * If the element does not already exist, it is inserted, effectively
	 * increasing the size of the btree by one and a pair containing and
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
	 * @param elem the element to be inserted
	 * @return a pair whose first field is an iterator positioned at
	 *         the matching element in the btree, and whose second field
	 *         stores true if and only if the element was actually added
	 */
	std::pair<iterator, bool> insert(const T& elem);

	/**
	 * Disposes of all internal resources, which includes
	 * the disposal of any client objects previously
	 * inserted using the insert operation.
	 * Check that your implementation does not leak memory! TODO
	 */
	~btree() = default;

private:
	class node;
	using node_ptr = std::unique_ptr<node>;
	node_ptr root{nullptr}; //a b-tree has a pointer to the root node
	size_t node_size; //and a value representing the maximum size of nodes

	class node {
	public:
		//make btree and the iterators friends
		friend class btree;
		friend class btree_iterator<T>;

		//constructor for a node
		node(const T& elem, node *parent, size_t position, size_t node_size);

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

		//and an index indicating which child of the parent this node is
		size_t position;

		//the maximum number of keys this node can hold
		size_t node_size;
	};

};

template <typename T>
btree<T>::node::node(const T& elem, node *p, size_t pos, size_t node_size) :
	parent{p}, position{pos}, node_size{node_size} {
	keys.insert(elem);
	children.resize(node_size + 1);
	std::fill(children.begin(), children.begin() + node_size + 1, nullptr);
}

template <typename T>
std::pair<typename btree<T>::iterator, bool> btree<T>::insert(const T& elem) {
	if (root == nullptr) {
		node n{elem, nullptr, 0, node_size};
		root = std::make_unique<node>(std::move(n));
		iterator it;
		return std::make_pair(it, true);
	} else {
		node *p = &*root;
		return root->insert(elem, p);
	}
}

template <typename T>
std::pair<typename btree<T>::iterator, bool>
btree<T>::node::insert(const T& elem, node *parent) {
	if (keys.size() < node_size) {
		//insert in current node if not yet full
		auto res = keys.insert(elem);
		iterator it;
		return std::make_pair(it, res.second);
	} else if (keys.find(elem) != keys.end()) {
		//do not re-insert element
		iterator it;
		return std::make_pair(it, false);
	} else {
		size_t i = 0;
		for (const auto& k: keys) {
			if (elem < k) break; //find the relevant child branch
			++i;
		}
		if (children[i] == nullptr) {
			//insert new node at child branch if not there
			node n{elem, parent, i, node_size};
			auto child = std::make_unique<node>(std::move(n));
			children[i] = std::move(child);
			iterator it;
			return std::make_pair(it, true);
		} else {
			//recursively find the right child branch
			return children[i]->insert(elem, &*children[i]);
		}
	}
	iterator it;
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
typename btree<T>::iterator btree<T>::begin() const {
	if (root == nullptr) {
		return iterator(&*root, 0, &*root);
	} else {
		//traverse until the left-most node
		node *curr = &*root;
		while (&*curr->children[0] != nullptr) {
			curr = &*curr->children[0];
		}
		return iterator(curr, 0, &*root);
	}
}

template <typename T>
typename btree<T>::iterator btree<T>::end() const {
	return btree<T>::iterator(nullptr, 0, &*root);
}

#endif
