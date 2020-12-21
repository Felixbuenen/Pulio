workspace "Pulio"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pulio"
   location "Pulio"
   kind "SharedLib"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}/")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}/")

   files 
   { 
       "%{prj.name}/src/**.h", 
       "%{prj.name}/src/**.cpp" 
   }

   includedirs
   {
       "%{prj.name}/src",
       "%{prj.name}/3rdparty/spdlog/include"
   }

   filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"
    
    defines 
    {
        "PL_PLATFORM_WINDOWS",
        "PL_BUILD_DLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "configurations:Debug"
        defines "PL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PL_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
 
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
         staticruntime "On"
         systemversion "latest"
     
     defines 
     {
         "PL_PLATFORM_WINDOWS"
     }
 
     filter "configurations:Debug"
         defines "PL_DEBUG"
         symbols "On"
 
     filter "configurations:Release"
         defines "PL_RELEASE"
         optimize "On"
 
     filter "configurations:Dist"
         defines "PL_DIST"
         optimize "On"