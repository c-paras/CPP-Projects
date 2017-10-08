/**
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of an iterator for the Generic B-Tree.
 */

#include <iterator>
#include <type_traits>

#ifndef BTREE_ITERATOR_H
#define BTREE_ITERATOR_H

//forward declaration to the btree
template <typename T> class btree;

//const and non-const decider
template <bool tag, typename True, typename False>
struct Constness;

//specialization on true, i.e. const type
template <typename True, typename False>
struct Constness<true, True, False> {
	using type = True;
};

//specialization on false, i.e. non-const type
template <typename True, typename False>
struct Constness<false, True, False> {
	using type = False;
};

template <typename T, bool isconst = false>
class btree_iterator {
public:
	//iterator aliases
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type = typename Constness<isconst, const T, T>::type;
	using reference = typename Constness<isconst, const T&, T&>::type;
	using pointer = typename Constness<isconst, const T*, T*>::type;

	//iterator constructors
	btree_iterator<T, isconst>() { }
	btree_iterator<T, isconst>(typename btree<T>::node *cnode, size_t cpos, typename btree<T>::node *root);

	//iterator operations
	reference operator*() const;
	pointer operator->() const { return &(operator*()); }
	btree_iterator<T, isconst>& operator++(); //prefix
	btree_iterator<T, isconst>& operator--();
	btree_iterator<T, isconst> operator++(int); //postfix
	btree_iterator<T, isconst> operator--(int);
	bool operator==(const btree_iterator<T, isconst>& other) const;
	bool operator!=(const btree_iterator<T, isconst>& other) const { return !operator==(other); }

	//casting operator
	using const_btree_iterator = btree_iterator<T, true>;
	operator const_btree_iterator() { return btree_iterator<T, true>(this->cnode, this->cpos, this->root); }
private:
	typename btree<T>::node *cnode; //current node in tree
	typename std::set<T>::iterator cval; //current value in node
	size_t cpos; //current position in node
	typename btree<T>::node *root; //root of btree - needed since the root has no parent

	void moveToCpos();
	void traverseToRightMostChild();
};

//constructor for an iterator
template <typename T, bool isconst>
btree_iterator<T, isconst>::btree_iterator(typename btree<T>::node *cnode, size_t cpos,
typename btree<T>::node *root) : cnode{cnode}, cpos{cpos}, root{root} {
	if (cnode != nullptr) {
		//set cval to the first value in the node regardless of the cpos
		//but only if not called from an empty tree or from end()
		cval = cnode->keys.begin();
	}
}

//dereference operator for an iterator
template <typename T, bool isconst>
typename btree_iterator<T, isconst>::reference btree_iterator<T, isconst>::operator*() const {
	return const_cast<T&>(*cval);
}

//move to current position specified by cpos in the current node (cnode)
template <typename T, bool isconst>
void btree_iterator<T, isconst>::moveToCpos() {
	size_t i = 0;
	T val{};
	for (const auto& k: cnode->keys) {
		if (i == cpos) {
			val = k;
			break;
		}
		++i;
	}
	cval = cnode->keys.find(val);
}

//prefix increment operator for an iterator
template <typename T, bool isconst>
btree_iterator<T, isconst>& btree_iterator<T, isconst>::operator++() {
	++cpos; //go to next value position in current node

	if (&*cnode->children[cpos] == nullptr) {
		//move to next value in node if no child node in between
		++cval;
		if (cval == cnode->keys.end()) {

			//go to "upper-most" parent node if no more values in this node
			while (cnode->parent != nullptr) {
				cpos = cnode->position;
				cnode = &*cnode->parent;
				//keep moving up parent nodes until a node is found such that
				//this node is a non-far right child - i.e. any left child
				if (cpos != cnode->keys.size()) break;
			}

			//if the last value in the node corresponds to the last position
			//in the "upper-most" parent, then that value was the last in the
			//in-order traversal of the btree
			if (cpos >= cnode->keys.size()) {
				cnode = nullptr;
				return *this;
			}

			//move to correct value in the node - i.e. whatever cpos is
			moveToCpos();
		}
	} else {
		//move to the child node and then traverse to the left-most node
		cnode = &*cnode->children[cpos];
		while (&*cnode->children[0] != nullptr) {
			cnode = &*cnode->children[0];
		}
		cval = cnode->keys.begin();
		cpos = 0;
	}
	return *this;
}

//traverse to the right-most child node from cnode
template <typename T, bool isconst>
void btree_iterator<T, isconst>::traverseToRightMostChild() {
	//traverse to the right-most child node from cnode
	while (&*cnode->children[cnode->keys.size()] != nullptr) {
		cnode = &*cnode->children[cnode->keys.size()];
	}

	//then go to the last value in that node
	cval = cnode->keys.end();
	--cval;
	cpos = cnode->keys.size();
}

//prefix decrement operator for an iterator
template <typename T, bool isconst>
btree_iterator<T, isconst>& btree_iterator<T, isconst>::operator--() {
	//go to last node & value in tree if at end()
	if (*this == cnode->tree->end()) {
		cnode = root;
		traverseToRightMostChild();
		return *this;
	}

	--cpos; //go to previous value position in current node

	if (cpos < 0 || &*cnode->children[cpos] == nullptr) {
		//move to previous value in node if no child node in between
		if (cval != cnode->keys.begin()) {
			//only move to the left if possible
			--cval;
		}
		if (cpos <= 0) {
			//go to "upper-most" parent node if no more values in this node
			while (cnode->parent != nullptr) {
				cpos = cnode->position;
				cnode = &*cnode->parent;
				//keep moving up parent nodes until a node is found such that
				//this node is a far left child
				if (cpos != 0) break;
			}

			//if the last value in the node corresponds to the first position
			//in the "upper-most" parent, then that value was the last in the
			//reverse in-order traversal of the btree
			if (cpos <= 0) {
				*this = cnode->tree->begin();
				return *this;
			}

			//move to correct value in the node - i.e. whatever cpos is
			//need to offset cpos by 1 since the traversal goes back to the previous node
			cpos--;
			moveToCpos();
			cpos++;
		}
	} else {
		//move to the child node and then traverse to the right-most node & value
		cnode = &*cnode->children[cpos];
		traverseToRightMostChild();
	}
	return *this;
}

//postfix increment operator for an iterator
template <typename T, bool isconst>
btree_iterator<T, isconst> btree_iterator<T, isconst>::operator++(int) {
	btree_iterator<T, isconst> temp = *this;
	++*this;
	return temp;
}

//postfix decrement operator for an iterator
template <typename T, bool isconst>
btree_iterator<T, isconst> btree_iterator<T, isconst>::operator--(int) {
	btree_iterator<T, isconst> temp = *this;
	--*this;
	return temp;
}

//test equality of iterators
template <typename T, bool isconst>
bool btree_iterator<T, isconst>::operator==(const btree_iterator<T, isconst>& other) const {
	if (cnode == nullptr && other.cnode == nullptr) {
		return true;
	} else {
		return cval == other.cval;
	}
}

#endif
