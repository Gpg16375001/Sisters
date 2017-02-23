
#include "WinMain.h"
#include "ConsoleWindow.h"

/*/
/*	�R���X�g���N�^
/*/
WinMain::WinMain( TCHAR* arg_szClassName , TCHAR* arg_szTitleName )
	: wPos_x_	( 32 )
	, wPos_y_	( 32 )
	, wSize_w_	( 800 )
	, wSize_h_	( 600 )
	, hWnd_		( NULL )
	, bitmap_	( NULL )
	, hDCBack_	( NULL )
{
	// ���Ԃ̐��x���グ��
	timeBeginPeriod( 1 ) ;

	//	�E�B���h�E�N���X���ƃE�B���h�E�^�C�g��������	
	lstrcpy( szClassName_ , arg_szClassName ) ;
	lstrcpy( szTitleName_ , arg_szTitleName ) ;

	// �C���X�^���X���󂯎��
	hInst_ = GetModuleHandle( NULL ) ;								// NULL ���w�肷��ƁA�Ăяo�����v���Z�X�̍쐬�Ɏg��ꂽ�t�@�C���̃n���h�����Ԃ�@( https://msdn.microsoft.com/ja-jp/library/cc429129.aspx )

	/* ____ �E�B���h�E�N���X�\���̂̒�` ____ */
	wc_.cbSize = sizeof( WNDCLASSEX ) ;
	wc_.style = ( CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS ) ;
	wc_.lpfnWndProc = ( WNDPROC ) WndProc_ ;						// �ÓI�����o�֐��� WndProc_( ) ��n��	( ��ɓ��I�ȕ������� )
	wc_.cbClsExtra = 0 ;
	wc_.cbWndExtra = 0 ;
	wc_.hInstance = hInst_ ;
	wc_.hIcon = LoadIcon( NULL , IDI_APPLICATION ) ;
	wc_.hCursor = LoadCursor( NULL , IDC_ARROW ) ;
	wc_.hbrBackground = ( HBRUSH )( COLOR_WINDOW + 1 ) ;			// �o�b�N�h���b�v�̐F
	wc_.lpszMenuName = NULL ;
	wc_.lpszClassName = szClassName_ ;								// �E�B���h�E�N���X�̖��O
	wc_.hIconSm = LoadIcon( NULL , IDI_APPLICATION ) ;

}

/*/
/*	�f�X�g���N�^
/*/
WinMain::~WinMain( )
{
	// ����ʂŎg�������̂�����
	if ( bitmap_ != NULL )
	{
		DeleteObject( bitmap_ ) ;
	}

	if ( hDCBack_ != NULL )
	{
		DeleteDC( hDCBack_ ) ;
	}

	// ���Ԃ̐��x��߂�
	timeEndPeriod( 1 ) ;

}

/*/
/*	�E�B���h�E�̍��W�ύX
/*/
void WinMain::SetWindowPos( int arg_x , int arg_y )
{
	wPos_x_ = arg_x ;
	wPos_y_ = arg_y ;
	if ( hWnd_ != NULL )
	{
		// �E�B���h�E�̈ʒu�̕ύX
		MoveWindow( hWnd_ , wPos_x_ , wPos_y_ , wSize_w_ , wSize_h_ , TRUE ) ;
	}
}

/*/
/*	�E�B���h�E�̃T�C�Y�ύX
/*/
void WinMain::SetWindowSize( int arg_w , int arg_h )
{
	wSize_w_ = arg_w ;
	wSize_h_ = arg_h ;
	if ( hWnd_ != NULL )
	{
		// �N���C�A���g�T�C�Y�����炤 ( SIZE�^�ŋA���Ă��� )
		SIZE size = GetClientSize_( wSize_w_, wSize_h_ ) ;
		MoveWindow( hWnd_ , wPos_x_ , wPos_y_ , size.cx , size.cy , TRUE ) ;
	}
}

/*/
/*	�J�n
/*/
bool WinMain::Start( )
{
	// �E�B���h�E�N���X�o�^
	RegisterClassEx ( &wc_ ) ;

	// �E�B���h�E�̍쐬
	SIZE size = GetClientSize_( wSize_w_ , wSize_h_ ) ;
	hWnd_ = CreateWindow(
		szClassName_ ,												// �E�B���h�E�N���X��
		szTitleName_ ,												// �L���v�V����������
		( WS_OVERLAPPEDWINDOW ) ,									// �E�B���h�E�X�^�C��
		wPos_x_ ,													// �������W�̈ʒu
		wPos_y_ ,													// �������W�̈ʒu
		size.cx ,													// ��
		size.cy ,													// ����
		NULL ,														// �e�E�B���h�E
		NULL ,														// �E�B���h�E���j���[
		hInst_ ,													// �C���X�^���X�n���h��
		this ) ;													// WM_CREATE�֏���n�� ( ���g�̃n���h���𑗂� )
	printf( "�E�B���h�E�쐬����!\n" ) ;

	if ( hWnd_ == NULL )
	{
		return( FALSE ) ;
	}

	/* ____ �E�B���h�E��\�� ____ */
	ShowWindow ( hWnd_ , SW_SHOWNORMAL ) ;
	UpdateWindow ( hWnd_ ) ;
	
	// ���Ԃ̏�����
	old_time_ = timeGetTime( ) ;
	start_time_ = old_time_ ;

	// ����ʐ���
	HDC hDC = GetDC( hWnd_ ) ;
	hDCBack_ = CreateCompatibleDC( hDC ) ;
	bitmap_ = CreateCompatibleBitmap( hDC , wSize_w_ , wSize_h_ ) ;
	SelectObject( hDCBack_ , bitmap_ ) ;							// �f�X�g���N�^�ŉ�������
	ReleaseDC( hWnd_ , hDC ) ;

	// �������̌Ăяo�� ( �摜��T�E���h�Z�b�g�Ȃ� )
	Initalize( ) ;

	/* ____ ���b�Z�[�W�`�F�b�N���[�v ____ */
	while ( true )
	{
		MSG	msg ;												// ���b�Z�[�W�\����
		if ( PeekMessage( &msg , 0 , 0 , 0 , PM_REMOVE ) )
		{
			if ( msg.message == WM_QUIT )
			{
				break ;
			}
			TranslateMessage ( &msg ) ;
			DispatchMessage ( &msg ) ;

		} else {
			// �p����̃��C�����[�v�̌Ăяo��
			Update( ) ;

			// �ĕ`��Ăяo��
			InvalidateRect( hWnd_ , NULL , FALSE ) ;

		}
	}

	// �I�����̌Ăяo��
	Finalize( ) ;

	return( true ) ;

}

/*/
/*	�E�B���h�v���V�[�W���[
/*/
LRESULT CALLBACK WinMain::WndProc_( HWND arg_hWnd , UINT arg_msg , UINT arg_wParam , LONG arg_lParam )
{
	WinMain* winm = reinterpret_cast<WinMain*>( GetWindowLong(arg_hWnd , GWL_USERDATA) ) ;
	switch ( arg_msg ) {

		// WinMain���N���X�����邽�߂Ɋi�[�����C���X�^���X�n���h����GWL_USERDATA��������o���Ă���
		case WM_CREATE :
			LPCREATESTRUCT data ;
			data = reinterpret_cast<LPCREATESTRUCT>( arg_lParam ) ;
			winm = reinterpret_cast<WinMain*>( data->lpCreateParams ) ;
			SetWindowLong( arg_hWnd , GWL_USERDATA , reinterpret_cast<long>(winm) ) ;
			break;

		case WM_DESTROY :
			PostQuitMessage( 0 ) ;
			return 0;

		case WM_PAINT :
			if ( winm != nullptr )
			{
				// �`����s��
				winm->Draw_( ) ;
			}
			break;

	}

	// �������疽�߂���������
	if ( winm != nullptr )
	{
		return winm->WndProc( arg_hWnd , arg_msg , arg_wParam , arg_lParam ) ;
	}
	// �����Ȃ��������@����������ɂ��
	return( DefWindowProc(arg_hWnd , arg_msg , arg_wParam , arg_lParam) ) ;

}

/*/
/*	�N���C�A���g�T�C�Y�̎擾
/*/
SIZE WinMain::GetClientSize_( int arg_w , int arg_h )
{
	RECT		rc ;												// �N���C�A���g�̈�T�C�Y�ݒ�p

	/* ___ �N���C�A���g�̈�̃T�C�Y�ݒ� ___ */
	rc.left		= 0 ;
	rc.right	= arg_w ;
	rc.top		= 0 ;
	rc.bottom	= arg_h ;
	AdjustWindowRect( &rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE ) ;

	SIZE size = {
		rc.right - rc.left ,
		rc.bottom - rc.top ,
	} ;

	return( size ) ;
}

/*/
/*	�`�揈��
/*/
void WinMain::Draw_( )
{
	printf( "<- Draw ! ->\n" ) ;

	PAINTSTRUCT ps ;
	HDC hDC = BeginPaint( hWnd_ , &ps ) ;

	//printf( "WM_PAINT�C�x���g�����s����܂���\n" );
	BitBlt( hDC , 0 , 0 , wSize_w_ , wSize_h_ , hDCBack_ , 0 , 0 , SRCCOPY ) ;

	EndPaint( hWnd_ , &ps );

}


