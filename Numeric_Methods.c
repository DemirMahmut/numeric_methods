#include <stdio.h>
#include <math.h>
#define STRING	100
#define BOYUT	10
#define BOYUT2  20

// math.h kutuphanesinde bulunan fakat elle yazdigim pow fonksiyonu
double usAl(double taban, double us){
	double sonuc = 1;
	int i;
	if(us < 0){
		for(i = 0; i > us; i--){
			sonuc /= taban;
		}
	}
	else{
		for(i = 0; i < us; i++){
			sonuc *= taban;
		}
	}
	return sonuc;
}
// Polinomu kullanicidan alan fonksiyon
void polinomAl(double pol[2][BOYUT],int xSayisi){
    int	i;

    for (i = 0; i < xSayisi; i++){
        printf("x'in kuvvetini giriniz: ");
        scanf("%lf",&pol[0][i]);

        printf("x'in katsayisini giriniz: ");
        scanf("%lf",&pol[1][i]);
    }
}
// Polinom cozmeye yarayan fonksiyon
double PolinomHesapla(double pol[2][BOYUT], double x, int xSayisi){
    int i;
    double sonuc = 0;
    for(i = 0; i < xSayisi; i++){
        sonuc += pol[1][i]*usAl(x,pol[0][i]);
    }
    return sonuc;
}
void TurevAl(double pol[2][BOYUT], double TurevliPol[2][BOYUT], int xSayisi){
	int	i;
	
	for(i = 0; i < xSayisi; i++){
		TurevliPol[0][i] = pol[0][i];
		TurevliPol[1][i] = pol[1][i];
	}
	
	for(i = 0; i < xSayisi; i++){
		if(TurevliPol[0][i] == 0){
			TurevliPol[1][i] = 0;
		}else{
			TurevliPol[1][i] *= TurevliPol[0][i];
			TurevliPol[0][i]--;
		}
	}
}
void matris_al(double matris[BOYUT][BOYUT], int N){
	int	i,j;
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("[%d][%d]: ",i,j);
			scanf("%lf",&matris[i][j]);
		}
		printf("\n");
	}
}
void sonuc_matris_al(double sonuc_matris[BOYUT][1], int N){
	int	i,j;
	
	for(i = 0; i < N; i++){
		printf("sonuc matris[%d][0]: ",i);
		scanf("%lf",&sonuc_matris[i][0]);
		printf("\n");
	}
}
void GaussYap(double matris[BOYUT][BOYUT], double sonuc_matris[BOYUT][1], int N){
	int i,j,k;
	double	sifirla; // Sifirlamaya calistigimiz eleman
	double	kosegen; // Kosegendeki eleman sayisi
	
	for(i = 0; i < N; i++){
		kosegen = matris[i][i];
		for(j = i+1; j < N; j++){
			sifirla = matris[j][i];
			for(k = i; k < N; k++){
				matris[j][k] = matris[j][k]*kosegen/sifirla;
				matris[j][k] = matris[i][k] - matris[j][k];
			}
			sonuc_matris[j][0] = sonuc_matris[j][0]*kosegen/sifirla;
			sonuc_matris[j][0] = sonuc_matris[i][0] - sonuc_matris[j][0];
		}
	}
}
void GaussCoz(double matris[BOYUT][BOYUT], double sonuc_matris[BOYUT][1], double degiskenler[BOYUT], int N){
	int 	i,j;
	
	for(i = N-1; i >= 0; i--){
		degiskenler[i] = sonuc_matris[i][0]/matris[i][i];
		for(j = N-1; j >= 0; j--){
			sonuc_matris[j][0] = sonuc_matris[j][0] - matris[j][i]*degiskenler[i];
		}
	}
	
	for(i = 0; i < N; i++){
		printf("x%d= %lf ",i+1 ,degiskenler[i]);
	}
}	
double	determinant(double matris[BOYUT][BOYUT], int N){
	int 	i,j,k;
	double	kosegen; // Kosegendeki eleman
	double	sifirla; // Sifirlamak istedigimiz eleman
	double	det = 1;
	double 	kontrol_matris[BOYUT][BOYUT]; 
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			kontrol_matris[i][j] = matris[i][j];
		}
	}

	for(i = 0; i < N; i++){
		kosegen = kontrol_matris[i][i];
		for(j = i+1; j < N; j++){
			sifirla = kontrol_matris[j][i];
			for(k = i; k < N; k++){
				kontrol_matris[j][k] = kontrol_matris[j][k]*kosegen/sifirla;
				kontrol_matris[j][k] = kontrol_matris[i][k] - kontrol_matris[j][k];
			}
			det = det*sifirla/kosegen;
			det *= -1;
		}
	}
	
	for(i = 0; i < N; i++){
		det *= kontrol_matris[i][i];
	}
	
	return det;
}
void MatrisTersi(double matris[BOYUT][BOYUT], int N){
	int 	i,j,k;
	double 	kosegen;
	double 	birimMatris[BOYUT][BOYUT];
	for(i = 0; i < 10; i++){		    //{1,0,0,0,0,0,0,0,0,0},
		for(j = 0; j < 10; j++){     	//{0,1,0,0,0,0,0,0,0,0},
			if(i == j){				 	//{0,0,1,0,0,0,0,0,0,0},
				birimMatris[i][j] = 1;  //{0,0,0,1,0,0,0,0,0,0},
			}else{					 	//{0,0,0,0,1,0,0,0,0,0},
				birimMatris[i][j] = 0;	//{0,0,0,0,0,1,0,0,0,0},
			}							//{0,0,0,0,0,0,1,0,0,0},
		}								//{0,0,0,0,0,0,0,1,0,0},
	}									//{0,0,0,0,0,0,0,0,1,0},												 
	for(i = 0; i < N; i++){				//{0,0,0,0,0,0,0,0,0,1},  Birim matrisini for dongusu yardimiyla yazdiririz.
		kosegen = matris[i][i];
		for(j = 0; j < N; j++){
			matris[i][j] /= kosegen; 
			birimMatris[i][j] /= kosegen;
		}	
		for(j = 0; j < N; j++){
			if(i != j){
				kosegen = matris[j][i]; 
				for(k = 0; k < N; k++){
					matris[j][k] = matris[j][k] - matris[i][k]*kosegen;
					birimMatris[j][k] = birimMatris[j][k] - birimMatris[i][k]*kosegen;
				}
			}
		}
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%lf ",birimMatris[i][j]);
		}
		printf("\n");
	}
}
double	IleriFark(double veriDegeri[BOYUT2], int whichDiffer, int x){
	double zero;
	
	if(whichDiffer > 0){
		zero = IleriFark(veriDegeri,whichDiffer-1,x+1) - IleriFark(veriDegeri,whichDiffer-1,x);
	}else{
		zero = veriDegeri[x];
	}
	
	return zero;
}
double	faktoriyel(int x){
	double i,sonuc = 1;
	
	for(i = 1; i <= x; i++){
		sonuc *= i;
	}
	return sonuc;
}
int main(){
		int		tercih;
	do{
    	double	polynom[2][BOYUT] = {0}; // Polinomun us ve katsayilarini tutan matris
    	double	TurevPol[2][BOYUT];
    	double 	matris[BOYUT][BOYUT];
    	double	sonuc_matris[BOYUT][1];
    	double	degiskenler[BOYUT] = {0}; // Bunu Gauss elimination metodunda degiskenleri tutmak icin kullanacagiz.
    	double	veriDegeri[BOYUT2] = {0}; // Bunu Gregory-Newton yonteminde verilerin degerlerini tutmak icin kullanacagiz.
	    int     xSayisi; // Polinomdali x sayisi
	    double	a;
	    double 	b; 
	    double  c = 0;
	    double  d; // Newton-Raphson yontemi icin baslama noktasi
	    double	x; // Sayisal turev ve Gregory-Newton Interpolasyon degeri
	    double	h; // Bosluklari gostermek icin kullanilir.
	    double	temp;
	    double	tmp[BOYUT];
		double	Degisken; 
	    int		MaksIter;
	    int 	n;
	    double	epsilon;
	    double	kosegen;
	    double	sonuc = 0; // Sayisal turev ve Simpson kurali sonucu
	    double	entsonuc = 0;
	    double	ilkDeger; // Integral icin baslangic degeri
	    double	sonDeger; // Integral icin bitis degeri
	    int		i,j,k;
	    double	ilk, son; // Simpson kurali ve trapez yonteminde for dongusu elemani
	    int		flag = 1;
	    int		N; // Kare matris satir ve sutun sayisi 
	    char	liste[11][STRING] = {"Quit: 0",
	                                "Bisection: 1",
	                                "Regula-Falsi: 2",
	                                "Newton-Raphson: 3",
	                                "Inverse Matrix: 4",
	                                "Gauss Elimination: 5",
	                                "Gauss-Seidel :6",
	                                "Numerical Differentiation: 7",
	                                "Simpson's Rule: 8",
	                                "Trapezoidal Rule: 9",
	                                "Gregory-Newton: 10\n"};
	
	
	
	    printf("\nLutfen kullanmak istediginiz yontemi seciniz:\n");
	    for(i=0;i<11;++i){
	        printf("%s\n",liste[i]);
	    }
	    printf("Seciminiz: ");
	    scanf("%d",&tercih);
	    printf("\n");
	
	    switch(tercih){
	    	
	    	case 0:
	        	printf("Program sonlandirildi.");
	        	break;
	    
	    	case 1:
		        printf("Maksimum iterasyon sayisini giriniz: ");
		        scanf("%d",&MaksIter);
		        printf("Epsilon degeri giriniz: ");
		        scanf("%lf",&epsilon);
		        printf("Baslangic degeri giriniz (f(baslangic) < 0 olacak sekilde) : ");
		        scanf("%lf",&a);
		        printf("Bitis degeri giriniz (f(bitis) > 0 olacak sekilde) : ");
		        scanf("%lf",&b);
		        printf("Polinomda kac adet x degeri istediginizi giriniz (Ornegin 5x^2 + 7x^1 + 3x^0 oldugu icin 3 tane x degeri vardir.) : ");
		        scanf("%d",&xSayisi);
		        polinomAl(polynom, xSayisi);
				
				for(i = 0; i < MaksIter - 1; i++){
		            c = (b + a)/2; // Her iterasyonda yeni orta noktalar bulmaya yarar.
		            if((b - a)/ usAl(2,i) < epsilon){ // Gereken durma kosulu saglandigi icin döngüden cikilir ve sonuc yazdirilir.
		               	i = MaksIter;
		               	flag = 0;
		           	}
		           	if(flag == 1){
		           		if(PolinomHesapla(polynom,c,xSayisi)*PolinomHesapla(polynom,a,xSayisi) < 0){
		               		printf("\nIterasyon %d: ",i+1);
		               		printf("\nBaslangic: %lf",a);
		               		printf("\nOrta: %lf",c);
		               		printf("\nBitis: %lf",b);
		               		printf("\nf(Baslangic): %lf",PolinomHesapla(polynom,a,xSayisi));
		               		printf("\nf(Orta): %lf",PolinomHesapla(polynom,c,xSayisi));
		               		printf("\nf(Bitis): %lf\n",PolinomHesapla(polynom,b,xSayisi));
		              		b = c;
		            	}else{
		            		printf("\nIterasyon %d: ",i+1);
		               		printf("\nBaslangic: %lf",a);
		               		printf("\nOrta: %lf",c);
		               		printf("\nBitis: %lf",b);
		               		printf("\nf(Baslangic): %lf",PolinomHesapla(polynom,a,xSayisi));
		               		printf("\nf(Orta): %lf",PolinomHesapla(polynom,c,xSayisi));
		               		printf("\nf(Bitis): %lf\n",PolinomHesapla(polynom,b,xSayisi));
		           			a = c;
						}
					}
		        }
		        printf("\nSonuc: %lf",c);
	    		break;
	    		
	    	case 2:
		    	printf("Maksimum iterasyon sayisini giriniz: ");
		        scanf("%d",&MaksIter);
		        printf("Epsilon degeri giriniz: ");
		        scanf("%lf",&epsilon);
		        printf("Baslangic degeri giriniz (f(baslangic) < 0 olacak sekilde) : ");
		        scanf("%lf",&a);
		        printf("Bitis degeri giriniz (f(bitis) > 0 olacak sekilde) : ");
		        scanf("%lf",&b);
		        printf("Polinomda kac adet x degeri istediginizi giriniz (Ornegin 5x^2 + 7x^1 + 3x^0 oldugu icin 3 tane x degeri vardir.) : ");
		        scanf("%d",&xSayisi);
		        polinomAl(polynom, xSayisi);
		        
		        for(i = 0; i < MaksIter - 1; i++){
		           	c = (a*PolinomHesapla(polynom,b,xSayisi) - b*PolinomHesapla(polynom,a,xSayisi))/(PolinomHesapla(polynom,b,xSayisi) - PolinomHesapla(polynom,a,xSayisi)); // Her iterasyonda yeni noktalar tanimlar
		           	if((b - a)/ usAl(2,i) < epsilon){
		               	i = MaksIter;
		               	flag = 0;
		           	}
		         	if(flag == 1){
		           		if(PolinomHesapla(polynom,c,xSayisi)*PolinomHesapla(polynom,a,xSayisi) < 0){
		               		printf("\nIterasyon %d: ",i+1);
		               		printf("\nBaslangic: %lf",a);
		               		printf("\nBitis: %lf",b);
		               		printf("\nKok: %lf",c);
		               		printf("\nf(Baslangic): %lf",PolinomHesapla(polynom,a,xSayisi));
		               		printf("\nf(Bitis): %lf",PolinomHesapla(polynom,b,xSayisi));
		               		printf("\nf(Kok): %lf\n",PolinomHesapla(polynom,c,xSayisi));
		             		b = c;
		            	}else{
		            		printf("\nIterasyon %d: ",i+1);
		               		printf("\nBaslangic: %lf",a);
		               		printf("\nBitis: %lf",b);
		               		printf("\nKok: %lf",c);
		               		printf("\nf(Baslangic): %lf",PolinomHesapla(polynom,a,xSayisi));
		               		printf("\nf(Bitis): %lf",PolinomHesapla(polynom,b,xSayisi));
		               		printf("\nf(Kok): %lf\n",PolinomHesapla(polynom,c,xSayisi));
		           			a = c;
						}
					}
		       	}
		       	printf("\nSonuc: %lf",c);
				break;
				
			case 3:
				printf("Maksimum iterasyon sayisini giriniz: ");
		        scanf("%d",&MaksIter);
		        printf("Epsilon degerini giriniz: ");
		        scanf("%lf",&epsilon);
		        printf("Baslangic degeri giriniz: ");
		        scanf("%lf",&d);
		        printf("Polinomda kac adet x degeri istediginizi giriniz (Ornegin 5x^2 + 7x^1 + 3x^0 oldugu icin 3 tane x degeri vardir.) : ");
		        scanf("%d",&xSayisi);
		        
		        polinomAl(polynom, xSayisi);
		        TurevAl(polynom,TurevPol,xSayisi);
		        
		        for(i = 0; i < MaksIter - 1; i++){
		        	if(PolinomHesapla(TurevPol,d,xSayisi-1) == 0){
		        		printf("Ornegin 0/0 gibi bazi degerler hesaplanamayabilir onun yerine baska bir baslangic noktasi seciniz.");
		        		i = MaksIter;
		        		flag = 0;
					}
		        	c = d - PolinomHesapla(polynom,d,xSayisi)/PolinomHesapla(TurevPol,d,xSayisi-1);
		            if(fabs(c - d) < epsilon){
		                i = MaksIter;
		                flag = 0;
		            }
		            if(flag == 1){
		            	printf("\nIterasyon%d: \n",i+1);
		            	printf("xn: %lf",c);
		            	printf("\nf(xn): %lf\n ",PolinomHesapla(polynom,c,xSayisi));
		            	c = c + d;
		            	d = c - d;
		            	c = c - d;
					}
		        }
				break;
				
			case 4:
				printf("Kare matrisin satir veya sutun sayisini giriniz: ");
				scanf("%d",&N);
				matris_al(matris,N);
				if(determinant(matris,N) == 0){
					printf("Matrisin determinanti 0'dir bu yuzden tersi hesaplanamaz.");
					flag = 0;
				}
				if(flag == 1){
					MatrisTersi(matris,N);
				}
				break;
				
			case 5:
				printf("Kare matrisin satir veya sutun sayisini giriniz: ");
				scanf("%d",&N);
				matris_al(matris,N);
				sonuc_matris_al(sonuc_matris,N);
				GaussYap(matris,sonuc_matris,N);
				GaussCoz(matris,sonuc_matris,degiskenler,N);
				break;
				
			case 6:
				printf("Maksimum iterasyon sayisini giriniz: ");
		        scanf("%d",&MaksIter);
		        printf("Epsilon degeri giriniz: ");
		        scanf("%lf",&epsilon);
		        printf("Kare matrisin satir veya sutun sayisini giriniz: ");
				scanf("%d",&N);
		        printf("Lutfen baskin kosegen matris olacak sekilde giriniz:\n");
				matris_al(matris,N);
				
				for(i = 0; i < N; i++){
					kosegen = matris[i][i];
					for(j = 0; j < N; j++){
						if(fabs(kosegen) < fabs(matris[i][j])){
							flag = 0;
						}
					}
				}
			
				if(flag == 1){
					sonuc_matris_al(sonuc_matris,N);
					printf("Degiskenler icin bir baslangic noktasi giriniz: \n");
					for(i = 0; i < N; i++){
						printf("x%d: ", i+1);
						scanf("%lf",&degiskenler[i]);
					}
			
					for(i = 0; i < MaksIter; i++){
						for(j = 0; j < N; j++){
							Degisken = 0;
							for(k = 0; k < N; k++){
								if(k != j){
									Degisken += matris[j][k]*degiskenler[k]; 
								}
							}
							degiskenler[j] = (sonuc_matris[j][0] - Degisken)/matris[j][j];
						}
						for(j = 0; j < N; j++){ 
							if((fabs(degiskenler[j] - tmp[j]) < epsilon) && i > 0){
								flag = 0;
							}else{
								flag = 1;
							}
						}
						printf("Iterasyon%d: ",i+1);
						for(j = 0; j < N; j++){
							printf("x%d %lf ", j+1,degiskenler[j]);
							tmp[j] = degiskenler[j];
						}
						printf("\n");
						if(flag == 0){
							i = MaksIter;
						}
					}
				}else{
					printf("Bu matris baskin kosegen bir matris degil.");
				}
				break;
			case 7:
				printf("Hangi metodu uygulamak istediginizi seciniz: ");
				printf("\n1- Geri Farklar");
				printf("\n2- Merkezi Farklar");
				printf("\n3- Ileri Farklar\n");
				printf("\nSeciminiz: ");
				scanf("%d",&tercih);
				printf("\nPolinomda kac adet x degeri istediginizi giriniz (Ornegin 5x^2 + 7x^1 + 3x^0 oldugu icin 3 tane x degeri vardir.) : ");
		        scanf("%d",&xSayisi);
				polinomAl(polynom,xSayisi);
				printf("Turevini almak istediginiz x degerini giriniz: ");
				scanf("%lf",&x);
				printf("h degerini giriniz: ");
				scanf("%lf",&h);
				if(tercih == 1){
					sonuc = (PolinomHesapla(polynom,x,xSayisi) - PolinomHesapla(polynom,x-h,xSayisi))/h;
					printf("sonuc: %lf",sonuc);
				}
				else if(tercih == 2){
					sonuc = (PolinomHesapla(polynom,x+h,xSayisi) - PolinomHesapla(polynom,x-h,xSayisi))/(2*h);
					printf("sonuc: %lf",sonuc);
				}
				else if(tercih == 3){
					sonuc = (PolinomHesapla(polynom,x+h,xSayisi) - PolinomHesapla(polynom,x,xSayisi))/h;
					printf("sonuc: %lf",sonuc);
				}
				else{
					printf("Gecerli bir tercih degil.");
				}
						
				break;
				
			case 8:
				printf("Tercih ettiginiz formulu seciniz: ");
				printf("\n1- Simpson 1/3 Kurali");
				printf("\n2- Simpson 3/8 Kurali\n");
				printf("\nSeciminiz: ");
				scanf("%d",&tercih);
				printf("\nIntegral icin bir baslangic degeri giriniz: ");
				scanf("%lf",&ilkDeger);
				printf("Integral icin bir bitis degeri giriniz: ");
				scanf("%lf",&sonDeger);
				printf("Bir n degeri giriniz: ");
				scanf("%d",&n);
				printf("Polinomda kac adet x degeri istediginizi giriniz (Ornegin 5x^2 + 7x^1 + 3x^0 oldugu icin 3 tane x degeri vardir.) : ");
		        scanf("%d",&xSayisi);
		        polinomAl(polynom,xSayisi);
		        
		        a = (sonDeger-ilkDeger)/n;
		        
				if(tercih == 1){
					for(ilk = ilkDeger; ilk < sonDeger; ilk +=a){
						son = ilk+a;
						sonuc += (son-ilk)*(PolinomHesapla(polynom,ilk,xSayisi) + 4*PolinomHesapla(polynom,(ilk+son)/2,xSayisi) + PolinomHesapla(polynom,son,xSayisi))/6; // Simpson 1/3 Kurali
					}
					printf("%lf",sonuc);
				}
				else if(tercih == 2){
					for(ilk = ilkDeger; ilk < sonDeger; ilk += a){
						son = ilk+a; 
						sonuc += (son-ilk)*(PolinomHesapla(polynom,ilk,xSayisi) + 3*PolinomHesapla(polynom,ilk + (son-ilk)/3,xSayisi) + 3*PolinomHesapla(polynom,ilk + 2*(son-ilk)/3,xSayisi) + PolinomHesapla(polynom,son,xSayisi))/8; // Simpson 3/8 Kurali
					}
					printf("%lf",sonuc);
				}else{
					printf("Gecerli bir tercih degil.");
				}
				break;
			case 9:
				printf("Integral icin bir baslangic degeri: ");
				scanf("%lf",&ilkDeger);
				printf("Integral icin bir bitis degeri: ");
				scanf("%lf",&sonDeger);
				printf("Bir n degeri giriniz: ");
				scanf("%d",&n);
				printf("Polinomda kac adet x degeri istediginizi giriniz (Ornegin 5x^2 + 7x^1 + 3x^0 oldugu icin 3 tane x degeri vardir.) : ");
		        scanf("%d",&xSayisi);
		        polinomAl(polynom,xSayisi);
		        
		        a = (sonDeger-ilkDeger)/n;
		         
		        for(ilk = ilkDeger; ilk < sonDeger; ilk += a){
		        	son = ilk+a;
		         	sonuc += (son-ilk)*(PolinomHesapla(polynom,ilk,xSayisi) + PolinomHesapla(polynom,son,xSayisi))/2; // Trapez Kurali
				}
				printf("%lf",sonuc);
				break;
			case 10:
				printf("Baslangic x degeri giriniz (x0): ");
				scanf("%lf",&a); // a == x0
				printf("Aralik miktarini giriniz (h): ");
				scanf("%lf",&h);
				printf("Alinacak veri sayisini giriniz (n): ");
				scanf("%d",&n);
				printf("Fonksiyonlarin degerlerini giriniz.\n");
				
				temp = a;
				for(i = 0; i < n; i++){
					printf("f(%lf): ",temp);
					scanf("%lf",&veriDegeri[i]);
					temp += h;
				}
				printf("Hesaplamak istediginiz x degerini giriniz: ");
				scanf("%lf",&x);
				
				for(i = 1; i < n; i++){
					temp = a;
					entsonuc = 1;
					for(j = 1; j <= i; j++){
						entsonuc = entsonuc*(x - temp)/(h*j);
						temp += h;
					}
					entsonuc = entsonuc*IleriFark(veriDegeri,i,0);
					sonuc += entsonuc;
				}
				sonuc = sonuc + veriDegeri[0];
				printf("sonuc: %lf",sonuc);
				break;
				
			default:
				printf("Hatali tercih. Lutfen gecerli bir secenek girin.\n");
		}
	} while (tercih != 0);
	

    return 0;
    }
