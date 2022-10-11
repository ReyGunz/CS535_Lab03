#include "main.h"

void shader_swap(Shader* shader, Shader* curr)
{
    shader->on();
    curr = shader;
}




void DEBUG_SCREEN(Mouse* mouse, Camera* cam, Shader* shader)
{
    ImGui::SetNextWindowSize(ImVec2(360, 480));
    ImGui::Begin("DEBUG");
    if (ImGui::CollapsingHeader("Camera"))
    {
        ImGui::Text("t: %f", cam->t);
        ImGui::Text("Camera Position: (%f, %f, %f)", cam->position.x, cam->position.y, cam->position.z);
        ImGui::Text("Camera Front: (%f, %f, %f)", cam->front.x, cam->front.y, cam->front.z);
    }
    if (ImGui::CollapsingHeader("Screen"))
    {
        ImGui::Text("Cursor Position: (%f, %f)", mouse->x, mouse->y);
    }
    if (ImGui::CollapsingHeader("Mouse"))
    {
        ImGui::Text("Mouse Front: (%f, %f, %f)", mouse->front.x, mouse->front.y, mouse->front.z);
        ImGui::Text("Mouse Rear: (%f, %f, %f)", mouse->back.x, mouse->back.y, mouse->back.z);
        ImGui::Text("Mouse Left: (%f, %f, %f)", mouse->left.x, mouse->left.y, mouse->left.z);
        ImGui::Text("Mouse Right: (%f, %f, %f)", mouse->right.x, mouse->right.y, mouse->right.z);
    }
    if (ImGui::CollapsingHeader("Shader"))
    {
        ImGui::Text("Shader ID: %d", shader->ID);
    }

    ImGui::End();
}

void MINI_MAP(Camera* camera, Mouse* mouse)
{
    ImGui::SetNextWindowSize(ImVec2(380, 400));
    ImGui::SetNextWindowPos(ImVec2(1920 - 380, 0));
    ImGui::Begin("Mini-Map");
    static ImVec2 scrolling(0.0f, 0.0f);

    ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();      // ImDrawList API uses screen coordinates!
    ImVec2 canvas_sz = ImGui::GetContentRegionAvail();   // Resize canvas to what's available
    if (canvas_sz.x < 50.0f) canvas_sz.x = 50.0f;
    if (canvas_sz.y < 50.0f) canvas_sz.y = 50.0f;
    ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);

    ImGuiIO& io = ImGui::GetIO();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(128, 255, 128, 64));
    draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));
    ImGui::InvisibleButton("canvas", canvas_sz, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
    const ImVec2 origin(canvas_p0.x + scrolling.x, canvas_p0.y + scrolling.y); // Lock scrolled origin
    const ImVec2 mouse_pos_in_canvas(io.MousePos.x - origin.x, io.MousePos.y - origin.y);

    float factor = mm_w / (2 * floor_w);
    float new_x = factor * (camera->position.x + floor_w), new_y = factor * (camera->position.z + floor_w);
    new_x += canvas_p0.x; new_y += canvas_p0.y;
    glm::vec2 center = glm::vec2(new_x,new_y);
    glm::vec2 new_front = glm::vec2(mouse->front.x, mouse->front.z);
    glm::vec2 new_left = glm::vec2(mouse->left.x, mouse->left.z);
    glm::vec2 new_right = glm::vec2(mouse->right.x, mouse->right.z);
    glm::vec2 new_rear = glm::vec2(mouse->back.x, mouse->back.z);

    draw_list->PushClipRect(canvas_p0, canvas_p1, true);

    const float GRID_STEP = 23.0f;
    int mid_x = (canvas_p0.x + canvas_p1.x) / 2;
    int mid_y = (canvas_p0.y + canvas_p1.y) / 2;

    for (float x = fmodf(scrolling.x, GRID_STEP); x < canvas_sz.x; x += GRID_STEP)
    {
        int x_index = canvas_p0.x + x;
        draw_list->AddLine(ImVec2(x_index, canvas_p0.y), ImVec2(x_index, canvas_p1.y), IM_COL32(200, 200, 200, 40));
    }
    draw_list->AddLine(ImVec2(mid_x, canvas_p0.y), ImVec2(mid_x, canvas_p1.y), IM_COL32(0, 200, 20, 255), 3.0);

    for (float y = fmodf(scrolling.y, GRID_STEP); y < canvas_sz.y; y += GRID_STEP)
    {
        int y_index = canvas_p0.y + y;
        draw_list->AddLine(ImVec2(canvas_p0.x, y_index), ImVec2(canvas_p1.x, y_index), IM_COL32(200, 200, 200, 40));
    }
    draw_list->AddLine(ImVec2(canvas_p0.x, mid_y), ImVec2(canvas_p1.x, mid_y), IM_COL32(0, 200, 20, 255), 3.0);

    glm::vec2 p1 = glm::round(center + 9.0f * new_front);
    glm::vec2 p2 = glm::round(center + 5.0f * (new_left + new_rear));
    glm::vec2 p3 = glm::round(center + 5.0f * (new_right + new_rear));
    float scale = 1.0f;

    ImVec2 f = ImVec2(scale * p1.x, scale * p1.y);
    ImVec2 l = ImVec2(scale * p2.x, scale * p2.y);
    ImVec2 r = ImVec2(scale * p3.x, scale * p3.y);
    draw_list->AddTriangleFilled(f, l, r, IM_COL32(255,64,64,224));

    //draw_list->PopClipRect();

    ImGui::End();
}

int main()
{
    GLFWwindow* window = nullptr;
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "Lab03", NULL, NULL);
    if(!window)
    {
        std::cout << "unable to create window" << std::endl;
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
	glViewport(0, 0, width, height);
    glfwSwapInterval(1);
    glEnable(GL_DEPTH_TEST);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    Shader first_shader("1.vert", "1.frag");
    //Shader second_shader("2.vert", "2.frag");
    Shader* curr_shader = &first_shader;
    shader_swap(&first_shader, curr_shader);
    //first_shader.send_color();

    Camera cam(width, height, Vec3(0,0,0));
    cam.set_bounds(-floor_w,floor_w,-1,1,-floor_w,floor_w);
    Mouse mouse;

    Floor floor(floor_w, floor_h);
    //Ceiling ceiling(ceiling_w, ceiling_h);

    Dummy crash;
    Ammo bullet;

    while(!glfwWindowShouldClose(window))
    {
        cam.clear();
        cam.ins(window, mouse);
        cam.M(fov, near, far, first_shader, "cam_M");
        cam.boundary();

        floor.draw();
        //crash.draw();
        bullet.draw();
        //ceiling.draw();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        DEBUG_SCREEN(&mouse, &cam, curr_shader);
        MINI_MAP(&cam, &mouse);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


        glfwSwapBuffers(window);
        glfwPollEvents();

        cam.step();
    }

    first_shader.deleet();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}