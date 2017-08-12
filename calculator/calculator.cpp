/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Stack-based calculator program.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <cmath>

void process_file(std::string file);
bool process_token(std::string s,
std::stack<std::pair<double, bool>>& tokens, std::queue<int>& num_repeats);
void show_num(auto n);
auto compute(std::string op, auto n1, auto n2);
double binary_op(std::string op, auto n1, auto n2);
std::string op_to_str(std::string op);
auto get_sqrt(auto n);
void reverse(std::stack<std::pair<double, bool>>& tokens, int n);

int main(int argc, char *argv[]) {
	//setup the print out format for the precision required
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout.precision(3);

	//open and process input file
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " FILE\n";
		return 1;
	}

	process_file(argv[1]);
	return 0;
}

//process tokens in the given file
void process_file(std::string file) {
	std::ifstream in;
	in.open(file);
	if (in.fail()) {
		std::cerr << "Cannot read '" << file << "'\n";
		exit(1);
	}
	std::string s;
	std::stack<std::pair<double, bool>> tokens; //stack of tokens

	//num times to repeat each repeat..endrepeat block
	//without nested repeats, the queue is redundant
	std::queue<int> num_repeats;

	//vector of all tokens in the repeat..endrepeat block
	std::vector<std::string> tokens_to_repeat;
	bool wait_for_endrepeat = false;

	//read the file while there is input
	while (in >> s) {
		if (wait_for_endrepeat == true && s.compare("endrepeat") == 0) {
			//process tokens in tokens_to_repeat num_repeats times
			wait_for_endrepeat = false;
			int num_rep = num_repeats.front();
			num_repeats.pop();
			for (int i = 0; i < num_rep; ++i) {
				for (auto &token: tokens_to_repeat) {
					wait_for_endrepeat = process_token(token, tokens, num_repeats);
				}
			}
			tokens_to_repeat.clear();
		} else if (wait_for_endrepeat == true && s.compare("endrepeat") != 0) {
			//collect all tokens in repeat..endrepeat block for later processing
			tokens_to_repeat.push_back(s);
		} else {
			//otherwise, process tokens out of repeat..endrepeat block right away
			wait_for_endrepeat = process_token(s, tokens, num_repeats);
		}
	}

	in.close();
}

//act on a specific token and print its result (if any)
//return true if the token is a repeat command; false otherwise
bool process_token(std::string s,
std::stack<std::pair<double, bool>>& tokens, std::queue<int>& num_repeats) {
	if (isdigit(s[0])) {
		if (s.find('.') == std::string::npos) {
			//integer, set flag to false
			tokens.push(std::make_pair(std::stoi(s), false));
		} else {
			//double, set flag to true
			tokens.push(std::make_pair(std::stod(s), true));
		}
	} else {
		if (s.compare("add") == 0 || s.compare("sub") == 0 ||
			s.compare("mult") == 0 || s.compare("div") == 0) {
			//binary operation
			auto n1 = tokens.top();
			tokens.pop();
			auto n2 = tokens.top();
			tokens.pop();
			auto res = compute(s, n1, n2);
			tokens.push(res);
			show_num(n1); std::cout << op_to_str(s); show_num(n2);
			std::cout << " = "; show_num(res); std::cout << "\n";
		} else if (s.compare("sqrt") == 0) {
			//square root
			auto n = tokens.top();
			tokens.pop();
			auto res = get_sqrt(n);
			tokens.push(res);
			std::cout << "sqrt "; show_num(n); std::cout << " = ";
			show_num(res); std::cout << "\n";
		} else if (s.compare("pop") == 0) {
			tokens.pop();
		} else if (s.compare("reverse") == 0) {
			int n = tokens.top().first;
			tokens.pop();
			reverse(tokens, n);
		} else if (s.compare("repeat") == 0) {
			num_repeats.push(int(tokens.top().first));
			tokens.pop();
			return true;
		} else {
			//skip invalid commands
			std::cerr << "Warning: invalid token '" << s << "'\n";
		}
	}
	return false;
}

//display number as an int or double, depending on flag
void show_num(auto n) {
	if (n.second == true) {
		double casted = n.first;
		std::cout << casted;
	} else {
		int casted = n.first;
		std::cout << casted;
	}
}

//prepare numbers for a binary operation
//convert to doubles if at least one double; otherwise, convert to ints
auto compute(std::string op, auto n1, auto n2) {
	if (n1.second == true || n2.second == true) {
		return std::make_pair(binary_op(op, n1.first, n2.first), true);
	} else {
		int m1 = n1.first;
		int m2 = n2.first;
		return std::make_pair(binary_op(op, m1, m2), false);
	}
}

//perform binary operation on ints/doubles
double binary_op(std::string op, auto n1, auto n2) {
	double result;
	switch (op[0]) {
		case 'a': result = n1 + n2; break;
		case 's': result = n1 - n2; break;
		case 'm': result = n1 * n2; break;
		case 'd': result = n1 / n2; break;
		default: result = 0;
	}
	return result;
}

//convert name of binary operator to a symbol
std::string op_to_str(std::string op) {
	std::string result;
	switch (op[0]) {
		case 'a': result = " + "; break;
		case 's': result = " - "; break;
		case 'm': result = " * "; break;
		case 'd': result = " / "; break;
		default: result = "";
	}
	return result;
}

//return the sqrt of a number, preserving its type
auto get_sqrt(auto n) {
	if (n.second == true) {
		return std::make_pair(sqrt(n.first), true);
	} else {
		return std::make_pair(double(sqrt(int(n.first))), false);
	}
}

//reverse the top n tokens on the stack
void reverse(std::stack<std::pair<double, bool>>& tokens, int n) {
	std::queue<std::pair<double, bool>> top_n;
	for (int i = 0; i < n; ++i) {
		top_n.push(tokens.top());
		tokens.pop();
	}
	for (int i = 0; i < n; ++i) {
		tokens.push(top_n.front());
		top_n.pop();
	}
}
