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
#include "btree_iterator.h"

//forward declaration for the non-template friend function operator<<
template <typename T> class btree;
template <typename T>
std::ostream& operator<<(std::ostream& os, const btree<T>& tree);

template <typename T> class btree {
public:
	//make the iterator classes friends
	friend class btree_iterator<T>;
	friend class const_btree_iterator<T>;

	//define some useful aliases for the iterators
	using iterator = btree_iterator<T>;
	using const_iterator = const_btree_iterator<T>;

	/**
	 * Constructs an empty btree.
	 *
	 * The elements stored in the btree must
	 * have a well-defined zero-arg constructor,
	 * copy constructor, operator=, and destructor.
	 * The elements must also implement operator<
	 * and operator== for the purposes of ordering.
	 *
	 * @param max_elems the maximum number of elements
	 *        that can be stored in each btree node
	 */
	btree(size_t max_elems = 40) : node_size{max_elems} { }

	/**
	 * The copy constructor and  assignment operator.
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
	btree(const btree<T>& original) {
		//TODO
	}

	/**
	 * Move constructor
	 * Creates a new B-Tree by "stealing" from original.
	 *
	 * @param original an rvalue reference to a B-Tree object
	 */
	btree(btree<T>&& original) {
		//TODO
	}

	/**
	 * Copy assignment
	 * Replaces the contents of this object with a copy of rhs.
	 *
	 * @param rhs a const lvalue reference to a B-Tree object
	 */
	btree<T>& operator=(const btree<T>& rhs) {
		//TODO
		return *this;
	}

	/**
	 * Move assignment
	 * Replaces the contents of this object with the "stolen"
	 * contents of original.
	 *
	 * @param rhs a const reference to a B-Tree object
	 */
	btree<T>& operator=(btree<T>&& rhs) {
		//TODO;
		return *this;
	}

	/**
	 * Puts a breadth-first traversal of the B-Tree onto the output
	 * stream os. Elements must, in turn, support the output operator.
	 * Elements are separated by space. Should not output any newlines.
	 *
	 * @param os a reference to a C++ output stream
	 * @param tree a const reference to a B-Tree object
	 * @return a reference to os
	 */
	friend std::ostream& operator<<(std::ostream& os, const btree<T>& tree) {
		//TODO
		return os;
	}

	/**
	 * Returns an iterator positioned at the first element.
	 */
	iterator begin();

	/**
	 * Returns an iterator positioned at one past the last element.
	 */
	iterator end();

	/**
	 * Returns an iterator positioned at the last element.
	 */
	iterator rbegin();

	/**
	 * Returns an iterator positioned at one before the first element.
	 */
	iterator rend();

	/**
	 * Returns a const iterator positioned at the first element.
	 */
	const_iterator cbegin();

	/**
	 * Returns a const iterator positioned at one past the last element.
	 */
	const_iterator cend();

	/**
	 * Returns a const iterator positioned at the last element.
	 */
	const_iterator crbegin();

	/**
	 * Returns a const iterator positioned at one before the first element.
	 */
	const_iterator crend();

	/**
	 * Returns an iterator to the matching element, or whatever
	 * the non-const end() returns if the element could
	 * not be found.
	 *
	 * @param elem the client element we are trying to match.  The elem,
	 *        if an instance of a true class, relies on the operator< and
	 *        and operator== methods to compare elem to elements already
	 *        in the btree.  You must ensure that your class implements
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
	 * Operation which inserts the specified element
	 * into the btree if a matching element isn't already
	 * present.  In the event where the element truly needs
	 * to be inserted, the size of the btree is effectively
	 * increases by one, and the pair that gets returned contains
	 * an iterator to the inserted element and true in its first and
	 * second fields.
	 *
	 * If a matching element already exists in the btree, nothing
	 * is added at all, and the size of the btree stays the same.  The
	 * returned pair still returns an iterator to the matching element, but
	 * the second field of the returned pair will store false.  This
	 * second value can be checked to after an insertion to decide whether
	 * or not the btree got bigger.
	 *
	 * The insert method makes use of T's zero-arg constructor and
	 * operator= method, and if these things aren't available,
	 * then the call to btree<T>::insert will not compile.  The implementation
	 * also makes use of the class's operator== and operator< as well.
	 *
	 * @param elem the element to be inserted.
	 * @return a pair whose first field is an iterator positioned at
	 *         the matching element in the btree, and whose second field
	 *         stores true if and only if the element needed to be added
	 *         because no matching element was there prior to the insert call.
	 */
	std::pair<iterator, bool> insert(const T& elem) {
		node n{elem};
		root = std::make_unique<node>(std::move(n));
		iterator it;
		return std::make_pair(it, true);
	}

	/**
	 * Disposes of all internal resources, which includes
	 * the disposal of any client objects previously
	 * inserted using the insert operation.
	 * Check that your implementation does not leak memory!
	 */
	~btree() {
		//TODO
	}

private:
	class node;
	using node_ptr = std::unique_ptr<node>;
	node_ptr root; //a b-tree has a pointer to the root node
	size_t node_size; //and a value representing the maximum size of nodes

	class node {
	public:
		node(const T& elem) {
			keys.push_back(elem);
		}
	private:
		//a node consists of a collection of keys
		std::vector<T> keys;

		//and a vector of pointers to its children nodes
		std::vector<node_ptr> children;
	};

};

#endif
