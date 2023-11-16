#include <windows.h>

void createComboBox(HINSTANCE hInstance);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR szCmdLine, int CmdShow)
{
	MessageBoxW(NULL, szCmdLine, L"Title", MB_OK);
	createComboBox(hInstance);
	return 0;
}

void createComboBox(HINSTANCE hInstance)
{
	HWND hwnd = CreateWindow(WC_COMBOBOX, L"Combo Box", WS_OVERLAPPEDWINDOW, 100, 100, 200, 200, NULL, NULL, hInstance, NULL);

	if (!hwnd)
	{
		return 1;
	}

	SendMessage(hwnd, CB_ADDSTRING, 0, (LPARAM)L"Item 1");
	SendMessage(hwnd, CB_ADDSTRING, 0, (LPARAM)L"Item 2");
	SendMessage(hwnd, CB_ADDSTRING, 0, (LPARAM)L"Item 3");

	SendMessage(hwnd, CB_SETCURSEL, 0, (LPARAM)0);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
