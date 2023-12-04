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
            HBRUSH hBrush;

            HPEN hPen;
            hPen = CreatePen(PS_SOLID, 5, RGB(128, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(255, 128, 0));
            SelectObject(hdc, hBrush);
            
            Rectangle(hdc, 50, 200, 300, 250);

            hPen = CreatePen(PS_SOLID, 5, RGB(0, 128, 255));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
            SelectObject(hdc, hBrush);

            Ellipse(hdc, 75, 275, 125, 225);
            DeleteObject(hBrush);
            hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 128));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 255, 0));
            SelectObject(hdc, hBrush);

            Ellipse(hdc, 225, 275, 275, 225);
            DeleteObject(hBrush);

            hPen = CreatePen(PS_SOLID, 5, RGB(128, 0, 0));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 100, 200, NULL);
            LineTo(hdc, 150, 150);
            LineTo(hdc, 250, 150);
            LineTo(hdc, 300, 200);

            // Snowman
            hPen = CreatePen(PS_SOLID, 5, RGB(100, 100, 100));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 0));
            SelectObject(hdc, hBrush);

            Ellipse(hdc, 350, 300, 450, 225);

            hPen = CreatePen(PS_SOLID, 4, RGB(150, 150, 150));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_CROSS, RGB(0, 0, 0));
            SelectObject(hdc, hBrush);

            MoveToEx(hdc, 320, 230, NULL);
            LineTo(hdc, 480, 230);

            Ellipse(hdc, 370, 250, 430, 205);

            hPen = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 255, 255));
            SelectObject(hdc, hBrush);

            Ellipse(hdc, 370, 200, 430, 155);

            hPen = CreatePen(PS_SOLID, 4, RGB(255, 128, 0));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 400, 185, NULL);
            LineTo(hdc, 380, 186);

            MoveToEx(hdc, 460, 300, NULL);
            LineTo(hdc, 460, 186);

            // bus
            hPen = CreatePen(PS_SOLID, 4, RGB(255, 50, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_CROSS, RGB(255, 0, 0));
            SelectObject(hdc, hBrush);
            
            Rectangle(hdc, 500, 250, 1000, 50);

            hPen = CreatePen(PS_SOLID, 4, RGB(134, 50, 123));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_CROSS, RGB(45, 3, 56));
            SelectObject(hdc, hBrush);

            Ellipse(hdc, 525, 275, 575, 225);
            Ellipse(hdc, 625, 275, 675, 225);
            Ellipse(hdc, 825, 275, 875, 225);
            Ellipse(hdc, 925, 275, 975, 225);

            hPen = CreatePen(PS_SOLID, 4, RGB(134, 50, 123));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(0, 50, 240));
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 500, 150, 700, 50);

            // chair
            hPen = CreatePen(PS_SOLID, 4, RGB(255, 128, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(255, 128, 0));
            SelectObject(hdc, hBrush);

            Rectangle(hdc, 1100, 250, 1120, 50);

            hPen = CreatePen(PS_SOLID, 6, RGB(230, 100, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(230, 100, 0));
            SelectObject(hdc, hBrush);

            Rectangle(hdc, 1120, 150, 1200, 130);

            hPen = CreatePen(PS_SOLID, 3, RGB(201, 70, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(201, 70, 0));
            SelectObject(hdc, hBrush);

            Rectangle(hdc, 1180, 150, 1200, 250);

            hPen = CreatePen(PS_SOLID, 3, RGB(200, 200, 200));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(200, 200, 200));
            SelectObject(hdc, hBrush);

            Rectangle(hdc, 1060, 280, 1240, 250);

            // cloud
            hPen = CreatePen(PS_SOLID, 3, RGB(200, 200, 200));
            SelectObject(hdc, hPen);
            hBrush = CreateSolidBrush(RGB(255, 255, 255));
            SelectObject(hdc, hBrush);

            Ellipse(hdc, 10, 50, 50, 10);
            Ellipse(hdc, 50, 50, 140, 8);
            Ellipse(hdc, 20, 70, 100, 5);
            
            hPen = CreatePen(PS_SOLID, 3, RGB(100, 100, 255));
            SelectObject(hdc, hPen);

            Ellipse(hdc, 210, 80, 300, 10);
            Ellipse(hdc, 180, 120, 360, 50);
            Ellipse(hdc, 210, 70, 280, 30);

            // clock

            hPen = CreatePen(PS_SOLID, 3, RGB(100, 100, 255));
            SelectObject(hdc, hPen);

            Ellipse(hdc, 500, 800, 800, 500);
            Pie(hdc, 500, 550, 600, 450, 1000, 500, 0, 500);
            Pie(hdc, 700, 550, 800, 450, 1000, 500, 0, 500);

            hBrush = CreateSolidBrush(RGB(100, 100, 255));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 640, 660, 660, 640);

            hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 650, 650, NULL);
            LineTo(hdc, 600, 730);

            hPen = CreatePen(PS_SOLID, 3, RGB(255, 128, 0));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 650, 650, NULL);
            LineTo(hdc, 600, 650);

            hPen = CreatePen(PS_SOLID, 3, RGB(100, 100, 255));
            SelectObject(hdc, hPen);

            MoveToEx(hdc, 650, 650, NULL);
            LineTo(hdc, 760, 730);

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
