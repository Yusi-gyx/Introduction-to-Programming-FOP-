#include<iostream>
using namespace std ;

///v1
int a[] = {5, 2, 6, 1, 7, 3, 4}; /// 全局数组变量
void sort(int z, int y)
{
	if (z >= y)
		return;

	int zz = z, yy = y, k = a[z], m = 0;
	do
	{
		/// scan from right to left
		while ((zz < yy) && (a[yy] > k))
			yy--;
		if (zz < yy)
			a[zz++] = a[yy];

		/// scan from left to right
		while ((zz < yy) && (a[zz] <= k))
			zz++;
		if (zz < yy)
			a[yy--] = a[zz];
	} while (zz != yy);
	m = zz;	  /// 找到了分区点，记录到m中
	a[m] = k; /// 完成分区操作（数值k归位）

	sort(z, m - 1);
	sort(m + 1, y);
}
int main()
{
	int len = sizeof(a) / sizeof(a[0]);
	sort(0, len - 1);

	for (int i = 0; i < len; i++)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
}


///v2(将分组与排序分开)
int split(int array[], int low, int high)
{
	int z = low, y = high - 1, k = array[z];
	do
	{
		/// scan from right to left
		while ((z < y) && (array[y] > k))
			y--;
		if (z < y)
			array[z++] = array[y];
		/// scan from left to right
		while ((z < y) && (array[z] <= k))
			z++;
		if (z < y)
			array[y--] = array[z];
	} while (z != y);
	array[z] = k;
	return z;
}
void sort(int array[], int low, int high)
{
	if (low >= high - 1)
		return;
	int z = split(array, low, high);
	sort(array, low, z);
	sort(array, z + 1, high);
}
int main()
{
	int a[] = {5, 2, 6, 1, 7, 3, 4};
	int len = sizeof(a) / sizeof(a[0]);
	sort(a, 0, len);
	for (int i = 0; i < len; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}
