@echo off

cd ../Tools/mapEditor

if exist "source/MapData" (
	MapEditor.exe
) else (
	md MapData
	move MapData source/
	MapEditor.exe
)
