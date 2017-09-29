/**
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of an iterator for the Generic B-Tree.
 */

#include <iterator>

#ifndef BTREE_ITERATOR_H
#define BTREE_ITERATOR_H

template <typename T>
class btree_iterator {
public:
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = T;
	using pointer = T*;
	using reference = T&;

	reference operator*() const;
	pointer operator->() const { return &(operator*()); }
	btree_iterator& operator++();
	btree_iterator& operator--();
	bool operator==(const btree_iterator& other) const;
	bool operator!=(const btree_iterator& other) const { return !operator==(other); }

	btree_iterator iterator();
private:
	//TODO
};

template <typename T>
btree_iterator<T> btree_iterator<T>::iterator() {
	//TODO
}

template <typename T>
class const_btree_iterator {
public:
	//TODO
private:
	//TODO
};

#endif
