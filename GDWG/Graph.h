/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Interface for the generic directed weighted graph.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

#ifndef GRAPH_H
#define GRAPH_H

namespace gdwg {
	template <typename N, typename E> class Graph {
	public:
		//default constructor
		Graph() = default;

		//copy constructor and move constructor
		Graph(const Graph& g) = default;
		Graph(Graph&& g) noexcept = default;

		//copy assignment and move assignment
		Graph& operator=(const Graph& g) = default;
		Graph& operator=(Graph&& g) noexcept = default;

		//standard Graph operations
		bool addNode(const N& val);
		bool addEdge(const N& src, const N& dst, const E& w);
		bool replace(const N& oldData, const N& newData);
		void mergeReplace(const N& oldData, const N& newData);
		void deleteNode(const N&) noexcept;
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

		class Node {
		public:
			Node(N val) : data{val} { }
			N getData() const { return data; }
			size_t outDegree() const { return edges.size(); }
		private:
			N data; //a Node consists of its data of type N
			std::vector<std::weak_ptr<Edge>> edges; //and a vector of its outgoing Edges
		};

		class Edge {
		public:

		private:
			Node src; //an Edge consists of a source Node,
			Node dest; //a destination Node
			E weight; //and a weight of type E
		};

	};

	//#include "Graph.tem"

	/*
	 * Adds a new Node with value val to the Graph. Returns true if the
	 * Node is added to the Graph and false if there is already a Node
	 * containing val in the Graph (with the Graph unchanged).
	 */
	template <typename N, typename E>
	bool Graph<N, E>::addNode(const N& val) {
		if (isNode(val) == false) {
			auto node = std::make_shared<Node>(val);
			nodes.push_back(node);
			std::sort(nodes.begin(), nodes.end(),
			[](const std::shared_ptr<Node>& lhs, const std::shared_ptr<Node>& rhs) {
				if (lhs->outDegree() != rhs->outDegree()) {
					return lhs->outDegree() < rhs->outDegree();
				} else {
					return lhs->getData() < rhs->getData();
				}
			});
			return true;
		} else {
			return false;
		}
	}

	/*
	 * Prints the data stored in all the Nodes in the graph, with one Node
	 * per line, starting from the Node with the smallest outdgree to the
	 * Node with the largest. If two Nodes have the same Edge count, then
	 * the one with the smaller Node value determined by the < operator is
	 * printed first.
	 */
	template <typename N, typename E>
	void Graph<N, E>::printNodes() const {
		for (const auto& node: nodes) {
			std::cout << node->getData() << "\n";
		}
	}

	/*
	 * Returns true if a Node with value val exists in the Graph
	 * and false otherwise.
	 */
	template <typename N, typename E>
	bool Graph<N, E>::isNode(const N& val) const {
		for (const auto& node: nodes) {
			//equality may not be defined on N
			if (!(node->getData() < val) && !(node->getData() > val)) {
				return true;
			}
		}
		return false;
	}

}

#endif
