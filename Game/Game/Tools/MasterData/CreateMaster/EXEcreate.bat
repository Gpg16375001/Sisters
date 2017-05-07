@echo off

::_____________________________________________
::				ƒfƒBƒŒƒNƒgƒŠ‚Ì‰Šú‰»
::PPPPPPPPPPPPPPPPPPPPPPPP
if exist source rmdir /Q /S source
mkdir source
cd source
mkdir master
cd ../

::_______________________________________________
::			   –¼‘O•Û‘¶—pƒtƒ@ƒCƒ‹ì¬
::PPPPPPPPPPPPPPPPPPPPPPPPP
for /R %%I in (*.xls) do (
	echo %%~nI>> source/master/name.txt
)
CreateMaster.exe

call build.bat


