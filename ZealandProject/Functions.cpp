#include "ZealandProject.h"
#include "framework.h"
#include <shellapi.h>
#include <windows.h>
#include <commctrl.h>
#include <wchar.h>
#include <mmsystem.h>
#include <fstream>
#include <Richedit.h>
#include <commdlg.h>

HWND CreateButton(
	HWND parent,
	HINSTANCE hInst,
	int x,
	int y,
	int width,
	int height,
	LPCWSTR text,
	int id,
	DWORD style
) {
	return CreateWindowW(
		L"BUTTON",
		text,
		style,
		x,
		y,
		width,
		height,
		parent,
		(HMENU)id,
		hInst,
		NULL
	);
}


HWND CreateText(
	HWND parent,
	HINSTANCE hInst,
	int x,
	int y,
	int width,
	int height,
	LPCWSTR text,
	DWORD style
	)	{
	return CreateWindowW(
		L"STATIC",
		text,
		style,
		x,
		y,
		width,
		height,
		parent,
		NULL,
		hInst,
		NULL
	);
}

HWND CreateToggleButton(
	HWND parent,
	HINSTANCE hInst,
	int x,
	int y,
	int width,
	int height,
	LPCWSTR text,
	int id,
	DWORD style
) {
	return CreateWindowW(
		L"BUTTON",
		text,
		style,
		x,
		y,
		width,
		height, 
		parent, 
		(HMENU)id,
		hInst,
		NULL
	);
}


HWND CreateListBox(
	HWND parent,
	HINSTANCE hInst,
	int x,
	int y,
	int width,
	int height,
	int id,
	DWORD dwStyle
) {
	return CreateWindowW(
		L"LISTBOX",
		NULL,
dwStyle | WS_CHILD | WS_VISIBLE,
x,
y,
width,
height,
parent,
(HMENU)id,
hInst,
NULL
);
}


HWND CreateSliderFunction(
	HWND parent,
	HINSTANCE hInst,
	int x,
	int y,
	int width,
	int height,
	int id,
	int minRange,
	int maxRange,
	int initialPos
) {
	InitCommonControls();
	HWND hSlider = CreateWindowEx(
		0, TRACKBAR_CLASS, L"",
		WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS,
		x, y, width, height,
		parent, (HMENU)id, hInst, NULL
	);
	// Configure the max and min range for the slider
	SendMessage(hSlider, TBM_SETRANGE, TRUE, MAKELONG(minRange, maxRange));
	// Set the initial value for the slider
	SendMessage(hSlider, TBM_SETPOS, TRUE, initialPos);
	// Configure the number of ticks on the slider
	SendMessage(hSlider, TBM_SETTICFREQ, (maxRange - minRange) / 10, 0);

	return hSlider;
}


void SetFontSize(HWND hWnd, int size) {
	HFONT Font = CreateFont(
		size,
		0,
		0,
		0,
		FW_BOLD,
		FALSE,
		FALSE,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		NULL
	);
	SendMessage(hWnd, WM_SETFONT, (WPARAM)Font, TRUE);
}


void PerformSearch(HWND hWnd) {
	wchar_t buffer[256];
	wchar_t url[1024];
	// Getting input from the text box
	if (GetWindowText(GetDlgItem(hWnd, 1502), buffer, 256) > 0) {
		//Constructing the URL with Google
		wsprintfW(url, L"https://www.google.com/search?q=%s", buffer);
		if (QuestionSetting == 1) {
			wchar_t message[512];
			wsprintfW(message, L"Would you like to search for: %s?", buffer);
			int msgboxID = MessageBoxW(hWnd, message, L"Search Confirmation", MB_YESNO | MB_ICONQUESTION);
			if (msgboxID == IDYES) {
				ShellExecuteW(0, L"open", url, 0, 0, SW_SHOW);
				SetWindowText(GetDlgItem(hWnd, 1502), L"");
			}
			else if (msgboxID == IDNO) {
				SetWindowText(GetDlgItem(hWnd, 1502), L"");
			}
		}
		else if (QuestionSetting == 0) {
			ShellExecuteW(0, L"open", url, 0, 0, SW_SHOW);
			SetWindowText(GetDlgItem(hWnd, 1502), L"");
		}
	}
}


void SaveNoteboxContent(HWND hWnd) {
	int length = GetWindowTextLength(GetDlgItem(hWnd, 1509));
	//Check if the length is over 0
	if (length > 0) {
		wchar_t* buffer = new wchar_t[length + 1];
		// Get text from the notebox
		GetWindowText(GetDlgItem(hWnd, 1509), buffer, length + 1);
		//Spaces - Check
		


		//Name of the saved notes (Saved Notebox)
		std::wofstream file(L"Saved Notebox.txt");
		// Opens the txt file and write
		if (file.is_open()) {
			file << buffer;
			file.close();
			if (file) {
				MessageBox(hWnd, L"Your notebox was saved successfully - check the current destination of the program.", L"Notebox Saved", MB_OK | MB_ICONINFORMATION);
				SendMessage(GetDlgItem(hWnd, 1509), WM_SETTEXT, 0, (LPARAM)L"");
			}
		}
		else if (!file) {
			MessageBox(hWnd, L"Something went wrong, please make sure the notebox has text and try again!", L"ERROR", MB_OK | MB_ICONERROR);
		}
		
		delete[] buffer;

	}
	else {
		MessageBox(hWnd, L"Your notebox is empty and cannot be saved!", L"Information", MB_OK | MB_ICONINFORMATION);
	}
}


typedef struct {
	LPCWSTR itemName;
	LPCWSTR url;
} ListItem;

ListItem ListItems[NUM_ITEMS_BOX] = {
	{ L"○ Moodle", L"https://moodle.zealand.dk/my/"},
	{ L"○ Skema", L"https://cloud.timeedit.net/zealand/web/3/ri1Y725QQ75Zc0Q39757ZpQ9.html" },
	{ L"○ Office", L"https://www.office.com" },
	{ L"○ Outlook", L"https://outlook.office.com/mail/" },
	{ L"○ Word", L"https://www.office.com/launch/Word/" },
	{ L"○ OneNote", L"https://www.office.com/launch/OneNote/" },
	{ L"○ Excel", L"https://www.office.com/launch/Excel/" },
	{ L"○ Forms", L"https://forms.office.com/Pages/DesignPageV2.aspx?origin=shell&subpage=creationv2" },
	{ L"○ OneDrive", L"https://www.office.com/onedrive" },
	{ L"○ Zoom", L"https://zealand.zoom.us" },
	{ L"○ Adobe", L"https://www.adobe.com/dk/creativecloud.html?mv=search&mv=search&mv2=paidsearch&sdid=D4P81NYZ&ef_id=Cj0KCQjw9Km3BhDjARIsAGUb4nzufZ-cRsL_5B8Fz_3wBINq1nCIP_DyEc92KYcwwxFKsjc8PPGK2KAaApcuEALw_wcB:G:s&s_kwcid=AL!3085!3!281107192278!e!!g!!adobe!1470417004!57319424579&gad_source=1&gclid=Cj0KCQjw9Km3BhDjARIsAGUb4nzufZ-cRsL_5B8Fz_3wBINq1nCIP_DyEc92KYcwwxFKsjc8PPGK2KAaApcuEALw_wcB"},
	{ L"○ Wiseflow", L"https://europe.wiseflow.net/participant/" },
	{ L"○ Conzoom", L"https://www.conzoom.dk/da/danmark/segmenter" },
	{ L"○ DinGeo", L"https://www.dingeo.dk" },
	{ L"○ Canva", L"https://www.canva.com" },
	{ L"○ Validator - HTML", L"https://validator.w3.org" },
	{ L"○ References - HTML", L"https://www.w3schools.com/tags/default.asp" },
	{ L"○ MDN Web", L"https://developer.mozilla.org/en-US/docs/Web" },
	{ L"○ Studiekort", L"https://kort.zea.dk" },
	{ L"○ Studieordning", L"https://www.zealand.dk/wp-content/uploads/2016/09/Multimediedesign-samlet-studieordning-2024.pdf" },
	{ L"○ UMS", L"https://ums.zea.dk/loggedin/default.aspx" },
	{ L"○ Studievejledning", L"https://moodle.zealand.dk/course/view.php?id=4590" },
	{ L"○ SPS", L"https://moodle.zealand.dk/course/view.php?id=4517" },
	{ L"○ Google Translate", L"https://translate.google.com/?sl=auto&tl=da&op=translate" },
	{ L"○ UddannelsesGuiden", L"https://www.ug.dk" },
	{ L"○ Rejseplanen", L"https://rejseplanen.dk" },
	{ L"○ Polyteknisk - Books", L"https://polyteknisk.vitalsource.com/home/my-library?context=login" },
	{ L"○ Gmail", L"https://mail.google.com/mail" }
};

void BoxSelection(HWND hWnd, LPCWSTR ItemText) {
	for (int i = 0; i < NUM_ITEMS_BOX; i++) {
		if (wcscmp(ItemText, ListItems[i].itemName) == 0) {
			ShellExecute(hWnd, L"open", ListItems[i].url, NULL, NULL, SW_SHOW);
			return;
		}
	}
}
