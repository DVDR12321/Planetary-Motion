#pragma once
class ThreeBodies
{

		
public:
	ThreeBodies(void);
	~ThreeBodies(void);

	double xp, yp, zp, xm, ym, zm, xs, ys, zs, vxs, vys, vzs, vxp, vyp, vzp, vxm, vym, vzm;
	double mp, mm, ms;
	double t, dt;

	// set i get

	void Setxp (double XP);
	void Setyp (double YP);
	void Setzp (double ZP);
	void Setxm (double XM);
	void Setym (double YM);
	void Setzm (double ZM);
	void Setxs (double XS);
	void Setys (double YS);
	void Setzs (double ZS);
	void Setmp (double MP);
	void Setmm (double MM);
	void Setms (double MS);
	void Sett  (double TT);
	void Setdt (double DT);
	void Setvxs (double VXS);
	void Setvys (double VYS);
	void Setvzs (double VZS);
	void Setvxp (double VXP);
	void Setvyp (double VYP);
	void Setvzp (double VZP);
	void Setvxm (double VXM);
	void Setvym (double VYM);
	void Setvzm (double VZM);
	double Getxp ();
	double Getyp ();
	double Getzp ();
	double Getxm ();
	double Getym ();
	double Getzm ();
	double Getxs ();
	double Getys ();
	double Getzs ();
	double Getmp ();
	double Getmm ();
	double Getms ();
	double Gett	 ();
	double Getdt ();
	double Getvxs();
	double Getvys();
	double Getvzs();
	double Getvxp();
	double Getvyp();
	double Getvzp();
	double Getvxm();
	double Getvym();
	double Getvzm();
	
	struct vctr
	{
		double x;
		double y;
		double z;
	};

	// jedinicni vektori
	
	vctr ix;
	vctr iy;
	vctr iz;
	// vektori polozaja 3 tela
	vctr rs;
	vctr rp;
	vctr rm;

	// racunanje intenziteta vektora (moze i 1 fja ali ovako je zgodnije za posle);

	double Setrsp (double xs, double xp, double ys, double yp, double zp, double zs);		//sunce-planeta
	double Setrsm (double xs, double xm, double ys, double ym, double zs, double zm);		//sunce-mesec
	double Setrpm (double xp, double xm, double yp, double ym, double zp, double zm);		//sunce-zvezda
	
	// operacije sa vektorima 
	vctr DotProduct(vctr a,		vctr b);
	vctr ScalarProduct(double n, vctr a);
	vctr VectorSubstraction(vctr a, vctr b);

	//Uzimanje koordinata is strukture vektor
	double TakeX(vctr a);
	double TakeY(vctr a);
	double TakeZ(vctr a);
	
	//runge kuta - 4

	void rk4 (ThreeBodies &a );	
};

