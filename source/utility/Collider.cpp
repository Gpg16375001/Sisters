/*
______________________________________________________________________________________________

	FILE	: Collider.cpp

	________/ Explanation of file /___________________________________________________________
    
		ColliderƒNƒ‰ƒX‚ÌÀ‘••”

PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include "Collider.h"


/*/
/*	ƒfƒXƒgƒ‰ƒNƒ^
/*/
Collider::~Collider( )
{
	// I—¹‚ğo—Í
	printf( "Management of a Collider is ended.\n" ) ;
}

/*/
/*	‰Šú‰»
/*/
void Collider::Initialize( )
{

	// ŠJn‚ğo—Í
	printf( "Management of a Collider is started.\n" ) ;
//	printf( "gravity = %8.4f\n" , Collider::GetInstance()->getGravity( ) ) ;

}

/*/
/*	‘«Œ³ƒ`ƒFƒbƒN
/*/
bool Collider::getFootCheck( )
{
	bool iRet = false ;



	return( iRet ) ;
}

/*/
/*	ƒL[î•ñ‚ÌXV
/*/
void Collider::update( )
{

}


		
