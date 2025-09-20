workspace "Siphon"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Siphon"
    location "Siphon"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

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

        buildoptions { "/utf-8" }

        defines
        {
            "SPN_PLATFORM_WINDOWS",
            "SPN_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "SPN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SPN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SPN_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputDir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Siphon/vendor/spdlog/include",
        "Siphon/src"
    }

    links
    {
        "Siphon"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        buildoptions { "/utf-8" }

        defines
        {
            "SPN_PLATFORM_WINDOWS",
        }
    
    filter "configurations:Debug"
        defines "SPN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SPN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SPN_DIST"
        optimize "On"