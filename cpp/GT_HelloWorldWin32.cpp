// GT_HelloWorldWin32.cpp 
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c 
// This is the simplest Win32 program and can be used as a template for developing desktop applications.

#include <windows.h> 
#include <stdlib.h> 
#include <string.h> 
#include <tchar.h> 

// ------------------------Global variables---------------------------------
// Main Form Class Name
static TCHAR szWindowClass[] = _T("win32app"); 
// Strings that appear in the application title bar
static TCHAR szTitle[] = _T("Win32 Guided Tour Application"); 

//HINSTANCE is a data type in Windows. It is used to mark (record) an instance of a program.
//It's the same as HMODULE (generic, these two types end up with 32-bit unsigned long shaping).
//HINSTANCE, separately HANDLE + INSTANCE
//An example is a program. Take qq for example: you can drive two qq numbers at the same time, but only one qq software in your computer.
//These two qq numbers are two examples of qq
HINSTANCE hInst; 

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 


//Each Windows desktop application must have a window procedure function
//This function handles a large number of messages that the application receives from the operating system. 
//For example, if the "OK" button is in the application's dialog box, the user clicks the button.
//The operating system sends a message to the application that the notification button has been clicked. WndProc is responsible for responding to this event.
//In this case, the corresponding response might be to close the dialog box.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 

//Official Content - --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Main Form Function (Entry Procedure)
//Each Win32-based application function must have a WinMain function
//Just as every C application and C++ console application must have a main function at the starting point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { 
	//Create a window class structure of type WNDCLASSEX. This structure contains information about windows
	//For example, the application icon, the background color of the window, the name displayed in the title bar, the name of the window procedure function, and so on.
	WNDCLASSEX wcex; 
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style          = CS_HREDRAW | CS_VREDRAW; 
	wcex.lpfnWndProc    = WndProc; 
	wcex.cbClsExtra     = 0; 
	wcex.cbWndExtra     = 0; 
	wcex.hInstance      = hInstance; 
	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION)); 
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW); 
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1); 
	wcex.lpszMenuName   = NULL; 
	wcex.lpszClassName  = szWindowClass; 
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION)); 
	
	//Register the created window class. Use the RegisterClassEx function and pass the window class structure as a parameter.
	if (!RegisterClassEx(&wcex)) { 
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("Win32 Guided Tour"), NULL); 
		return 1; 
	} 

	// Store instance handle in our global variable 
	// Store handle instances in global variables
	hInst = hInstance; 
	
	// Parametric interpretation of the CreateWindow function: 
	// szWindowClass: the name of the application 
	// szTitle: the text that appears in the title bar 
	// WS_OVERLAPPEDWINDOW: the type of window to create 
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y) 
	// 500, 100: initial size (width, length) 
	// NULL: the parent of this window 
	// NULL: this application does not have a menu bar 
	// hInstance: the first parameter from WinMain 
	// NULL: not used in this application 
	// The returned HWND is a handle to a window
	HWND hWnd = CreateWindow( szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 100, NULL, NULL, hInstance, NULL ); 
	if (!hWnd) { 
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), NULL); 
		return 1; 
	} 


	// Parametric Interpretation of Show Window Function: 
	// HWnd: Window handle returned by the CreateWindow function 
	// nCmdShow: the fourth parameter from WinMain 
	ShowWindow(hWnd, nCmdShow);
	// The Update Window function is used to update the area specified by the window
	// If the window update area is not empty, the Update Window function sends a WM_PAINT message to update the client area of the specified window.
	// Function bypasses the application's message queue and sends WM_PAINT messages directly to the window of the specified window
	// If the update area is empty, no message is sent.
	UpdateWindow(hWnd); 

	// Main message loop: 
	// Add a message loop to listen for messages sent by the operating system. 
	// When an application receives a message, the loop schedules the message to the WndProc function for processing. 
	MSG msg; 
	while (GetMessage(&msg, NULL, 0, 0)) { 
		TranslateMessage(&msg); //Translation message
		DispatchMessage(&msg);  //Dispatch message
	} 
	return (int) msg.wParam; 
} 

// // Functions: WndProc(HWND, UINT, WPARAM, LPARAM) 
// // Goal: Processing the information generated by the main form
// // WM_PAINT message represents drawing the main form 
// // WM_DESTROY message represents the delivery of an exit message and the return 
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) { 
	PAINTSTRUCT ps;
	HDC hdc; 
	TCHAR greeting[] = _T("Hello, World!"); 
	switch (message) { 
		case WM_PAINT: 
			//To process WM_PAINT messages, first call BeginPaint
			//It then processes all the logic and lays out text, buttons, and other controls in the window.
			//Then call EndPaint. 
			hdc = BeginPaint(hWnd, &ps); 

			// Layout the application in this code - -------------------------------------------------------------------------------------------------------------------------------------------- 
			// For this application, the logic between the start and end calls is to display the string "Hello, World!" in the window.
			// Note that the TextOut function is used to display strings.
			TextOut(hdc, 50, 5, greeting, _tcslen(greeting)); 
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------

			EndPaint(hWnd, &ps);
			break; 
		case WM_DESTROY: 
			PostQuitMessage(0); 
			break;
		default: 
			//Def Windows Proc default window handler
			//This function is the default window handler, and we can throw all messages we don't care about to it for processing.
			return DefWindowProc(hWnd, message, wParam, lParam); 
			break; 
	} 
	return 0; 
} 