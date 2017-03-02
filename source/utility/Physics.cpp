/*
______________________________________________________________________________________________

	FILE	: Physics.cpp

	________/ Explanation of file /___________________________________________________________
    
		PhysicsÉNÉâÉXÇÃé¿ëïïî

ÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅPÅP
*/

#include <windows.h>
#include <stdio.h>
#include <math.h>

#include "Physics.h"


/*/
/*	ÉfÉXÉgÉâÉNÉ^
/*/
Physics::~Physics( )
{
	// èIóπÇèoóÕ
	printf( "Management of a physics is ended.\n" ) ;
}

/*/
/*	èâä˙âª
/*/
void Physics::Initialize( )
{

	// äJénÇèoóÕ
	printf( "Management of a physics is started.\n" ) ;
//	printf( "gravity = %8.4f\n" , Physics::GetInstance()->getGravity( ) ) ;

}

/*/
/*	ÉLÅ[èÓïÒÇÃçXêV
/*/
void Physics::update( )
{

}


		
