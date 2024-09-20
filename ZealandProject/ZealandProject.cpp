// ZealandProject.cpp : Defines the entry point for the application.
//

#include "ZealandProject.h"
#include "framework.h"
#include <shellapi.h>
#include <commctrl.h>
#include <windows.h>
#include <WinBase.h>
#include <malloc.h>
#include <mmsystem.h>
#include <Richedit.h>

#define MAX_LOADSTRING 100
#define MAX_SIZE 16382


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name


//Version
float Version = 1.8;

//Settings
int QuestionSetting = 1;
int ShowImportant = 0;

int g_sliderValue = 130;



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

    

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ZEALANDPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ZEALANDPROJECT));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ZEALANDPROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = CreateSolidBrush(RGB(g_sliderValue, g_sliderValue, g_sliderValue));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ZEALANDPROJECT);
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

// Text List here to create "box effect" under buttons
   HWND SocialsText = CreateText(hWnd, hInst, 248, 45, 204, 260, L"               ▸ Socials ◂");

// BUTTONS
   HWND YouTubeButton = CreateButton(hWnd, hInst, 250, 70, 100, 30, L"YouTube", 1001);
   HWND FacebookButton = CreateButton(hWnd, hInst, 250, 120, 100, 30, L"Facebook", 1002);
   HWND FacebookButtonZealand = CreateButton(hWnd, hInst, 250, 148, 100, 15, L"Zealand Group", 1003);
   HWND MessengerButton = CreateButton(hWnd, hInst, 250, 170, 100, 30, L"Messenger", 1004);
   HWND MessengerButtonZealand = CreateButton(hWnd, hInst, 250, 198, 100, 15, L"Zealand Group", 1005);
   HWND InstagramButton = CreateButton(hWnd, hInst, 250, 220, 100, 30, L"Instagram", 1006);
   HWND LinkdinButton = CreateButton(hWnd, hInst, 350, 70, 100, 30, L"LinkdIn", 1007);
   HWND TwitchButton = CreateButton(hWnd, hInst, 350, 120, 100, 30, L"Twitch", 1008);
   HWND SnapchatButton = CreateButton(hWnd, hInst, 350, 170, 100, 30, L"Snapchat", 1009);
   HWND TikTokButton = CreateButton(hWnd, hInst, 350, 220, 100, 30, L"TikTok", 1010);
   HWND RedditButton = CreateButton(hWnd, hInst, 250, 270, 100, 30, L"Reddit", 1011);
   HWND XButton = CreateButton(hWnd, hInst, 350, 270, 100, 30, L"Twitter ( X )", 1012);

   HWND ClearNoteBoxButton = CreateButton(hWnd, hInst, 470, 220, 100, 30, L"Clear", 1510);
   HWND SaveNoteBoxButton = CreateButton(hWnd, hInst, 570, 220, 100, 30, L"Save", 1511);
   HWND ColorButton = CreateButton(hWnd, hInst, 620, 40, 50, 20, L"Color", 1514);


   HWND SearchButton = CreateButton(hWnd, hInst, 30, 320, 80, 30, L"Go!", 1501);
   HWND BugReportsButton = CreateButton(hWnd, hInst, 30, 460, 70, 20, L"Report a bug", 1505);
   HWND CheckForUpdatesButton = CreateButton(hWnd, hInst, 100, 460, 100, 20, L"Check for Updates", 1508);


// Text
   HWND TitleText = CreateText(hWnd, hInst, 30, 10, 125, 38, L" Tool Kit 1.8\nZealand Edition");
   HWND SettingsText = CreateText(hWnd, hInst, 30, 380, 68, 20, L"Settings");
   HWND InputText = CreateText(hWnd, hInst, 30, 280, 200, 30, L"Internet Search");
   HWND ListBoxDescription = CreateText(hWnd, hInst, 30, 60, 100, 30, L" Websites");
   HWND ThemeTextSlider = CreateText(hWnd, hInst, 150, 355, 210, 17, L"Brightness");
   HWND NoteBoxText = CreateText(hWnd, hInst, 471, 40, 58, 30, L"Notebox");
   
   
   //Font
   SetFontSize(ColorButton, 13);
   SetFontSize(MessengerButtonZealand, 10);
   SetFontSize(FacebookButtonZealand, 10);
   SetFontSize(SocialsText, 18);
   SetFontSize(SettingsText, 20);
   SetFontSize(InputText, 17);
   SetFontSize(TitleText, 20);
   SetFontSize(BugReportsButton, 13);
   SetFontSize(CheckForUpdatesButton, 13);


   //Settings
   
   HWND InputFastSearch = CreateWindowW(
       L"EDIT",
       L"",
       WS_VISIBLE |  WS_CHILD | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL,
       30, 300, // X and Y Pos
       200, 20, // Height and Width
       hWnd,
       (HMENU)1502,
       NULL,
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
   );
   HWND NoteBox = CreateWindowW(
       L"EDIT",
       L"",
       WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE,
       470, 60, // X and Y Pos
       200, 150, // Height and Width
       hWnd,
       (HMENU)1509,
       NULL,
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
   );
   HWND ColorBox = CreateWindowEx(0, MSFTEDIT_CLASS, L"",
       WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | WS_VSCROLL,
       10, 10, 300, 200, hWnd, (HMENU)1515, hInst, NULL);
   HWND ToggleWarning = CreateToggleButton(hWnd, hInst, 30, 400, 278, 30, L"Question - Pop Up", 1503);
   HWND ToggleAlwaysOnTop = CreateToggleButton(hWnd, hInst, 30, 430, 138, 30, L"Always On Top", 1504);
   HWND ToggleShowImportant = CreateToggleButton(hWnd, hInst, 168, 430, 140, 30, L"Show Important", 1507);
   SendMessage(ToggleWarning, BM_SETCHECK, BST_CHECKED, 0);
   //CreateTabs(hWnd, hInst);
   ListBoxCreation(hWnd, hInst);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}



void ClearMemory()
{
    int i;
    char *buffer;
    i = 0;
    buffer = (char*)malloc(MAX_SIZE);
    if (buffer != NULL) {
        buffer[0] = '\0';
        free(buffer);
    }
}



void ListBoxCreation(HWND hWnd, HINSTANCE hInst) {
    HWND MakeListBox = CreateListBox(hWnd, hInst, 30, 75, 200, 200, 1506, LBS_STANDARD);

    SendMessage(MakeListBox, LB_INSERTSTRING, 0, (LPARAM)L"○ Moodle");
    SendMessage(MakeListBox, LB_INSERTSTRING, 1, (LPARAM)L"○ Skema");
    SendMessage(MakeListBox, LB_INSERTSTRING, 2, (LPARAM)L"○ Office");
    SendMessage(MakeListBox, LB_INSERTSTRING, 3, (LPARAM)L"○ Outlook");
    SendMessage(MakeListBox, LB_INSERTSTRING, 4, (LPARAM)L"○ Gmail");
    SendMessage(MakeListBox, LB_INSERTSTRING, 5, (LPARAM)L"○ Word");
    SendMessage(MakeListBox, LB_INSERTSTRING, 6, (LPARAM)L"○ OneNote");
    SendMessage(MakeListBox, LB_INSERTSTRING, 7, (LPARAM)L"○ Excel");
    SendMessage(MakeListBox, LB_INSERTSTRING, 8, (LPARAM)L"○ Forms");
    SendMessage(MakeListBox, LB_INSERTSTRING, 9, (LPARAM)L"○ OneDrive");
    SendMessage(MakeListBox, LB_INSERTSTRING, 10, (LPARAM)L"○ Zoom");
    SendMessage(MakeListBox, LB_INSERTSTRING, 11, (LPARAM)L"○ Adobe");
    SendMessage(MakeListBox, LB_INSERTSTRING, 12, (LPARAM)L"○ Wiseflow");
    SendMessage(MakeListBox, LB_INSERTSTRING, 13, (LPARAM)L"○ Polyteknisk - Books");
    SendMessage(MakeListBox, LB_INSERTSTRING, 14, (LPARAM)L"○ Conzoom");
    SendMessage(MakeListBox, LB_INSERTSTRING, 15, (LPARAM)L"○ DinGeo");
    SendMessage(MakeListBox, LB_INSERTSTRING, 16, (LPARAM)L"○ Canva");
    SendMessage(MakeListBox, LB_INSERTSTRING, 17, (LPARAM)L"○ Validator - HTML");
    SendMessage(MakeListBox, LB_INSERTSTRING, 18, (LPARAM)L"○ References - HTML");
    SendMessage(MakeListBox, LB_INSERTSTRING, 19, (LPARAM)L"○ MDN Web");
    SendMessage(MakeListBox, LB_INSERTSTRING, 20, (LPARAM)L"○ Studiekort");
    SendMessage(MakeListBox, LB_INSERTSTRING, 21, (LPARAM)L"○ Studieordning");
    SendMessage(MakeListBox, LB_INSERTSTRING, 22, (LPARAM)L"○ UMS");
    SendMessage(MakeListBox, LB_INSERTSTRING, 23, (LPARAM)L"○ Studievejledning");
    SendMessage(MakeListBox, LB_INSERTSTRING, 24, (LPARAM)L"○ SPS");
    SendMessage(MakeListBox, LB_INSERTSTRING, 25, (LPARAM)L"○ Google Translate");
    SendMessage(MakeListBox, LB_INSERTSTRING, 26, (LPARAM)L"○ UddannelsesGuiden");
    SendMessage(MakeListBox, LB_INSERTSTRING, 27, (LPARAM)L"○ Rejseplanen");
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
                wchar_t Infomessage[150];
                swprintf(Infomessage, 150, L"Application: Tool Kit - Zealand Edition\nVersion: %.1f\nDeveloper: Andreas\nContact: anm013@edu.zealand.dk", Version);
                MessageBox(hWnd, Infomessage, L"Information", MB_OK);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            
            // Buttons (Click)
            case 1001: // YouTube 
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.youtube.com");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open YouTube?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1002: // Facebook
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.facebook.com");
                if (QuestionSetting == 1) { 
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open Facebook?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }          
                break;
            }
            case 1003: // Facebook Zealand
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.facebook.com/groups/285964078723998");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open Facebook - Zealand?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0)
                {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }                
                break;
            }
            case 1004: // Messenger
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.messenger.com");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open Messenger?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1005: // Messenger - Zealand
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.messenger.com/t/8608842255814419/");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open Messenger - Zealand?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1006: // Instagram
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.instagram.com");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open Instagram?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1007: // LinkdIn
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.linkedin.com/learning");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open LinkdIn?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1008: // Twitch
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.twitch.tv");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open Twitch?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1009: // Snapchat
            {
                wchar_t url[1024];
                wsprintf(url, L"https://web.snapchat.com");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open Snapchat?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1010: // TikTok
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.tiktok.com");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open TikTok?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1011: // Reddit
            {
                wchar_t url[1024];
                wsprintf(url, L"https://www.reddit.com");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open Reddit?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1012: // Twitter
            {
                wchar_t url[1024];
                wsprintf(url, L"https://x.com");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to open Twitter (X)?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            case 1504:
            {
                HWND ToggleAlwaysOnTopButton = GetDlgItem(hWnd, 1504);
                HWND hwnd = GetForegroundWindow();
                if (ToggleAlwaysOnTopButton) {
                    int state = SendMessage(ToggleAlwaysOnTopButton, BM_GETCHECK, 0, 0);
                    if (state == BST_CHECKED) {  
                        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
                    }
                    else if (state == BST_UNCHECKED){
                        SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
                    }
                }
                ClearMemory();
                break;
            }
            case 1505:
            {
                wchar_t url[1024];
                wsprintf(url, L"");
                if (QuestionSetting == 1) {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to report a bug?", L"Bug Report", MB_YESNO | MB_ICONERROR);
                    if (msgboxID == IDYES) {
                        ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                    }
                }
                else if (QuestionSetting == 0) {
                    ShellExecute(0, L"open", url, 0, 0, SW_SHOW);
                }
                break;
            }
            // ListBox - Interaction
            case 1506:
            {
                if (HIWORD(wParam) == LBN_DBLCLK) {
                    int selIndex = SendMessage((HWND)lParam, LB_GETCURSEL, 0, 0);
                    if (selIndex != LB_ERR) {
                        wchar_t ItemText[256];
                        SendMessage((HWND)lParam, LB_GETTEXT, selIndex, (LPARAM)ItemText);
                        BoxSelection(hWnd, ItemText);
                    }
                }
                break;
            }

            case 1507:
            {
                HWND ToggleShowImportantButton = GetDlgItem(hWnd, 1507);
                if (ToggleShowImportantButton) {
                    int state = SendMessage(ToggleShowImportantButton, BM_GETCHECK, 0, 0);
                    if (state == BST_CHECKED) {

                    }
                }
                ClearMemory();
                break;
            }
            case 1508: // Update
            {

            }
            case 1510:
            {
                if (GetWindowTextLength(GetDlgItem(hWnd, 1509)) > 0) {
                    
                    if (QuestionSetting == 1) {
                        int msgboxID = MessageBox(hWnd, L"Do you wish to CLEAR the notebox?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                        if (msgboxID == IDYES) {
                            SendMessage(GetDlgItem(hWnd, 1509), WM_SETTEXT, 0, (LPARAM)L"");
                        }
                    }
                    else if (QuestionSetting == 0) {
                        SendMessage(GetDlgItem(hWnd, 1509), WM_SETTEXT, 0, (LPARAM)L"");                    
                    }               
                }          
                break;
            }
            case 1511:
            {
                if (QuestionSetting == 1)
                {
                    int msgboxID = MessageBox(hWnd, L"Do you wish to SAVE the notebox?", L"Notification", MB_YESNO | MB_ICONQUESTION);
                    if (msgboxID == IDYES) {
                        SaveNoteboxContent(hWnd);
                    }
                }
                else if (QuestionSetting == 0) {
                    SaveNoteboxContent(hWnd);
                }                
                break;
            }
            case 1514: 
            {
                CHOOSECOLOR cc;
                COLORREF acrCustClr[16];
                ZeroMemory(&cc, sizeof(cc));
                cc.lStructSize = sizeof(cc);
                cc.hwndOwner = hWnd;
                cc.lpCustColors = (LPDWORD)acrCustClr;
                cc.rgbResult = RGB(0, 0, 0);
                cc.Flags = CC_FULLOPEN | CC_RGBINIT;
                if (ChooseColor(&cc)) {
                    CHARFORMAT2 cf;
                    ZeroMemory(&cf, sizeof(cf));
                    cf.cbSize = sizeof(CHARFORMAT2);
                    cf.dwMask = CFM_COLOR;
                    cf.crTextColor = cc.rgbResult;
                    SendMessage(GetDlgItem(hWnd, 1509), EM_SETCHARFORMAT, SCF_ALL, (LPARAM)&cf);
                }
                break;
            }

            // Check Box - (Question Pop Up)
            case 1503:
            {
                HWND ToggleQuestionButton = GetDlgItem(hWnd, 1503);
                if (ToggleQuestionButton) {
                    int state = SendMessage(ToggleQuestionButton, BM_GETCHECK, 0, 0);
                    if (state == BST_CHECKED) {
                        QuestionSetting = 1;
                    }
                    else if (state == BST_UNCHECKED) {
                        QuestionSetting = 0;
                    }
                    
                    break;
                }
            }
            // Internet Search - Button
            case 1501:
            {
                PerformSearch(hWnd);
                ClearMemory();
                break;
            }
               default:
               return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HPEN PenBlack;
            HPEN PenOld;
            HDC hdc = BeginPaint(hWnd, &ps);

            //Create Black Color
            PenBlack = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
            PenOld = (HPEN)SelectObject(hdc, PenBlack);

            //Line
            MoveToEx(hdc, 0, 30, NULL);
            LineTo(hdc, 400, 30);

            // Left Side (Title)
            MoveToEx(hdc, 29, 9, NULL);
            LineTo(hdc, 29, 48);

            //Right Side (Title)
            MoveToEx(hdc, 156, 10, NULL);
            LineTo(hdc, 156, 48);

            //Bottom Side (Title)
            MoveToEx(hdc, 29, 10, NULL);
            LineTo(hdc, 156, 10);

            //Top Side (Title)
            MoveToEx(hdc, 29, 48, NULL);
            LineTo(hdc, 156, 48);

            //Website (Top)
            MoveToEx(hdc, 29, 58, NULL);
            LineTo(hdc, 131, 58);

            //Website Side (Right)
            MoveToEx(hdc, 29, 57, NULL);
            LineTo(hdc, 29, 76);

            //Website Side (Left)
            MoveToEx(hdc, 131, 57, NULL);
            LineTo(hdc, 131, 76);


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_CREATE:
    {
        
        //Brightness
        HWND CreateThemeSlider = CreateSliderFunction(hWnd, hInst, 150, 373, 210, 20, 1508, 1, 10, 5);
        SendMessage(CreateThemeSlider, TBM_SETPOS, TRUE, 5);

        break;
    }
    case WM_HSCROLL:
    {
        HWND hThemeSlider = (HWND)lParam;
        //Get Slider position
        if (hThemeSlider != NULL && LOWORD(wParam) == TB_ENDTRACK) {
            int ThemeSliderPos = SendMessage(hThemeSlider, TBM_GETPOS, 0, 0);
            if (ThemeSliderPos == 1) {
                g_sliderValue = 26;
            }
            if (ThemeSliderPos == 2) {
                g_sliderValue = 52;
            }
            if (ThemeSliderPos == 3) {
                g_sliderValue = 78;
            }
            if (ThemeSliderPos == 4) {
                g_sliderValue = 104;
            }
            if (ThemeSliderPos == 5) {
                g_sliderValue = 130;
            }
            if (ThemeSliderPos == 6) {
                g_sliderValue = 156;
            }
            if (ThemeSliderPos == 7) {
                g_sliderValue = 182;
            }
            if (ThemeSliderPos == 8) {
                g_sliderValue = 208;
            }
            if (ThemeSliderPos == 9) {
                g_sliderValue = 234;
            }
            if (ThemeSliderPos == 10) {
                g_sliderValue = 255;
            }
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    }
    case WM_ERASEBKGND:
    {
        HDC hdc = (HDC)wParam;
        //Slider value controls (Red, Green & Blue) at the same time - which makes black and white
        int colorValue = g_sliderValue;
        HBRUSH hBrush = CreateSolidBrush(RGB(colorValue, colorValue, colorValue));
        //Fill the background
        RECT rect;
        GetClientRect(hWnd, &rect);
        FillRect(hdc, &rect, hBrush);
        //Remove brush and return af complete
        DeleteObject(hBrush);
        return 1;

    }
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


