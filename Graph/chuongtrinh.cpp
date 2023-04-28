#include "thuvien.h"
int main()
{
	AdjacencyMatrix g;
	ArrayEdge tapCanh;
	int choice,dinh;
	bool isRunning = true;
	while (isRunning)
	{
		displayMenu();
		cout << "\n Lua Chon 1 So De Thuc Thi: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			Read("doThiCoHuong.txt", g);
			XuatAdjMatrix(g);
			break;
		case 2:
			system("cls");
			Read("doThiVoHuong.txt", g);
			XuatAdjMatrix(g);
			break;
		case 3:
			system("cls");
			cout << "\n Ghi File ";
			Write("ghiFile.txt", g);
			XuatAdjMatrix(g);
			break;
		case 4:
			system("cls");
			int temp;
			cout << "\n Nhap Dinh Muon Tinh Bac Vao: ";
			cin >> dinh;
			temp = tinhBacVaoDTCoHuong(g, dinh);
			cout<<"\n So Bac Vao Cua Dinh "<<dinh<<" La: " << temp;
			break;
		case 5:
			system("cls");
			cout << "\n Nhap Dinh Muon Tinh Bac ra: ";
			cin >> dinh;
			temp = tinhBacRaDTCoHuong(g, dinh);
			cout << "\n So Bac ra Cua Dinh " << dinh << " La: " << temp;
			break;
		case 6:
			system("cls");
			tapCanh = tapCanhDTCH(g);
			if (tapCanh.count == 0)
			{
				cout << "\n Do Thi Kh Co Canh Nao. ";
			}
			else
			{
				printArrayEdge(tapCanh);
			}
			cout << "\n";
			break;
		case 7:
			system("cls");
			int max;
			tapCanh = tapCanhDTCH(g);
			if (timTrongSoLonNhat(tapCanh, max))
			{
				cout << "\n Trong So Lon Nhat La: " << max;
			}
			break;
		case 0:
			isRunning = false;
			break;
		default:
			cout << "\n Lua chon khong hop le. Vui Long Nhap Lai ";
			break;
		}
	}
	
}