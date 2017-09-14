/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Interface for the Generic Directed Weighted Graph.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#ifndef GRAPH_H
#define GRAPH_H

namespace gdwg {
	template <typename N, typename E> class Graph {
	public:
		//default constructor
		Graph() = default;

		//copy constructor and move constructor
		Graph(const Graph& g);
		Graph(Graph&& g) noexcept;

		//copy assignment and move assignment
		Graph& operator=(const Graph& g);
		Graph& operator=(Graph&& g) noexcept;

		//standard Graph operations
		bool addNode(const N& val);
		bool addEdge(const N& src, const N& dst, const E& w);
		bool replace(const N& oldData, const N& newData);
		void mergeReplace(const N& oldData, const N& newData);
		void deleteNode(const N& val) noexcept;
		void deleteEdge(const N& src, const N& dst, const E& w) noexcept;
		void clear() noexcept;
		bool isNode(const N& val) const;
		bool isConnected(const N& src, const N& dst) const;
		void printNodes() const;
		void printEdges(const N& val) const;

		//iterator for enumerating Node values in the Graph
		void begin() const;
		bool end() const;
		void next() const;
		const N& value() const;
	private:
		class Node;
		class Edge;
		std::vector<std::shared_ptr<Node>> nodes; //a Graph is a vector of Nodes
		mutable typename std::vector<std::shared_ptr<Node>>::const_iterator current; //current Node (iterator)

		class Node {
		public:
			Node(N val) : data{val} { }
			N getData() const { return data; }
			void setData(const N& val) { data = val; }
			size_t outDegree() const { return edges.size(); }
			bool addEdge(const Edge& e);
			void showEdges() const;
			void deleteEdge(const N& dst, const E& weight) noexcept;
			std::vector<std::shared_ptr<Edge>> getEdges() const { return edges; }
			bool isEdge(const Node& n) const;

		private:
			N data; //a Node consists of its data of type N
			std::vector<std::shared_ptr<Edge>> edges; //and a vector of its outgoing Edges
		};

		class Edge {
		public:
			Edge(std::shared_ptr<Node> src, std::shared_ptr<Node> dst, E w) :
				src{src}, dst{dst}, weight{w} { }
			std::shared_ptr<Node> getDest() const { return dst; }
			E getWeight() const { return weight; }
			void setDest(const std::shared_ptr<Node>& node) { dst = node; }

		private:
			std::shared_ptr<Node> src; //an Edge consists of a source Node,
			std::shared_ptr<Node> dst; //a destination Node
			E weight; //and a weight of type E
		};

		auto getNode(const N& val) const;
	};

	#include "Graph.tem"
}

#endif
