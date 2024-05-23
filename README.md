**README for Windows Branch**

**CreepySnake Game (Windows)**

This project is a simple yet professionally built snake game using SFML. It is designed to help students understand the basics of game development and C++ programming. The installation and build process is straightforward, ensuring ease of use for educational   purposes.

**Features**

Snake game mechanics
Simple, easy-to-understand codebase
SFML for graphics and event handling

**Prerequisites**
Before you begin, ensure you have met the following requirements:

Windows 10/11
Visual Studio with C++ development tools
CMake
vcpkg
SFML

**Installation**

**Step 1: Install Visual Studio**
Download and install Visual Studio. During the installation, ensure you select the "Desktop development with C++" workload.

**Step 2: Install CMake**
Download and install CMake. Ensure you add CMake to your system PATH during installation.

**Step 3: Install vcpkg**
Clone the vcpkg repository and bootstrap it:

git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat


**Step 4: Install SFML via vcpkg**
Use vcpkg to install SFML:

.\vcpkg install sfml:x64-windows

**Step 5: Integrate vcpkg with CMake**
Integrate vcpkg with CMake:

.\vcpkg integrate install

**Step 6: Clone the CreepySnake Repository**
Clone the repository:

git clone <repository-url>
cd creepySnake

**Step 7: Build the Project**
Open the CMake GUI and configure the project:


Set the source code directory to the creepySnake directory.
Set the build directory to a build directory inside creepySnake.

Click on "Configure" and select the appropriate Visual Studio compiler (e.g., Visual Studio 2019, x64).



Set CMAKE_TOOLCHAIN_FILE to vcpkg/scripts/buildsystems/vcpkg.cmake.



Click on "Generate" and then "Open Project".
In Visual Studio, build the project by selecting "Build > Build Solution".

**Running the Game**
After building, you can run the game from Visual Studio or by navigating to the build directory and running the executable in Debig folder:


Editing the Source Code
To edit the source code, open the solution file in Visual Studio. Ensure you have the necessary SFML libraries installed and configured.
