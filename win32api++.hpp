#ifndef ___WIN32APIPLUSPLUS9
#define ___WIN32APIPLUSPLUS9
#include "global.h"

#ifdef UNICODE
#define SendMessage(h,m,w,l) SendMessageW((HWND)(h), (UINT)(m), (WPARAM)(w), (LPARAM)(l))
#define SendDlgItemMessage(h,i,m,w,l) SendDlgItemMessageW((HWND)(h), (UINT)(i), (UINT)(m), (WPARAM)(w), (LPARAM)(l))
#define DialogBoxParam(t,p,f,u) DialogBoxParamW(hinstance, (LPCTSTR)(t), p, (DLGPROC)(f), (LPARAM)(u) )
#define CreateDialogParam(i,p,f,u) CreateDialogParamW(hinstance, (LPCTSTR)i, p, (DLGPROC)f, (LPARAM)u)
#define CallProc(f) SendMessageW(win, WM_RUNPROC, 0, (LPARAM)( new std::function<void()>(f) ))
#else
#define SendMessage(h,m,w,l) SendMessageA((HWND)(h), (UINT)(m), (WPARAM)(w), (LPARAM)(l))
#define SendDlgItemMessage(h,i,m,w,l) SendDlgItemMessageA((HWND)(h), (UINT)(i), (UINT)(m), (WPARAM)(w), (LPARAM)(l))
#define DialogBoxParam(t,p,f,u) DialogBoxParamA(hinstance, (LPCTSTR)(t), p, (DLGPROC)(f), (LPARAM)(u) )
#define CreateDialogParam(i,p,f,u) CreateDialogParamA(hinstance, (LPCTSTR)i, p, (DLGPROC)f, (LPARAM)u)
#define CallProc(f) SendMessageA(win, WM_RUNPROC, 0, (LPARAM)( new std::function<void()>(f) ))
#endif

#define EnableMenuItem2(m,i,t,e) EnableMenuItem(m, i, (t) | ((e)? MF_ENABLED : MF_GRAYED | MF_DISABLED))

#define CREATED_TIME 0
#define LAST_ACCESSED_TIME 1
#define LAST_MODIFIED_TIME 2

#define VKM_CTRL 512
#define VKM_SHIFT 1024
#define VKM_ALT 2048

inline void SetWindowText (HWND hwnd, const tstring& ts) { SetWindowText(hwnd, ts.c_str()); }
inline void SetDlgItemText (HWND hwnd, int i, const tstring& ts) { SetDlgItemText(hwnd, i, ts.c_str()); }
inline int GetDlgItemTextLength (HWND hwnd, int id) { return SendDlgItemMessage(hwnd, id, WM_GETTEXTLENGTH, 0, 0); }
inline void EnableDlgItem (HWND hwnd, int id, BOOL enable) { EnableWindow(GetDlgItem(hwnd,id), enable); }
inline BOOL IsDlgItemEnabled (HWND hwnd, int id) { return IsWindowEnabled(GetDlgItem(hwnd,id)); }
inline void SetDlgItemFocus (HWND hwnd, int id) { SetFocus(GetDlgItem(hwnd, id)); }

tstring export GetWindowText (HWND);
tstring export GetDlgItemText (HWND, int);

tstring export EditGetLine (HWND hEdit) ;
tstring export EditGetLine (HWND hEdit, int line, int lineindex=-1);
tstring export EditGetSelectedText (HWND hEdit);
tstring export EditGetSubstring (HWND, int, int);

inline bool IsCtrlDown () { return GetKeyState(VK_CONTROL)<0; }
inline bool IsShiftDown () { return GetKeyState(VK_SHIFT)<0; }
inline bool IsAltDown () { return GetKeyState(VK_MENU)<0; }
inline int GetCurrentModifiers () { 
return (IsCtrlDown()? VKM_CTRL:0)
| (IsShiftDown()? VKM_SHIFT:0)
| (IsAltDown()? VKM_ALT:0);
}


unsigned long long export GetFileTime (LPCTSTR, int);
unsigned long long GetCurTime ();

#endif
