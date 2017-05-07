@echo off

cd ../Tools/mapEditor/exe

if exist "source/MapData" (
	MapEditor.exe
) else (
	md MapData
	move MapData source/
	MapEditor.exe
)
