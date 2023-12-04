// Task1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Task1.h"

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
    LoadStringW(hInstance, IDC_TASK1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TASK1));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TASK1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TASK1);
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

void Image0(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);

    POINT p[4];
    p[0].x = cx;
    p[0].y = cy + 20;
    p[1].x = cx + 20;
    p[1].y = cy - 20;
    p[2].x = cx - 20;
    p[2].y = cy - 20;
    p[3].x = cx;
    p[3].y = cy + 20;

    Polygon(hdc, p, 4);
    DeleteObject(hPen);
}
void Image1(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 0));
    SelectObject(hdc, hPen);

    POINT p[4] = {
    cx,         cy + 20,
    cx + 20,    cy - 20,
    cx - 20,    cy - 20,
    cx,         cy + 20,
    };
    

    Polygon(hdc, p, 4);
    DeleteObject(hPen);
}

void Image2(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
    SelectObject(hdc, hPen);

    POINT p[5] = {
    cx,         cy - 20,
    cx + 20,    cy,
    cx,         cy + 20,
    cx - 20,    cy,
    cx,         cy - 20,
    };


    Polygon(hdc, p, 4);
    DeleteObject(hPen);
}


void Image3(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    POINT p[5] = {
    cx,         cy,
    cx + 20,    cy - 20,
    cx,         cy + 20,
    cx - 20,    cy - 20,
    cx,         cy,
    };


    Polygon(hdc, p, 4);
    DeleteObject(hPen);
}

void Image4(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 128, 128));
    SelectObject(hdc, hPen);

    POINT p[6] = {
    cx - 20,    cy,
    cx + 20,    cy,
    cx,         cy - 10,
    cx + 20,    cy - 20,
    cx - 20,    cy - 20,
    cx - 20,    cy + 20,
    };


    Polygon(hdc, p, 6);
    DeleteObject(hPen);
}
void Image5(HDC hdc, int cx, int cy) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 128));
    SelectObject(hdc, hPen);

    POINT p[6] = {
    cx,    cy,
    cx + 20,    cy - 20,
    cx + 20,    cy + 20,
    cx - 20,    cy + 20,
    cx - 20,    cy - 20,
    cx,    cy,
    };


    Polygon(hdc, p, 5);
    DeleteObject(hPen);
}

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
            int x, y;
            x = 0, y = 0;
            // task 1
            Image0(hdc, x + 40, y + 40);
            Image0(hdc, x + 140, y + 40);
            Image0(hdc, x + 240, y + 40);
            Image0(hdc, x + 240, y + 240);
            Image0(hdc, x + 40, y + 240);
            x = 300, y = 0;
            // task 2

            Image1(hdc, x + 40, y + 40);
            Image1(hdc, x + 140, y + 40);
            Image1(hdc, x + 240, y + 40);
            Image1(hdc, x + 240, y + 240);
            Image1(hdc, x + 40, y + 240);

            x = 0, y = 300;
            // task 3

            Image2(hdc, x + 40, y + 40);
            Image2(hdc, x + 140, y + 40);
            Image2(hdc, x + 240, y + 40);
            Image2(hdc, x + 240, y + 240);
            Image2(hdc, x + 40, y + 240);

            x = 300, y = 300;
            // task 4

            Image3(hdc, x + 40, y + 40);
            Image3(hdc, x + 140, y + 40);
            Image3(hdc, x + 240, y + 40);
            Image3(hdc, x + 240, y + 240);
            Image3(hdc, x + 40, y + 240);

            x = 600, y = 0;
            // task 5

            Image4(hdc, x + 40, y + 40);
            Image4(hdc, x + 140, y + 40);
            Image4(hdc, x + 240, y + 40);
            Image4(hdc, x + 240, y + 240);
            Image4(hdc, x + 40, y + 240);

            x = 600, y = 300;
            // task 5

            Image5(hdc, x + 40, y + 40);
            Image5(hdc, x + 140, y + 40);
            Image5(hdc, x + 240, y + 40);
            Image5(hdc, x + 240, y + 240);
            Image5(hdc, x + 40, y + 240);

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
