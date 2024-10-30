# <p align="center">Computer Graphics and Animation</p>
<hr>

## Several Codes Related to Computer Graphics and Animation
- DDA Line Algorithm using OpenGL. The code is [here](https://github.com/nishatrhythm/Computer-Graphics-and-Animation/blob/main/ddaLineAlgorithm/main.cpp).
- Mid Point Line Algorithm using OpenGL. The code is [here](https://github.com/nishatrhythm/Computer-Graphics-and-Animation/blob/main/midpointLineAlgorithm/main.cpp).
- Bresenham Line Drawing Algorithm using OpenGL. The code is [here](https://github.com/nishatrhythm/Computer-Graphics-and-Animation/blob/main/bresenhamLineDrawingAlgorithm/main.cpp).
- Mid Point Circle Algorithm using OpenGL. The code is [here](https://github.com/nishatrhythm/Computer-Graphics-and-Animation/blob/main/midpointCircleAlgorithm/main.cpp).

## National Monument of Bangladesh
<img src="images/nationalMonumentOfBangladesh.png" alt="National Monument of Bangladesh" width="500"><br>
- Find the code [here](https://github.com/nishatrhythm/Computer-Graphics-and-Animation/blob/main/Still%20Object%20(2D)/nationalMonumentOfBangladesh/main.cpp).

## Shaheed Minar of Bangladesh
<img src="images/shaheedMinar.png" alt="Shaheed Minar of Bangladesh" width="500"><br>
- Find the code [here](https://github.com/nishatrhythm/Computer-Graphics-and-Animation/blob/main/Still%20Object%20(2D)/shaheedMinarOptimized/main.cpp).

## Create a GLUT Project in CodeBlocks (Windows 64-bit)

### If you install _CodeBlocks with MinGW_ and have _not installed MinGW separately_
- Download and install `codeblocks-20.03mingw-setup.exe` from [here](https://www.codeblocks.org/downloads/binaries).
- Download [this](https://raw.githubusercontent.com/nishatrhythm/Computer-Graphics-and-Animation/main/glut-3.7.6-bin.rar) GLUT file.
- Extract the file using [WinRAR](https://www.rarlab.com/download.htm) or another unzipper software.
- Copy `glut.h` and paste it inside `C:\Program Files\CodeBlocks\MinGW\include\GL`
- Copy `glut32.lib` and paste it inside `C:\Program Files\CodeBlocks\MinGW\lib`
- Copy `glut32.dll` and paste it inside `C:\Windows\SysWOW64`
- Create a new project in CodeBlocks and select the GLUT project. Give a name to your project.
- Select the GLUT location as `C:\Program Files\CodeBlocks\MinGW`

### If you install _CodeBlocks and MinGW separately_
- Download the MinGW downloader from [here](https://sourceforge.net/projects/mingw/files/latest/download).
- Install the basic package of MinGW and add the location `C:\MinGW\bin` to the Environment Variable path.
- Download and install `codeblocks-20.03mingw-setup.exe` from [here](https://www.codeblocks.org/downloads/binaries).
- Download [this](https://raw.githubusercontent.com/nishatrhythm/Computer-Graphics-and-Animation/main/glut-3.7.6-bin.rar) GLUT file.
- Extract the file using [WinRAR](https://www.rarlab.com/download.htm) or another unzipper software.
- Copy `glut.h` and paste it inside `C:\MinGW\include\GL`
- Copy `glut32.lib` and paste it inside `C:\MinGW\lib`
- Copy `glut32.dll` and paste it inside `C:\Windows\SysWOW64`
- Create a new project in CodeBlocks and select the GLUT project. Give a name to your project.
- Select the GLUT location as `C:\MinGW`

