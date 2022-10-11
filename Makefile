all:
	g++ ./*.cpp ./include/imgui/*.cpp ./include/imgui/backends/imgui_impl_glfw.cpp ./include/imgui/backends/imgui_impl_opengl3.cpp -o main -lglfw -lglad

	./main