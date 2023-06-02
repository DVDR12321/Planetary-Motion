// ptt.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "ptt.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstring>
#include "ThreeBodies.h"
#include <Windows.h>
#include "Grafik.h"


#define MAX_LOADSTRING 100


// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
HWND hWndm1m;
HWND hZaSimul, hZaGraf1, hZaGraf2, hZaGraf3 ;
int sirinaprozora, visinaprozora, StartStop;
extern int brojpodataka;
ThreeBodies SMZ;
extern double *aa, *bb;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ZaGraf3(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ZaGraf2(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ZaGraf1(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ZaSimul(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam);
DWORD WINAPI Thread_za_Graf( LPDWORD lpdwData );

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_PTT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PTT));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PTT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_PTT);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_SIZE :
		{
		 // resize za sve prozore

		 RECT WinDim;  
		 GetClientRect(hWnd, &WinDim); 
             
		 sirinaprozora=WinDim.right; // vraća sirinu prozora
		 visinaprozora=WinDim.bottom; // vraća visinu prozora


		 MoveWindow( hZaSimul, 0, 0, sirinaprozora/2, visinaprozora/2, TRUE );
		 MoveWindow( hZaGraf1, sirinaprozora/2, 0, sirinaprozora/2, visinaprozora/2, TRUE );
	 
		 MoveWindow( hZaGraf2, 0, visinaprozora/2, sirinaprozora/2, visinaprozora/2, TRUE );
		 MoveWindow( hZaGraf3, sirinaprozora/2, visinaprozora/2, sirinaprozora/2, visinaprozora/2, TRUE );

		}

		break;
	case WM_CREATE :

		 //kreiranje novih prozora u glavnom

		 hZaSimul = CreateDialog(hInst, (LPCTSTR)IDD_ZASIMUL, hWnd, (DLGPROC)ZaSimul);
		 hZaGraf1 = CreateDialog(hInst, (LPCTSTR)IDD_ZAGRAF1, hWnd, (DLGPROC)ZaGraf1);
		 hZaGraf2 = CreateDialog(hInst, (LPCTSTR)IDD_ZAGRAF2, hWnd, (DLGPROC)ZaGraf2);
		 hZaGraf3 = CreateDialog(hInst, (LPCTSTR)IDD_ZAGRAF3, hWnd, (DLGPROC)ZaGraf3);
		 break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDM_WORK:
			// pocetni uslovi

			SMZ.rk4(SMZ);

			HANDLE hThread;
				DWORD dwId;
 
			StartStop=1;     // Postavljamo StartStop na 1                  
			hThread = CreateThread( NULL, 0, (unsigned long (__stdcall *)(void *)) Thread_za_Graf,
			NULL, 0, &dwId );  // Pozivanje threda


			break;
		case IDM_INFO :
			{

			//ovo treba da se ispravi
			 int z = MessageBox( hWnd, _T("Sunce 0:0:0\nZemlja 1.49e11:0:0\nMesec 1.47e11:0:0 "), _T("Default koordinate"),  MB_OK|MB_APPLMODAL);
			 //if (z = 1) PostQuitMessage(0);
			}
			break;
		case IDM_CLEAR:
			{
				// ne znam da li je ovo dobro, trebali bi da restartuje sve prozore

				ShowWindow (hWnd, SW_MINIMIZE);// nestaje
				ShowWindow (hWnd, SW_MAXIMIZE); // prikazuje se
			}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

// 4 f-je za prozore


LRESULT CALLBACK ZaSimul(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_INITDIALOG:           
		return TRUE;
	case WM_COMMAND:
            switch (LOWORD(wParam))
				{	
    	       	case IDD_COORD:
			      // code..

			char buffer[100];
			GetDlgItemText(hZaSimul,IDC_EDIT1, buffer, 100);
			int n = 60*60*24*atoi(buffer);
			SMZ.Setdt(n);
			char buffer2[100];
			GetDlgItemText(hZaSimul,IDC_EDIT2, buffer2, 100);
			SMZ.Sett(SMZ.Getdt()*atof(buffer2));

			/*SMZ.Setdt(1*60*60);
			SMZ.Sett(SMZ.Getdt()*5000);*/

			SMZ.Setxs(0.0);
			SMZ.Setys(0.0);
			SMZ.Setzs(0.0);

			SMZ.Setxp(1.49*pow(10.0, 11));
			SMZ.Setyp(0.0);
			SMZ.Setzp(0.0);

			SMZ.Setxm(1.51*pow(10.0, 11));
			SMZ.Setym(0.0);
			SMZ.Setzm(0.0);

			SMZ.Setvxs(0.0);
			SMZ.Setvys(0.0);
			SMZ.Setvzs(0.0);

			SMZ.Setvxp(0.0);
			SMZ.Setvyp(30000.0);
			SMZ.Setvzp(0.0);

			SMZ.Setvxm(0.0);
			SMZ.Setvym(10000.25);
			SMZ.Setvzm(0.0);

			SMZ.Setms(1.98*pow(10.0, 30));
			SMZ.Setmp(5.97*pow(10.0, 24));
			SMZ.Setmm(7.3*pow(10.0,22));
			MessageBox( hZaGraf1, _T("Ucitane su koordinate"), _T("Default"),  MB_OK|MB_APPLMODAL);
			    //MessageBox(hWndDlg, _T("Simulacija u toku keepo"), _T("Klappa"),MB_OK);
				  } 
				break;
	case WM_PAINT:
		{			PAINTSTRUCT ps;
					HDC hdc;
			        hdc = BeginPaint(hZaSimul, &ps);
					HFONT font;
              	        font = CreateFont(20, 7, 0, 0,
                           	FW_NORMAL, FALSE, FALSE, FALSE,
                          		ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		         	CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		         	DEFAULT_PITCH | FF_ROMAN,
			"");

		        SelectObject(hdc, font);
        		TextOut(hdc, 20, 35, "dt[d]=", 12);
				TextOut(hdc, 25, 115, "t[d]=",12);
        DeleteObject(font);
	        
	       EndPaint(hWndDlg, &ps);

		}break;
	}

	return FALSE;
}
LRESULT CALLBACK ZaGraf1(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_INITDIALOG:           
		return TRUE;

	}

	return FALSE;
}
LRESULT CALLBACK ZaGraf2(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_INITDIALOG:           
		return TRUE;

	}

	return FALSE;
}

LRESULT CALLBACK ZaGraf3(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_INITDIALOG:           
		return TRUE;

	}

	return FALSE;
}

DWORD WINAPI Thread_za_Graf( LPDWORD lpdwData )
{
	while( TRUE )
	{
	    if ( StartStop==0) 
	    {
		ExitThread( IDYES );		  
       	    }
	    else	
        	    {             
           		grafik graf1;
				graf1.ucitaj_podatke(aa, bb, brojpodataka);
					graf1.crtaj_ose(hZaGraf2);
					graf1.crtaj_XY(hZaGraf2);
				
           		StartStop=0 ;    
	   }
	}	

	return( 0 );   
}


	


