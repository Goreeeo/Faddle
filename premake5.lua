workspace "FaddleEngine"
	architecture "x64"
	startproject "Example"
	
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Faddle"
	location "Faddle"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "fmpch.h"
	pchsource "Faddle/src/fmpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FM_PLATFORM_WINDOWS",
			"FM_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Example")
		}

	filter "configurations:Debug"
		defines "FM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FM_DIST"
		optimize "On"

project "Example"
	location "Example"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Faddle/vendor/spdlog/include",
		"Faddle/src"
	}

	links {
		"Faddle"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"FM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FM_DIST"
		optimize "On"