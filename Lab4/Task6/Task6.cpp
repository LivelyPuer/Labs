// Task6.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Task6.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TASK6, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TASK6));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
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
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TASK6));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TASK6);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HPEN hPen;
            // -------ДОМ-------
            // крыша
            hPen = CreatePen(PS_DASH, 5, RGB(255, 128, 0));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 150, 350, NULL);
            LineTo(hdc, 275, 250);
            LineTo(hdc, 400, 350);

            // дом
            hPen = CreatePen(PS_DASH, 8, RGB(0, 0, 0));
            SelectObject(hdc, hPen);

            LineTo(hdc, 400, 525);
            LineTo(hdc, 150, 525);
            LineTo(hdc, 150, 350);
            LineTo(hdc, 400, 350);

            // окно
            hPen = CreatePen(PS_DASH, 2, RGB(0, 128, 255));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 225, 400, NULL);
            LineTo(hdc, 225, 475);
            LineTo(hdc, 325, 475);
            LineTo(hdc, 325, 400);
            LineTo(hdc, 225, 400);

            // рама
            MoveToEx(hdc, 275, 400, NULL);
            LineTo(hdc, 275, 475);
            MoveToEx(hdc, 275, 425, NULL);
            LineTo(hdc, 325, 425);
            // -------ДОМ-------


            // -------ЕЛЬ-------
            hPen = CreatePen(PS_DASH, 5, RGB(0, 255, 128));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 450, 525, NULL);
            LineTo(hdc, 525, 450);
            LineTo(hdc, 600, 525);
            LineTo(hdc, 450, 525);

            MoveToEx(hdc, 470, 450, NULL);
            LineTo(hdc, 525, 380);
            LineTo(hdc, 580, 450);
            LineTo(hdc, 470, 450);

            MoveToEx(hdc, 500, 380, NULL);
            LineTo(hdc, 525, 350);
            LineTo(hdc, 550, 380);
            LineTo(hdc, 500, 380);
            // -------ЕЛЬ--------

            // ------ДЕРЕВО------


            MoveToEx(hdc, 60, 525, NULL);
            LineTo(hdc, 60, 350);

            MoveToEx(hdc, 60, 500, NULL);
            LineTo(hdc, 0, 475);

            MoveToEx(hdc, 60, 475, NULL);
            LineTo(hdc, 120, 450);

            MoveToEx(hdc, 60, 450, NULL);
            LineTo(hdc, 0, 425);

            MoveToEx(hdc, 60, 425, NULL);
            LineTo(hdc, 120, 400);

            MoveToEx(hdc, 60, 400, NULL);
            LineTo(hdc, 0, 375);

            // ------ДЕРЕВО------

            // ------ЗАБОР-------

            hPen = CreatePen(PS_DASH, 1, RGB(255, 128, 0));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 50, 575, NULL);
            LineTo(hdc, 800, 575);
            MoveToEx(hdc, 50, 585, NULL);
            LineTo(hdc, 800, 585);

            hPen = CreatePen(NULL, 2, RGB(255, 128, 0));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 50, 550, NULL);
            LineTo(hdc, 50, 600);
            LineTo(hdc, 100, 550);
            LineTo(hdc, 100, 600);

            LineTo(hdc, 150, 550);
            LineTo(hdc, 150, 600);

            LineTo(hdc, 200, 550);
            LineTo(hdc, 200, 600);

            LineTo(hdc, 250, 550);
            LineTo(hdc, 250, 600);

            LineTo(hdc, 300, 550);
            LineTo(hdc, 300, 600);

            LineTo(hdc, 350, 550);
            LineTo(hdc, 350, 600);

            LineTo(hdc, 400, 550);
            LineTo(hdc, 400, 600);

            LineTo(hdc, 450, 550);
            LineTo(hdc, 450, 600);

            LineTo(hdc, 500, 550);
            LineTo(hdc, 500, 600);

            LineTo(hdc, 550, 550);
            LineTo(hdc, 550, 600);

            LineTo(hdc, 600, 550);
            LineTo(hdc, 600, 600);

            LineTo(hdc, 650, 550);
            LineTo(hdc, 650, 600);

            LineTo(hdc, 700, 550);
            LineTo(hdc, 700, 600);

            LineTo(hdc, 750, 550);
            LineTo(hdc, 750, 600);

            LineTo(hdc, 800, 550);
            LineTo(hdc, 800, 600);
            // ------ЗАБОР-------

            // ------САРАЙ-------
            
            hPen = CreatePen(NULL, 5, RGB(0, 0, 255));
            SelectObject(hdc, hPen);

            // ------САРАЙ-------

            MoveToEx(hdc, 650, 525, NULL);
            LineTo(hdc, 900, 525);
            LineTo(hdc, 900, 325);
            LineTo(hdc, 950, 300);
            LineTo(hdc, 1000, 325);
            LineTo(hdc, 1000, 525);
            LineTo(hdc, 1250, 525);
            LineTo(hdc, 1250, 250);
            LineTo(hdc, 950, 200);
            LineTo(hdc, 650, 250);
            LineTo(hdc, 650, 525);

            MoveToEx(hdc, 650, 475, NULL);
            LineTo(hdc, 900, 475);

            MoveToEx(hdc, 1000, 475, NULL);
            LineTo(hdc, 1250, 475);

            hPen = CreatePen(PS_DOT, 10, RGB(0, 0, 255));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 900, 475, NULL);
            LineTo(hdc, 650, 250);

            MoveToEx(hdc, 1000, 475, NULL);
            LineTo(hdc, 1250, 250);

            EndPaint(hWnd, &ps);
        }
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
