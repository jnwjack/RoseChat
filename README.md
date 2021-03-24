# RoseChat
This project was meant to be a way to learn network programming in C++ using the Boost.Asio library.  I also wanted to try out desktop GUI development using the Fast Light Toolkit (FLTK).  This project was never intended to have a serious release.

## Building with Visual Studio
### Boost.Asio
In order to build this project, FLTK and Boost::asio
From Visual Studio's File menu, select New > Project…

In the left-hand pane of the resulting New Project dialog, select Visual C++ > Win32.

In the right-hand pane, select Win32 Console Application (VS8.0) or Win32 Console Project (VS7.1).

In the name field, enter “RoseChat”

Right-click example in the Solution Explorer pane and select Properties from the resulting pop-up menu

In Configuration Properties > C/C++ > General > Additional Include Directories, enter the path to the Boost root directory, for example

C:\Program Files\boost\boost_1_60_0

In Configuration Properties > C/C++ > Precompiled Headers, change Use Precompiled Header (/Yu) to Not Using Precompiled Headers.2

Copy the files from the repo to the project directory.

From the Build menu, select Build Solution to test if the application builds.
These instructions were obtained here: https://www.boost.org/doc/libs/1_60_0/more/getting_started/windows.html#build-from-the-visual-studio-ide

### FLTK
In Visual C++ you will need to tell the compiler where to find the FLTK header files. This can be done by selecting "Settings" from the "Project" menu and then changing the "Preprocessor" settings under the "C/C++" tab. You will also need to add the FLTK (FLTK.LIB or FLTKD.LIB) and the Windows Common Controls (COMCTL32.LIB) libraries to the "Link" settings. You must also define WIN32.

These instructions were obtained here: https://www.fltk.org/doc-1.3/basics.html#basics_writing
