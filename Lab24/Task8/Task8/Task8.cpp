// Task8.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Task8.h"
#include <stdio.h>

#define MAX_LOADSTRING 100
#define MAP_SIZE 1024

#define CELL_SIZE 5; 
//коды 
// 0 - пусто
// 1 - игрок
// 2 - стена
// 3 - золото
int map_size = 150;
int map[MAP_SIZE][MAP_SIZE];
int steps = 0;
int gold = 0;

COORD PlayerCoord() {
    int i, j;
    COORD c;
    for (i = 0; i < map_size; i++) {
        for (j = 0; j < map_size; j++) {
            if (map[i][j] == 1) {
                c.X = i;
                c.Y = j;
                return c;
            }
        }
    }
}
void generate_start_map() {
    map[1][1] = 1;

    map[4][4] = 2;
    map[4][5] = 2;
    map[5][5] = 2;
    map[5][4] = 2;
    map[6][4] = 2;
    map[7][4] = 2;
    map[8][4] = 2;
    map[8][6] = 2;
    map[9][6] = 2;
    map[10][6] = 2;

    map[15][15] = 3;
    map[15][16] = 3;
    map[15][17] = 3;
    map[16][15] = 3;
    map[16][16] = 3;
    map[16][17] = 3;
    map[17][17] = 3;
    map[17][16] = 3;
    map[17][15] = 3;

}
void DrawMap(HDC hdc) {
    HBRUSH hBrushEmptyCell = CreateSolidBrush(RGB(255, 255, 255));
    HBRUSH hBrushGold = CreateSolidBrush(RGB(255, 255, 0));
    HBRUSH hBrushWall = CreateSolidBrush(RGB(0, 0, 0));
    HBRUSH hBrushMan = CreateSolidBrush(RGB(0, 0, 255));

    HBRUSH brush[4] = { hBrushEmptyCell, hBrushMan, hBrushWall, hBrushGold };
    int i, j;
    for (i = 0; i < map_size; i++) {
        for (j = 0; j < map_size; j++) {
            int x1 = j * CELL_SIZE;
            int x2 = (j + 1) * CELL_SIZE;
            int y1 = i * CELL_SIZE;
            int y2 = (i + 1) * CELL_SIZE;
            RECT r = { x1, y1, x2, y2 };
            FillRect(hdc, &r, brush[map[i][j]]);
        }
    }
    for (i = 0; i < 4; i++) {
        DeleteObject(brush[i]);
    }

    char strC[80];
    sprintf_s(strC, "steps=%d golds=%d", steps, gold);
    TCHAR strWin[80];
    OemToChar(strC, strWin);

    HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(0, 0, 128));

    TextOut(hdc, 10, 30 * strlen(strC), (LPCWSTR)strWin, _tcslen(strWin));
}
bool in_bounds(int x, int y) {
    return x >= 0 && y >= 0 && x < map_size&& y < map_size;
}
void MovePlayer(int dir) {
    /*
    * 0 - right
    * 1 - up
    * 2 - left
    * 3 - down
    */
    COORD player = PlayerCoord();
    int dirPair[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

    int mv_x = -1, mv_y = -1;
    mv_x = player.X + dirPair[dir][0], mv_y = player.Y + dirPair[dir][1];
    if (!in_bounds(mv_x, mv_y) || map[mv_x][mv_y] == 2) {
        return;
    }
    if (map[mv_x][mv_y] == 3) {
        gold++;
    }
    map[mv_x][mv_y] = 1;
    map[mv_x - dirPair[dir][0]][mv_y - dirPair[dir][1]] = 0;
    steps++;
    return;



}
void CreateWall() {
    COORD player = PlayerCoord();
    if (in_bounds(player.X, player.Y - 1)) {
        map[player.X][player.Y - 1] = 2;
    }
}
void CreateGold() {
    COORD player = PlayerCoord();
    if (in_bounds(player.X, player.Y + 1)) {
        map[player.X][player.Y + 1] = 3;
    }
}
void CreateCubeGold() {
    COORD player = PlayerCoord();
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (in_bounds(player.X - 4 + i, player.Y - 1 + j)) {
                map[player.X - 4 + i][player.Y - 1 + j] = 3;
            }
        }
    }
}
void CreateWallFortnite() {
    COORD player = PlayerCoord();
    int wall[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (in_bounds(player.X - 2 + i, player.Y - 2 + j)) {
                if (wall[i][j] == 1) {
                    map[player.X - 2 + i][player.Y - 2 + j] = 2;
                }
            }
        }
    }

}
void SaveBinary() {
    FILE* fout;
    fopen_s(&fout, "c:\\game.bin", "wb");
    if (fout == NULL) {
        printf("file %s not exists\n", "c:\\game.bin");
        return;
    }
    int n = map_size, m = map_size;
    fwrite(&n, sizeof(n), 1, fout);
    fwrite(&m, sizeof(m), 1, fout);

    fwrite(map, sizeof(map), 1, fout);

    fwrite(&steps, sizeof(steps), 1, fout);
    fwrite(&gold, sizeof(gold), 1, fout);
    fclose(fout);
}

void LoadBinary() {
    FILE* fin;
    fopen_s(&fin, "c:\\game.bin", "rb");
    if (fin == NULL) {
        printf("file %s not exists\n", "c:\\game.bin");
        return;
    }
    fread(&map_size, sizeof(map_size), 1, fin);
    fread(&map_size, sizeof(map_size), 1, fin);

    fread(map, sizeof(map), 1, fin);

    fread(&steps, sizeof(steps), 1, fin);
    fread(&gold, sizeof(gold), 1, fin);
    fclose(fin);
}
// ----- LAB 24 -----
void doMidasHand(int x, int y) {
    if (map[x][y] == 2) {
        if (in_bounds(x + 1, y)) doMidasHand(x + 1, y);
        if (in_bounds(x - 1, y)) doMidasHand(x - 1, y);
        if (in_bounds(x, y + 1)) doMidasHand(x, y + 1);
        if (in_bounds(x, y - 1)) doMidasHand(x, y - 1);
    }
}
void midasHandToRight() {
    COORD player = PlayerCoord();
    if (in_bounds(player.X, player.Y + 1) && map[player.X][player.Y + 1] == 2) {
        doMidasHand(player.X, player.Y + 1);
    }
}

// ----- LAB 24 -----

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TASK8, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TASK8));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TASK8));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TASK8);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

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
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        generate_start_map();
        break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
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

        DrawMap(hdc);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam) {
        case VK_RIGHT:
            MovePlayer(0);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            MovePlayer(1);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_LEFT:
            MovePlayer(2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN:
            MovePlayer(3);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x30: // 0
            SaveBinary();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x31: // 1
            LoadBinary();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x41: // A
            CreateWall();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x44: // D
            CreateGold();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x57: // W
            CreateCubeGold();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x53: // S
            CreateWallFortnite();
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 0x4d: // M - MidasHand
            midasHandToRight();
            InvalidateRect(hWnd, NULL, TRUE);
            break;


        }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
