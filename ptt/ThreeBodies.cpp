#include "StdAfx.h"
#include "ThreeBodies.h"
#include <math.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <Windows.h>

extern HWND hZaGraf1;
int indeks = 0;
int brojpodataka;
double *aa;
double *bb;


using namespace std;
ThreeBodies::ThreeBodies(void)
{
}

ThreeBodies::~ThreeBodies(void)
{
}

void ThreeBodies::Setxp(double XP)
{
	xp = XP;
}
void ThreeBodies::Setyp(double YP)
{
	yp = YP;
}
void ThreeBodies::Setzp(double ZP)
{
	zp = ZP;
}
void ThreeBodies::Setxm(double XM)
{
	xm = XM;
}
void ThreeBodies::Setym(double YM)
{
	ym = YM;
}
void ThreeBodies::Setzm(double ZM)
{
	zm = ZM;
}
void ThreeBodies::Setxs(double XS)
{
	xs = XS;
}
void ThreeBodies::Setys(double YS)
{
	ys = YS;
}
void ThreeBodies::Setzs(double ZS)
{
	zs = ZS;
}
void ThreeBodies::Setmp(double MP)
{
	mp = MP;
}
void ThreeBodies::Setmm(double MM)
{
	mm = MM;
}
void ThreeBodies::Setms(double MS)
{
	ms = MS;
}
void ThreeBodies::Sett(double TT)
{
	t = TT;
}
void ThreeBodies::Setdt(double DT)
{
	dt = DT;
}
void ThreeBodies::Setvxs (double VXS)
{
	vxs = VXS;
}
void ThreeBodies::Setvys (double VYS)
{
	vys = VYS;
}
void ThreeBodies::Setvzs (double VZS)
{
	vzs = VZS;
}
void ThreeBodies::Setvxp (double VXP)
{
	vxp = VXP;
}
void ThreeBodies::Setvyp (double VYP)
{
	vyp = VYP;
}
void ThreeBodies::Setvzp (double VZP)
{
	vzp = VZP;
}
void ThreeBodies::Setvxm (double VXM)
{
	vxm = VXM;
}
void ThreeBodies::Setvym (double VYM)
{
	vym = VYM;
}
void ThreeBodies::Setvzm (double VZM)
{
	vzm = VZM;
}

double ThreeBodies::Getxp ()
{
	return xp;
}
double ThreeBodies::Getyp()
{
	return yp;
}
double ThreeBodies::Getzp()
{
	return zp;
}
double ThreeBodies::Getxm()
{
	return xm;
}
double ThreeBodies::Getym()
{
	return ym;
}
double ThreeBodies::Getzm()
{
	return zm;
}
double ThreeBodies::Getxs()
{
	return xs;
}
double ThreeBodies::Getys()
{
	return ys;
}
double ThreeBodies::Getzs()
{
	return zs;
}
double ThreeBodies::Getmp()
{
	return mp;
}
double ThreeBodies:: Getmm()
{
	return mm;
}
double ThreeBodies:: Getms ()
{ 
	return ms;
}
double ThreeBodies:: Gett()
{
	return t;
}
double ThreeBodies:: Getdt()
{
	return dt;
}
double ThreeBodies::Getvxs()
{
	return vxs;
}
double ThreeBodies::Getvys()
{
	return vys;
} 
double ThreeBodies::Getvzs()
{
	return vzs;
}
double ThreeBodies::Getvxp()
{
	return vxp;
}
double ThreeBodies::Getvyp()
{
	return vyp;
}
double ThreeBodies::Getvzp()
{
	return vzp;
}
double ThreeBodies::Getvxm()
{
	return vxm;
}
double ThreeBodies::Getvym()
{
	return vym;
}
double ThreeBodies::Getvzm()
{
	return vzm;
}

double ThreeBodies::Setrsp ( double xs, double xp, double ys, double yp, double zp, double zs)// izbaci promenljive i radi unutra 
{
	double rsp;
	rsp = sqrt(pow((xs - xp ), 2) + pow((ys - yp), 2) + pow((zs - zp), 2));
	return rsp;
}

double ThreeBodies::Setrsm(double xs, double xm, double ys, double ym, double zs, double zm)
{
	double rsm;
	rsm = sqrt(pow((xs - xm), 2) + pow((ys - ym), 2) + pow ((zs - zm), 2));
	return rsm;
}

double ThreeBodies::Setrpm(double xp, double xm, double yp, double ym, double zp, double zm)
{
	double rpm;
	rpm = sqrt(pow((xp - xm), 2) + pow((yp - ym), 2) + pow((zp - zm),2));
	return rpm;
}

double ThreeBodies::TakeX(vctr a)
{
	double z;
	return z=a.x;
}
double ThreeBodies::TakeY(vctr a)
{
	double z;
	return z=a.y;
}
double ThreeBodies::TakeZ(vctr a)
{
	double z;
	return z=a.z;
}
ThreeBodies::vctr ThreeBodies::DotProduct(vctr a, vctr b )
	{
		vctr c;
		c.x = a.x*b.x;
		c.y = a.y*b.y;
		c.z = a.z*b.z;
		return c;
	}
ThreeBodies::vctr ThreeBodies::ScalarProduct(double n, vctr a)
{
	vctr c;
	c.x = a.x*n;
	c.y = a.y*n;
	c.z = a.z*n;
	return c;
}
ThreeBodies::vctr ThreeBodies::VectorSubstraction(vctr a, vctr b)
{
	vctr c;
	c.x = a.x-b.x;
	c.y = a.y-b.y;
	c.z = a.z-b.z;
	return c;
}

void ThreeBodies::rk4(ThreeBodies &a)
{
	 HDC  hDC;
     hDC = GetDC( hZaGraf1 );
     HPEN hPen1, hPen2, hPen3;
     hPen1=CreatePen(PS_SOLID, 1, RGB(247, 255, 0)); //zuta
     hPen2=CreatePen(PS_SOLID, 1, RGB(0, 102, 255));  //plava
	 hPen3=CreatePen(PS_SOLID, 1, RGB(189, 107, 13));//braon
	
		 int sirina, visina;
		 RECT WinDim; 
		 GetClientRect(hZaGraf1, &WinDim); 

		 sirina=WinDim.right; // vraća sirinu prozora
		 visina=WinDim.bottom; // vraća visinu prozora

	
	// jedinicni vektor
	a.ix.x=1.0;
	a.ix.y=0.0;
	a.ix.z=0.0;
	
	a.iy.x=0.0;
	a.iy.y=1.0;
	a.iy.z=0.0;

	a.iz.x=0.0;
	a.iz.y=0.0;
	a.iz.z=1.0;


	std::ofstream izlaznifajl;
	izlaznifajl.open("D:\\c++\\TriTela\\ptt2\\izlazni.txt");
	
	double G = 6.67*pow(10.0, -11);
	long int nsteps = 1+(int)(t/dt); // broj koraka u simulaciji
	double *data[18];
	brojpodataka = (int)nsteps-1;
	for(int l = 0; l < 18; l++) data[l] = new double[nsteps]; // matrica koja sadrzi sve podatke u simulaciji7
	aa = new double[brojpodataka];
	bb = new double[brojpodataka];
	
	
	//koordinate polozaja i brzine sva 3 tela u trenutnoj tacki

	data[0][0] = a.Getxs();//xs;
	data[1][0] = a.Getys();//ys;
	data[2][0] = a.Getzs();//zs;
	data[3][0] = a.Getxp();//xp;
	data[4][0] = a.Getyp();//yp;
	data[5][0] = a.Getzp();//zp;
	data[6][0] = a.Getxm();//xm;
	data[7][0] = a.Getym();//ym;
	data[8][0] = a.Getzm();//zm;
	data[9][0] = a.Getvxs();//vxs;
	data[10][0] = a.Getvys();//vys;
	data[11][0] = a.Getvzs();//vzs;
	data[12][0] = a.Getvxp();//vxp;
	data[13][0] = a.Getvyp();//vyp;
	data[14][0] = a.Getvzp();//vzp;
	data[15][0] = a.Getvxm();//vxm;
	data[16][0] = a.Getvym();//vym;
	data[17][0] = a.Getvzm();//vzm;




	for ( int i = 0; i < nsteps; i++)
	{
		
		std::vector <double> temp(27), k1(18), k2(18), k3(18), k4(18);
		int OX = sirina / 2, OY = visina / 2, RS = 17, RP = 7, RM = 4;

		double lala = a.Getxp() / pow(10.0, 9.0);
		SelectObject(hDC, hPen1); Ellipse(hDC, (int)(a.Getxs() / pow(10.0, 9.0)/2 + OX), (int)(a.Getys() / pow(10.0, 9.0)/2 + OY), (int)(a.Getxs() / pow(10.0, 9.0)/2 + RS + OX), (int)(a.Getys() / pow(10.0, 9.0)/2 + RS + OY));
		SelectObject(hDC, hPen2); Ellipse(hDC, (int)(a.Getxp() / pow(10.0, 9.0)/2 + OX), (int)(a.Getyp() / pow(10.0, 9.0)/2 + OY), (int)(a.Getxp() / pow(10.0, 9.0)/2 + RP + OX), (int)(a.Getyp() / pow(10.0, 9.0)/2 + RP) + OY);
		SelectObject(hDC, hPen3); Ellipse(hDC, (int)(a.Getxm() / pow(10.0, 9.0)/2 + OX), (int)(a.Getym() / pow(10.0, 9.0)/2 + OY), (int)(a.Getxm() / pow(10.0, 9.0)/2 + RM + OX), (int)(a.Getym() / pow(10.0, 9.0)/2 + RM) + OY);
		Sleep(10);
		for (int k = 0; k < 18; k++ )
		{
			temp[k] = data [k][i];

		}

	//vektor polozaja sunca u trenutnoj tacki
	a.rs.x = a.Getxs();
	a.rs.y = a.Getys();
	a.rs.z = a.Getzs();
	//vektor polozaja planete u trenutnoj tacki
	a.rp.x = a.Getxp();
	a.rp.y = a.Getyp();
	a.rp.z = a.Getzp();
	//vektor polozaja meseca u trenutnoj tacki
	a.rm.x = a.Getxm();
	a.rm.y = a.Getym();
	a.rm.z = a.Getzm();
		
		//racunanje ubrzanja pomocu operacija nad vektorima

		double asx, asy, asz, apx, apy, apz, amx, amy, amz;

		asx = temp[18] = -(((G*mp) / pow(a.Setrsp(a.xs, a.ys, a.zs, a.xp, a.yp, a.zp), 3))*(rs.x - rp.x)) - (((G*mm) / pow(a.Setrsm(a.xs, a.ys, a.zs, a.xm, a.ym, a.zm), 3))*(rs.x - rm.x));
		asy = temp[19] = -(((G*mp) / pow(a.Setrsp(a.xs, a.ys, a.zs, a.xp, a.yp, a.zp), 3))*(rs.y - rp.y)) - (((G*mm) / pow(a.Setrsm(a.xs, a.ys, a.zs, a.xm, a.ym, a.zm), 3))*(rs.y - rm.y));
		asz = temp[20] = -(((G*mp) / pow(a.Setrsp(a.xs, a.ys, a.zs, a.xp, a.yp, a.zp), 3))*(rs.z - rp.z)) - (((G*mm) / pow(a.Setrsm(a.xs, a.ys, a.zs, a.xm, a.ym, a.zm), 3))*(rs.z - rm.z));
		
		apx = temp[21] = -(((G*mm) / pow(a.Setrpm(a.xp, a.yp, a.zp, a.xm, a.ym, a.zm), 3))*(rp.x - rm.x)) - (((G*ms) / pow(a.Setrsp(a.xs, a.ys, a.zs, a.xp, a.yp, a.zp), 3))*(rp.x - rs.x));
		apy = temp[22] = -(((G*mm) / pow(a.Setrpm(a.xp, a.yp, a.zp, a.xm, a.ym, a.zm), 3))*(rp.y - rm.y)) - (((G*ms) / pow(a.Setrsp(a.xs, a.ys, a.zs, a.xp, a.yp, a.zp), 3))*(rp.y - rs.y));
		apz = temp[23] = -(((G*mm) / pow(a.Setrpm(a.xp, a.yp, a.zp, a.xm, a.ym, a.zm), 3))*(rp.z - rm.z)) - (((G*ms) / pow(a.Setrsp(a.xs, a.ys, a.zs, a.xp, a.yp, a.zp), 3))*(rp.z - rs.z));
		
		amx = temp[24] = -(((G*ms) / pow(a.Setrsm(a.xs, a.ys, a.zs, a.xm, a.ym, a.zm), 3))*(rm.x - rs.x)) - (((G*mp) / pow(a.Setrpm(a.xp, a.yp, a.zp, a.xm, a.ym, a.zm), 3))*(rm.x - rp.x));
		amy = temp[25] = -(((G*ms) / pow(a.Setrsm(a.xs, a.ys, a.zs, a.xm, a.ym, a.zm), 3))*(rm.y - rs.y)) - (((G*mp) / pow(a.Setrpm(a.xp, a.yp, a.zp, a.xm, a.ym, a.zm), 3))*(rm.y - rp.y));
		amz = temp[26] = -(((G*ms) / pow(a.Setrsm(a.xs, a.ys, a.zs, a.xm, a.ym, a.zm), 3))*(rm.z - rs.z)) - (((G*mp) / pow(a.Setrpm(a.xp, a.yp, a.zp, a.xm, a.ym, a.zm), 3))*(rm.z - rp.z));
		
		izlaznifajl<<*aa<<" ";
		aa[i] = a.rp.x - a.rs.x;
		izlaznifajl<<*bb<<" ";
		bb[i]=a.rp.y-a.rs.y;
		
		// RK 4

		//koeficijent 1	

				k1[0] = temp[18]*temp[0];		//k1v
				k1[1] = temp[19]*temp[1];
				k1[2] = temp[20]*temp[2];
				k1[3] = temp[21]*temp[3];
				k1[4] = temp[22]*temp[4];
				k1[5] = temp[23]*temp[5];
				k1[6] = temp[24]*temp[6];		
				k1[7] = temp[25]*temp[7];
				k1[8] = temp[26]*temp[8];
				k1[9] = temp[9];				//k1r
				k1[10] = temp[10];
				k1[11] = temp[11];
				k1[12] = temp[12];
				k1[13] = temp[13];
				k1[14] = temp[14];
				k1[15] = temp[15];
				k1[16] = temp[16];
				k1[17] = temp[17];

				//koeficijent 2

				k2[0] = temp[18]*(temp[0]+(dt/2)*k1[9]);  //k2v
				k2[1] = temp[19]*(temp[1]+(dt/2)*k1[10]);
				k2[2] = temp[20]*(temp[2]+(dt/2)*k1[11]);
				k2[3] = temp[21]*(temp[3]+(dt/2)*k1[12]);
				k2[4] = temp[22]*(temp[4]+(dt/2)*k1[13]);
				k2[5] = temp[23]*(temp[5]+(dt/2)*k1[14]);
				k2[6] = temp[24]*(temp[6]+(dt/2)*k1[15]);
				k2[7] = temp[25]*(temp[7]+(dt/2)*k1[16]);
				k2[8] = temp[26]*(temp[8]+(dt/2)*k1[17]);
				k2[9] = temp[9]*(dt/2)*k1[0];			//k2r
				k2[10] = temp[10]*(dt/2)*k1[1];
				k2[11] = temp[11]*(dt/2)*k1[2];
				k2[12] = temp[12]*(dt/2)*k1[3];
				k2[13] = temp[13]*(dt/2)*k1[4];
				k2[14] = temp[14]*(dt/2)*k1[5];
				k2[15] = temp[15]*(dt/2)*k1[6];
				k2[16] = temp[16]*(dt/2)*k1[7];
				k2[17] = temp[17]*(dt/2)*k1[8];

				
				//koeficijent  3

				k3[0] = temp[18]*(temp[0]+(dt/2)*k2[9]);  //k3v
				k3[1] = temp[19]*(temp[1]+(dt/2)*k2[10]);
				k3[2] = temp[20]*(temp[2]+(dt/2)*k2[11]);
				k3[3] = temp[21]*(temp[3]+(dt/2)*k2[12]);
				k3[4] = temp[22]*(temp[4]+(dt/2)*k2[13]);
				k3[5] = temp[23]*(temp[5]+(dt/2)*k2[14]);
				k3[6] = temp[24]*(temp[6]+(dt/2)*k2[15]);
				k3[7] = temp[25]*(temp[7]+(dt/2)*k2[16]);
				k3[8] = temp[26]*(temp[8]+(dt/2)*k2[17]);
				k3[9] = temp[9]*(dt/2)*k2[0];			//k3r
				k3[10] = temp[10]*(dt/2)*k2[1];
				k3[11] = temp[11]*(dt/2)*k2[2];
				k3[12] = temp[12]*(dt/2)*k2[3];
				k3[13] = temp[13]*(dt/2)*k2[4];
				k3[14] = temp[14]*(dt/2)*k2[5];					
				k3[15] = temp[15]*(dt/2)*k2[6];
				k3[16] = temp[16]*(dt/2)*k2[7];
				k3[17] = temp[17]*(dt/2)*k2[8];

				//koeficijent 4

				k4[0] = temp[18]*(temp[0]+dt*k3[9]);  //k4v
				k4[1] = temp[19]*(temp[1]+dt*k3[10]);
				k4[2] = temp[20]*(temp[2]+dt*k3[11]);
				k4[3] = temp[21]*(temp[3]+dt*k3[12]);
				k4[4] = temp[22]*(temp[4]+dt*k3[13]);
				k4[5] = temp[23]*(temp[5]+dt*k3[14]);
				k4[6] = temp[24]*(temp[6]+dt*k3[15]);			
				k4[7] = temp[25]*(temp[7]+dt*k3[16]);
				k4[8] = temp[26]*(temp[8]+dt*k3[17]);
				k4[9] = temp[9]*dt*k3[0];	//k4r		
				k4[10] = temp[10]*dt*k3[1];
				k4[11] = temp[11]*dt*k3[2];
				k4[12] = temp[12]*dt*k3[3];
				k4[13] = temp[13]*dt*k3[4];
				k4[14] = temp[14]*dt*k3[5];
				k4[15] = temp[15]*dt*k3[6];
				k4[16] = temp[16]*dt*k3[7];
				k4[17] = temp[17]*dt*k3[8];
				
				 //nove vrednosti za sve sem a
				
				//a.Setxs((data[0][i]+(dt/6)*(k1[9]+2*k2[9]+2*k3[9]+k4[9]))); 
				//data[0][i+1] = a.Getxs();										// novo xs
				//a.Setys((data[1][i]+(dt/6)*(k1[10]+2*k2[10]+2*k3[10]+k4[10]))) ;
				//data[1][i+1] = a.Getys();
				//a.Setzs((data[2][i]+(dt/6)*(k1[11]+2*k2[11]+2*k3[11]+k4[11])));
				//data[2][i+1] = a.Getzs();
				//a.Setxp((data[3][i]+(dt/6)*(k1[12]+2*k2[12]+2*k3[12]+k4[12])));
				//data[3][i+1] = a.Getxp();
				//a.Setyp((data[4][i]+(dt/6)*(k1[13]+2*k2[13]+2*k3[13]+k4[13])));
				//data[4][i+1] = a.Getyp();
				//a.Setzp((data[5][i]+(dt/6)*(k1[14]+2*k2[14]+2*k3[14]+k4[14])));
				//data[5][i+1] = a.Getzp();
				//a.Setxm((data[6][i]+(dt/6)*(k1[15]+2*k2[15]+2*k3[15]+k4[15])));
				//data[6][i+1] = a.Getxm();
				//a.Setym((data[7][i]+(dt/6)*(k1[16]+2*k2[16]+2*k3[16]+k4[16])));
				//data[7][i+1] = a.Getym();
				//a.Setzm((data[8][i]+(dt/6)*(k1[17]+2*k2[17]+2*k3[17]+k4[17])));
				//data[8][i+1] = a.Getzm();
				//a.Setvxs((data[9][i]+(dt/6)*(k1[0]+2*k2[0]+2*k3[0]+k4[0])));		// novo vxs
				//data[9][i+1] = a.Getvxs();
				//a.Setvys((data[10][i]+(dt/6)*(k1[1]+2*k2[1]+2*k3[1]+k4[1])));
				//data[10][i+1] = a.Getvys();
				//a.Setvzs((data[11][i]+(dt/6)*(k1[2]+2*k2[2]+2*k3[2]+k4[2])));
				//data[11][i+1] = a.Getvzs();
				//a.Setvxp((data[12][i]+(dt/6)*(k1[3]+2*k2[3]+2*k3[3]+k4[3])));
				//data[12][i+1] = a.Getvxp();
				//a.Setvyp((data[13][i]+(dt/6)*(k1[4]+2*k2[4]+2*k3[4]+k4[4])));
				//data[13][i+1] =	a.Getvyp();
				//a.Setvzp((data[14][i]+(dt/6)*(k1[5]+2*k2[5]+2*k3[5]+k4[5])));
				//data[14][i+1] = a.Getvzp();
				//a.Setvxm((data[15][i]+(dt/6)*(k1[6]+2*k2[6]+2*k3[6]+k4[6])));
				//data[15][i+1] = a.Getvxm();
				//a.Setvym((data[16][i]+(dt/6)*(k1[7]+2*k2[7]+2*k3[7]+k4[7])));
				//data[16][i+1] = a.Getvym();
				//a.Setvzm((data[17][i]+(dt/6)*(k1[8]+2*k2[8]+2*k3[8]+k4[8])));
				//data[17][i+1] = a.Getvzm();

				//////////////////////////////////////////
				
				//ojler
				
				a.Setvxp(temp[12] + dt*apx);
				data[12][i+1] = a.Getvxp();
				a.Setvyp((temp[13]+dt*apy));
				data[13][i+1] =	a.Getvyp();
				a.Setvzp((temp[14]+dt*apz));
				data[14][i+1] = a.Getvzp();

				a.Setxp(temp[3] + dt*a.Getvxp());
				data[3][i+1] = a.Getxp();
				a.Setyp(temp[4] + dt*a.Getvyp());
				data[4][i+1] = a.Getyp();
				a.Setzp(temp[5]+dt*a.Getvzp());
				data[5][i+1] = a.Getzp();

				///////////////////////////
				
				a.Setvxm(temp[15] + dt*amx);
				data[15][i+1] = a.Getvxm();
				a.Setvym(temp[16] + dt*amy);
				data[16][i+1] = a.Getvym();
				a.Setvzm(temp[17] + dt*amz);
				data[17][i+1] = a.Getzm();

				a.Setxm(temp[6] + dt*a.Getvxm());
				data[6][i+1] = a.Getxm();
				a.Setym(temp[7] + dt*a.Getvym());
				data[7][i+1] = a.Getym();
				a.Setzm(temp[8]+dt*a.Getvzm());
				data[8][i+1] = a.Getzm();



				// ispisivanje vrednosti u fajl

				for ( int q = 0; q < 18; q++)
				{
					izlaznifajl<<data[q][i]<<" ;";
					std::cout<<endl<<endl<<endl;
				}
				temp.clear();
				k1.clear();
				k2.clear();
				k3.clear();
				k4.clear();
	}

	izlaznifajl.close();

	 ReleaseDC( hZaGraf1, hDC ); 
     DeleteObject( hPen1 );
     DeleteObject( hPen2 );
	 DeleteObject( hPen3 );

}