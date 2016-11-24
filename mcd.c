#include <math.h>

int mcd(int x, int y) {
	if (x<y) {
		int temp = x;
		x = y;
		y = temp;

	}


	if (x%y == 0) {
		return y;
	}
	else {
		int i = 0;
		while (y != 0) {

			y = x - y*((int)(x / y));

			if (x == y && i == 0) {
				return 1;
				break;
			}
			else if (y == 0) {
				return x;
				break;
			}
			i++;
			x = y;
		}
	}
}