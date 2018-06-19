#include <core/Godot.hpp>
#include <core/String.hpp>
#include <Reference.hpp>


using namespace godot;

// NOTE: Change the Class name
class HelloWorld : public GodotScript<Reference> {
	GODOT_CLASS(HelloWorld);
	
public:
	HelloWorld() {}
	
	// Ex. 1: Prints Hello World
	void greet1(){
		return Godot::print("Hello World!");
	}

	// Ex. 2: Demonstrates argument and return. Returns a string
	String greet2(String your_name){
		return "Hello " + your_name;
	}


	// NOTE: Register your methods here.	
	static void _register_methods(){
        register_method("greet", &HelloWorld::greet1);
		register_method("greet_with_name", &HelloWorld::greet2);
	}

};


/** GDNative Initialize **/
extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o)
{
    Godot::gdnative_init(o);
}

/** GDNative Terminate **/
extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o)
{
    Godot::gdnative_terminate(o);
}

/** NativeScript Initialize **/
extern "C" void GDN_EXPORT godot_nativescript_init(void *handle)
{
    Godot::nativescript_init(handle);
	// NOTE: Change the Class name
    register_class<HelloWorld>();
}
