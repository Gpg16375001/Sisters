/*
______________________________________________________________________________________________

	FILE : BitmapData.h

	________/ Explanation of file /___________________________________________________________

		ƒrƒbƒgƒ}ƒbƒv‚ğ“Ç‚İ‚İƒf[ƒ^‚ğ•Û‚·‚éƒNƒ‰ƒX
		
			--- å‚Èg‚¢•û ---
			1‚Â‚ÌƒCƒ“ƒXƒ^ƒ“ƒX‚Å1024–‡‚Ìƒrƒbƒgƒ}ƒbƒvƒf[ƒ^‚ğ•Û‚·‚é‚±‚Æ‚ª‚Å‚«‚éB
			‚Â‚Ü‚èA‰æ‘œ‚Ìî•ñ‚ğ•âŠ®‚·‚éƒNƒ‰ƒX‚È‚Ì‚Å‚Ù‚µ‚¢‰æ‘œ‚Ì”Ô†‚©‚çŒÄ‚Ño‚·‚±‚Æ‚É‚È‚éB
			‚©‚È‚ç‚¸ˆê“x‚¾‚¯Å‰‚É BitmapData::GetInstance( )->Initialize( ) ‚Å‰Šú‰»‚·‚éB

			—á1. ‰æ‘œ‚Ì“Ç‚İ‚İ•û–@
			BitmapData::GetInstance( )->loadData( bmpNo , file_path , width , height ) ;


PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

struct BmpData {
	HBITMAP _hBmp ;
	int		_w , _h ;				// •‚‚³
} ;

// ƒNƒ‰ƒX‚ÌéŒ¾
class BitmapData
{
	static const int MAX_BMP_IMAGES = 256 ;

	public :
		/*/
		/*	‰Šú‰»
		/*/
		void Initialize( ) ; 

		~BitmapData( ) ;

		int loadData( int arg_bmpNo_ , LPCTSTR arg_pStr , int arg_width , int arg_height ) ;
		int clearData( int arg_bmpNo ) ;
		int setBmpWH( int arg_bmpNo , int arg_w , int arg_h ) ;

		/*/
		/*	Å‘å•Û”‚Ìæ“¾
		/*/
		int getMaxBmp( ) const
		{
			return( MAX_BMP_IMAGES ) ;
		}
		/*/
		/*	ƒrƒbƒgƒ}ƒbƒv‚Ìƒnƒ“ƒhƒ‹‚ÌƒAƒNƒZƒbƒT
		/*/
		HBITMAP getBmpData( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._hBmp ) ;
		}
		/*/
		/*	•‚Ìæ“¾
		/*/
		int getBmpWidth( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._w ) ;
		}
		/*/
		/*	‚‚³‚Ìæ“¾
		/*/
		int getBmpHeight( int arg_bmpNo ) const
		{
			return ( bmpDataTable_[ arg_bmpNo ]._h ) ;
		}

		/*/
		/*	Shingleton -> ƒCƒ“ƒXƒ^ƒ“ƒX‚Ìæ“¾
		/*/
		static BitmapData* GetInstance( )
		{
			static BitmapData v ;
			return &v ;
		}

	private :
		/*/
		/*	ƒRƒ“ƒXƒgƒ‰ƒNƒ^
		/*/
		BitmapData( ) {	} ;

		BmpData bmpDataTable_[ MAX_BMP_IMAGES ] ;			// ‰æ‘œƒf[ƒ^


} ;


