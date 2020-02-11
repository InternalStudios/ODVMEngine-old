workspace "ODVM"
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}



	
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "ODVM/libs/GLFW/include"
IncludeDir["Glad"] = "ODVM/libs/Glad/include"
IncludeDir["ImGui"] = "ODVM/libs/ImGui"
IncludeDir["glm"] = "ODVM/libs/glm"
IncludeDir["stb"] = "ODVM/libs/stb"

startproject "Sandbox"


	
project "ODVM"
	location "ODVM"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "odvmpch.h"
	pchsource "ODVM/src/odvmpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/libs/stb/**.cpp",
		"%{prj.name}/libs/stb/**.h",
		"%{IncludeDir.glm}/glm/**.hpp",
		"%{IncludeDir.glm}/glm/**.inl"
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/libs/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"ODVM_PLATFORM_WINDOWS",
			"_WINDLL",
			"ODVM_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
	filter "configurations:Debug"
		defines "ODVM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ODVM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ODVM_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"ODVM/libs/spdlog/include",
		"ODVM/src",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"ODVM"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"ODVM_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "ODVM_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ODVM_RELEASE"
		runtime "Release"		
		optimize "on"
		

	filter "configurations:Dist"
		defines "ODVM_DIST"
		runtime "Release"
		optimize "on"

group "Dependencies"
	include "ODVM/libs/GLFW"
	include "ODVM/libs/Glad"
	include "ODVM/libs/ImGui"

	