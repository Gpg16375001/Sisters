/*
______________________________________________________________________________________________

	FILE	: Physics.cpp

	________/ Explanation of file /___________________________________________________________
    
		Physics�N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include "Physics.h"


/*/
/*	�f�X�g���N�^
/*/
Physics::~Physics( )
{
	// �I�����o��
	printf( "Management of a physics is ended.\n" ) ;
}

/*/
/*	������
/*/
void Physics::Initialize( )
{

	// �J�n���o��
	printf( "Management of a physics is started.\n" ) ;
//	printf( "gravity = %8.4f\n" , Physics::GetInstance()->getGravity( ) ) ;

}

/*/
/*	�L�[���̍X�V
/*/
void Physics::update( )
{

}


		
