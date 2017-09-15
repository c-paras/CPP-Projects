/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Test case for the Generic Directed Weighted Graph.
 */

#include <iostream>
#include <string>
#include "Graph.h"

int main(int argc, char *argv[]) {

	//enable printing of booleans as "true" and "false"
	std::cout << std::boolalpha;

	//create some strings and ints
	int a = 3;
	int b = (int)5.8;
	int c = static_cast<int>(14.4);
	std::string x{"hello 1"};
	std::string y{std::move("world 2")};
	std::string z = "test 3";

	//create a graph: nodes contain strings and edges have integer weights
	std::cout << "Create an empty graph:" << std::endl;
	gdwg::Graph<std::string, int> g1;
	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	try {
		g1.printEdges(x);
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		g1.printEdges(y);
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		g1.printEdges(z);
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	//add some nodes
	std::cout << "Add some nodes:" << std::endl;
	std::cout << g1.addNode(x) << std::endl;
	std::cout << g1.addNode(y) << std::endl;
	std::cout << g1.addNode(z) << std::endl;
	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(y);
	g1.printEdges(z);

	//check that the nodes are in the graph
	std::cout << "Check the nodes are in the graph:" << std::endl;
	std::cout << g1.isNode(x) << std::endl;
	std::cout << g1.isNode(y) << std::endl;
	std::cout << g1.isNode(z) << std::endl;

	//check for nodes that are not in the graph
	std::cout << "Check for nodes that are not in the graph:" << std::endl;
	std::cout << g1.isNode("not in graph") << std::endl;
	std::cout << g1.isNode("unknown node") << std::endl;
	std::cout << g1.isNode("fake node") << std::endl;

	//add duplicate nodes - graph should be unchanged
	std::cout << "Add duplicate nodes:" << std::endl;
	std::cout << g1.addNode(x) << std::endl;
	std::cout << g1.addNode(y) << std::endl;
	std::cout << g1.addNode(z) << std::endl;
	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(y);
	g1.printEdges(z);

	//check that the nodes are still in the graph
	std::cout << "Check the nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode(x) << std::endl;
	std::cout << g1.isNode(y) << std::endl;
	std::cout << g1.isNode(z) << std::endl;

	//add some edges
	std::cout << "Add some edges:" << std::endl;
	std::cout << g1.addEdge(x, y, a) << std::endl;
	std::cout << g1.addEdge(x, y, b) << std::endl;
	std::cout << g1.addEdge(x, y, c) << std::endl;
	std::cout << g1.addEdge(y, x, -55) << std::endl;
	std::cout << g1.addEdge(y, x, 290) << std::endl;
	std::cout << g1.addEdge(y, z, -824) << std::endl;
	std::cout << g1.addEdge(y, z, 66) << std::endl;
	std::cout << g1.addEdge(y, z, 0) << std::endl;
	std::cout << g1.addEdge(z, x, 1) << std::endl;
	std::cout << g1.addEdge(z, x, 66) << std::endl;
	std::cout << g1.addEdge(z, y, 290) << std::endl;
	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(y);
	g1.printEdges(z);

	//check that the edges exist
	std::cout << "Check that the edges exist:" << std::endl;
	std::cout << g1.isConnected(x, y) << std::endl;
	std::cout << g1.isConnected(y, x) << std::endl;
	std::cout << g1.isConnected(y, z) << std::endl;
	std::cout << g1.isConnected(z, x) << std::endl;
	std::cout << g1.isConnected(z, y) << std::endl;

	//check for edges that are not in the graph
	std::cout << "Check for edges that are not in the graph:" << std::endl;
	std::cout << g1.isConnected(x, z) << std::endl;
	std::cout << g1.isConnected(x, x) << std::endl;
	std::cout << g1.isConnected(y, y) << std::endl;
	std::cout << g1.isConnected(z, z) << std::endl;

	//call isConnected with invalid arguments
	std::cout << "Call isConnected with invalid arguments:" << std::endl;
	try {
		std::cout << g1.isConnected("hello 1", "world") << std::endl;
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << g1.isConnected("hello", "world 2") << std::endl;
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << g1.isConnected("fake 1", "fake 2") << std::endl;
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	//add duplicate edges - graph should be unchanged
	std::cout << "Add duplicate edges:" << std::endl;
	std::cout << g1.addEdge(x, y, a) << std::endl;
	std::cout << g1.addEdge(x, y, b) << std::endl;
	std::cout << g1.addEdge(x, y, c) << std::endl;
	std::cout << g1.addEdge(y, x, -55) << std::endl;
	std::cout << g1.addEdge(y, x, 290) << std::endl;
	std::cout << g1.addEdge(y, z, -824) << std::endl;
	std::cout << g1.addEdge(y, z, 66) << std::endl;
	std::cout << g1.addEdge(y, z, 0) << std::endl;
	std::cout << g1.addEdge(z, x, 1) << std::endl;
	std::cout << g1.addEdge(z, x, 66) << std::endl;
	std::cout << g1.addEdge(z, y, 290) << std::endl;
	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(y);
	g1.printEdges(z);

	//check that the edges still exist
	std::cout << "Check that the edges still exist:" << std::endl;
	std::cout << g1.isConnected(x, y) << std::endl;
	std::cout << g1.isConnected(y, x) << std::endl;
	std::cout << g1.isConnected(y, z) << std::endl;
	std::cout << g1.isConnected(z, x) << std::endl;
	std::cout << g1.isConnected(z, y) << std::endl;

	//add some invalid edges
	std::cout << "Add some invalid edges:" << std::endl;
	try {
		g1.addEdge("hello 1", "non-existant node", 99);
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		g1.addEdge("non-existant node", "world 2", 36);
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		g1.addEdge("non-existant node 1", "non-existant node 2", -324);
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	//add some more nodes to check ordering
	std::cout << "Add some more nodes to check ordering:" << std::endl;
	std::cout << g1.addNode("zzzz") << std::endl;
	std::cout << g1.addNode("10") << std::endl;
	std::cout << g1.addNode("1") << std::endl;
	std::cout << g1.addNode("5") << std::endl;
	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(y);
	g1.printEdges(z);
	g1.printEdges("zzzz");
	g1.printEdges("10");
	g1.printEdges("1");
	g1.printEdges("5");

	//check that all nodes are in the graph
	std::cout << "Check that all nodes are in the graph:" << std::endl;
	std::cout << g1.isNode("hello 1") << std::endl;
	std::cout << g1.isNode("world 2") << std::endl;
	std::cout << g1.isNode("test 3") << std::endl;
	std::cout << g1.isNode("zzzz") << std::endl;
	std::cout << g1.isNode("10") << std::endl;
	std::cout << g1.isNode("1") << std::endl;
	std::cout << g1.isNode("5") << std::endl;

	//add some more edges to check ordering
	std::cout << "Add some more edges to check ordering:" << std::endl;

	//move 1 and 5 after 10 and zzzz in node ordering
	std::cout << g1.addEdge("1", "10", 0) << std::endl;
	std::cout << g1.addEdge("5", "10", -25) << std::endl;

	//add some edges with the same weights to check secondary sort
	std::cout << g1.addEdge("test 3", "hello 1", 290) << std::endl;
	std::cout << g1.addEdge("test 3", "world 2", 66) << std::endl;
	std::cout << g1.addEdge("test 3", "world 2", 1) << std::endl;
	std::cout << g1.addEdge("1", "zzzz", 0) << std::endl;
	std::cout << g1.addEdge("5", "zzzz", -25) << std::endl;
	std::cout << g1.addEdge("world 2", "hello 1", -824) << std::endl;
	std::cout << g1.addEdge("world 2", "hello 1", 0) << std::endl;
	std::cout << g1.addEdge("world 2", "test 3", 290) << std::endl;

	//move test 3 after world 2 in node ordering
	std::cout << g1.addEdge("test 3", "hello 1", -128) << std::endl;
	std::cout << g1.addEdge("test 3", "hello 1", -129) << std::endl;
	std::cout << g1.addEdge("test 3", "hello 1", -130) << std::endl;

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(y);
	g1.printEdges(z);
	g1.printEdges("zzzz");
	g1.printEdges("10");
	g1.printEdges("1");
	g1.printEdges("5");

	//check that all nodes are still in the graph
	std::cout << "Check that all nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode("hello 1") << std::endl;
	std::cout << g1.isNode("world 2") << std::endl;
	std::cout << g1.isNode("test 3") << std::endl;
	std::cout << g1.isNode("zzzz") << std::endl;
	std::cout << g1.isNode("10") << std::endl;
	std::cout << g1.isNode("1") << std::endl;
	std::cout << g1.isNode("5") << std::endl;

	//check that all edges are in the graph
	std::cout << "Check that all edges are in the graph:" << std::endl;
	std::cout << g1.isConnected(x, y) << std::endl;
	std::cout << g1.isConnected(y, x) << std::endl;
	std::cout << g1.isConnected(y, z) << std::endl;
	std::cout << g1.isConnected(z, x) << std::endl;
	std::cout << g1.isConnected(z, y) << std::endl;
	std::cout << g1.isConnected("1", "10") << std::endl;
	std::cout << g1.isConnected("5", "10") << std::endl;
	std::cout << g1.isConnected("1", "zzzz") << std::endl;
	std::cout << g1.isConnected("5", "zzzz") << std::endl;

	//delete some nodes not in the graph
	std::cout << "Delete some nodes not in the graph:" << std::endl;
	g1.deleteNode("");
	g1.deleteNode("aaaa");
	g1.deleteNode("bbbb");
	g1.deleteNode("cccc");

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(y);
	g1.printEdges(z);
	g1.printEdges("zzzz");
	g1.printEdges("10");
	g1.printEdges("1");
	g1.printEdges("5");

	//delete some edges not in the graph
	std::cout << "Delete some edges not in the graph:" << std::endl;
	g1.deleteEdge("aaa", "bbb", 5);
	g1.deleteEdge(x, x, 5);
	g1.deleteEdge(y, y, 5);
	g1.deleteEdge(z, z, 5);
	g1.deleteEdge(z, x, 291);
	g1.deleteEdge(z, x, 289);
	g1.deleteEdge(y, x, 289);
	g1.deleteEdge(y, x, 291);

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(y);
	g1.printEdges(z);
	g1.printEdges("zzzz");
	g1.printEdges("10");
	g1.printEdges("1");
	g1.printEdges("5");

	//check that all nodes are still in the graph
	std::cout << "Check that all nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode("hello 1") << std::endl;
	std::cout << g1.isNode("world 2") << std::endl;
	std::cout << g1.isNode("test 3") << std::endl;
	std::cout << g1.isNode("zzzz") << std::endl;
	std::cout << g1.isNode("10") << std::endl;
	std::cout << g1.isNode("1") << std::endl;
	std::cout << g1.isNode("5") << std::endl;

	//check that all edges are in the graph
	std::cout << "Check that all edges are in the graph:" << std::endl;
	std::cout << g1.isConnected(x, y) << std::endl;
	std::cout << g1.isConnected(y, x) << std::endl;
	std::cout << g1.isConnected(y, z) << std::endl;
	std::cout << g1.isConnected(z, x) << std::endl;
	std::cout << g1.isConnected(z, y) << std::endl;
	std::cout << g1.isConnected("1", "10") << std::endl;
	std::cout << g1.isConnected("5", "10") << std::endl;
	std::cout << g1.isConnected("1", "zzzz") << std::endl;
	std::cout << g1.isConnected("5", "zzzz") << std::endl;

	//delete some edges from the graph
	std::cout << "Delete some edges from the graph:" << std::endl;
	g1.deleteEdge(x, y, 3);
	g1.deleteEdge(x, y, 5);
	g1.deleteEdge(x, y, 14);
	g1.deleteEdge(z, x, -129);
	g1.deleteEdge("1", "zzzz", 0);

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(y);
	g1.printEdges(z);
	g1.printEdges("zzzz");
	g1.printEdges("10");
	g1.printEdges("1");
	g1.printEdges("5");

	//check that all nodes are still in the graph
	std::cout << "Check that all nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode("hello 1") << std::endl;
	std::cout << g1.isNode("world 2") << std::endl;
	std::cout << g1.isNode("test 3") << std::endl;
	std::cout << g1.isNode("zzzz") << std::endl;
	std::cout << g1.isNode("10") << std::endl;
	std::cout << g1.isNode("1") << std::endl;
	std::cout << g1.isNode("5") << std::endl;

	//check that all edges are in the graph
	std::cout << "Check that all edges are in the graph:" << std::endl;
	std::cout << g1.isConnected(y, x) << std::endl;
	std::cout << g1.isConnected(y, z) << std::endl;
	std::cout << g1.isConnected(z, x) << std::endl;
	std::cout << g1.isConnected(z, y) << std::endl;
	std::cout << g1.isConnected("1", "10") << std::endl;
	std::cout << g1.isConnected("5", "10") << std::endl;
	std::cout << g1.isConnected("5", "zzzz") << std::endl;

	//check that removed edges no longer exist
	std::cout << "Check that removed edges no longer exist:" << std::endl;
	std::cout << g1.isConnected(x, y) << std::endl;
	std::cout << g1.isConnected("1", "zzzz") << std::endl;

	//delete some nodes from the graph
	std::cout << "Delete some nodes from the graph:" << std::endl;
	g1.deleteNode("zzzz");
	g1.deleteNode("5");
	g1.deleteNode("world 2");

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(z);
	g1.printEdges("10");
	g1.printEdges("1");

	//check that all nodes are still in the graph
	std::cout << "Check that all nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode("hello 1") << std::endl;
	std::cout << g1.isNode("test 3") << std::endl;
	std::cout << g1.isNode("10") << std::endl;
	std::cout << g1.isNode("1") << std::endl;

	//check that all edges are in the graph
	std::cout << "Check that all edges are in the graph:" << std::endl;
	std::cout << g1.isConnected(z, x) << std::endl;
	std::cout << g1.isConnected("1", "10") << std::endl;

	//check that deleted nodes are not in graph
	std::cout << "Check that deleted nodes are not in graph:" << std::endl;
	std::cout << g1.isNode("world 2") << std::endl;
	std::cout << g1.isNode("5") << std::endl;
	std::cout << g1.isNode("zzzz") << std::endl;

	//call replace with a non-existant nodess
	std::cout << "Call replace with non-existant nodes:" << std::endl;
	try {
		g1.replace("world 2" , "something");
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		g1.replace("5" , "something else");
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		g1.replace("zzzz" , "nothing");
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	//call replace with existing destination data
	std::cout << "Call replace with existing destination data:" << std::endl;
	std::cout << g1.replace("hello 1", "hello 1") << std::endl;
	std::cout << g1.replace("test 3", "hello 1") << std::endl;
	std::cout << g1.replace("10", "test 3") << std::endl;
	std::cout << g1.replace("1", "10") << std::endl;

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges(x);
	g1.printEdges(z);
	g1.printEdges("10");
	g1.printEdges("1");

	//check that all nodes are still in the graph
	std::cout << "Check that all nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode("hello 1") << std::endl;
	std::cout << g1.isNode("test 3") << std::endl;
	std::cout << g1.isNode("10") << std::endl;
	std::cout << g1.isNode("1") << std::endl;

	//check that all edges are in the graph
	std::cout << "Check that all edges are in the graph:" << std::endl;
	std::cout << g1.isConnected(z, x) << std::endl;
	std::cout << g1.isConnected("1", "10") << std::endl;

	//call replace with valid pairs of arguments
	std::cout << "Call replace with valid pairs of args:" << std::endl;
	std::cout << g1.replace("hello 1", "1 HELLO") << std::endl;
	std::cout << g1.replace("test 3", "test") << std::endl;

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges("1 HELLO");
	g1.printEdges("test");
	g1.printEdges("10");
	g1.printEdges("1");

	//check that all nodes are still in the graph
	std::cout << "Check that all nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode("1 HELLO") << std::endl;
	std::cout << g1.isNode("test") << std::endl;
	std::cout << g1.isNode("10") << std::endl;
	std::cout << g1.isNode("1") << std::endl;

	//check that all edges are in the graph
	std::cout << "Check that all edges are in the graph:" << std::endl;
	std::cout << g1.isConnected("test", "1 HELLO") << std::endl;
	std::cout << g1.isConnected("1", "10") << std::endl;

	//check that renamed nodes are no longer in graph
	std::cout << "Check that renamed nodes are not in graph:" << std::endl;
	std::cout << g1.isNode("hello 1") << std::endl;
	std::cout << g1.isNode("test 3") << std::endl;

	//call mergeReplace with unknown nodes
	std::cout << "Call mergeReplace with unknown nodes:" << std::endl;
	try {
		g1.mergeReplace("10", "unknown");
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		g1.mergeReplace("unknown", "10");
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		g1.mergeReplace("unknown", "unknown");
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	//call mergeReplace on nodes with no outgoing edges
	std::cout << "Call mergeReplace on nodes with no outgoing edges:" << std::endl;
	g1.mergeReplace("1 HELLO", "10");

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges("test");
	g1.printEdges("10");
	g1.printEdges("1");

	//check that all nodes are still in the graph
	std::cout << "Check that all nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode("test") << std::endl;
	std::cout << g1.isNode("10") << std::endl;
	std::cout << g1.isNode("1") << std::endl;

	//check that all edges are in the graph
	std::cout << "Check that all edges are in the graph:" << std::endl;
	std::cout << g1.isConnected("test", "10") << std::endl;
	std::cout << g1.isConnected("1", "10") << std::endl;

	//check that "1 HELLO" has been deleted
	std::cout << "Check that \"1 HELLO\" has been deleted" << std::endl;
	std::cout << g1.isNode("1 HELLO") << std::endl;

	//call mergeReplace on nodes where one has outgoing edges
	std::cout << "Call mergeReplace on nodes where one has outgoing edges:" << std::endl;
	g1.mergeReplace("1", "10");

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges("test");
	g1.printEdges("10");

	//check that all nodes are still in the graph
	std::cout << "Check that all nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode("test") << std::endl;
	std::cout << g1.isNode("10") << std::endl;

	//check that all edges are in the graph
	std::cout << "Check that all edges are in the graph:" << std::endl;
	std::cout << g1.isConnected("test", "10") << std::endl;
	std::cout << g1.isConnected("10", "10") << std::endl;

	//check that "1" has been deleted
	std::cout << "Check that \"1\" has been deleted:" << std::endl;
	std::cout << g1.isNode("1") << std::endl;

	//call mergeReplace on nodes both with outgoing edges
	std::cout << "Call mergeReplace on nodes both with outgoing edges:" << std::endl;
	g1.mergeReplace("10", "test");

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges("test");

	//check that all nodes are still in the graph
	std::cout << "Check that all nodes are still in the graph:" << std::endl;
	std::cout << g1.isNode("test") << std::endl;

	//check that all edges are in the graph
	std::cout << "Check that all edges are in the graph:" << std::endl;
	std::cout << g1.isConnected("test", "test") << std::endl;

	//check that "10" has been deleted
	std::cout << "Check that \"10\" has been deleted:" << std::endl;
	std::cout << g1.isNode("10") << std::endl;

	//remove all nodes and edges from the graph
	std::cout << "Remove all nodes and edges from the graph:" << std::endl;
	g1.clear();
	std::cout << "Nodes:" << std::endl;
	g1.printNodes();

	//add in a few new nodes
	std::cout << "Add new nodes and edges to the graph:" << std::endl;
	std::cout << g1.addNode("new node") << std::endl;
	std::cout << g1.addNode("another node") << std::endl;
	std::cout << g1.addNode("yet another node") << std::endl;
	std::cout << g1.addNode("extra node") << std::endl;

	//add in a few new edges
	std::cout << g1.addEdge("new node", "another node", 15) << std::endl;
	std::cout << g1.addEdge("new node", "yet another node", 27) << std::endl;
	std::cout << g1.addEdge("new node", "yet another node", 42) << std::endl;
	std::cout << g1.addEdge("another node", "yet another node", -357) << std::endl;
	std::cout << g1.addEdge("another node", "new node", 1) << std::endl;
	std::cout << g1.addEdge("another node", "another node", -7) << std::endl;

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges("new node");
	g1.printEdges("another node");
	g1.printEdges("yet another node");
	g1.printEdges("extra node");

	//check the nodes and edges are in the graph
	std::cout << "Check the nodes and edges are in the graph" << std::endl;
	std::cout << g1.isNode("new node") << std::endl;
	std::cout << g1.isNode("another node") << std::endl;
	std::cout << g1.isNode("yet another node") << std::endl;
	std::cout << g1.isNode("extra node") << std::endl;
	std::cout << g1.isConnected("new node", "another node") << std::endl;
	std::cout << g1.isConnected("new node", "yet another node") << std::endl;
	std::cout << g1.isConnected("another node", "yet another node") << std::endl;
	std::cout << g1.isConnected("another node", "new node") << std::endl;
	std::cout << g1.isConnected("another node", "another node") << std::endl;

	//remove all nodes and edges again
	std::cout << "Remove all nodes and edges from the graph:" << std::endl;
	g1.clear();
	std::cout << "Nodes:" << std::endl;
	g1.printNodes();

	//add some new nodes to the graph
	std::cout << "Add some new nodes to the graph:" << std::endl;
	std::cout << g1.addNode("node 1") << std::endl;
	std::cout << g1.addNode("node 2") << std::endl;
	std::cout << g1.addNode("node 3") << std::endl;
	std::cout << g1.addNode("node 4") << std::endl;
	std::cout << g1.addNode("node 5") << std::endl;
	std::cout << g1.addNode("node 6") << std::endl;
	std::cout << g1.addNode("node 7") << std::endl;
	std::cout << g1.addNode("node 8") << std::endl;

	//add a few edges to a few of the nodes
	std::cout << g1.addEdge("node 5", "node 7", 5) << std::endl;
	std::cout << g1.addEdge("node 3", "node 4", 32) << std::endl;
	std::cout << g1.addEdge("node 5", "node 3", 16) << std::endl;
	std::cout << g1.addEdge("node 3", "node 2", -4) << std::endl;

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges("node 1");
	g1.printEdges("node 2");
	g1.printEdges("node 3");
	g1.printEdges("node 4");
	g1.printEdges("node 5");
	g1.printEdges("node 6");
	g1.printEdges("node 7");
	g1.printEdges("node 8");

	//check the nodes and edges are in the graph
	std::cout << "Check the nodes and edges are in the graph:" << std::endl;
	std::cout << g1.isNode("node 1") << std::endl;
	std::cout << g1.isNode("node 2") << std::endl;
	std::cout << g1.isNode("node 3") << std::endl;
	std::cout << g1.isNode("node 4") << std::endl;
	std::cout << g1.isNode("node 5") << std::endl;
	std::cout << g1.isNode("node 6") << std::endl;
	std::cout << g1.isNode("node 7") << std::endl;
	std::cout << g1.isNode("node 8") << std::endl;
	std::cout << g1.isConnected("node 5", "node 7") << std::endl;
	std::cout << g1.isConnected("node 3", "node 4") << std::endl;
	std::cout << g1.isConnected("node 5", "node 3") << std::endl;
	std::cout << g1.isConnected("node 3", "node 2") << std::endl;

	//iterate through the graph using the iterator
	std::cout << "Iterate through graph using the iterator:" << std::endl;
	for (g1.begin(); !g1.end(); g1.next()) {
		std::cout << g1.value() << ":" << std::endl;
		g1.printEdges(g1.value());
	}

	//copy construct g1
	std::cout << "Copy construct g1 to g2:" << std::endl;
	gdwg::Graph<std::string, int> g2 = g1;

	std::cout << "Nodes:" << std::endl;
	g2.printNodes();
	std::cout << "Edges:" << std::endl;
	g2.printEdges("node 1");
	g2.printEdges("node 2");
	g2.printEdges("node 3");
	g2.printEdges("node 4");
	g2.printEdges("node 5");
	g2.printEdges("node 6");
	g2.printEdges("node 7");
	g2.printEdges("node 8");

	//check the nodes and edges are in the new graph
	std::cout << "Check the nodes and edges are in new graph:" << std::endl;
	std::cout << g2.isNode("node 1") << std::endl;
	std::cout << g2.isNode("node 2") << std::endl;
	std::cout << g2.isNode("node 3") << std::endl;
	std::cout << g2.isNode("node 4") << std::endl;
	std::cout << g2.isNode("node 5") << std::endl;
	std::cout << g2.isNode("node 6") << std::endl;
	std::cout << g2.isNode("node 7") << std::endl;
	std::cout << g2.isNode("node 8") << std::endl;
	std::cout << g2.isConnected("node 5", "node 7") << std::endl;
	std::cout << g2.isConnected("node 3", "node 4") << std::endl;
	std::cout << g2.isConnected("node 5", "node 3") << std::endl;
	std::cout << g2.isConnected("node 3", "node 2") << std::endl;

	//construct a new graph
	std::cout << "Construct a new graph g3:" << std::endl;
	gdwg::Graph<std::string, int> g3;
	std::cout << g3.addNode("55") << std::endl;
	std::cout << g3.addNode("44") << std::endl;
	std::cout << g3.addNode("node 1") << std::endl;
	std::cout << g3.addNode("node 2") << std::endl;
	std::cout << g3.addEdge("node 1", "node 2", 14) << std::endl;
	std::cout << g3.addEdge("55", "node 1", 342) << std::endl;

	std::cout << "Nodes:" << std::endl;
	g3.printNodes();
	std::cout << "Edges:" << std::endl;
	g3.printEdges("55");
	g3.printEdges("44");
	g3.printEdges("node 1");
	g3.printEdges("node 2");

	std::cout << g3.isNode("55") << std::endl;
	std::cout << g3.isNode("44") << std::endl;
	std::cout << g3.isNode("node 1") << std::endl;
	std::cout << g3.isNode("node 2") << std::endl;
	std::cout << g3.isConnected("node 1", "node 2") << std::endl;
	std::cout << g3.isConnected("55", "node 1") << std::endl;

	std::cout << "Copy assign g1 to g3:" << std::endl;
	g3 = g1;

	std::cout << "Nodes:" << std::endl;
	g3.printNodes();
	std::cout << "Edges:" << std::endl;
	g3.printEdges("node 1");
	g3.printEdges("node 2");
	g3.printEdges("node 3");
	g3.printEdges("node 4");
	g3.printEdges("node 5");
	g3.printEdges("node 6");
	g3.printEdges("node 7");
	g3.printEdges("node 8");

	//check the nodes and edges are in the new graph
	std::cout << "Check the nodes and edges are in new graph:" << std::endl;
	std::cout << g3.isNode("node 1") << std::endl;
	std::cout << g3.isNode("node 2") << std::endl;
	std::cout << g3.isNode("node 3") << std::endl;
	std::cout << g3.isNode("node 4") << std::endl;
	std::cout << g3.isNode("node 5") << std::endl;
	std::cout << g3.isNode("node 6") << std::endl;
	std::cout << g3.isNode("node 7") << std::endl;
	std::cout << g3.isNode("node 8") << std::endl;
	std::cout << g3.isConnected("node 5", "node 7") << std::endl;
	std::cout << g3.isConnected("node 3", "node 4") << std::endl;
	std::cout << g3.isConnected("node 5", "node 3") << std::endl;
	std::cout << g3.isConnected("node 3", "node 2") << std::endl;

	//modify the original graph g1
	std::cout << g1.addNode("hello world") << std::endl;
	std::cout << g1.addNode("new node") << std::endl;
	std::cout << g1.addEdge("node 1", "node 2", 861) << std::endl;
	g1.deleteNode("node 3");
	g1.deleteEdge("node 5", "node 7", 5);
	g1.replace("node 6", "new name for node 6");
	g1.mergeReplace("node 1", "new node");

	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges("node 2");
	g1.printEdges("node 4");
	g1.printEdges("node 5");
	g1.printEdges("new name for node 6");
	g1.printEdges("node 7");
	g1.printEdges("node 8");
	g1.printEdges("hello world");
	g1.printEdges("new node");

	//check the nodes and edges are in the graph
	std::cout << "Check the nodes and edges are in the graph:" << std::endl;
	std::cout << g1.isNode("node 2") << std::endl;
	std::cout << g1.isNode("node 4") << std::endl;
	std::cout << g1.isNode("node 5") << std::endl;
	std::cout << g1.isNode("new name for node 6") << std::endl;
	std::cout << g1.isNode("node 7") << std::endl;
	std::cout << g1.isNode("node 8") << std::endl;
	std::cout << g1.isNode("hello world") << std::endl;
	std::cout << g1.isNode("new node") << std::endl;
	std::cout << g1.isConnected("new node", "node 2") << std::endl;

	//check that the node and edge are deleted
	std::cout << "Check that the node and edge are deleted:" << std::endl;
	std::cout << g1.isNode("node 1") << std::endl;
	std::cout << g1.isNode("node 3") << std::endl;
	std::cout << g1.isNode("node 6") << std::endl;
	std::cout << g1.isConnected("node 5", "node 7") << std::endl;

	//check that g2 is unaffected
	std::cout << "Check that g2 is unaffected:" << std::endl;
	std::cout << "Nodes:" << std::endl;
	g2.printNodes();
	std::cout << "Edges:" << std::endl;
	g2.printEdges("node 1");
	g2.printEdges("node 2");
	g2.printEdges("node 3");
	g2.printEdges("node 4");
	g2.printEdges("node 5");
	g2.printEdges("node 6");
	g2.printEdges("node 7");
	g2.printEdges("node 8");

	//check the nodes and edges are in the new graph
	std::cout << "Check the nodes and edges are in new graph:" << std::endl;
	std::cout << g2.isNode("node 1") << std::endl;
	std::cout << g2.isNode("node 2") << std::endl;
	std::cout << g2.isNode("node 3") << std::endl;
	std::cout << g2.isNode("node 4") << std::endl;
	std::cout << g2.isNode("node 5") << std::endl;
	std::cout << g2.isNode("node 6") << std::endl;
	std::cout << g2.isNode("node 7") << std::endl;
	std::cout << g2.isNode("node 8") << std::endl;
	std::cout << g2.isConnected("node 5", "node 7") << std::endl;
	std::cout << g2.isConnected("node 3", "node 4") << std::endl;
	std::cout << g2.isConnected("node 5", "node 3") << std::endl;
	std::cout << g2.isConnected("node 3", "node 2") << std::endl;

	//check that g3 is unaffected
	std::cout << "Check that g3 is unaffected:" << std::endl;
	std::cout << "Nodes:" << std::endl;
	g3.printNodes();
	std::cout << "Edges:" << std::endl;
	g3.printEdges("node 1");
	g3.printEdges("node 2");
	g3.printEdges("node 3");
	g3.printEdges("node 4");
	g3.printEdges("node 5");
	g3.printEdges("node 6");
	g3.printEdges("node 7");
	g3.printEdges("node 8");

	//check the nodes and edges are in the new graph
	std::cout << "Check the nodes and edges are in new graph:" << std::endl;
	std::cout << g3.isNode("node 1") << std::endl;
	std::cout << g3.isNode("node 2") << std::endl;
	std::cout << g3.isNode("node 3") << std::endl;
	std::cout << g3.isNode("node 4") << std::endl;
	std::cout << g3.isNode("node 5") << std::endl;
	std::cout << g3.isNode("node 6") << std::endl;
	std::cout << g3.isNode("node 7") << std::endl;
	std::cout << g3.isNode("node 8") << std::endl;
	std::cout << g3.isConnected("node 5", "node 7") << std::endl;
	std::cout << g3.isConnected("node 3", "node 4") << std::endl;
	std::cout << g3.isConnected("node 5", "node 3") << std::endl;
	std::cout << g3.isConnected("node 3", "node 2") << std::endl;

	//move construct g3 to g4
	gdwg::Graph<std::string, int> g4 = std::move(g3);
	std::cout << "Nodes:" << std::endl;
	g4.printNodes();
	std::cout << "Edges:" << std::endl;
	g4.printEdges("node 1");
	g4.printEdges("node 2");
	g4.printEdges("node 3");
	g4.printEdges("node 4");
	g4.printEdges("node 5");
	g4.printEdges("node 6");
	g4.printEdges("node 7");
	g4.printEdges("node 8");

	//check the nodes and edges are in the new graph
	std::cout << "Check the nodes and edges are in new graph:" << std::endl;
	std::cout << g4.isNode("node 1") << std::endl;
	std::cout << g4.isNode("node 2") << std::endl;
	std::cout << g4.isNode("node 3") << std::endl;
	std::cout << g4.isNode("node 4") << std::endl;
	std::cout << g4.isNode("node 5") << std::endl;
	std::cout << g4.isNode("node 6") << std::endl;
	std::cout << g4.isNode("node 7") << std::endl;
	std::cout << g4.isNode("node 8") << std::endl;
	std::cout << g4.isConnected("node 5", "node 7") << std::endl;
	std::cout << g4.isConnected("node 3", "node 4") << std::endl;
	std::cout << g4.isConnected("node 5", "node 3") << std::endl;
	std::cout << g4.isConnected("node 3", "node 2") << std::endl;

	//check that g3 is in a valid state
	std::cout << "Nodes:" << std::endl;
	g3.printNodes();

	//move assign g4 to g1
	g1 = std::move(g4);
	std::cout << "Nodes:" << std::endl;
	g1.printNodes();
	std::cout << "Edges:" << std::endl;
	g1.printEdges("node 1");
	g1.printEdges("node 2");
	g1.printEdges("node 3");
	g1.printEdges("node 4");
	g1.printEdges("node 5");
	g1.printEdges("node 6");
	g1.printEdges("node 7");
	g1.printEdges("node 8");

	//check the nodes and edges are in the new graph
	std::cout << "Check the nodes and edges are in new graph:" << std::endl;
	std::cout << g1.isNode("node 1") << std::endl;
	std::cout << g1.isNode("node 2") << std::endl;
	std::cout << g1.isNode("node 3") << std::endl;
	std::cout << g1.isNode("node 4") << std::endl;
	std::cout << g1.isNode("node 5") << std::endl;
	std::cout << g1.isNode("node 6") << std::endl;
	std::cout << g1.isNode("node 7") << std::endl;
	std::cout << g1.isNode("node 8") << std::endl;
	std::cout << g1.isConnected("node 5", "node 7") << std::endl;
	std::cout << g1.isConnected("node 3", "node 4") << std::endl;
	std::cout << g1.isConnected("node 5", "node 3") << std::endl;
	std::cout << g1.isConnected("node 3", "node 2") << std::endl;

	//check that g4 is in a valid state
	std::cout << "Nodes:" << std::endl;
	g4.printNodes();

	//copy construct g1 to a const graph g5
	const gdwg::Graph<std::string, int> g5 = g1;
	std::cout << "Nodes:" << std::endl;
	g5.printNodes();
	std::cout << "Edges:" << std::endl;
	g5.printEdges("node 1");
	g5.printEdges("node 2");
	g5.printEdges("node 3");
	g5.printEdges("node 4");
	g5.printEdges("node 5");
	g5.printEdges("node 6");
	g5.printEdges("node 7");
	g5.printEdges("node 8");

	//check the nodes and edges are in the new graph
	std::cout << "Check the nodes and edges are in new graph:" << std::endl;
	std::cout << g5.isNode("node 1") << std::endl;
	std::cout << g5.isNode("node 2") << std::endl;
	std::cout << g5.isNode("node 3") << std::endl;
	std::cout << g5.isNode("node 4") << std::endl;
	std::cout << g5.isNode("node 5") << std::endl;
	std::cout << g5.isNode("node 6") << std::endl;
	std::cout << g5.isNode("node 7") << std::endl;
	std::cout << g5.isNode("node 8") << std::endl;
	std::cout << g5.isConnected("node 5", "node 7") << std::endl;
	std::cout << g5.isConnected("node 3", "node 4") << std::endl;
	std::cout << g5.isConnected("node 5", "node 3") << std::endl;
	std::cout << g5.isConnected("node 3", "node 2") << std::endl;

	//iterate through the const graph using the iterator
	std::cout << "Iterate through const graph with iterator:" << std::endl;
	for (g5.begin(); !g5.end(); g5.next()) {
		std::cout << g5.value() << ":" << std::endl;
		g5.printEdges(g5.value());
	}

	return 0;
}
