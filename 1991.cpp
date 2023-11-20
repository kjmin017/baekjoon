#include <iostream>
#include <vector>
#define MAX 26

using namespace std;

struct node {
	char left;
	char right;
};

vector<node> v(MAX);

void preOrder(char node) { 
	if (node == '.') return;
	printf("%c", node);
	preOrder(v[node - 'A'].left);
	preOrder(v[node - 'A'].right);
}

void inOrder(char node) {
	if (node == '.') return;
	inOrder(v[node - 'A'].left);
	printf("%c", node);
	inOrder(v[node - 'A'].right);
}

void postOrder(char node) {
	if (node == '.') return;
	postOrder(v[node - 'A'].left);
	postOrder(v[node - 'A'].right);
	printf("%c", node);
}

int main() {
	int n;
	scanf("%d", &n);

	char rt, l, r;
	for (int i = 0; i < n; i++) {
		cin >> rt >> l >> r;
		v[rt - 'A'].left = l;
		v[rt - 'A'].right = r;
	}

	preOrder('A');
	printf("\n");

	inOrder('A');
	printf("\n");

	postOrder('A');

	return 0;
}
