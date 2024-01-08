workspace "KineZ"
    architecture "x64"
    startproject "Keisan"

    configurations 
    {
        "Debug",
        "Release",
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "assimp"
  kind "StaticLib"
  language "C++"
  cppdialect "C++17"
  staticruntime "on"

  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

  defines {
      -- "SWIG",
      "ASSIMP_BUILD_NO_OWN_ZLIB",

      "ASSIMP_BUILD_NO_X_IMPORTER",
      "ASSIMP_BUILD_NO_3DS_IMPORTER",
      "ASSIMP_BUILD_NO_MD3_IMPORTER",
      "ASSIMP_BUILD_NO_MDL_IMPORTER",
      "ASSIMP_BUILD_NO_MD2_IMPORTER",
      "ASSIMP_BUILD_NO_PLY_IMPORTER",
      "ASSIMP_BUILD_NO_ASE_IMPORTER",
      -- "ASSIMP_BUILD_NO_OBJ_IMPORTER",
      "ASSIMP_BUILD_NO_AMF_IMPORTER",
      "ASSIMP_BUILD_NO_HMP_IMPORTER",
      "ASSIMP_BUILD_NO_SMD_IMPORTER",
      "ASSIMP_BUILD_NO_MDC_IMPORTER",
      "ASSIMP_BUILD_NO_MD5_IMPORTER",
      "ASSIMP_BUILD_NO_STL_IMPORTER",
      "ASSIMP_BUILD_NO_LWO_IMPORTER",
      "ASSIMP_BUILD_NO_DXF_IMPORTER",
      "ASSIMP_BUILD_NO_NFF_IMPORTER",
      "ASSIMP_BUILD_NO_RAW_IMPORTER",
      "ASSIMP_BUILD_NO_OFF_IMPORTER",
      "ASSIMP_BUILD_NO_AC_IMPORTER",
      "ASSIMP_BUILD_NO_BVH_IMPORTER",
      "ASSIMP_BUILD_NO_IRRMESH_IMPORTER",
      "ASSIMP_BUILD_NO_IRR_IMPORTER",
      "ASSIMP_BUILD_NO_Q3D_IMPORTER",
      "ASSIMP_BUILD_NO_B3D_IMPORTER",
      "ASSIMP_BUILD_NO_COLLADA_IMPORTER",
      "ASSIMP_BUILD_NO_TERRAGEN_IMPORTER",
      "ASSIMP_BUILD_NO_CSM_IMPORTER",
      "ASSIMP_BUILD_NO_3D_IMPORTER",
      "ASSIMP_BUILD_NO_LWS_IMPORTER",
      "ASSIMP_BUILD_NO_OGRE_IMPORTER",
      "ASSIMP_BUILD_NO_OPENGEX_IMPORTER",
      "ASSIMP_BUILD_NO_MS3D_IMPORTER",
      "ASSIMP_BUILD_NO_COB_IMPORTER",
      "ASSIMP_BUILD_NO_BLEND_IMPORTER",
      "ASSIMP_BUILD_NO_Q3BSP_IMPORTER",
      "ASSIMP_BUILD_NO_NDO_IMPORTER",
      "ASSIMP_BUILD_NO_IFC_IMPORTER",
      "ASSIMP_BUILD_NO_XGL_IMPORTER",
      "ASSIMP_BUILD_NO_FBX_IMPORTER",
      "ASSIMP_BUILD_NO_ASSBIN_IMPORTER",
      "ASSIMP_BUILD_NO_GLTF_IMPORTER",
      "ASSIMP_BUILD_NO_C4D_IMPORTER",
      "ASSIMP_BUILD_NO_3MF_IMPORTER",
      "ASSIMP_BUILD_NO_X3D_IMPORTER",
      "ASSIMP_BUILD_NO_MMD_IMPORTER",
      
      "ASSIMP_BUILD_NO_STEP_EXPORTER",
      "ASSIMP_BUILD_NO_SIB_IMPORTER",

      -- "ASSIMP_BUILD_NO_MAKELEFTHANDED_PROCESS",
      -- "ASSIMP_BUILD_NO_FLIPUVS_PROCESS",
      -- "ASSIMP_BUILD_NO_FLIPWINDINGORDER_PROCESS",
      -- "ASSIMP_BUILD_NO_CALCTANGENTS_PROCESS",
      "ASSIMP_BUILD_NO_JOINVERTICES_PROCESS",
      -- "ASSIMP_BUILD_NO_TRIANGULATE_PROCESS",
      "ASSIMP_BUILD_NO_GENFACENORMALS_PROCESS",
      -- "ASSIMP_BUILD_NO_GENVERTEXNORMALS_PROCESS",
      "ASSIMP_BUILD_NO_REMOVEVC_PROCESS",
      "ASSIMP_BUILD_NO_SPLITLARGEMESHES_PROCESS",
      "ASSIMP_BUILD_NO_PRETRANSFORMVERTICES_PROCESS",
      "ASSIMP_BUILD_NO_LIMITBONEWEIGHTS_PROCESS",
      -- "ASSIMP_BUILD_NO_VALIDATEDS_PROCESS",
      "ASSIMP_BUILD_NO_IMPROVECACHELOCALITY_PROCESS",
      "ASSIMP_BUILD_NO_FIXINFACINGNORMALS_PROCESS",
      "ASSIMP_BUILD_NO_REMOVE_REDUNDANTMATERIALS_PROCESS",
      "ASSIMP_BUILD_NO_FINDINVALIDDATA_PROCESS",
      "ASSIMP_BUILD_NO_FINDDEGENERATES_PROCESS",
      "ASSIMP_BUILD_NO_SORTBYPTYPE_PROCESS",
      "ASSIMP_BUILD_NO_GENUVCOORDS_PROCESS",
      "ASSIMP_BUILD_NO_TRANSFORMTEXCOORDS_PROCESS",
      "ASSIMP_BUILD_NO_FINDINSTANCES_PROCESS",
      "ASSIMP_BUILD_NO_OPTIMIZEMESHES_PROCESS",
      "ASSIMP_BUILD_NO_OPTIMIZEGRAPH_PROCESS",
      "ASSIMP_BUILD_NO_SPLITBYBONECOUNT_PROCESS",
      "ASSIMP_BUILD_NO_DEBONE_PROCESS",
      "ASSIMP_BUILD_NO_EMBEDTEXTURES_PROCESS",
      "ASSIMP_BUILD_NO_GLOBALSCALE_PROCESS",
  }

  files {
      "KineZ/vendor/assimp/include/**",
      "KineZ/vendor/assimp/code/Assimp.cpp",
      "KineZ/vendor/assimp/code/BaseImporter.cpp",
      "KineZ/vendor/assimp/code/ColladaLoader.cpp",
      "KineZ/vendor/assimp/code/ColladaParser.cpp",
      "KineZ/vendor/assimp/code/CreateAnimMesh.cpp",
      "KineZ/vendor/assimp/code/PlyParser.cpp",
      "KineZ/vendor/assimp/code/PlyLoader.cpp",
      "KineZ/vendor/assimp/code/BaseProcess.cpp",
      "KineZ/vendor/assimp/code/EmbedTexturesProcess.cpp",
      "KineZ/vendor/assimp/code/ConvertToLHProcess.cpp",
      "KineZ/vendor/assimp/code/DefaultIOStream.cpp",
      "KineZ/vendor/assimp/code/DefaultIOSystem.cpp",
      "KineZ/vendor/assimp/code/DefaultLogger.cpp",
      "KineZ/vendor/assimp/code/GenVertexNormalsProcess.cpp",
      "KineZ/vendor/assimp/code/Importer.cpp",
      "KineZ/vendor/assimp/code/ImporterRegistry.cpp",
      "KineZ/vendor/assimp/code/MaterialSystem.cpp",
      "KineZ/vendor/assimp/code/PostStepRegistry.cpp",
      "KineZ/vendor/assimp/code/ProcessHelper.cpp",
      "KineZ/vendor/assimp/code/scene.cpp",
      "KineZ/vendor/assimp/code/ScenePreprocessor.cpp",
      "KineZ/vendor/assimp/code/ScaleProcess.cpp",
      "KineZ/vendor/assimp/code/SGSpatialSort.cpp",
      "KineZ/vendor/assimp/code/SkeletonMeshBuilder.cpp",
      "KineZ/vendor/assimp/code/SpatialSort.cpp",
      "KineZ/vendor/assimp/code/TriangulateProcess.cpp",
      "KineZ/vendor/assimp/code/ValidateDataStructure.cpp",
      "KineZ/vendor/assimp/code/Version.cpp",
      "KineZ/vendor/assimp/code/VertexTriangleAdjacency.cpp",
      "KineZ/vendor/assimp/code/ObjFileImporter.cpp",
      "KineZ/vendor/assimp/code/ObjFileMtlImporter.cpp",
      "KineZ/vendor/assimp/code/ObjFileParser.cpp",
      "KineZ/vendor/assimp/code/glTFImporter.cpp",
      "KineZ/vendor/assimp/code/glTF2Importer.cpp",
      "KineZ/vendor/assimp/code/MakeVerboseFormat.cpp",
      "KineZ/vendor/assimp/code/CalcTangentsProcess.cpp",
      "KineZ/vendor/assimp/code/ScaleProcess.cpp",
      "KineZ/vendor/assimp/code/EmbedTexturesProcess.cpp",
      "KineZ/vendor/assimp/contrib/irrXML/*",
  }

  includedirs {
      "KineZ/vendor/assimp/include",
      "KineZ/vendor/assimp/contrib/irrXML",
      "KineZ/vendor/assimp/contrib/zlib",
      "KineZ/vendor/assimp/contrib/rapidjson/include",
  }


   filter "system:windows"
      systemversion "latest"

   filter  "configurations:Debug"
       runtime "Debug"
       symbols "on"

   filter  "configurations:Release"
       runtime "Release"
       optimize "on"

project "GLFW"
    kind "StaticLib"
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

        -- prebuildcommands 
        -- {
        --     ("{MKDIR}  bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Keisan/")
        -- }

        -- postbuildcommands 
        -- {
        --     ("{COPY} bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/GLFW/GLFW.dll bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Keisan/")
        -- }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        optimize "On"


project "KineZ"
    location "KineZ"
    kind "StaticLib"
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
        "%{prj.name}/vendor/GLAD/include",
        "%{prj.name}/vendor/GLM/",
        "%{prj.name}/vendor/STB/include",
        "%{prj.name}/vendor/assimp/include"
    }

    libdirs 
    {
        -- "bin/" .. outputdir .. "/GLFW"
        -- "bin/" .. outputdir .. "/assimp"
    }

    links
    {
        "GLFW",
        "assimp"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            -- "KZ_BUILD_DLL",
            "KZ_PLATFORM_WINDOWS"
        }

        -- prebuildcommands 
        -- {
        --     ("{MKDIR}  ../bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Keisan/")
        -- }

        -- postbuildcommands 
        -- {
        --     ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Keisan")
        -- }
    

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
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/shaders/**.glsl"

    }

    includedirs
    {
        "KineZ/vendor/GLFW/include",
        "KineZ/vendor/GLAD/include",
        "KineZ/vendor/GLM/",
        "KineZ/vendor/STB/include",
        "KineZ/src",
        "KineZ/vendor/assimp/include"
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