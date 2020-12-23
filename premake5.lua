workspace "Pulio"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Pulio/3rdparty/GLFW"

project "Pulio"
   location "Pulio"
   kind "SharedLib"
   language "C++"
   staticruntime "on"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}/")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}/")

   pchheader "plpch.h"
   pchsource "%{prj.name}/src/plpch.cpp"

   files 
   { 
       "%{prj.name}/src/**.h", 
       "%{prj.name}/src/**.cpp" 
   }

   includedirs
   {
       "Pulio/src",
       "Pulio/3rdparty/spdlog/include",
       "Pulio/3rdparty/GLFW/include"
   }

   links
   {
       "GLFW",
       "opengl32.lib"
   }

   filter "system:windows"
        cppdialect "c++17"
        systemversion "latest"
    
    defines 
    {
        "PL_PLATFORM_WINDOWS",
        "PL_BUILD_DLL"
        --"GLFW_INCLUDE_NONE"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "configurations:Debug"
        defines "PL_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "PL_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "PL_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"
 
    targetdir ("bin/" .. outputdir .. "/%{prj.name}/")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}/")
 
    files 
    { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.cpp" 
    }
 
    includedirs
    {
        "Pulio/3rdparty/spdlog/include",
        "Pulio/src"
    }

    links
    {
        "Pulio"
    }
 
    filter "system:windows"
         cppdialect "c++17"
         systemversion "latest"
     
     defines 
     {
         "PL_PLATFORM_WINDOWS"
     }
 
     filter "configurations:Debug"
         defines "PL_DEBUG"
         buildoptions "/MDd"
         symbols "on"
 
     filter "configurations:Release"
         defines "PL_RELEASE"
         buildoptions "/MD"
         optimize "on"
 
     filter "configurations:Dist"
         defines "PL_DIST"
         buildoptions "/MD"
         optimize "on"