int a = 5, b =8, c = 18;

if (b > 18) {
	c -= a;
	b /= 2;
	if (b == c)
		cout << 2 * b;
	else
		cout << c / 2;
}
else if (b >= 5 && c/3 > a) {
	c /= 2;
	a += b;
	if (b < c)
		cout << (c - b) * 2;
	else
		cout << (b - c) * 2;
}
else {
	a *= 2;
	c /= 4;
	if (c < b)
		cout << a;
	else
		cout << a/b + c;
}
