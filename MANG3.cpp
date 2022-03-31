#include<iostream>
using namespace std;
void nhapmang(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]=";
		cin >> A[i];
	}
}
void am(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (A[i] < 0)
			cout << "A[" << i << "]=" << A[i] << endl;
	}
}
void Min(int A[], int n)
{
	int vitri = 0;
	int min = A[0];
	for (int i = 0; i < n; i++)
	{
		if (min > A[i])
		{
			min = A[i];
			vitri = i;
		}
	}
	cout << "A[" << vitri << "]=" << min << endl;
}
void Max(int A[], int n)
{
	int vitri = 0;
	int max = A[0];
	for (int i = 0; i < n; i++)
	{
		if (max < A[i])
		{
			max = A[i];
			vitri = i;
		}
	}
	cout << "A[" << vitri << "]=" << max << endl;
}
void am1(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (A[i] < 0)
		{
			cout << "A[" << i << "]=" << A[i] << endl;
			return;
		}
	}
	cout << -1 << endl;
}
void duong(int A[], int n)
{
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] > 0)
			tong += A[i];
	}
	cout << tong << endl;
}
void tangamgiamduong(int A[], int n)
{
	int doi1, doi2, i, j;
	for (int i = 0; i < n; i++)
	{
		if (A[i] < 0)
		{
			for (int i = 0; i < n; i++)
				for (int j = 1; j < n; j++)
					if (A[i] < A[j])
					{
						doi1 = A[i];
						A[i] = A[j];
						A[j] = doi1;
					}
			cout << A[i]<<" ";
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (A[i] >= 0)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (A[i] > A[j])
					{
						doi2 = A[i];
						A[i] = A[j];
						A[j] = doi2;
					}
			cout << A[i] << " ";
		}
	}
}
int main()
{
	int n;
	cout << "nhap so phan tu : ";
	cin >> n;
	int* A = new int[n];
	nhapmang(A, n);
	cout << "phan tu am cua mang" << endl;
	am(A, n);
	cout << "vi tri cua phan tu nho nhat:";
	Min(A, n);
	cout << "vi tri cua phan tu lon nhat:";
	Max(A, n);
	cout << "phan tu am dau tien:";
	am1(A, n);
	cout << "tong cac phan tu duong:";
	duong(A, n);
	cout << "tang dan so am va giam dan so duong:";
	tangamgiamduong(A, n);
}
