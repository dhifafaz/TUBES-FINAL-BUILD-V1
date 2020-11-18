#include<bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std; 
#define N 100

void read_normal ( int sementara [N][N],int baris, int kolom)
{
	fstream f;
	f.open	("input.txt");
	// check error atau tidak
	if (f.fail())
	{
		cerr << "Error Saat Membuka File"<<endl;
		exit(1); 
	}

		for (int i=0; i<baris; i++)
		{
			for (int j = 0; j< kolom; j++)
			{
				f >> sementara [i][j];
			}
		}
	

}

void read_float ( float sementara [N][N],int baris, int kolom)
{
	fstream f;
	f.open	("input.txt");
	// check error atau tidak
	if (f.fail())
	{
		cerr << "Error Saat Membuka File"<<endl;
		exit(1); 
	}

		for (int i=0; i<baris; i++)
		{
			for (int j = 0; j< kolom; j++)
			{
				f >> sementara [i][j];
			}
		}
	

}

void read_hasil_normal ( int smntr [N],int baris)
{
	fstream f;
	f.open	("input_hasil.txt");
	// check error atau tidak
	if (f.fail())
	{
		cerr << "Error Saat Membuka File"<<endl;
		exit(1); 
	}
	
	
		for (int j = 0; j< baris; j++)
			{
				f >> smntr [j];
			}
	
}
void read_hasil_float ( float smntr [N],int baris)
{
	fstream f;
	f.open	("input_hasil.txt");
	// check error atau tidak
	if (f.fail())
	{
		cerr << "Error Saat Membuka File"<<endl;
		exit(1); 
	}
	
	
		for (int j = 0; j< baris; j++)
			{
				f >> smntr [j];
			}
	
}

void inputM_float (float matrix [][N], int a, int b)
{
	for (int i = 0; i < a ; i ++){
			for (int j = 0 ; j < b ; j ++){
				cin >> matrix [i][j] ;
			}
		}
}
void inputhsl_float (float hsl[N], int a)
{
	for (int i = 0; i < a ; i ++){
		cin >> hsl [i] ;
	}
	
}
void inputM_normal (int matrix [N][N], int a, int b)
{
	for (int i = 0; i < a ; i ++){
			for (int j = 0 ; j < b ; j ++){
				cin >> matrix [i][j] ;
			}
		}
}


// Fungsi kofaktor
void kofaktor(int mat[N][N], int temp[N][N], int p, int q, int ukuran) 
{ 
	int i = 0, j = 0; 

	// Looping for setiap elemen dalam baris 
	for (int baris = 0; baris < ukuran; baris++) 
	{ 
		for (int kolom = 0; kolom < ukuran; kolom++) 
		{ 
			//kopi semua matriks yang tidak termasuk baris dan kolom yg ditentukan
			if (baris != p && kolom != q) 
			{ 
				temp[i][j++] = mat[baris][kolom]; 

				//baris udah penuh keisi, terus baris++, dan indeks kolom direset biar ga lompat kebawah
				// reset kolom 
				if (j == ukuran - 1) 
				{ 
					j = 0; 
					i++; 
				} 
			} 
		} 
	} 
} 

/* Rekursif untuk mencari determinan matriks. 
n adalah ukuran mat[][] di kondisi sekarang(n nanti bakal berubah sampe ukurannya 1). */
int determinan_matriks(int mat[N][N], int ukuran) 
{ 
	int determinan = 0; // inisialisasi determinan

	// Base case (ketika matriks hanya berisi satu anggota(ordo 1*1)) 
	if (ukuran == 1) 
		return mat[0][0]; 

	int temp[N][N]; // tempat nyimpen kofaktor nanti

	int patokan = 1; // tanda perkalian kofaktor (1), agar kofaktor menjadi +, -, +, - dst

	// iterasi setiap elemen 
	for (int f = 0; f < ukuran; f++) 
	{ 
		// mencari kofaktor mat[0][f] (f adalah perpindahan ke indeks kolom baru)
		kofaktor(mat, temp, 0, f, ukuran);

		determinan += patokan * mat[0][f] * determinan_matriks(temp, ukuran - 1); 

		// ketentuan polanya setiap indeks kolom ganjil adalah bertanda minus (0,1,2,3) -> (+, -, +, -)
		patokan = -patokan; 
	} 
	return determinan; 
} 
// Function untuk mencari adj dari mat[N][N] yang disimpan ke  adj[N][N]. 
void adjoint(int mat[N][N],int adj[N][N], int ukuran) 
{ 
	if (ukuran == 1) 
	{ 
		adj[0][0] = 1; 
		return; 
	} 
	//temp untuk menyimpan kofaktor A[][] 
	int tanda = 1, temp[N][N]; 
	for (int i=0; i<ukuran; i++) 
	{ 
		for (int j=0; j<ukuran; j++) 
		{ 
			// kofaktor A[i][j] 
			kofaktor(mat, temp, i, j, ukuran); 
			// tanda adj akan positif jika total nilai indeks i dan j adalah genap
			tanda = ((i+j)%2==0)? 1: -1; 
			//menjadikan matriks adj sebagai adj^T (transposenya)
			adj[j][i] = (tanda)*(determinan_matriks(temp, ukuran-1)); 
		} 
	} 
} 
// fungsi untuk menyimpan nilai inverse dan bakal salah kalau matriks yang dikerjakan adalah matriks singular
bool inverse(int mat[N][N], float inverse[N][N], int ukuran) 
{ 
	// nyari determinan matriks normal mat[][] 
	int det = determinan_matriks(mat, ukuran); 
	if (det == 0) 
	{ 
		cout << "Matriks ini singular sehingga tidak ada inverse"; 
		return false; 
	} 
	//mencari adj 
	int adj[N][N]; 
	adjoint(mat, adj, ukuran); 

	// cari inverse dengan rumus "inverse(A) = adj(A)/det(A)" 
	for (int i=0; i<ukuran; i++) 
		for (int j=0; j<ukuran; j++) 
			inverse[i][j] = adj[i][j]/float(det); 

	return true; 
} 
// fungsi untuk menampilkan matriks baik adjoint dan inverse, adjoint dalam bentuk integer dan inverse dalam bentuk float
template<class T> 
void tampilan(T mat[N][N], int ukuran) 
{ 
	ofstream f("HASIL.txt",ios_base::app);
	f<<endl<<endl;
	for (int i=0; i<ukuran; i++) 
	{ 
		
		for (int j=0; j<ukuran; j++)
		{ 
			cout << mat[i][j] << " "; 
			f << mat[i][j] << " "; 
		}
		cout << endl;
		f << endl; 
	} 
	f.close();	
} 

void balikan(float hasil[N], float mat[N][N], int ukuran ){
	ofstream f("HASIL.txt",ios_base::app);
	float temp [ukuran];
	temp [0] = 0 ;
	for (int i=0; i<ukuran; i++) { 
		for (int j=0; j<ukuran; j++)
		 	temp [i]+=  mat[i][j] * hasil[j];
	
	} 
	cout << "\nMATRIX BALIKAN : ";
	f << "\nMATRIX BALIKAN : ";
	for (int i=0; i<ukuran; i++) {
		cout << temp [i] << " ";
		f <<temp [i] << " ";
	}
	f.close();
}


void Gaus (float matrix [][N], int n, int m, float temp, float coba[], bool w)
{
	cout << "Gauss "<< endl;
			ofstream f("HASIL.txt",ios_base::app);
			for (int i = 0; i < n ; i ++){
				for (int j = 0 ; j < m ; j ++){
				
				if (j == 0) temp = matrix [i][j];
					
				if (i == 0)
				{
					matrix [i][j] /= temp ;
					coba [j] = matrix [i][j] ;
					
					if (j == m-1) w = false ;
					
					if (!w) {
					
						for (int i = 0; i < n ; i ++){
							for (int j = 0 ; j < m ; j ++){
								cout << matrix [i][j] << " ";
								f<< matrix [i][j] << " ";
						}
						
						cout << endl;
						f<<endl;
						}
						cout << endl << endl ;
						f<<endl<<endl;	
						
					}
				}	
			if (i == 1)
				{
					w = true ;
					matrix [i][j] += ((temp * -1) * coba [j]) ;
					coba [j] = matrix [i][j] ;
					
						if (j == m-1) w = false ;
						if (!w) {
							temp = matrix [i][1];
							
							for (int k = 0 ; k < m ; k++) {
								matrix [1][k] /= temp ;
								coba [k] = matrix [1][k] ;
							}
					
						for (int i = 0; i < n ; i ++){
							for (int j = 0 ; j < m ; j ++){
								cout << matrix [i][j] << " ";
								f << matrix [i][j] << " ";
								
						}
						
						cout << endl;
						f<<endl;
						}
						cout << endl << endl ;
						f<<endl<<endl;	
					}
					
				}
				if (i == 2){
					w = true ;
					matrix [i][j] *= coba[j] ;
					if (j == m-1){
						temp = matrix [i][i-1];
						for (int k = 0 ; k<m; k++)
						{
							matrix [i][k] += ((temp * -1) * coba [k]) ;
						}
						temp = matrix [i][i] ;
						for (int k = 0 ; k<m; k++)
						{
							matrix [i][k] /= temp ;
							coba [k] = matrix [i][k];
						}
						
					}
				} 			
			}
		}
		cout << "temp : "<< temp  << endl << "coba : ";
		f<< "temp : "<< temp  << endl << "coba : ";
		for (int j = 0 ; j < m ; j ++) 
		{
			cout << coba [j] << " ";
			f << coba [j] << " ";
		}
			cout << "\nHASIL : " << endl ;
			f<< "\nHASIL : " << endl ;
			for (int i = 0; i < n ; i ++){
				for (int j = 0 ; j < m ; j ++){
					cout<<matrix [i][j] << " ";
					f<<matrix [i][j] << " ";
				}
				cout << endl;
				f<<endl;
			}
}

int determinan_matriks_reduksi(int matriks[N][N], int n) 
{ 
	int x1,x2,det = 1,index,total = 1; // inisiasi awal
	// array temp untuk menyimpan baris 
	int temp[n + 1]; 
	// For loop untuk mengecek semua bilangan yang terletak di diagonal
	for(int i = 0; i < n; i++) 
	{ 
		//inisiasi indeksnya
		index = i; 
		//while untuk ngecek angka-angka yang ada diagonal matriks  
		while(matriks[index][i] == 0 && index < n) 
		{ 
			index++; // Jika nilai indeks di diagonal 0 maka akan dilanjut mencari bil. tidak nol di kolom yang sama	 
		} 
		if(index == n) //kalo diagonalnya nol semua maka det akan 0  
		{  
			continue; 
		} 
		if(index != i) //kalo indeks kolomnya pindah kebawahnya maka akan ditukar posisi barisnya dengan baris yang diatsnya(yang punya 0)
		{ 
			//loop untuk menukar baris tadi
			for(int j = 0; j < n; j++) 
			{ 
				swap(matriks[index][j],matriks[i][j]);	 
			} 
				//tanda determinan akan berubah kalo baris ditukar (sesuai aturan)
				det = det*pow(-1,index-i);	 
	} 		
	//menyimpan nilai diagonal tadi 
	for(int j = 0; j < n; j++) 
	{ 
		temp[j] = matriks[i][j]; 			
	} 
	//men-cek setiap baris yang ada dibawah diagonal
	for(int j = i+1; j < n; j++) 
	{ 
		x1 = temp[i]; //nilai dari diagonal yang sudah disimpan tadi 
		x2 = matriks[j][i]; //nilai dari baris selanjutnya 
		//men-cek setiap kolom dalam satu baris dan mengalikan dengan semua baris 
		for(int k = 0; k < n; k++) 
		{ 
			matriks[j][k] = (x1 * matriks[j][k]) - (x2 * temp[k]); 	//perkalian untuk membuat nilai diagonal dan nilai pada baris selanjutnya setara
		} 
		total = total * x1; //Det(kA)=kDet(A) 
		} 	
	} 
	//mengakalikan diagonal untuk mencari nilai determinan 
	for(int i = 0; i < n; i++) 
	{ 
		det = det * matriks[i][i]; 			
	} 
	return (det/total); //Det(kA)/k=Det(A); 
	} 
	
	void cramerjing (int cramer[N][N],int cramertemp[N][N], int hasil[N],int temporari[N],int kolom, int baris){
	int count = 0;
	cout << "Berikut adalah penjabaran dari proses yang terjadi pada matriksnya : \n"; 
	//while untuk mengganti setiap kolom dengan hasil sesuai kaidah cramer serta langsung mencari determinannya
	ofstream f("HASIL.txt",ios_base::app);
			while (count <=kolom)
			{
				for (int i = 0; i < kolom ; i++) 
				{ 
					for (int j = 0; j < baris; j++) 
					{ 
						cramer[i][j]=cramertemp[i][j];	
					}
				}
				for (int i = 0; i < baris; i++) 
				{ 
					cramer [i][count]=hasil [i];		
				}
				cout <<endl;					
				f<<endl;		
				for (int i = 0; i < kolom; i++) 
				{ 
					for (int j = 0; j < baris; j++) 
					{ 
						cout <<cramer[i][j]<< " ";
						f << cramer[i][j]<< " ";
					}
					cout << endl;
					f << endl;
				}
				temporari[count]  = determinan_matriks_reduksi (cramer,kolom);
				count++;
			}
			cout << endl;
			f << endl;
			for (int i = 0; i <baris; i++)
				{	
					if (temporari[baris]!=0)
					{
					cout << "X"<<i+1<< " : "<< temporari [i] << "/" << temporari [baris] << endl;
					f<< "X"<<i+1<< " : "<< temporari [i] << "/" << temporari [baris] << endl;
					}
					else
					{
						cout << "Tidak ada solusinya atau solusi banyak\n.";
						f<< "Tidak ada solusinya atau solusi banyak\n.";
						break;
					}
				}
}

	

