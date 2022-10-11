//#include "main.h"
//
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, GLFW_TRUE);
//    else if (key == GLFW_KEY_W && action == GLFW_PRESS)
//        std::cout << "W" << std::endl;
//}
//
//int mainx()
//{
//    std::vector<GLfloat> vertices;
//
//    float loop_start = -1 / 8;
//    float loop_stop = 1 / 8;
//
//    int steps = 8;
//
//    for (int i = -4; i < 4; i++)
//    {
//        float i_ind = static_cast<float>(i);
//        i_ind *= 0.125;
//
//        vertices.push_back(0.0f);
//        vertices.push_back(i_ind);
//        vertices.push_back(0.5f);
//
//        for (int j = -4; j < 4; j++)
//        {
//            float j_ind = static_cast<float>(j);
//            j_ind *= 0.125;
//
//            vertices.push_back(j_ind + 0.125);
//            vertices.push_back(i_ind);
//            vertices.push_back(i_ind);
//
//            vertices.push_back(j_ind + 0.125);
//            vertices.push_back(i_ind + 0.125);
//            vertices.push_back(i_ind);
//        }
//    }
//    // vertices.push_back(0);
//    // vertices.push_back(0);
//    // vertices.push_back(0);
//
//    // vertices.push_back(0.01);
//    // vertices.push_back(0.01);
//    // vertices.push_back(0.01);
//
//    GLFWwindow* window = nullptr;
//    glfwInit();
//
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    window = glfwCreateWindow(1920, 1080, "Lab03", NULL, NULL);
//    if (!window)
//    {
//        std::cout << "unable to create window" << std::endl;
//        return 1;
//    }
//
//    //glfwSetKeyCallback(window, key_callback);
//
//    glfwMakeContextCurrent(window);
//    gladLoadGL();
//    glViewport(0, 0, 1080, 1080);
//
//    glfwSwapInterval(1);
//
//    IMGUI_CHECKVERSION();
//    ImGui::CreateContext();
//    ImGuiIO& io = ImGui::GetIO(); (void)io;
//
//    ImGui::StyleColorsDark();
//
//    ImGui_ImplGlfw_InitForOpenGL(window, true);
//    ImGui_ImplOpenGL3_Init("#version 330");
//
//    GLuint VAO, VBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    glBindVertexArray(VAO);
//
//    //bind the VBO
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    //send the data to the GPU
//    int points = vertices.size();
//    glBufferData(GL_ARRAY_BUFFER, points * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
//
//    //Configure the attributes
////	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    // glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//    glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//    //Make it valid
//    glEnableVertexAttribArray(0);
//
//    vertices.clear(); //no need for the data, it is on the GPU now
//
//    // Floor jerry;
//
//    int shader_program = CompileShaders();
//    GLint modelviewParameter = glGetUniformLocation(shader_program, "modelview");
//
//    float bg_color[4] = { 0.20, 0.25, 0.30, 0.50 };
//    float color[4] = { 0.8f, 0.8f, 0.2f, 1.0f };
//    //send the color to the fragment shader
//    glUniform4f(glGetUniformLocation(shader_program, "color"), color[0], color[1], color[2], color[3]);
//
//
//    //glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
//    //glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
//    //glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        glClearColor(bg_color[0], bg_color[1], bg_color[2], bg_color[3]);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        ImGui_ImplOpenGL3_NewFrame();
//        ImGui_ImplGlfw_NewFrame();
//        ImGui::NewFrame();
//
//        //float fov = 65.0f;
//        //float ratio = 1920.0f / 1080.0f;
//        //float near = 0.01f, far = 1000.0f;
//
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        {
//            //cameraPos += cameraFront;
//            //std::cout << cameraPos[2] << std::endl;
//        }
//        else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        {
//            //cameraPos -= cameraFront;
//            //std::cout << cameraPos[2] << std::endl;
//        }
//
//        //      glm::mat4 proj = glm::perspective(fov, ratio, near, far);
//              //// //set the viewing matrix (looking from [0,0,5] to [0,0,0])
//              //glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//              //// //get the modeling matrix from the trackball
//              //glm::mat4 model = glm::mat4(1.0f);
//              //// //premultiply the modelViewProjection matrix
//              //glm::mat4 modelView = proj * view * model;
//              //glUniformMatrix4fv(modelviewParameter, 1, GL_FALSE, glm::value_ptr(modelView));
//
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_POINTS, 0, points / 3);
//        glDrawArrays(GL_LINE_STRIP, 0, points / 3);
//
//        ImGui::Begin("test");
//        ImGui::End();
//
//        ImGui::Render();
//        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    ImGui_ImplOpenGL3_Shutdown();
//    ImGui_ImplGlfw_Shutdown();
//    ImGui::DestroyContext();
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    return 0;
//}