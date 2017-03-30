/*
	�}�X�^�[�T���v��
*/

#include <windows.h>
#include <stdio.h>		// --- �R���\�[���p

#include "WndProc.h"	// --- �E�B���h�E�v���V�[�W��
#include "Common.h"		// --- �S�t�@�C���ł̋��ʃw�b�_�[

// --- �G���g���|�C���g
int WINAPI WinMain( HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow )
{
	WNDCLASSEX	wc;		// --- �E�B���h�E�N���X�\����
	HWND		hWnd;	// --- �E�B���h�E�n���h��
	BOOL		bRet;	// --- GetMessage() �̖߂�l
	MSG			msg;	// --- MSG�\����
	RECT		rc;		// --- �N���C�A���g�̈�T�C�Y�ݒ�p

	// --- �C���X�^���X�n���h�����O���[�o���ϐ��ɃR�s�[
	g_hInstance = hCurInst;

	// --- �N���C�A���g�̈�̃T�C�Y�ݒ�
	rc.left		= 0;
	rc.right	= WINDOW_W;
	rc.top		= 0;
	rc.bottom	= WINDOW_H;
	AdjustWindowRect( &rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE );

	// --- �E�B���h�E�N���X�̒�`�i�E�B���h�E�N���X�\���̂̏������j
	wc.cbSize			= sizeof( WNDCLASSEX );				// --- ���̍\���̂̃T�C�Y
	wc.style			= ( CS_HREDRAW | CS_VREDRAW );		// --- �E�C���h�E�̃X�^�C��
	wc.lpfnWndProc		= ( WNDPROC )WndProc;				// --- ���b�Z�[�W�����֐��̓o�^
	wc.cbClsExtra		= 0;								// --- �ʏ�͎g��Ȃ��̂ŏ��0
	wc.cbWndExtra		= 0;								// --- �ʏ�͎g��Ȃ��̂ŏ��0
	wc.hInstance		= g_hInstance;						// --- �C���X�^���X�ւ̃n���h��
	wc.hIcon			= NULL;								// --- �A�C�R���i�Ȃ��j
	wc.hIconSm			= NULL;								// --- ���A�C�R���i�Ȃ��j
	wc.hCursor			= LoadCursor( NULL, IDC_ARROW );	// --- �J�[�\���̌`
	wc.hbrBackground	= ( HBRUSH )( COLOR_WINDOW + 1 );	// --- �w�i�Ȃ�
	wc.lpszMenuName		= NULL;								// --- ���j���[�Ȃ�
	wc.lpszClassName	= g_szWndClass;						// --- �N���X���̎w��

	// --- �E�B���h�E�N���X�̓o�^
	if( RegisterClassEx( &wc ) == 0 ) { return ( false ); }	// --- �o�^���s 

	// --- �E�B���h�E�̍쐬
	hWnd = CreateWindow
	(
		g_szWndClass,								// �E�B���h�E�N���X��
		g_szAppTitle,								// �^�C�g��
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,	// �E�B���h�E�X�^�C��
		CW_USEDEFAULT,								// �����ʒu
		CW_USEDEFAULT,								// �����ʒu
		rc.right - rc.left,							// ��
		rc.bottom - rc.top,							// ����
		NULL,
		NULL,
		g_hInstance,
		NULL
	);

	if ( !hWnd ) return FALSE;

	// �E�B���h�E�̕\��
	ShowWindow( hWnd, nCmdShow );
	UpdateWindow( hWnd );

	// ���b�Z�[�W���[�v
	while( ( bRet = GetMessage( &msg, NULL, 0, 0 ) ) != 0 )
	{
		if ( bRet == -1 ) 
		{
			// WM_TIMER ���g��Ȃ��ꍇ������FPS�𑪂�A�Q�[������������
			break;
		}
		else 
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
	}

	// --- WinMain() �̖߂�l
	return ( ( int )msg.wParam );
}


















