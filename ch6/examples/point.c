#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};

struct point makepoint  (int x, int y);
struct point addpoint (struct point p1, struct point p2);
int ptinrect (struct point p, struct rect r);
int ptinrect2 (struct point p, struct rect r);
struct rect canonrect (struct rect r);

int main (void) {
	struct rect r;
	struct point p = {7, 8};
	r.pt1 = makepoint (1, 10);
	r.pt2 = makepoint (8, 2);

	r = canonrect (r);
	printf("pt1 x %d pt1 y %d pt2 x %d pt2 y %d\n", r.pt1.x, r.pt1.y, r.pt2.x, r.pt2.y);

	return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint (int x, int y) {
	struct point p;
	p.x = x;
	p.y = y;

	return p;
}

/* addpoint: add two points */
struct point addpoint (struct point p1, struct point p2) {
	p1.x += p2.x;
	p1.y += p2.y;

	return p1;
}

/* ptinrect: return 1 if p in r 0 otherwise */
int ptinrect (struct point p, struct rect r) {
	return  p.x >= r.pt1.x && p.x < r.pt2.x &&
				 p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect (struct rect r) {
	struct rect temp;

	temp.pt1.x = MIN(r.pt1.x, r.pt2.x);
	temp.pt1.y = MIN(r.pt1.y, r.pt2.y);

	temp.pt2.x = MAX(r.pt1.x, r.pt2.x);
	temp.pt2.y = MAX(r.pt1.y, r.pt2.y);

	return temp;
}
