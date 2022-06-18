
workspace "CatEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

project "CatEngine"
    location "CatEngine"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    editAndContinue "Off"
    
    pchheader "precompiled/pch.hpp"
	pchsource("%{prj.name}/src/precompiled/pch.cpp")

	editAndContinue "Off"
    
    files
    {
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.hpp",
    }

    excludes 
    {
    }

    defines
    {
        "C_DEBUG"
    }
    
    ignoredefaultlibraries 
    { 
    }

    removefiles
    {
    }

    -- Directories to be included (libraries, plug-ins, etc)
    includedirs
    {
        "%{prj.name}/src/",
        "%{prj.name}/Dep/",
    }

    libdirs
    {
    }

    links
    {
    }

    postbuildcommands
    {
    }

    cppdialect "C++17"
    systemversion "latest"

    flags
    {
    }

    filter "configurations:Debug"
        defines "CE_DEBUG"
        symbols "On"

        libdirs
        {
        }

        links
        {
        }

    filter "configurations:Release"
        defines "CE_RELEASE"
        optimize "Speed"

        flags
        {
        }

        libdirs
        {
        }

        links
        {
        }