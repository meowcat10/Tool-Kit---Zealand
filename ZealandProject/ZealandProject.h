#include "resource.h"
#include <windows.h>

//Settings Value
// Theme Button : 1500
// Search Button : 1501
// Fast Search (Input) : 1502
// Question - Pop Up : 1503
// Always On Top : 1504
// Report a bug : 1505
// ListBox : 1506
// Show Important : 1507
// Check for updates : 1508

// NoteBox : 1509
// Clear Notebox : 1510
// Save Notebox : 1511
// Open Last Saved : 1512

// Dialog : 1513
//Color Button : 1514

//


//Other Value
// YouTube : 1001
// Facebook : 1002
// Facebook Zealand : 1003
// Messenger : 1004
// Messenger Zealand : 1005
// Instagram : 1006
// LinkdIn : 1007
// Twitch : 1008
// Snapchat : 1009
// TikTok : 1010
// Reddit : 1011
// Twitter : 1012


extern float Version;
extern int QuestionSetting;
extern int g_sliderValue;


// Button Creation

HWND CreateButton(
	HWND parent,
	HINSTANCE hInst,
	int x,
	int y,
	int width,
	int height,
	LPCWSTR text,
	int id,
	DWORD style = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON
);


HWND CreateToggleButton(
	HWND parent,        
	HINSTANCE hInst,    
	int x,              
	int y,              
	int width,          
	int height,         
	LPCWSTR text,       
	int id,             
	DWORD style = WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX
);

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
);


// Text Creation
HWND CreateText(
	HWND parent,
	HINSTANCE hInst,
	int x,
	int y,
	int width,
	int height,
	LPCWSTR text,
	DWORD style = WS_VISIBLE | WS_CHILD
);

HWND CreateListBox(
	HWND parent,
	HINSTANCE hInst,
	int x,
	int y,
	int width,
	int height,
	int id,
	DWORD dwStyle
);



//void CreateTabs(HWND hWnd, HINSTANCE hInst);
void SetFontSize(HWND hWnd, int amount);
void ListBoxCreation(HWND hWnd, HINSTANCE hInst);


void PerformSearch(HWND hWnd);

void ClearMemory();


// Amount of references under listbox
#define NUM_ITEMS_BOX 32
void BoxSelection(HWND hWnd, LPCWSTR ItemText);


// Note related
bool FindLastNote(LPCWSTR filename);
void SaveNoteboxContent(HWND Notebox);
void LoadSavedTextFile(HWND hWnd);