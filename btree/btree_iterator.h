/**
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of an iterator for the Generic B-Tree.
 */

#include <iterator>

#ifndef BTREE_ITERATOR_H
#define BTREE_ITERATOR_H

//forward declaration to the btree
template <typename T> class btree;

template <typename T>
class btree_iterator {
public:
	//iterator aliases
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = T;
	using pointer = T*;
	using reference = T&;

	//iterator operations
	reference operator*() const;
	pointer operator->() const { return &(operator*()); }
	btree_iterator<T>& operator++();
	btree_iterator<T>& operator--();
	bool operator==(const btree_iterator<T>& other) const;
	bool operator!=(const btree_iterator<T>& other) const { return !operator==(other); }

	//iterator constructor
	btree_iterator() { } //TODO
	btree_iterator(typename btree<T>::node *cnode, typename btree<T>::node *root);
private:
	typename btree<T>::node *cnode; //current node in tree
	typename std::set<T>::iterator cval; //current value in node

	typename btree<T>::node *root; //root of btree
	//needed since the root has no parent
};

//constructor for an iterator
template <typename T>
btree_iterator<T>::btree_iterator(typename btree<T>::node *cnode, typename btree<T>::node *root) :
	cnode{cnode}, root{root} {
	cval = cnode.keys.begin();
}

//dereference operator for an iterator
template <typename T>
typename btree_iterator<T>::reference btree_iterator<T>::operator*() const {
	return *cval;
}

//increment operator for an iterator
template <typename T>
btree_iterator<T>& btree_iterator<T>::operator++() {
	//TODO
}

//decrement operator for an iterator
template <typename T>
btree_iterator<T>& btree_iterator<T>::operator--() {
	//TODO
}

//test equality of iterators
template <typename T>
bool btree_iterator<T>::operator==(const btree_iterator<T>& other) const {
	return *cval == *other.cval;
}

template <typename T>
class const_btree_iterator {
public:
	//TODO
private:
	//TODO
};

#endif
