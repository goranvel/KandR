
int a(int *b) {
	*b = 5;
}

int b() {
	int *c;
	a(c);
}
