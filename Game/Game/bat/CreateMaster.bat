@echo off

cd ../Tools/MasterData/CreateMaster

call EXEcreate.bat

if exist MasterData.vcxproj del MasterData.vcxproj
if exist source move source ../
if exist MasterData.exe move MasterData.exe ../

copy *.csv ../Data.csv

pause