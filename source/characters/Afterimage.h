/*
______________________________________________________________________________________________

	FILE	: Afterimage.cpp

	________/ Explanation of file /___________________________________________________________
       
    Afterimage�N���X

	Afterimage�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include <windows.h>
#include "Common.h"
#include <stdio.h>

class Afterimage
{
	public :
		/*/
		/*	�R���X�g���N�^
		/*/
		Afterimage( ) ;

		/*/
		/*	�f�X�g���N�^
		/*/
		~Afterimage( ) ;

		/*/
		/*	 ������
		/*/
		void Initialize( ) ;

		/*/
		/*	 �I����
		/*/
		void Finalize( ) ;

		void AfterimageAction( int arg_bmpno , float arg_xpos , float arg_ypos , RECT arg_rc , bool arg_flip ) ;

		/*/
		/*	 �X�V
		/*/
		void Update( ) ;

		bool create_flg_ ;

	private :
		enum AfterimageMode {
			e_init = 0 ,
			e_anim
		} ;
		AfterimageMode mode_ ;

		// �v���C���[�̃f�[�^
		int				Afterimage_bmpno_ ;
		float			Afterimage_xpos_ ;
		float			Afterimage_ypos_ ;
		RECT			Afterimage_rc_ ;
		float			alpha_ ;
		bool			flipMag_ ;

} ;


