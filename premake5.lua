workspace "KineZ"
    architecture "x64"
    startproject "Keisan"

    configurations 
    {
        "Debug",
        "Release",
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GLFW"
    kind "SharedLib"
    language "C"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "KineZ/vendor/GLFW/include/GLFW/glfw3.h",
        "KineZ/vendor/GLFW/include/GLFW/glfw3native.h",
        "KineZ/vendor/GLFW/src/internal.h",
        "KineZ/vendor/GLFW/src/platform.h",
        "KineZ/vendor/GLFW/src/mappings.h",
        "KineZ/vendor/GLFW/src/context.c",
        "KineZ/vendor/GLFW/src/init.c",
        "KineZ/vendor/GLFW/src/input.c",
        "KineZ/vendor/GLFW/src/monitor.c",
        "KineZ/vendor/GLFW/src/platform.c",
        "KineZ/vendor/GLFW/src/vulkan.c",
        "KineZ/vendor/GLFW/src/window.c",
        "KineZ/vendor/GLFW/src/egl_context.c",
        "KineZ/vendor/GLFW/src/osmesa_context.c",
        "KineZ/vendor/GLFW/src/null_platform.h",
        "KineZ/vendor/GLFW/src/null_joystick.h",
        "KineZ/vendor/GLFW/src/null_init.c",

        "KineZ/vendor/GLFW//src/null_monitor.c",
        "KineZ/vendor/GLFW//src/null_window.c",
        "KineZ/vendor/GLFW//src/null_joystick.c",

    }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

        files
        {
            "KineZ/vendor/GLFW/src/win32_init.c",
            "KineZ/vendor/GLFW/src/win32_module.c",
            "KineZ/vendor/GLFW/src/win32_joystick.c",
            "KineZ/vendor/GLFW/src/win32_monitor.c",
            "KineZ/vendor/GLFW/src/win32_time.h",
            "KineZ/vendor/GLFW/src/win32_time.c",
            "KineZ/vendor/GLFW/src/win32_thread.h",
            "KineZ/vendor/GLFW/src/win32_thread.c",
            "KineZ/vendor/GLFW/src/win32_window.c",
            "KineZ/vendor/GLFW/src/wgl_context.c",
            "KineZ/vendor/GLFW/src/egl_context.c",
            "KineZ/vendor/GLFW/src/osmesa_context.c"
        }

        defines 
        { 
            "_GLFW_WIN32",
            "_GLFW_BUILD_DLL",
            "_CRT_SECURE_NO_WARNINGS"

        }

        postbuildcommands 
        {
            ("{COPY} bin/Debug-windows-x86_64/GLFW/GLFW.dll bin/Debug-windows-x86_64/Keisan/")
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"


project "KineZ"
    location "KineZ"
    kind "SharedLib"
    language "C++"
    

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/KineZ/utils/DoubleLinkedList.cpp",
        "%{prj.name}/src/KineZ/utils/DoubleLinkedList.h"
        

    }

    includedirs
    {
        "%{prj.name}/vendor/GLFW/include",
        "%{prj.name}/vendor/GLAD/include";
        "%{prj.name}/vendor/GLM/"
    }

    libdirs 
    {
        "bin/" .. outputdir .. "/GLFW"
    }

    links
    {
        "GLFW",
        -- "GLAD"
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
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Keisan")
        }
    
    filter "configurations:Debug"
        defines "KZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "KZ_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "KZ_DIST"
        optimize "On"

project "Keisan"
    location "Keisan"
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
        "KineZ/vendor/GLFW/include",
        "KineZ/vendor/GLAD/include",
        "KineZ/vendor/GLM/",
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
    
    filter "configurations:Dist"
        defines "KZ_DIST"
        optimize "On"