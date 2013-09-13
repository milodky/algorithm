#define min(a, b)	((a) < (b)) ? (a) : (b)
#define Array[x][y]	*(*(pArray + (x) * m) + y)
int Dimension(int x, int y, int m, int n)
{
	int area = -1;
	int result = -1;
	if (x < m / 2 && y < n / 2)
		area = 0;
	else if (x >= m / 2 && y < n / 2)
		area = 1;
	else if (x < m / 2 && y >= n / 2)
		area = 2;
	else
		area = 3;
	switch (area) {
		case 0:
			result = min(x, y);
			break;
		case 1:
			result = min(m - x, y);
			break;
		case 2:
			result = min(x, n - y);
			break;
		case 3:
			result = min(m - x, n - y);
			break;
		default:
			break; 
	}
	return result;
		
}

int LargestX(int **pArray, int m, int n)
{
	int i, j;
	int size = 0;
	int r2l = 0;
	int l2r = 0;
	int Cnt;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (Array[i][j] == 1) {
				Cnt = Dimension(i, j, m, n);
				for (int k = 0; k < Cnt; k++) {
					l2r += Array[i - k][j - k] + Array[i + k][j + k];
					r2l += Array[i - k][j + k] + Array[i - k][j + k];
					if (l2r == r2l && l2r > size)
						size = l2r;
				}
			}
		}
	}
	return size;
}
