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
#pragma region Task1
void drawTree(HDC hdc, int x, int y) {
    MoveToEx(hdc, x + 20, y + 0, NULL);
    LineTo(hdc, x + 30, y + 20);
    LineTo(hdc, x + 10, y + 20);
    LineTo(hdc, x + 20, y + 0);
    // средний треугольник MoveToEx(hdc, 20, 10, NULL);
    MoveToEx(hdc, x + 20, y + 10, NULL);
    LineTo(hdc, x + 30, y + 40);
    LineTo(hdc, x + 10, y + 40);
    LineTo(hdc, x + 20, y + 10);
    // нижний треугольник
    MoveToEx(hdc, x + 20, y + 30, NULL);
    LineTo(hdc, x + 40, y + 80);
    LineTo(hdc, x + 0, y + 80);
    LineTo(hdc, x + 20, y + 30);
}

void drawTask1(HDC hdc) {
    int n = 0;
    do {
        drawTree(hdc, n * 50 + 10, 10);
        n += 1;
    } while (n < 10);

    n = 0;
    do {
        drawTree(hdc, n * 50 + 10, n * 50 + 10);
        n += 1;
    } while (n < 10);

    n = 0;
    do {
        drawTree(hdc, 10, n * 100 + 10);
        n += 1;
    } while (n < 5);
}

#pragma endregion

#pragma region Task2
void drawTruck(HDC hdc, int x, int y)
{
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, hPen);

    Rectangle(hdc, x, y + 30, x + 40, y + 50);
    Rectangle(hdc, x + 10, y + 10, x + 40, y + 30);
    Rectangle(hdc, x + 40, y, x + 100, y + 50);

    hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, hPen);

    Ellipse(hdc, x + 10, y + 40, x + 30, y + 60);
    Ellipse(hdc, x + 70, y + 40, x + 90, y + 60);
}
void drawTruck1(HDC hdc) {
    int n = 0;
    do {
        drawTruck(hdc, n * 105 + 10, 10);
        n += 1;
    } while (n < 10);
}
void drawTruck2(HDC hdc) {
    int n = 0;
    do {
        drawTruck(hdc, n * 80 + 10, n * 80 + 10);
        n += 1;
    } while (n < 5);
}
void drawTruck3(HDC hdc) {
    int n = 0;
    do {
        drawTruck(hdc, 10, n * 80 + 10);
        n += 1;
    } while (n < 5);
}
void drawTask2(HDC hdc) {
    drawTruck1(hdc);
    drawTruck2(hdc);
    drawTruck3(hdc);
}
#pragma endregion

#pragma region Task3
void drawSnowMan(HDC hdc, int x, int y) {
    Ellipse(hdc, x + 20, y + 0,  40 + x, 20 + y);
    Ellipse(hdc, x + 10, y + 20, 50 + x, 60 + y);
    Ellipse(hdc, x + 0,  y + 60, 60 + x, 120 + y);

    MoveToEx(hdc, x, y + 40, NULL);
    LineTo(hdc, x + 30, y + 20);

    MoveToEx(hdc, x + 60, y + 40, NULL);
    LineTo(hdc, x + 30, y + 20);

    MoveToEx(hdc, x + 70, y, NULL);
    LineTo(hdc, x + 40, y + 120);

    MoveToEx(hdc, x + 65, y, NULL);
    LineTo(hdc, x + 67, y + 20);
    LineTo(hdc, x + 75, y);
}
void drawSnowMan1(HDC hdc) {
    drawSnowMan(hdc, 10, 10);
    drawSnowMan(hdc, 300, 10);
    drawSnowMan(hdc, 10, 300);
    drawSnowMan(hdc,150, 150);
    drawSnowMan(hdc,300, 300);
}
void drawSnowMan2(HDC hdc) {
    int n = 0;
    do {
        drawSnowMan(hdc, n * 80 + 10, 10);
        n += 1;
    } while (n < 10);
}
void drawSnowMan3(HDC hdc) {
    int n = 0;
    do {
        drawSnowMan(hdc, n * 80 + 10, 10 +  125 * n);
        n += 1;
    } while (n < 5);
}
void drawSnowMan4(HDC hdc) {
    int n = 0;
    do {
        drawSnowMan(hdc, 10, 10 + 125 * n);
        n += 1;
    } while (n < 5);
}
void drawTask3(HDC hdc) {
    drawSnowMan1(hdc);
    drawSnowMan2(hdc);
    drawSnowMan3(hdc);
    drawSnowMan4(hdc);
}
#pragma endregion

#pragma region Task4
void drawOpel(HDC hdc, int x, int y) {

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 10, RGB(128, 128, 128));
    SelectObject(hdc, hPen);

    Ellipse(hdc, x + 20, y + 20, x + 100, y + 100);
    MoveToEx(hdc, x, y + 50, NULL);
    LineTo(hdc, x + 70, y + 50);
    LineTo(hdc, x + 50, y + 70);
    LineTo(hdc, x + 120, y + 70);
}
void drawOpel1(HDC hdc) {
    drawSnowMan(hdc, 10, 10);
    drawSnowMan(hdc, 300, 10);
    drawSnowMan(hdc, 10, 300);
    drawSnowMan(hdc, 150, 150);
    drawSnowMan(hdc, 300, 300);
}
void drawOpel2(HDC hdc) {
    int n = 0;
    do {
        drawOpel(hdc, n * 125 + 10, 10);
        n += 1;
    } while (n < 10);
}
void drawOpel3(HDC hdc) {
    int n = 0;
    do {
        drawOpel(hdc, n * 60 + 10, 1000 - 125 * n);
        n += 1;
    } while (n < 5);
}
void drawOpel4(HDC hdc) {
    int n = 0;
    do {
        drawOpel(hdc, 10, 10 + 125 * n);
        n += 1;
    } while (n < 5);
}
void drawTask4(HDC hdc) {
    drawOpel1(hdc);
    drawOpel2(hdc);
    drawOpel3(hdc);
    drawOpel4(hdc);
}
#pragma endregion

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

            drawTask1(hdc);
            drawTask2(hdc);
            drawTask3(hdc);
            drawTask4(hdc);
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
