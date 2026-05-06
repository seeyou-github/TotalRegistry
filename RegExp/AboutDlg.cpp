#include "pch.h"
#include "resource.h"
#include "AboutDlg.h"
#include "VersionResourceHelper.h"

LRESULT CAboutDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/) {
	CenterWindow(GetParent());
	SetDialogIcon(IDR_MAINFRAME);

	WCHAR path[MAX_PATH];
	::GetModuleFileName(nullptr, path, _countof(path));
	VersionResourceHelper vr(path);
	auto version = vr.GetValue(L"ProductVersion");
	auto copyright = vr.GetValue(L"LegalCopyright");
	SetDlgItemText(IDC_VERSION, L"Total Registry v" + version);
	SetDlgItemText(IDC_COPYRIGHT, copyright);

	return TRUE;
}

LRESULT CAboutDlg::OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/) {
	EndDialog(wID);
	return 0;
}
