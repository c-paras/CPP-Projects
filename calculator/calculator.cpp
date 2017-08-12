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
bool process_token(std::string s, std::stack<std::string>& tokens, std::queue<int>& num_repeats);
std::string compute(std::string op, std::string s1, std::string s2);
double binary_op(std::string op, double n1, double n2);
int binary_op(std::string op, int n1, int n2);
std::string expr_to_str(std::string n1, std::string s, std::string n2, std::string res);
std::string round_number(std::string number);
std::string get_sqrt(std::string s);
void reverse(std::stack<std::string>& tokens, int n);

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
	std::stack<std::string> tokens; //stack of tokens

	//note: without nested repeats, the queue is redundant
	std::queue<int> num_repeats; //num times to repeat each repeat..endreapeat block
	std::vector<std::string> tokens_to_repeat; //vector of all tokens in the repeat..endrepeat block
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
			//collect all tokens within repeat..endrepeat block for later processing
			tokens_to_repeat.push_back(s);
		} else {
			//otherwise, process tokens outside of repeat..endrepeat block straight away
			wait_for_endrepeat = process_token(s, tokens, num_repeats);
		}
	}

	in.close();
}

//TODO: debug-only
void print_stack(std::stack<std::string>& tokens) {
	std::stack<std::string> tmp;
	std::cout << "stack: ";
	while (tokens.empty() == false) {
		tmp.push(tokens.top());
		std::cout << tmp.top() << " ";
		tokens.pop();
	}
	std::cout << "\n";
	while (tmp.empty() == false) {
		tokens.push(tmp.top());
		tmp.pop();
	}
}

//act on a specific token and print its result (if any)
//return true if the token is a repeat command; false otherwise
bool process_token(std::string s, std::stack<std::string>& tokens, std::queue<int>& num_repeats) {
	//print_stack(tokens); //TODO: debug-only
	if (isdigit(s[0])) {
		//invalid inputs:
		//stack is empty before popping
		//i.e. for pop, add, sub, div, sqrt, mult, reverse, repeat
		//double instead of an int or negative:
		//for reverse and repeat (and negative for sqrt)
		tokens.push(s);
	} else {
		if (s.compare("add") == 0 || s.compare("sub") == 0 ||
			s.compare("mult") == 0 || s.compare("div") == 0) {
			//binary operation
			std::string n1 = tokens.top();
			tokens.pop();
			std::string n2 = tokens.top();
			tokens.pop();
			std::string res = compute(s, n1, n2);
			tokens.push(res);
			std::string expr = expr_to_str(n1, s, n2, res);
			std::cout << expr << "\n";
		} else if (s.compare("sqrt") == 0) {
			//square root
			std::string n = tokens.top();
			tokens.pop();
			std::string res = get_sqrt(n);
			tokens.push(res);
			std::cout << "sqrt " << round_number(n) << " = " << round_number(res) << "\n";
		} else if (s.compare("pop") == 0) {
			tokens.pop();
		} else if (s.compare("reverse") == 0) {
			std::string n = tokens.top();
			tokens.pop();
			reverse(tokens, std::stoi(n));
		} else if (s.compare("repeat") == 0) {
			num_repeats.push(std::stoi(tokens.top()));
			tokens.pop();
			return true;
		} else {
			//skip invalid commands
			std::cerr << "Warning: invalid token '" << s << "'\n";
		}
	}
	return false;
}

//prepare numbers for a binary operation
//convert to doubles if at least one double; otherwise, convert to ints
std::string compute(std::string op, std::string s1, std::string s2) {
	if (s1.find('.') != std::string::npos ||
		s2.find('.') != std::string::npos) {
		double n1 = std::stod(s1);
		double n2 = std::stod(s2);
		return std::to_string(binary_op(op, n1, n2));
	} else {
		int n1 = std::stoi(s1);
		int n2 = std::stoi(s2);
		return std::to_string(binary_op(op, n1, n2));
	}
}

//perform binary operation on doubles
//ideally, a template would be used to avoid repeated code
double binary_op(std::string op, double n1, double n2) {
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

//perform binary operation on ints
//ideally, a template would be used to avoid repeated code
int binary_op(std::string op, int n1, int n2) {
	int result;
	switch (op[0]) {
		case 'a': result = n1 + n2; break;
		case 's': result = n1 - n2; break;
		case 'm': result = n1 * n2; break;
		case 'd': result = n1 / n2; break;
		default: result = 0;
	}
	return result;
}

//convert expression to printable string
std::string expr_to_str(std::string n1, std::string s, std::string n2, std::string res) {
	std::string expr = round_number(n1);
	switch (s[0]) {
		case 'a': expr += " + "; break;
		case 's': expr += " - "; break;
		case 'm': expr += " * "; break;
		case 'd': expr += " / "; break;
	}
	return expr + round_number(n2) + " = " + round_number(res);
}

//round a number to 3 decimals and convert back to a string for display
std::string round_number(std::string number) {
	if (number.find('.') != std::string::npos) {
		//double, so round to 3 decimals
		double num = std::stod(number);
		std::ostringstream s;
		s << std::fixed << std::setprecision(3) << num;
		return s.str();
	} else {
		return number; //integer
	}
}

//return the sqrt of a number as a string
std::string get_sqrt(std::string s) {
	if (s.find('.') != std::string::npos) {
		return std::to_string(sqrt(std::stoi(s)));
	} else {
		return std::to_string(int(sqrt(std::stod(s))));
	}
}

//reverse the top n tokens on the stack
void reverse(std::stack<std::string>& tokens, int n) {
	std::queue<std::string> top_n;
	for (int i = 0; i < n; ++i) {
		top_n.push(tokens.top());
		tokens.pop();
	}
	for (int i = 0; i < n; ++i) {
		tokens.push(top_n.front());
		top_n.pop();
	}
}
