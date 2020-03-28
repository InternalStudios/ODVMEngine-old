workspace "ODVM"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "ODVM/libs/GLFW/include"
IncludeDir["Glad"] = "ODVM/libs/Glad/include"
IncludeDir["ImGui"] = "ODVM/libs/ImGui"
IncludeDir["glm"] = "ODVM/libs/glm"
IncludeDir["stb"] = "ODVM/libs/stb"
IncludeDir["discord"] = "ODVM/libs/discord"
IncludeDir["vulkan"] = "ODVM/libs/Vulkan/latest"

include "ODVM/libs/GLFW"
include "ODVM/libs/Glad"
include "ODVM/libs/ImGui"
include "ODVM/libs/Discord"

project "ODVM"
	location "ODVM"
	kind "StaticLib"
    language "C++"
    cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	filter "action:vs2017"
		pchheader "odvmpch.h"
		pchsource "Hazel/src/odvmpch.cpp"

	filter "action:xcode4"
		pchheader "src/odvmpch.h"
		pchsource "Hazel/src/odvmpch.cpp"

	filter "action:gmake"
		pchheader "../src/odvmpch.h"
		pchsource "Hazel/src/odvmpch.cpp"


    filter {}

	files
	{
        "%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/libs/stb/**.cpp",
		"%{prj.name}/libs/stb/**.h",
		"%{IncludeDir.glm}/glm/**.hpp",
		"%{IncludeDir.glm}/glm/**.inl"
	}

	includedirs
	{
        "%{prj.name}/src",
        "%{prj.name}/libs/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb}",
	"%{IncludeDir.discord}/cpp",
        "%{IncludeDir.vulkan}/Include"
	}

	filter "action:xcode4"
		sysincludedirs
		{
			"%{prj.name}/src",
			"%{prj.name}/libs/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.ImGui}",
			"%{IncludeDir.glm}",
			"%{IncludeDir.stb}",
			"%{IncludeDir.vulkan}/Include"
		}

		links
		{
			"QuartzCore.framework"
		}

	filter "action:gmake"
		links
		{
			"QuartzCore.framework"
		}

	filter {}

	links
	{
		"GLFW",
		"Glad",
        	"ImGui",
        	"opengl32.lib",
		"Discord"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "system:macosx"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
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
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
        	"ODVM/libs/spdlog/include",
		"ODVM/src",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.discord}/cpp",
		"%{IncludeDir.vulkan}/Include"
	}


	links
	{
        	"ODVM",
		"GLFW",
		"Discord",
		"Glad",
		"ImGui"
	}
		

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
		}


	filter "system:macosx"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
		}

		links
		{
	        	"Cocoa.framework",
        		"IOKit.framework"
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
