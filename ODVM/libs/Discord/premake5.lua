project "Discord"
	kind "StaticLib"
	language "C++"
    cppdialect "C++17"
    systemversion "latest"
    staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"cpp/**.cpp",
        "cpp/**.h"
	}
	

    
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"
