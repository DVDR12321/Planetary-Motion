#include "StdAfx.h"
#include "grafik.h"
#include <stdio.h>
#include <Windows.h>


double grafik::get_min(double *A, int n)
{
	double min=1e38;
	for(int i=0; i<n; i++)
	{
	if(A[i]<min)
		min=A[i];
	}
	return min;
}
double grafik::get_max(double *A, int n)
{
	double max=-1e38;
	for(int i=0; i<n; i++)
	{
	if(A[i]>max)
		max=A[i];
	}
	return max;
}

grafik::grafik()
{
}

void grafik::ucitaj_podatke(double *XX, double *YY, int nn)
{
	X=XX;
	Y=YY;
	n=nn;
}
void grafik::crtaj_ose(HWND hwnd)
{
	HDC hDC;
	hDC= GetDC(hwnd);

	RECT WinDim;
	GetClientRect(hwnd, &WinDim);
	
	int sirina= WinDim.right;
	int visina= WinDim.bottom;
	
	
	
	//x osa
	
	MoveToEx(hDC,0, visina-0.05*visina, NULL);
		LineTo(hDC,sirina, visina-0.05*visina);

	//y osa
		MoveToEx( hDC, sirina*0.05, 0, NULL);
		LineTo(hDC, sirina*0.05, visina);

}

void grafik::crtaj_XY(HWND hwnd)
{
	
	HDC hDC;
	hDC= GetDC(hwnd);

	RECT WinDim;
	GetClientRect(hwnd, &WinDim);
	
	int sirina= WinDim.right;
	int visina= WinDim.bottom;

	double min_x = get_min(X,n);
	double max_x = get_max(X,n);
	
	double min_y = get_min(Y,n);
	double max_y= get_max(Y,n);

	char buffer[50];

	sprintf(buffer,"%g", max_y);
	TextOut(hDC, sirina*0.06, 0 , buffer, strlen(buffer));

	sprintf(buffer,"%g, %g", min_x,min_y);
	TextOut(hDC, sirina*0.06-sirina*0.06, visina-0.15*visina , buffer, strlen(buffer));


	sprintf(buffer,"%g", max_x);
	TextOut(hDC,sirina, visina-0.15*visina, buffer, strlen(buffer));

	double sX,sY;
	sX=sirina/(max_x-min_x);
	sY=visina/max_y;
	MoveToEx(hDC,sirina*0.05+(X[0]-min_x)*sX, visina-0.05*visina-(Y[0]-min_y)*sY, NULL);
	for(int i=1; i<n; i++)
	{
		LineTo(hDC,sirina*0.05+(X[i]-min_x)*sX, visina-0.05*visina-(Y[i]-min_y)*sY);
	}

}
grafik::~grafik(void)
{
}
