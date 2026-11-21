//Gorev Listesi (TO DO APP G�B�):yapilacal isleri gir, kaydet ve guncelle 

#include <graphics.h>
#include <string.h>

#define MAX_GOREV 100
#define MAX_UZUNLUK 100


#define MAX_DIZI_BOYUTU 50 // Dizinin maksimum boyutu

char gorevler[MAX_GOREV][MAX_UZUNLUK];

FILE *dosya;

int x,y;

void hosgeldiniz();
void giris();
void guncelle();
void ekle();
void kayitlar();

int main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	x=mousex();
	y=mousey();
	
	hosgeldiniz();

	giris();

	closegraph(); //grafik modunu kapat
	return 0;
}

void hosgeldiniz() {

	int colors[] = {BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
					DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
				   };
	int num_colors = sizeof(colors) / sizeof(colors[0]);
	int i = 0,k = 0;

	while (1) { //bir tusa basilana kadar devam eder
		setbkcolor(colors[i]);
		cleardevice(); //ekrani temizleyerek arka plani uygular
		settextstyle(BOLD_FONT,0,4);
		outtextxy(getmaxx()/2-130,50,"~TO DO APP~");
		settextstyle(BOLD_FONT,k,4);
		outtextxy(getmaxx()/2-130,getmaxy()/2,"HOSGELDINIZ");
		delay(500); // 500 milisaniye = yarim saniye
		k++;
		i = (i + 1) % num_colors;

		if(k==5) {
			setbkcolor(colors[15]);
			break;
		}
	}
}

void giris() {

	while(1) {
		getmouseclick(WM_LBUTTONDOWN,x,y);

		cleardevice();
		setcolor(BLACK);
		settextstyle(DEFAULT_FONT,0,1);
		setfillstyle(SOLID_FILL,LIGHTGRAY);

		outtextxy(getmaxx()/2-60,getmaxy()/2+183,"EKLE");
		rectangle(getmaxx()/2-100,getmaxy()/2+170,getmaxx()/2,getmaxy()/2+200);
		rectangle(getmaxx()/2-101,getmaxy()/2+171,getmaxx()/2+1,getmaxy()/2+201);
		
		kayitlar();

		//ekle
		if(x<getmaxx()/2&&x>getmaxx()/2-100&&y<getmaxy()/2+200&&y>getmaxy()/2+170) {
			cleardevice();
			settextstyle(BOLD_FONT,0,4);
			setcolor(BLACK);
			outtextxy(getmaxx()/2-130,50,"~TO DO APP~");

			settextstyle(DEFAULT_FONT,0,1);
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			outtextxy(getmaxx()/2+67,getmaxy()/2+183,"GUNCELLE");
			rectangle(getmaxx()/2+50,getmaxy()/2+170,getmaxx()/2+150,getmaxy()/2+200);
			rectangle(getmaxx()/2+49,getmaxy()/2+171,getmaxx()/2+151,getmaxy()/2+201);

			outtextxy(getmaxx()/2-55,getmaxy()/2+188,"EKLE");
			rectangle(getmaxx()/2-95,getmaxy()/2+171,getmaxx()/2+1,getmaxy()/2+201);
			rectangle(getmaxx()/2-96,getmaxy()/2+172,getmaxx()/2+2,getmaxy()/2+202);
			delay(1);
			outtextxy(getmaxx()/2-55,getmaxy()/2+188,"EKLE");
			rectangle(getmaxx()/2-98,getmaxy()/2+172,getmaxx()/2+2,getmaxy()/2+202);
			rectangle(getmaxx()/2-99,getmaxy()/2+173,getmaxx()/2+3,getmaxy()/2+203);
			delay(1);
			outtextxy(getmaxx()/2-55,getmaxy()/2+188,"EKLE");
			rectangle(getmaxx()/2-97,getmaxy()/2+173,getmaxx()/2+3,getmaxy()/2+203);
			rectangle(getmaxx()/2-98,getmaxy()/2+174,getmaxx()/2+4,getmaxy()/2+204);
			delay(1);
			outtextxy(getmaxx()/2-56,getmaxy()/2+188,"EKLE");
			rectangle(getmaxx()/2-96,getmaxy()/2+174,getmaxx()/2+4,getmaxy()/2+204);
			rectangle(getmaxx()/2-97,getmaxy()/2+175,getmaxx()/2+5,getmaxy()/2+205);
			delay(1);
			outtextxy(getmaxx()/2-55,getmaxy()/2+188,"EKLE");
			rectangle(getmaxx()/2-95,getmaxy()/2+175,getmaxx()/2+5,getmaxy()/2+205);
			rectangle(getmaxx()/2-96,getmaxy()/2+176,getmaxx()/2+6,getmaxy()/2+206);
			delay(100);
			ekle();

		}

		delay(100);
	}
}

void guncelle() {

}

void ekle() {
	cleardevice();
	char dizi[MAX_DIZI_BOYUTU + 1]; //+1 null karakter icin
	int dizi_uzunlugu = 0;
	char karakter;
	dosya = fopen("kullanici_bilgileri.txt", "a");

	if (dosya != NULL) {
		setcolor(BLACK); // Yazi rengini siyah yap

		//bilgilendirme metinleri
		outtextxy(10, 10, "Lutfen bir metin girin (Max 50 karakter).");
		outtextxy(10, 30, "Backspace ile sil, Enter ile bitir");
		outtextxy(10, 50, "Kaydet'e basinca kayit olur");

		//girdiginiz Metin başlığı
		char sabitMetin[] = "Girdiginiz Metin: ";
		outtextxy(10, 90, sabitMetin);

		//yazinin baslayacagi x konumunu hesapla
		int baslangic_x = 10 + textwidth(sabitMetin);

		//baslangicta diziyi bos yap
		dizi[0] = '\0';
		outtextxy(baslangic_x, 90, dizi);

		while (1) {
			if (kbhit()) {     //klavye tusuna basildi mi?

				karakter = getch();  //basilan tusu al

				//onceki yaziyi silmek icin beyaz bar sec (arka plan rengiyle)
				setcolor(WHITE);
				bar(baslangic_x, 90, baslangic_x + 300, 110); //silme alani

				setcolor(BLACK); //tekrar yazi rengi siyah yap

				if (karakter == 8) { //backspace
					if (dizi_uzunlugu > 0) {
						dizi_uzunlugu--;
						dizi[dizi_uzunlugu] = '\0';
					}
				}
				else if (karakter == '\r' || karakter == '\n') { //enter
					break;
				}
				else if (dizi_uzunlugu < MAX_DIZI_BOYUTU && karakter >= 32 && karakter <= 126) {
					dizi[dizi_uzunlugu++] = karakter;
					dizi[dizi_uzunlugu] = '\0';
				}

				//guncel metni tekrar yaz
				outtextxy(baslangic_x, 90, dizi);
			}
			delay(10);
		}

		fprintf(dosya, "%s\n", dizi); //satir sonuyla birlikte kaydet
		fclose(dosya);
		delay(100);
	}
}


void kayitlar(){

	int sayac=0;
	
	char karakter;
	dosya = fopen("kullanici_bilgileri.txt","r");

	if (dosya == NULL) {
        outtextxy(100, 200, "Dosya acilamadi");
    } else {
        while (fgets(gorevler[sayac], MAX_UZUNLUK, dosya) && sayac < MAX_GOREV) {
            //satir sonu karakterini kaldir
            gorevler[sayac][strcspn(gorevler[sayac], "\n")] = '\0';
            sayac++;
        }
        fclose(dosya);
    }

	int num_tasks = sayac;

	//baslik yazdir
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	outtextxy(150, 30, "GOREV LISTESI");

	if(num_tasks==0) {
		settextstyle(BOLD_FONT, HORIZ_DIR, 1);
		outtextxy(150, 70, "GOREV YOK GOREV EKLE");
	}

	else {
		//gorevleri listele
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

		for (int i=0; i<num_tasks; i++) {
			outtextxy(100, 100 + i * 40,gorevler[i]);
		}
	}
	fclose(dosya);
}
