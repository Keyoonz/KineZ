workspace "KineZ"
    architecture "x64"
    startproject "Sandbox"

    configurations 
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "KineZ"
    location "KineZ"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "KZ_BUILD_DLL",
            "KZ_PLATFORM_WINDOWS"
        }

        postbuildcommands 
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "KZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "KZ_RELEASE"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "KineZ/vendor/spdlog/include",
        "KineZ/src"
    }

    links
    {
        "KineZ"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "KZ_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "KZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "KZ_RELEASE"
        optimize "On"