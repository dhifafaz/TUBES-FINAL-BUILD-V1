#include <bits/stdc++.h> 
#include "FUNCTIONS.cpp"
using namespace std; 

#define N 100


int main ()
{
	ofstream f("HASIL.txt",ios_base::app);
	BAMBANG :
	/////////////////////////////FILE STREAM////////////////////
	int sementara[N][N];
	int c;
	/////////////////////////////GAUS////////////////////
	int n , m;
	bool w = true;
	// batasan : n harus lah <=3, 
	float matrix [N] [N], temp, coba [m];
	/////////////////////////////BALIKAN//////////////////////////
	int ukuran;
	int mat[N][N];
	int adj[N][N]; // untuk menampung adj mat[][] 
	float inv[N][N]; // untuk menampung inverse mat][] 
	float hasil [N];
	//////////////////////////////JORDAN///////////////////////////////
	int a , b ;
    float jordan[N][N],solusi[N];
	/////////////////////////////cramer/////////////////////////////////////
	int kolom, baris ;
   	int cramer [N][N] ;
   	int cramertemp [N][N];
   	int hasil1 [N];
	int temporari [N];
	int hsl [N][N];
	
	int number;
	int menu1;
	
	cout << "\n1. SISTEM PERSAMAAN LINEAR \n2. MATRIKS BALIKAN (INVERSE) \n3. DETERMINAN \n";
	cout << "input nomor berapa : ";
	cin >> menu1 ;
	if (menu1==1) goto soal_1;
	else if (menu1==2) goto soal_2;
	else if (menu1==3) goto soal_3;
	else exit(0);
		
		
	soal_1:
		
		cout << "\n1. Metode eliminasi Gauss\n2. Metode eliminasi Gauss-Jordan\n3. Metode matriks balikan\n4. Kaidah Cramer\n";
		cout << "Masukkan pilihan : ";
		cin >> number;
		if (number == 1){
		
			cout << "\nGAUS "<<endl ;
			cout << "\nOrdo matriks N x M : \n";
			cin >> n >> m;
			cout << "Pilih metode input : \n";
			cout << "1 . Input Keyboard \n2 . Input File (Pastikan file berada dalam folder sama dan bernama 'input.txt' untuk file matriks, dan 'input_hasil.txt' untuk file matriks hasil) \n";
			cin >> c;
			if (c==1)
			{
				cout << "Masukkan matriksnya : ";
				inputM_float (matrix, n,m);
			}
			if (c==2){
				read_float(matrix, n, m);
			}
			cout << "Solusinya adalah : ";
			f<< "\nSolusinya adalah : ";
			Gaus (matrix, n, m, temp, coba, w);
			f.close();
		}
		if (number == 2) {
		
			cout << "\nGauss-Jordan"<< endl;
			cout << "Masukan nilai baris : ";
  			cin >> a ;
  			cout << "Masukan nilai kolom : ";
  			cin >> b ;
  			cout << "Pilih metode input : \n";
			cout << "1 . Input Keyboard \n2 . Input File (Pastikan file berada dalam folder sama dan bernama 'input.txt') \n";
			cin >> c;
			if (c==1)
			{
				cout << "\nMasukkan matriksnya :\n";
				inputM_float(jordan, a, b);
			}
			else if (c==2)
			{
				read_float (jordan, a, b);
			}
  			// untuk mencari tiap angka di diagonal pada matrix
   			for(int j=0; j<a; j++) 
			{
      			for(int i=0; i<b; i++) 
				{
         			if(i!=j) 
					{
            			temp=jordan[i][j]/jordan[j][j];
            			for(int k=0; k<b; k++) 
						{ 
               				jordan[i][k]=jordan[i][k]-temp*jordan[j][k];
            			}
         			}
      			}
   			}
   			if (b <= a+1)
			{
   				cout<<"\nSolusinya adalah : \n";
   				f<<"\nSolusinya adalah : \n";
   				for(int i=0; i<a; i++) 
				{
      				solusi[i]=jordan[i][b-1]/jordan[i][i];
      				cout<<"x"<<i+1 << "="<<solusi[i]<<" ";
      				f<<"x"<<i+1 << "="<<solusi[i]<<" ";
      				
		   		}
			}
			else 
			{
				cout << "Solusi Banyak "<< endl ;
				f<< "\nSolusi Banyak "<< endl ;
			}
			f.close();
  		}
   
			
		if (number == 3) {
		
			cout << "\nMatrix bolak balik "<< endl;
		
			cout << "UKURAN MATRIX : ";
	
			cin >> ukuran;
			
			cout << "Masukkan matrix "<< ukuran <<"x"<<ukuran <<" : "<< endl;
			cout << "Pilih metode input : \n";
			cout << "1 . Input Keyboard \n2 . Input File (Pastikan file berada dalam folder sama dan bernama 'input.txt' untuk file matriks, dan 'input_hasil.txt' untuk file matriks hasil) \n";
			cin >> c;
			if (c==1)
			{
				cout << "\nMasukkan matriksnya :\n";
				inputM_normal(mat, ukuran, ukuran);
				cout << "Masukkan matriks hasil : " << endl ;
				inputhsl_float(hasil, ukuran);
			}
			else if (c==2)
			{
				read_normal (mat, ukuran, ukuran);
				read_hasil_float (hasil, ukuran);
			}
			cout << "MATRIKSNYA :\n"; 
			tampilan(mat, ukuran); 

			cout << "\nADJOINNYA :\n"; 
			adjoint(mat, adj, ukuran); 
			tampilan(adj, ukuran); 

			cout << "\nINVERSENYA :\n"; 
			if (inverse(mat, inv, ukuran)) 
				tampilan(inv, ukuran); 
			
			
			balikan (hasil ,inv, ukuran) ;
	
		}
			
		if (number == 4){
		
	
			cout << "\nCramer "<< endl;
			cout << "Input kolom : ";
			cin >> kolom ;
			cout << "Input baris : ";
			cin >> baris ;
			cout << "Pilih metode input : \n";
			cout << "1 . Input Keyboard \n2 . Input File (Pastikan file berada dalam folder sama dan bernama 'input.txt' untuk file matriks, dan 'input_hasil.txt' untuk file matriks hasil) \n";
			cin >> c;
			
			if (c==1)
			{
				cout << "\nMasukkan matriksnya :\n ";
				for (int i = 0; i < kolom ; i++) 
				{ 
					for (int j = 0; j < baris; j++) 
					{ 
						cin >>cramer[i][j];
						cramertemp [i][j]=cramer[i][j];
					}
				}
				cout << "\nMasukkan matriks hasilnya :\n ";
				for (int j = 0; j <baris; j++) 
				{ 
					cin >> hasil1 [j];
				}
			cout << endl;
			}
			else if (c==2)
			{
				for (int i = 0; i < kolom ; i++) 
				{ 
					for (int j = 0; j < baris; j++) 
					{ 
						read_normal (cramer, kolom, baris);
						cramertemp [i][j]=cramer[i][j];
					}
				}
			
				int beda =0;
				for (int j = 0; j <baris; j++) 
				{ 
					read_hasil_normal(hasil1, baris);
					hsl [j][0]=hasil1[j];
				}
			cout << endl;
			}			
			cramerjing(cramer, cramertemp,hasil1,temporari,kolom, baris);
		}
	exit(0);
	soal_2:
		cout << "\nMatriks Balikan\nMasukkan ukuran yang diinginkan (NxN, N==N) : ";
		cin >> ukuran;
		
		cout << "\nPilih metode input : \n";
		cout << "1 . Input Keyboard \n2 . Input File (Pastikan file berada dalam folder sama dan bernama 'input.txt') \n";
		cin >> c;

		if (c==1)
		{
			cout << "\nMasukkan matriksnya :\n";
			inputM_normal(mat, ukuran, ukuran);
		}
		else if (c==2)
		{
			read_normal (mat, ukuran, ukuran);
		}
	
		cout << "MATRIKSNYA :\n";
		
		tampilan(mat, ukuran); 
	
		cout << "\nADJOINNYA :\n"; 
		 
		adjoint(mat, adj, ukuran); 
		tampilan(adj, ukuran); 

		cout << "\nINVERSENYA :\n"; 
		
		if (inverse(mat, inv, ukuran)) 
		tampilan(inv, ukuran);
		
		exit(0);
		
		
	soal_3:
		int pilih;
		cout << "\nDeterminan\n1 . Metode kofaktor\n2 . Metode reduksi baris\nPilih metode yang ingin dilakukan :";
		cin >> pilih;
		if (pilih == 1)
		{
			//ekspansi kofaktor
			cout << "\nMetode kofaktor\nMasukkan ukuran yang diinginkan (NxN, N==N) : ";
			cin >> ukuran;
			cout << "Pilih metode input : \n";
			cout << "1 . Input Keyboard \n2 . Input File (Pastikan file berada dalam folder sama dan bernama 'input.txt') \n";
			cin >> c;
			if (c==1)
			{
				cout << "\nMasukkan matriksnya :\n";
				inputM_normal(mat, ukuran, ukuran);
			}
			else if (c==2)
			{
				read_normal (mat, ukuran, ukuran);
			}
			
			int you1 = determinan_matriks(mat, ukuran);
			cout << "Determinannya adalah "<< you1;
			f << "\nDeterminannya adalah "<<you1<<endl;
			f.close();	
		}
		
		else if (pilih == 2)
		{
			//reduksi baris
			cout << "\nMetode reduksi baris\nMasukkan ukuran yang diinginkan (NxN, N==N) : ";
			cin >> ukuran;
			cout << "Pilih metode input : \n";
			cout << "1 . Input Keyboard \n2 . Input File (Pastikan file berada dalam folder sama dan bernama 'input.txt') \n";
			cin >> c;
		
			int matriks[N][N];
			if (c==1)
			{
				cout << "\nMasukkan matriksnya :\n";
				inputM_normal(matriks, ukuran, ukuran);
			}
			else if (c==2)
			{
				read_normal (matriks, ukuran, ukuran);
			}
					
			int you = determinan_matriks_reduksi(matriks, ukuran);
			cout << "Determinannya adalah "<< you;
			f << "\nDeterminannya adalah "<<you<<endl;
			f.close();
		}
	exit(0);
return 0;		
}
