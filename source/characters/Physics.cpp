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
	Pi		 = 3.141592654f ;
	RadToDeg = 57.29577951f ;
	DegToRad = 0.017453293f ;
	gravity_ = 9.81f ;
	mass_	 = 1.0f ;

	// �J�n���o��
	printf( "Management of a physics is started.\n" ) ;
//	printf( "gravity = %8.4f\n" , Physics::GetInstance()->getGravity( ) ) ;

}

/*/
/*	�I����
/*/
void Physics::Finalize( )
{
	Pi		 = 0.0f ;
	RadToDeg = 0.0f ;
	DegToRad = 0.0f ;
	gravity_ = 0.0f ;
	mass_	 = 0.0f ;

	// �J�n���o��
	printf( "Management of a physics is started.\n" ) ;
//	printf( "gravity = %8.4f\n" , Physics::GetInstance()->getGravity( ) ) ;

}

/*/
/*	�g�����F2�_�Ԃ��Ȃ����������߂�
/*	�����@�F���W������킷float�z��Q��
/*	�Ԃ�l�F�����̌X��
/*/
float Physics::slopePoint( float *arg_point1 , float *arg_point2  )
{
	return( (arg_point2[ 1 ] - arg_point1[ 1 ]) / (arg_point2[ 0 ] - arg_point1[ 0 ]) ) ;
}

/*/
/*	�g�����F�x�N�g���� polar ���� component �ɕϊ�
/*	�����@�Fpolar �\���̃x�N�g��
/*	�Ԃ�l�Fcomponent �\���̃x�N�g��
/*/
Vector2D_compo Physics::PolarToCompo( Vector2D_polar arg_vector2d )
{
	Vector2D_compo temp2d ;

	temp2d.x = arg_vector2d.mag * cos( arg_vector2d.deg * Pi / 180 ) ;
	temp2d.y = arg_vector2d.mag * sin( arg_vector2d.deg * Pi / 180 ) ;

	return( temp2d ) ;
}

/*/
/*	�g�����F�x�N�g���� component ���� polar �ɕϊ�
/*	�����@�Fcomponent �\���̃x�N�g��
/*	�Ԃ�l�Fpolar �\���̃x�N�g��
/*/
Vector2D_polar Physics::CompoToPolar( Vector2D_compo arg_vector2d )
{
	Vector2D_polar temp2d = { 0 , 0 } ;

	// �s�^�S���X�̒藝�� C2 �����߂�
	temp2d.mag = (arg_vector2d.x * arg_vector2d.x) + (arg_vector2d.y * arg_vector2d.y) ;
	temp2d.mag = temp2d.mag / temp2d.mag ;

	// �o�O��� 0 �Ŋ���Ȃ��悤��
	if ( temp2d.mag == 0 )
	{
		return( temp2d ) ;
	}

	// �p�x���v�Z ( asin() �� (90)~(-90)�x ��Ԃ� )
	temp2d.deg = (180 / Pi) * asin( arg_vector2d.y / temp2d.mag ) ;

	// ��̌v�Z�� (90)~(-90)�x �ł͂Ȃ������Ƃ�
	if ( arg_vector2d.x < 0 )
	{
		temp2d.deg = 180 - temp2d.deg ;
	}
	// (0)~(-90)�x�ɂ������ꍇ
	else if ( (arg_vector2d.x > 0) && (arg_vector2d.y < 0) ) {
		temp2d.deg += 360 ;
	}

	return( temp2d ) ;
}

/*/
/*	�g�����F�d�� �̃x�N�g���ɕϊ�
/*	�����@�F���� �� �����x
/*	�Ԃ�l�F���̕��̂ɓ��� �d�� �̃x�N�g��
/*/
Vector2D_compo Physics::Weight2D( float arg_mass , float arg_grav )
{
	if ( (arg_mass == 1.0f) && (arg_grav == 0.0f) )
	{
		weight_.y = mass_ * gravity_ ;

	} else {
		weight_.y = arg_mass * arg_grav ;
	}
	return( weight_ ) ;
}


/*/
/*	���ʂ̑��
/*/
int Physics::setMass( float arg_mass )
{
	mass_ = arg_mass ;
	return( true ) ;
}

/*/
/*	�L�[���̍X�V
/*/
void Physics::update( )
{

}


		
