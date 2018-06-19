extends Node

# class member variables go here, for example:
# var a = 2
# var b = "textvar"


func _ready():
	
	var gdn = load("res://HelloWorld.gdns").new()
	gdn.greet()
	print(gdn.greet_with_name("Vince"))
	

# It is now loading, but the functions are not working
	

	

#func _process(delta):
#	# Called every frame. Delta is time since last frame.
#	# Update game logic here.
#	pass
