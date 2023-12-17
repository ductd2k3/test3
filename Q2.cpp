#include<fstream>
#include<bits/stdc++.h>
using namespace std;
//Tao 1 struct sinh vien
//============================================================
struct CB{
	string maCB;
	string tenCB;
	int namSinh;
	string queQuan;
	string donVi;
	
	CB(){}
	CB(string maCBx, string tenCBx, int namSinhx, string queQuanx, string donVix){
		maCB = maCBx;
		tenCB = tenCBx;
		namSinh = namSinhx;
		queQuan = queQuanx;
		donVi = donVix;
	}
};
//==============================================================
//------------------------------------------------------
void hienThi(vector<CB> cb){
	cout << "So luong can bo: " << cb.size() << endl;
	cout << setw(10) << left <<"Ma CB"
		<< setw(30) << left <<"Ten CB"
		<< setw(10) << left <<"Nam Sinh"
		<< setw(10) << left <<"Que Quan"
		<< setw(10) << left <<"Don vi" << endl;
	for(int i = 0; i < cb.size(); i++){
		cout << setw(10) << left <<cb[i].maCB 
			 << setw(30) << left <<cb[i].tenCB
			 << setw(10) << left <<cb[i].namSinh
			 << setw(10) << left <<cb[i].queQuan
			 << setw(10) << left <<cb[i].donVi << endl;
	}
}
//----------------------------------------
void timKiem(vector<CB> cb){
	string name;
	bool timthay = false;
	cout << "Nhap ten ban muon tim: ";
	getline(cin, name);
	for(int i = 0; i < cb.size(); i++){
		if(name.compare(cb[i].tenCB) == 0){
			if(timthay == false){
				cout << setw(10) << left <<"Ma CB"
				<< setw(30) << left <<"Ten CB"
				<< setw(10) << left <<"Nam Sinh"
				<< setw(10) << left <<"Que Quan"
				<< setw(10) << left <<"Don Vi" << endl;
			}
			cout << setw(10) << left <<cb[i].maCB 
			 << setw(30) << left <<cb[i].tenCB
			 << setw(10) << left <<cb[i].namSinh
			 << setw(10) << left <<cb[i].queQuan
			 << setw(10) << left <<cb[i].donVi << endl;
			 timthay = true;
		}
	}
	if(timthay == false)
		cout << "Khong tim thay sinh vien";
}
//-------------------------------------------------------
bool trungID(vector<CB> cb, string id){
	for(int i = 0; i < cb.size(); i++){
		if(id.compare(cb[i].maCB) == 0)
			return true;
	}
	return false;
}
vector<CB> themMoi(vector<CB> cb){
	cout << "HAY NHAP THONG TIN HOC SINH MOI\n";
	string maCB;
	while(true){
		cout << "Ma can bo: "; getline(cin, maCB);
		if(trungID(cb, maCB) == false){
			break;
		}
		else{
			cout << "Ma can bo bi trung. Hay thu lai\n";
		}
	}
	cout << "Ten can bo: "; string tenCB; getline(cin, tenCB);
	cout << "Nam sinh: "; int namSinh; cin >> namSinh; cin.ignore();
	cout << "Que Quan: "; string queQuan; getline(cin, queQuan);
	cout << "Don Vi: "; string donvi; cin >> donvi; cin.ignore();
	CB s = CB(maCB, tenCB, namSinh, queQuan, donvi);
	cb.push_back(s);
	cout << "Them moi thanh cong\n";
	return cb;
}
//------------------------------------------------------------------

void phanLoai(vector<CB> cb){
	cout << "Phan Loai Sinh Vien\n";
	vector<CB> phanloaiDoanVien;

	for(int i = 0; i < cb.size(); i++){
		if(cb[i].namSinh >= 1988){
			phanloaiDoanVien.push_back(cb[i]);
		}
	}
	cout << "----------------Doan Vien----------------\n";
	hienThi(phanloaiDoanVien);
	cout << "\n";
}
//----------------------------------------------------------------

void tachchuoi(string str, string tach[]){
	int j = 0;
	string chucai = "";
	for(int i = 0; i < str.length(); i++){
		if(str[i] != ',' && j != 4){
			chucai += str[i];
		}
		else if(j == 4){
			for(int k = i; k<str.length(); k++){
				chucai += str[k];
			}
			tach[4] = chucai;
			return;
		}
		else{
			tach[j] = chucai;
			j++;
			chucai = "";
		}
	}
}

//doc file
vector<CB> docfcb(){
	fstream fs;
	fs.open("D:\\C_Cplus_plus_program\\CB.txt");

	vector<CB> cb;
	int soLuongCB = -1;
	while(!fs.eof()){
		if(soLuongCB == -1){
			fs >> soLuongCB;
			fs.ignore();
		}
		else{
			string sinhvien;
			getline(fs, sinhvien);
			string thanhphan[5];
			tachchuoi(sinhvien, thanhphan);
			int namsinh;
			istringstream(thanhphan[2]) >> namsinh;
			CB s = CB(thanhphan[0], thanhphan[1], namsinh, thanhphan[3], thanhphan[4]);
			cb.push_back(s);
		}
	}
	fs.close();
	return cb;	
}
//Luu file
void luufile(vector<CB> cb){
	fstream fs;
	fs.open("D:\\C_Cplus_plus_program\\CB.txt", ios::out | ios::trunc);
	fs << cb.size();
	for(int i = 0; i < cb.size(); i++){
		fs << "\n";
		ostringstream  namSinh; namSinh << cb[i].namSinh;
		string str = cb[i].maCB+","+cb[i].tenCB+","+namSinh.str()+","+cb[i].queQuan+","+cb[i].donVi;
		fs << str;
	}
	fs.close();
}


int main(){

//----------------------------------------
	int luaChon = -1;
	vector<CB> cb = docfcb();
	while(luaChon != 6){		
		cout << "\n<=========================QUAN LY SINH VIEN======================>\n";
		cout << "1. Hien thi toan bo danh sach\n";
		cout << "2. Them moi 1 can bo\n";
		cout << "3. Tim kiem theo ten\n";
		cout << "4. Doan vien\n";
		cout << "5. Luu danh sach\n";
		cout << "6. EXIT!\n";
		cout << "Lua chon cua ban: "; cin >> luaChon;
		cin.ignore();
		cout << "\n";
		switch(luaChon){
			case 1:
				hienThi(cb);
				cout << "\n--------------------------------------------------------------------------------";
				break;
			case 2:
				cb = themMoi(cb);
				cout << "\n--------------------------------------------------------------------------------";
				break;
			case 3:
				timKiem(cb);
				cout << "\n--------------------------------------------------------------------------------";
				break;
			case 4:
				phanLoai(cb);
				cout << "\n--------------------------------------------------------------------------------";
				break;
			case 5:
				luufile(cb);
				break;
		}
		
	}
		
	return 0;
}
// ghi file: fs << ...
// doc file: getline(fs, ...)
