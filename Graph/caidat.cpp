#include "thuvien.h"

// đọc file
int Read(const char* filename, AdjacencyMatrix& g)
{
	FILE* f;
	fopen_s(&f, filename, "rt");
	if (f == NULL) return 0;
	fscanf_s(f, "%d", &g.n);
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++) {
			fscanf_s(f, "%d", &g.mt[i][j]);
		}
	}
	fclose(f);
	return 1;
}

// ghi file
int Write(const char* filename, AdjacencyMatrix g)
{
	FILE* f;
	fopen_s(&f, filename, "wt");
	if (f == NULL) return 0;
	fprintf(f, "%d", g.n);
	for (int i = 0; i < g.n; i++)
	{
		fprintf(f, "\n");
		for (int j = 0; j < g.n; j++)
			fprintf(f, "%d\t", g.mt[i][j]);
	}
	fclose(f);
	return 1;
}
// xuất cạnh Edge ra màn hình
void printEdge(EDGE e)
{
	cout << "(" << (char)(e.dinhDau+65) << "," << (char)(e.dinhCuoi+65) << ")";
}
// Xuất danh sách cạnh Edge ra màn hình
void printArrayEdge(ArrayEdge ae)
{
	for (int i = 0; i < ae.count; i++)
	{
		cout << "\t";
		printEdge(ae.ds[i]);
	}
}

// Xuất ma trận kề ra màn hình 
void XuatAdjMatrix(AdjacencyMatrix g)
{
	cout << "\n Gia Tri Trong File La: ";
	cout << "\n" << g.n << "\n";
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
			cout << g.mt[i][j] << " ";
		cout << "\n";
	}
}

void displayMenu()
{
	cout << "\n==========================";
	cout << "\n\n\t\t1. Doc File do thi co huong !!";
	cout << "\n\n\t\t2. Doc File do thi vo huong !!";
	cout << "\n\n\t\t3. Ghi File !!";
	cout << "\n\n\t\t4. Tinh Bac Vao Cua Do Thi Co Huong: ";
	cout << "\n\n\t\t5. Tinh Bac Ra Cua Do Thi Co Huong: ";
	cout << "\n\n\t\t6. Tim Cac Cap Canh Cua Do Thi. ";
	cout << "\n\n\t\t7. Tim Trong So Lon Nhat Trong Cac Canh ";
	cout << "\n\n\t\t0. Dung Lai !!!";
	cout << "\n==========================";
}

// hàm tính bậc vào độ thị có hướng 
int tinhBacVaoDTCoHuong(AdjacencyMatrix g, int v)
{
	int dem = 0;
	for (int i = 0; i < g.n;i++)
	{
		if (g.mt[i][v] != 0)
			dem++;
	}
	return dem;
}
// hàm tính bậc ra độ thị có hướng 
int tinhBacRaDTCoHuong(AdjacencyMatrix g, int v)
{
	int dem = 0;
	for (int i = 0; i < g.n; i++)
	{
		if (g.mt[v][i] != 0)
			dem++;
	}
	return dem;
}
// hàm trả về tập cạnh của đồ thị có hướng 
ArrayEdge tapCanhDTCH(AdjacencyMatrix g)
{
	ArrayEdge tapCanh;
	tapCanh.count = 0;
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			if (g.mt[i][j] != 0)
			{
				EDGE e;
				e.dinhDau = i;
				e.dinhCuoi = j;
				e.trongso = g.mt[i][j];
				tapCanh.ds[tapCanh.count] = e;
				tapCanh.count++;
			}
		}
	}
	return tapCanh;
}
// tìm tập cạnh có trọng số lớn nhất
// tìm trọng số lớn nhất trong các cạnh 


