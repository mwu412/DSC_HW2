// OJ 7/10

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n_matrix, m, n;        //number of matrix, size: mxn

stack<int> si, sj, sdir;   //path: ith row, jth col
int count_p = 0;           //count of parentheses
int count_step = 0;        //count final steps

bool exam(char arr[][100], int mi, int mj) {

	char N = arr[si.top()][sj.top()];
	int ssi = si.top() + mi;
	int ssj = sj.top() + mj;
	char t = arr[ssi][ssj];



	//BC
	if (ssi < 0 || ssi >= m
		|| ssj < 0 || ssj >= n) {
		return false;
	}

	//step on path
	stack<int> di, dj;
	di = si;
	dj = sj;
	while (!di.empty()) {
		if (ssi == di.top() && ssj == dj.top()) {
			return false;
		}
		else {
			di.pop();
			dj.pop();
		}
	}

	//math
	//numbers
	if ((N == '1' || N == '2' || N == '3' || N == '4' || N == '5' || N == '6' || N == '7' || N == '8' || N == '9') && t == '(') {
		return false;
	}
	//+, -, *, /
	else if ((N == '+' || N == '-' || N == '*' || N == '/') && (t == ')' || t == '+' || t == '-' || t == '*' || t == '/')) {
		return false;
	}
	//(
	else if ((N == '(') && (t == ')' || t == '+' || t == '-' || t == '*' || t == '/')) {
		return false;
	}
	//(
	else if ((N == ')') && (t == '(' || t == '1' || t == '2' || t == '3' || t == '4' || t == '5' || t == '6' || t == '7' || t == '8' || t == '9')) {
		return false;
	}


	else {
		//count (, )
		if (t == '(') count_p++;
		else if (t == ')') count_p--;

		//
		//		if (ssi == (m - 1) && ssj == (n - 1) && count_p != 0)
		//			return false;

		//ok! push
		si.push(ssi);
		sj.push(ssj);
		//				cout << "p=" << count_p << endl;
		//				cout << "(" << si.top() + 1 << ", " << sj.top() + 1 << endl;


		//test only return math
		/*		stack<int> sssi, sssj;
		stack<int> ddi, ddj;
		sssi = si;
		sssj = sj;
		while (!sssi.empty()) {
		ddi.push(sssi.top());
		ddj.push(sssj.top());
		sssi.pop();
		sssj.pop();
		}
		while (!ddi.empty()) {
		cout << arr[ddi.top()][ddj.top()];
		ddi.pop();
		ddj.pop();
		}
		cout << endl;
		*/
		//bingo
		if (si.top() == (m - 1) && sj.top() == (n - 1) && count_p == 0)
			return true;

		if (exam(arr, 1, 0) == true) return true;
		else if (exam(arr, 0, 1) == true) return true;
		else if (exam(arr, 0, -1) == true) return true;
		else if (exam(arr, -1, 0) == true) return true;

		else {
			if (t == '(') count_p--;
			else if (t == ')') count_p++;
			si.pop();
			sj.pop();
			//						cout << "pop\n";
			//						cout << "(" << si.top() + 1 << ", " << sj.top() + 1 << endl;

			return false;
		}
	}
}



//I2P
// Simply determine if character is one of the four standard operators.
bool isOperator(char character) {
	if (character == '+' || character == '-' || character == '*' || character == '/') {
		return true;
	}
	return false;
}


// If the character is not an operator or a parenthesis, then it is assumed to be an operand.
bool isOperand(char character) {
	if (!isOperator(character) && character != '(' && character != ')') {
		return true;
	}
	return false;
}


// Compare operator precedence of main operators.
// Return 0 if equal, -1 if op2 is less than op1, and 1 if op2 is greater than op1.
int compareOperators(char op1, char op2) {
	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) { return -1; }
	else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) { return 1; }
	return 0;
}


void I2P(string e)
{
	// Empty character stack and blank postfix string.
	stack<char> opStack;
	string postFixString = "";



	// Loop through the array (one character at a time) until we reach the end of the string.
	for (int i = 0; i< e.length(); i++) {
		// If operand, simply add it to our postfix string.
		// If it is an operator, pop operators off our stack until it is empty, an open parenthesis or an operator with less than or equal precedence.
		if (isOperand(e[i])) {
			postFixString += e[i];
			if (i == e.length() - 1)
				postFixString += ' ';
			else if (!isOperand(e[i + 1]))
				postFixString += ' ';

		}
		else if (isOperator(e[i])) {
			while (!opStack.empty() && opStack.top() != '(' && compareOperators(opStack.top(), e[i]) <= 0) {
				postFixString += opStack.top();
				postFixString += ' ';
				opStack.pop();
			}
			opStack.push(e[i]);
		}
		// Simply push all open parenthesis onto our stack
		// When we reach a closing one, start popping off operators until we run into the opening parenthesis.
		else if (e[i] == '(') { opStack.push(e[i]); }
		else if (e[i] == ')') {
			while (!opStack.empty()) {
				if (opStack.top() == '(') { opStack.pop(); break; }
				postFixString += opStack.top();
				postFixString += ' ';
				opStack.pop();
			}
		}
	}

	// After the input expression has been ran through, if there is any remaining operators left on the stack
	// pop them off and put them onto the postfix string.
	while (!opStack.empty()) {
		postFixString += opStack.top();
		postFixString += ' ';
		opStack.pop();
	}


	// Show the postfix string at the end.
	cout << postFixString << endl;
}

void printIP(char arr[][100]) {
	//Infix
	stack<int> ddi, ddj;
	char N, t;
	stack<int> sssi, sssj;
	sssi = si;
	sssj = sj;
	while (!sssi.empty()) {
		ddi.push(sssi.top());
		ddj.push(sssj.top());
		sssi.pop();
		sssj.pop();
	}
	string infix(si.size(), 'x');
	for (int i = 0; !ddi.empty(); i++) {
		N = arr[ddi.top()][ddj.top()];
		infix[i] = N;	//problem maybe
		cout << N;
		ddi.pop();
		ddj.pop();
		if (!ddi.empty())
			t = arr[ddi.top()][ddj.top()];
		if (!((N == '1' || N == '2' || N == '3' || N == '4' || N == '5' || N == '6' || N == '7' || N == '8' || N == '9')
			&& (t == '1' || t == '2' || t == '3' || t == '4' || t == '5' || t == '6' || t == '7' || t == '8' || t == '9')
			&& !ddi.empty())) {
			cout << ' ';
		}
	}
	cout << endl;

	//postfix
	I2P(infix);
}

int main() {

	cin >> n_matrix;
	cout << n_matrix << endl;

	for (int i = 0; i<n_matrix; i++) {
		cin >> n >> m;
		cout << n << endl << m << endl;
		cin.ignore();
		char arr[100][100];
		string in;
		count_p = 0;

		while (!si.empty()) {
			si.pop();
			sj.pop();
		}
		si.push(0);
		sj.push(0);



		//get matrix
		for (int i = 0; i<m; i++) {

			getline(cin, in);
			for (int j = 0; j * 2<in.size(); j++) {
				arr[i][j] = in.at(j * 2);
			}
		}

		//print matrix
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}

		if (arr[0][0] == '(') { count_p++; }
		else if (arr[0][0] == ')') { count_p--; }

		//one matrix finished
		//print the maze result
		//silly fail
		if (arr[0][0] == '+' || arr[0][0] == '-' || arr[0][0] == '/' || arr[0][0] == '*')
			cout << "No";
		else if (arr[m - 1][n - 1] == '+' || arr[m - 1][n - 1] == '-' || arr[m - 1][n - 1] == '/' || arr[m - 1][n - 1] == '*')
			cout << "No";
		else if (exam(arr, 1, 0) == true) {
			cout << "Yes" << endl;
			printIP(arr);
		}
		else if (exam(arr, 0, 1) == true) {
			cout << "Yes" << endl;
			printIP(arr);
		}
		else cout << "No" << endl;


	}
	system("pause");
	return 0;

}
