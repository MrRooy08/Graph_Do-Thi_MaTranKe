#include <iostream>
using namespace std;

// MAXV: số đỉnh tối đa
const int MAXV = 20;

// MAXE: số cạnh tối đa 
const int MAXE = MAXV * MAXV;

//VERTEX: kiểu của một đỉnh
typedef int VERTEX;

//EDGE: kiểu của một cạnh 
struct EDGE
{
	VERTEX dinhDau;
	VERTEX dinhCuoi;
	int trongso;
};

// ArrayEdge: danh sách cạnh
struct ArrayEdge
{
	EDGE ds[MAXE];
	int count;
};

//Ma trận kề của đồ thị (Adjacency-Matrix)
struct AdjacencyMatrix
{
	int mt[MAXV][MAXV];
	int n;
};

// đọc file
int Read(const char* filename, AdjacencyMatrix &g);
// ghi file
int Write(const char* filename, AdjacencyMatrix g);
// xuất cạnh
void printEdge(EDGE e);
// xuất danh sách cạnh
void printArrayEdge(ArrayEdge ae);
// xuất ma trận kề 
void XuatAdjMatrix(AdjacencyMatrix g);
// Menu chọn 
void displayMenu();
// tính bậc vào 
int tinhBacVaoDTCoHuong(AdjacencyMatrix, int);
// tính bậc ra
int tinhBacRaDTCoHuong(AdjacencyMatrix, int); 
// tìm cập cạnh của đồ thị 
ArrayEdge tapCanhDTCH(AdjacencyMatrix g);
//tìm trọng số lớn nhất 
bool timTrongSoLonNhat(ArrayEdge ae, int &maxTrongSo);

