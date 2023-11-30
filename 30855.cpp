#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Fraction {
	long long numerator;
	long long denominator;
};

long long  GCD(long long  a, long long  b) {
	return b ? GCD(b, a % b) : a;
}

long long  LCM(long long  a, long long  b) {
	return a * b / GCD(a, b);
}

Fraction addFrac(Fraction a, Fraction b) {
	Fraction z;
	long long  lcm = LCM(a.denominator, b.denominator);
	z.numerator = (a.numerator * (lcm / a.denominator)) + (b.numerator * (lcm / b.denominator));
	z.denominator = lcm;
	return z;
}

Fraction divFrac(Fraction a, Fraction b) {
	Fraction z;

	z.numerator = a.numerator * b.denominator;
	z.denominator = a.denominator* b.numerator;
	long long  gcd = GCD(z.denominator, z.numerator);
	z.numerator = a.numerator * b.denominator/gcd;
	z.denominator = a.denominator* b.numerator/gcd;
	return z;
}




Fraction parseAndCompute(vector<string>& tokens, int& pos) {
	Fraction a;
	Fraction b;
	Fraction c;
	if (pos == 0) {
		pos++;
		Fraction result = parseAndCompute(tokens, pos);
		pos++;
		return result;
	}
	else {
		
		if (pos < tokens.size() && tokens[pos] == "(") {
			if (pos < tokens.size())pos++;
			a = parseAndCompute(tokens, pos);
			if (pos < tokens.size())pos++;
		}
		else if (pos < tokens.size()) {
			a = { stoi(tokens[pos])*stoi(tokens[pos]),stoi(tokens[pos]) };
			if (pos < tokens.size())pos++;
		}
		
		if (pos < tokens.size() && tokens[pos] == "(") {
			if (pos < tokens.size())pos++;
			b = parseAndCompute(tokens, pos);
			if (pos < tokens.size())pos++;
		}
		else if (pos < tokens.size()) {
			b = { stoi(tokens[pos])*stoi(tokens[pos]),stoi(tokens[pos]) };
			if (pos < tokens.size())pos++;
		}
		if (pos < tokens.size() && tokens[pos] == "(") {
			if (pos < tokens.size())pos++;
			c = parseAndCompute(tokens, pos);
			if (pos < tokens.size())pos++;
		}
		else if (pos < tokens.size()) {
			c = { stoi(tokens[pos])*stoi(tokens[pos]),stoi(tokens[pos]) };
			if (pos < tokens.size())pos++;
		}
		if (tokens[pos] != "(" && tokens[pos] != ")" || tokens[pos] == "(") {
			return{ 0,1 };
		}
		return addFrac(a, divFrac(b, c));
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ocnt = 0;
	int ccnt = 0;
	int t;
	cin >> t;
	vector<string> tokens(t);
	for (int i = 0; i < t; i++) {
		cin >> tokens[i];
		if (tokens[i] == "(") {
			ocnt++;
		}
		if (tokens[i] == ")") {
			ccnt++;
		}
	}
	if (ocnt != ccnt) {
		cout << -1;
		return 0;
	}
	int pos = 0;
	Fraction result = parseAndCompute(tokens, pos);
	if (result.numerator == 0 && result.denominator == 1) {
		cout << -1 << "\n";
		return 0;
	}
	int g = GCD(result.denominator, result.numerator);
	cout << result.numerator / g << " " << result.denominator / g <<"\n";
	return 0;
}