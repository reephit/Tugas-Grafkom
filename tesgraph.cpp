/*
 * tesgraph.cpp
 *
 *  Created on: Mar 30, 2013
 *      Author: Reza  */

#include <graphics.h>
#include <stdio.h>

//Prosedur DDA
void garisDDA(int x1, int y1, int x2, int y2, int warna) {
	int step, k;
	float increamentX, increamentY, x = x1, y = y1;

	int deltaX = x2 - x1;
	int deltaY = y2 - y1;

	if (abs(deltaX) > abs(deltaY)) {
		step = deltaX;
	} else {
		step = deltaY;
	}

	increamentX = deltaX / step;
	increamentY = deltaY / step;

	putpixel(x, y, warna);
	for (k = 0; k < step; ++k) {

		x += increamentX;
		y += increamentY;
		putpixel(x, y, warna);
	}
	outtextxy(x, y, "Garis DDA");
}

//Prosedur Bresenham
void garisBresenham(int x1, int y1, int x2, int y2, int warna) {
	int step, x, y, pk;

	int deltaX = x2 - x1;
	int deltaY = y2 - y1;

	int deltaX2 = deltaX * 2;
	int deltaY2 = deltaY * 2;

	int deltaY2MinDeltaX2 = deltaY2 - deltaX2;
	int p0 = deltaY2 - deltaX;
	step = deltaX;

	if (x1 > x2) {
		x = x2;
		y = y2;
		x2 = x;
	} else {
		x = x1;
		y = y1;
	}
	putpixel(x, y, warna);
	pk = p0;
	x = x - 1;
	y = y - 1;

	while (x <= x2) {

		x++;

		if (pk < 0) {
			pk += deltaY2;
		} else {
			y++;
			pk += deltaY2MinDeltaX2;
		}
		putpixel(x, y, warna);
	}
	outtextxy(x, y, "Garis Bresenham");
}

void midPoint(int x1, int y1, int x2, int y2, int warna)
// Algorith midpoint
// It is assumed that x1 < x2 and the gradient is less than 1.
		{
	int x, y = y1;
	int a = y2 - y1;
	int b = x2 - x1;
	int G = 2 * a - b; // Decision variable
	int DeltaG1 = 2 * (a - b);
	int DeltaG2 = 2 * a;

	for (x = x1; x <= x2; x++) {
		if (G > 0) {
			G += DeltaG1;
			y++;
			;    // Next column and row.
			putpixel(x, y, warna);
		} else {
			G += DeltaG2;
			// y not changed     // Next column.
			putpixel(x, y, warna);
		}
	}
	outtextxy(x, y, "Garis Midpoint");
}

void circ_mid(int xc, int yc, int r, int warna) {
	int x, y, G, DeltaG1, DeltaG2;
	x = 0;
	y = r;
	G = 1 - r;
	DeltaG1 = 3;
	DeltaG2 = -2 * r + 5;
	while (x < y) {
		if (G < 0) {
			G += DeltaG1;
			DeltaG1 += 2;
			DeltaG2 = DeltaG2 + 2;
		} else {
			G += DeltaG2;
			DeltaG1 += 2;
			DeltaG2 += 4;
			y--;
		}
		x++;
		putpixel(xc + x, yc + y, warna);
	}
	outtextxy(xc + x, yc + y, "Circle Midpoint");
}

int main(int argc, char **argv) {

	int gdriver = DETECT, gmode = VGAMAX;
	initgraph(&gdriver, &gmode, 0);
	putpixel(10,40,5);

	//panggil prosedur garis dda
	garisDDA(10, 10, 300, 300, 1);
	//panggil prosedur garis bresenham
	garisBresenham(10, 20, 300, 350, 2);
	//panggil prosedur midpoint
	midPoint(10, 30, 300, 400, 3);
	//setengah lingkaran
	circ_mid(300, 100, 200, 4);
	getch();
	system("PAUSE");
	closegraph();

	return 0;
}
