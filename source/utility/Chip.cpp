/*
________________________________________________________________________________________________________________

	FILE : Chip.cpp

	________/ Explanation of file /___________________________________________________________

		Chip �N���X�̎�����

�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
*/
#include "Chip.h"

/*/
/*	�f�X�g���N�^
/*/
Chip::~Chip( )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
	for ( int i = 0 ; i < MAX_BMP_CBG ; ++i )
	{
		if( bmpCBGTable_[ i ]._hBmp != NULL )
		{
			DeleteObject( bmpCBGTable_[ i ]._hBmp ) ;
		}
		clearData( i ) ; 
	}
}

/*/
/*	������
/*/
void Chip::Initialize( )
{
	// --- �g�p����Ă�����I�u�W�F�N�g�j��
	for ( int i = 0 ; i < MAX_BMP_CBG ; ++i )
	{
		if( bmpCBGTable_[ i ]._hBmp != NULL )
		{
			bmpCBGTable_[ i ]._hBmp = NULL ;
		}
		clearData( i ) ; 
	}
	setMapSize( 0 , 0 ) ;
	RenderMapSize( 0 , 0 ) ;

}

/*/
/*	�摜�f�[�^�̃N���A
/*/
int Chip::clearData( int arg_bmpNo )
{
	setUseFlg( arg_bmpNo , false ) ;
	setBmpXY( arg_bmpNo , 0 , 0 ) ;
	setBmpUV( arg_bmpNo , 0 , 0 ) ;
	setBmpWH( arg_bmpNo , 0 , 0 ) ;
	setBmpScale( arg_bmpNo , 0 , 0 ) ;
	setAlpha( arg_bmpNo , 255 ) ;
	setUseAlpha( arg_bmpNo , false ) ;
	setAngle( arg_bmpNo , 0 ) ;
	setUseRotate( arg_bmpNo , false ) ;

	return( true ) ;
}

/*/
/*	�C���[�W�ǂݍ���
/*/
int Chip::loadBmpData( int arg_bmpNo , HBITMAP arg_hbmp )
{
	// �g�p����Ă�����I�u�W�F�N�g�j��
	clearData( arg_bmpNo ) ;

	// �f�[�^�̓ǂݍ��݂ƕ��ƍ������Z�b�g
	bmpCBGTable_[ arg_bmpNo ]._hBmp = arg_hbmp ;

	return ( true ) ;
}

/*/
/*	�ꊇ�C���[�W�ǂݍ���
/*/
int Chip::loadBmpDataAll( HBITMAP arg_hbmp )
{
	for ( int i = 0 ; i < MAX_BMP_CBG ; ++i )
	{
		loadBmpData( i , arg_hbmp ) ;
	}

	return ( true ) ;
}


/*/
/*	��ʂɕ`��ł���O���b�h�̐����w����w��
/*/
int Chip::RenderMapSize( int arg_w , int arg_h )
{
	renderMap_w_ = arg_w ;
	renderMap_h_ = arg_h ;

	return( true ) ;
}

/*/
/*	�}�b�v�̃T�C�Y���Z�b�g
/*/
int Chip::setMapSize( int arg_w , int arg_h )
{
	map_w_ = arg_w ;
	map_h_ = arg_h ;

	return( true ) ;
}

/*/
/*	�`�悷�邩�ǂ����̃t���O���Z�b�g
/*/
int Chip::setUseFlg( int arg_bmpNo , bool arg_useFlg )
{
	bmpCBGTable_[ arg_bmpNo ]._useFlg = arg_useFlg ;

	return( true ) ;
}

/*/
/*	�������������邩�ǂ����̃t���O���Z�b�g
/*/
int Chip::setUseAlpha( int arg_bmpNo , bool arg_useAlpha )
{
	bmpCBGTable_[ arg_bmpNo ]._useAlpha = arg_useAlpha ;

	return( true ) ;
}

/*/
/*	��]���������邩�ǂ����̃t���O���Z�b�g
/*/
int Chip::setUseRotate( int arg_bmpNo , bool arg_useRotate )
{
	bmpCBGTable_[ arg_bmpNo ]._useRotate = arg_useRotate ;

	return( true ) ;
}

/*/
/*	�|�W�V�����̃Z�b�g
/*/
int Chip::setBmpXY( int arg_bmpNo , int arg_x , int arg_y )
{
	bmpCBGTable_[ arg_bmpNo ]._x = arg_x ;
	bmpCBGTable_[ arg_bmpNo ]._y = arg_y ;

	return( true ) ;
}

/*/
/*	�؂���ʒu�̃Z�b�g
/*/
int Chip::setBmpUV( int arg_bmpNo , int arg_u , int arg_v )
{
	bmpCBGTable_[ arg_bmpNo ]._u = arg_u ;
	bmpCBGTable_[ arg_bmpNo ]._v = arg_v ;

	return( true ) ;
}

/*/
/*	���A�����̃Z�b�g
/*/
int Chip::setBmpWH( int arg_bmpNo , int arg_w , int arg_h )
{
	bmpCBGTable_[ arg_bmpNo ]._w = arg_w ;
	bmpCBGTable_[ arg_bmpNo ]._h = arg_h ;

	return( true ) ;
}

/*/
/*	�g�嗦�̃Z�b�g
/*/
int Chip::setBmpScale( int arg_bmpNo , float arg_w , float arg_h )
{
	bmpCBGTable_[ arg_bmpNo ]._scaleX = arg_w ;
	bmpCBGTable_[ arg_bmpNo ]._scaleY = arg_h ;

	return( true ) ;
}

/*/
/*	�A���J�[���Z�b�g
/*/
int Chip::setAnchor( int arg_bmpNo , int arg_anchor )
{
	bmpCBGTable_[ arg_bmpNo ]._anchor = arg_anchor ;

	return( true ) ;
}

/*/
/*	�����x�̃Z�b�g
/*/
int Chip::setAlpha( int arg_bmpNo , int arg_alpha )
{
	bmpCBGTable_[ arg_bmpNo ]._alpha = arg_alpha ;	

	return( true ) ;
}

/*/
/*	�p�x�̃Z�b�g
/*/
int Chip::setAngle( int arg_bmpNo , float arg_degree )
{
	bmpCBGTable_[ arg_bmpNo ]._degree = arg_degree ;

	return( true ) ;
}


/*/
/*	�z����W�̃Z�b�g
/*/
int Chip::setArray( int arg_bmpNo , int arg_ax , int arg_ay  )
{
	bmpCBGTable_[ arg_bmpNo ]._arrayX = arg_ax ;
	bmpCBGTable_[ arg_bmpNo ]._arrayY = arg_ay ;

	return( true ) ;
}

/*/
/*	�`�悷������Z�b�g
/*/
int Chip::setChipData(
		int arg_bmpNo ,
		int arg_anchor ,
		int arg_arrayX , int arg_arrayY ,
		int arg_x , int arg_y ,
		int arg_u , int arg_v ,
		int arg_w , int arg_h ,
		float arg_scaleX , float arg_scaleY ,
		int arg_alpha ,
		float arg_degree
	) 
{
	bmpCBGTable_[ arg_bmpNo ]._bmpNo = arg_bmpNo ;
	setUseFlg( arg_bmpNo , true ) ;
	setAnchor( arg_bmpNo , arg_anchor ) ;
	setArray( arg_bmpNo , arg_arrayX , arg_arrayY ) ;
	setBmpXY( arg_bmpNo , arg_x , arg_y ) ;
	setBmpUV( arg_bmpNo , arg_u , arg_v ) ;
	setBmpWH( arg_bmpNo , arg_w , arg_h ) ;
	setBmpScale( arg_bmpNo , arg_scaleX , arg_scaleY ) ;
	if ( arg_alpha < 255 )
	{
		setUseAlpha( arg_bmpNo , true ) ;
		setAlpha( arg_bmpNo , arg_alpha ) ;
	}
	if ( arg_degree != 0 )
	{
		setUseRotate( arg_bmpNo , true ) ;
		setAngle( arg_bmpNo , arg_degree ) ;
	}

	return( true ) ;
}

/*/
/*	Update
/*
/*	�����̃}�b�v�f�[�^�����ƂɃO���b�h�z�u�̌v�Z������
/*/
void Chip::Update( )
{
	for ( int i = 0 ; i < renderMap_w_ * renderMap_h_ ; ++i )	// MAP �̕��ƍ���
	{
		setChipData(
				i ,
				0 ,
				i % map_w_ , i / map_h_ ,
				(i % renderMap_w_) * 64 , (i / renderMap_w_) * 64 ,
				64 , 0 ,
				64 , 64 ,
				1.0f , 1.0f
			) ;
	}

}



