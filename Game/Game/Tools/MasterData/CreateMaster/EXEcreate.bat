@echo off

::_____________________________________________
::				�f�B���N�g���̏�����
::�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
if exist source rmdir /Q /S source
mkdir source
cd source
mkdir master
cd ../

::_______________________________________________
::			   ���O�ۑ��p�t�@�C���쐬
::�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
for /R %%I in (*.xls) do (
	echo %%~nI>> source/master/name.txt
)
CreateMaster.exe

call build.bat


