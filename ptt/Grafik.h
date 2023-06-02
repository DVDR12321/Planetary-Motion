#pragma once
class grafik
{
private:
	double *X, *Y, minX, minY, maxX, maxY; 
	int n;

	double get_min(double *A, int n);
	double get_max(double *A, int n);

public:
	grafik(void);
	~grafik(void);


	void ucitaj_podatke(double *XX, double *YY, int nn);
	void crtaj_ose(HWND hwnd);
	void crtaj_XY(HWND);
};