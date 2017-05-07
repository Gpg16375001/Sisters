@echo off

del /Q MasterData.vcxproj

:: MasterData.vcxproj
	echo ^<?xml version="1.0" encoding="utf-8"?^>																																					>> MasterData.vcxproj
	echo ^<Project DefaultTargets="Build" ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003"^>																			>> MasterData.vcxproj
	echo 	^<ItemGroup Label="ProjectConfigurations"^>																																				>> MasterData.vcxproj
	echo 		^<ProjectConfiguration Include="Debug|Win32"^>																																		>> MasterData.vcxproj
	echo 			^<Configuration^>Debug^</Configuration^>																																		>> MasterData.vcxproj
	echo 			^<Platform^>Win32^</Platform^>																																					>> MasterData.vcxproj
	echo 		^</ProjectConfiguration^>																																							>> MasterData.vcxproj
	echo 		^<ProjectConfiguration Include="Release|Win32"^>																																	>> MasterData.vcxproj
	echo 			^<Configuration^>Release^</Configuration^>																																		>> MasterData.vcxproj
	echo 			^<Platform^>Win32^</Platform^>																																					>> MasterData.vcxproj
	echo 		^</ProjectConfiguration^>																																							>> MasterData.vcxproj
	echo 	^</ItemGroup^>																																											>> MasterData.vcxproj
	echo 	^<PropertyGroup Label="Globals"^>																																						>> MasterData.vcxproj
	echo 		^<ProjectGuid^>{BFEC2F66-3E44-4F63-8AF7-3312732E3F5D}^</ProjectGuid^>																												>> MasterData.vcxproj
	echo 		^<Keyword^>Win32Proj^</Keyword^>																																					>> MasterData.vcxproj
	echo 		^<RootNamespace^>MasterData^</RootNamespace^>																																		>> MasterData.vcxproj
	echo 	^</PropertyGroup^>																																										>> MasterData.vcxproj
	echo 	^<Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" /^>																														>> MasterData.vcxproj
	echo 	^<PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'" Label="Configuration"^>																						>> MasterData.vcxproj
	echo 		^<ConfigurationType^>Application^</ConfigurationType^>																																>> MasterData.vcxproj
	echo 		^<UseDebugLibraries^>true^</UseDebugLibraries^>																																		>> MasterData.vcxproj
	echo 		^<CharacterSet^>Unicode^</CharacterSet^>																																			>> MasterData.vcxproj
	echo 		^</PropertyGroup^>																																									>> MasterData.vcxproj
	echo 	^<PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'" Label="Configuration"^>																					>> MasterData.vcxproj
	echo 		^<ConfigurationType^>Application^</ConfigurationType^>																																>> MasterData.vcxproj
	echo 		^<UseDebugLibraries^>false^</UseDebugLibraries^>																																	>> MasterData.vcxproj
	echo 		^<WholeProgramOptimization^>true^</WholeProgramOptimization^>																														>> MasterData.vcxproj
	echo 		^<CharacterSet^>Unicode^</CharacterSet^>																																			>> MasterData.vcxproj
	echo 	^</PropertyGroup^>																																										>> MasterData.vcxproj
	echo 	^<Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" /^>																																>> MasterData.vcxproj
	echo 	^<ImportGroup Label="ExtensionSettings"^>																																				>> MasterData.vcxproj
	echo 	^</ImportGroup^>																																										>> MasterData.vcxproj
	echo 	^<ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"^>																						>> MasterData.vcxproj
	echo 		^<Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" /^>	>> MasterData.vcxproj
	echo 	^</ImportGroup^>																																										>> MasterData.vcxproj
	echo 	^<ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|Win32'"^>																					>> MasterData.vcxproj
	echo 		^<Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" /^>	>> MasterData.vcxproj
	echo 	^</ImportGroup^>																																										>> MasterData.vcxproj
	echo 	^<PropertyGroup Label="UserMacros" /^>																																					>> MasterData.vcxproj
	echo 	^<PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"^>																											>> MasterData.vcxproj
	echo 		^<LinkIncremental^>true^</LinkIncremental^>																																			>> MasterData.vcxproj
	echo 		^<GenerateManifest^>false^</GenerateManifest^>																																		>> MasterData.vcxproj
	echo 	^</PropertyGroup^>																																										>> MasterData.vcxproj
	echo 	^<PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'"^>																											>> MasterData.vcxproj
	echo 		^<LinkIncremental^>false^</LinkIncremental^>																																		>> MasterData.vcxproj
	echo 	^</PropertyGroup^>																																										>> MasterData.vcxproj
	echo 	^<ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"^>																										>> MasterData.vcxproj
	echo 		^<ClCompile^>																																										>> MasterData.vcxproj
	echo 			^<PrecompiledHeader^>																																							>> MasterData.vcxproj
	echo 			^</PrecompiledHeader^>																																							>> MasterData.vcxproj
	echo 			^<WarningLevel^>Level3^</WarningLevel^>																																			>> MasterData.vcxproj
	echo 			^<Optimization^>Disabled^</Optimization^>																																		>> MasterData.vcxproj
	echo 			^<PreprocessorDefinitions^>WIN32;_CRT_SECURE_NO_WARNINGS;_DEBUG;_CONSOLE;%%(PreprocessorDefinitions)^</PreprocessorDefinitions^>												>> MasterData.vcxproj
	echo 			^<RuntimeLibrary^>MultiThreaded^</RuntimeLibrary^>																																>> MasterData.vcxproj
	echo 		^</ClCompile^>																																										>> MasterData.vcxproj
	echo 		^<Link^>																																											>> MasterData.vcxproj
	echo 		  ^<SubSystem^>Console^</SubSystem^>																																				>> MasterData.vcxproj
	echo 		  ^<GenerateDebugInformation^>true^</GenerateDebugInformation^>																														>> MasterData.vcxproj
	echo 		^</Link^>																																											>> MasterData.vcxproj
	echo 	^</ItemDefinitionGroup^>																																								>> MasterData.vcxproj
	echo 	^<ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'"^>																									>> MasterData.vcxproj
	echo 	^<ClCompile^>																																											>> MasterData.vcxproj
	echo 		^<WarningLevel^>Level3^</WarningLevel^>																																				>> MasterData.vcxproj
	echo 		^<PrecompiledHeader^>																																								>> MasterData.vcxproj
	echo 		^</PrecompiledHeader^>																																								>> MasterData.vcxproj
	echo 		^<Optimization^>MaxSpeed^</Optimization^>																																			>> MasterData.vcxproj
	echo 		^<FunctionLevelLinking^>true^</FunctionLevelLinking^>																																>> MasterData.vcxproj
	echo 		^<IntrinsicFunctions^>true^</IntrinsicFunctions^>																																	>> MasterData.vcxproj
	echo 		^<PreprocessorDefinitions^>WIN32;_CRT_SECURE_NO_WARNINGS;NDEBUG;_CONSOLE;%%(PreprocessorDefinitions)^</PreprocessorDefinitions^>													>> MasterData.vcxproj
	echo 	^</ClCompile^>																																											>> MasterData.vcxproj
	echo 	^<Link^>																																												>> MasterData.vcxproj
	echo 		^<SubSystem^>Console^</SubSystem^>																																					>> MasterData.vcxproj
	echo 		^<GenerateDebugInformation^>true^</GenerateDebugInformation^>																														>> MasterData.vcxproj
	echo 		^<EnableCOMDATFolding^>true^</EnableCOMDATFolding^>																																	>> MasterData.vcxproj
	echo 		^<OptimizeReferences^>true^</OptimizeReferences^>																																	>> MasterData.vcxproj
	echo 	^</Link^>																																												>> MasterData.vcxproj
	echo 		^</ItemDefinitionGroup^>																																							>> MasterData.vcxproj
	echo 		^<ItemGroup^>																																										>> MasterData.vcxproj
	echo 			^<ClCompile Include="source\Main.cpp" /^>																																		>> MasterData.vcxproj
	echo 			^<ClCompile Include="source\master\Master.cpp" /^>																																>> MasterData.vcxproj

				for /f %%a in (source/master/name.txt) do (																 
					set %%a=%%b
					echo 			^<ClCompile Include="source\master\%%a.cpp" /^>																													>> MasterData.vcxproj
				)
	echo 		^</ItemGroup^>																																										>> MasterData.vcxproj
	echo 		^<ItemGroup^>																																										>> MasterData.vcxproj
	echo 		    ^<ClInclude Include="source\master\Master.hpp" /^>																																>> MasterData.vcxproj

				for /f %%a in (source/master/name.txt) do (																 
					set %%a=%%b
					echo 			^<ClCompile Include="source\master\%%a.h" /^>																													>> MasterData.vcxproj
				)
	echo 		^</ItemGroup^>																																										>> MasterData.vcxproj
	echo 		^<Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" /^>																														>> MasterData.vcxproj
	echo 		^<ImportGroup Label="ExtensionTargets"^>																																			>> MasterData.vcxproj
	echo 	^</ImportGroup^>																																										>> MasterData.vcxproj
	echo ^</Project^>																																												>> MasterData.vcxproj
	echo;																																															>> MasterData.vcxproj
	echo;																																															>> MasterData.vcxproj
	echo;																																															>> MasterData.vcxproj
																									
cd source/master/
del /Q name.txt
cd ../../
																									
C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild MasterData.vcxproj /p:configuration=release

move release\MasterData.exe MasterData.exe

if exist release rmdir /S /Q release

pause