/*
______________________________________________________________________________________________

	FILE	: Collider.cpp

	________/ Explanation of file /___________________________________________________________
    
		Collider�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include "Collider.h"


/*/
/*	�f�X�g���N�^
/*/
Collider::~Collider( )
{
	// �I�����o��
	printf( "Management of a Collider is ended.\n" ) ;
}

/*/
/*	������
/*/
void Collider::Initialize( )
{

	// �J�n���o��
	printf( "Management of a Collider is started.\n" ) ;
//	printf( "gravity = %8.4f\n" , Collider::GetInstance()->getGravity( ) ) ;

}

/*/
/*	�����`�F�b�N
/*/
bool Collider::getFootCheck( )
{
	bool iRet = false ;



	return( iRet ) ;
}

/*/
/*	�L�[���̍X�V
/*/
void Collider::update( )
{

}


		
