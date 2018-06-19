## My gdnative Hello World
This is my first attempt to make a gdnative. After several trials and errors, I have decided to document what I did in order to make it work.

Note: All steps were done via linux machine.

What you need: 
  * godot_cpp
  * godot_headers 
  * scons 
  * clang

You can clone godot_cpp and godot_headers here or use the one provided in this project:
  * git clone https://github.com/GodotNativeTools/godot_headers
  * git clone https://github.com/GodotNativeTools/godot-cpp

Note: Godot headers content is copied inside godot-cpp\godot-headers

**STEPS**
Compile godot_cpp
  * Go to godot_cpp > src
    * Execute the following command: ```scons generate_bindings="yes" p=linux```
      * Note: generate_bindings="yes" is used so that it will generate all the necesarry hpp files. It should generate a .a file on bin folder			  
		
Go to project folder

Create .so file. You can do it manually by following the instructions below:
  * Execute:
  ```
  clang -fPIC -o src/(cpp-name).os -c src/(cpp-name).cpp -g -O3 -std=c++14 -I- ../godot-cpp/include -I../godot_headers
  ```
  It should create (cpp-name).os on src folder

  * Execute:
  ```
  clang -o lib/(cpp-name).so -shared src/(cpp-name).os -L../godot-cpp/include -L$godot_cpp/bin -lgodot-cpp.linux.64
  ```
  It should create (cpp-name).so on lib folder

  * Note: You can also run the prebuild ./clang_me script inside the project folder (which does the same thing)

**Using the .so file on Godot**
Create a Godot Project
Create a lib folder on your Godot Project
Copy the .so file on your Godot lib folder
Make a GDNative Resource on Godot ( + Sign on inspector > Choose GDNative)
  * Put the Class name (use the name of the class that you use on your cpp file)
  * On Library, Create a new GDNative Library
    * It will give you a list of Platforms. Choose the correct platform.
    * Point it to the .so file that you generated (inside Godot lib)
    * Save the GDNative Library as <name>.gdnlib
    * Save the GDNative Resource as <name>.gdns

Load it via script
  * load the GDNative file to a variable
	```var my_class = load("res://HelloWorld.gdns").new();```
  * You should be able to use the method as
	* ```my_class.greet();```
	* ```my_class.greet("Name") # Returns a String```
	
I have included a built Godot Project with compiled gdnative included.


References:
* https://github.com/GodotNativeTools/godot-cpp/blob/master/README.md
* https://github.com/GodotNativeTools/godot_headers/blob/master/README.md#how-do-i-use-native-scripts-from-the-editor
