/*
void CreateTabs(HWND hWnd, HINSTANCE hInst) {
    // Create the Tab Control
    hTab = CreateWindowW(WC_TABCONTROL, L"Test", WS_CHILD | WS_VISIBLE,
        400, 50, 250, 150, hWnd, (HMENU)5000, hInst, NULL);

    // Initialize Tab Data
    TCITEM tie;
    tie.mask = TCIF_TEXT;

    // Add Tab 1
    LPWSTR tabText1 = (LPWSTR)L"Tab 1";
    tie.pszText = tabText1;
    TabCtrl_InsertItem(hTab, 0, &tie);

    // Add Tab 2
    LPWSTR tabText2 = (LPWSTR)L"Tab 2";
    tie.pszText = tabText2;
    TabCtrl_InsertItem(hTab, 1, &tie);

    //Add Tab 3
    LPWSTR tabText3 = (LPWSTR)L"Tab 3";
    tie.pszText = tabText3;
    TabCtrl_InsertItem(hTab, 2, &tie);

    // Add Tab 4
    LPWSTR tabText4 = (LPWSTR)L"Tab 4";
    tie.pszText = tabText4;
    TabCtrl_InsertItem(hTab, 3, &tie);

    // Add Tab 5
    LPWSTR tabText5 = (LPWSTR)L"Tab 5";
    tie.pszText = tabText5;
    TabCtrl_InsertItem(hTab, 4, &tie);
}

*/

/*void AdjustVolume(int value) {
	DWORD volumeLeft, volumeRight;
	waveOutGetVolume(0, &volumeLeft);
	volumeRight = (volumeLeft >> 16) & 0xFFFF;
	if (value) {
		volumeLeft += 0x0100;
		volumeRight += 0x0100;
	}
	else {
		volumeLeft -= 0x0100;
		volumeRight -= 0x0100;
	}
	if (volumeLeft > 0xFFFF) volumeLeft = 0xFFFF;
	if (volumeRight > 0xFFFF) volumeRight = 0xFFFF;
	DWORD newVolume = (volumeRight << 16) | volumeLeft;
	waveOutSetVolume(0, waveOutGetVolume(0, 0) + 1);
}*/