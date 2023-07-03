Personal template to abuse imgui as a general UI library

Linux only

* SDL 2.28.1
* imgui 1.89.6
* GLAD/openGL 4.6

* fullScreenUI -> combine flags to show a window covering the whole window
* glDrawRainBow -> draw background via openGL then draw imgui

#### Notes

* Vulkan+SDL2 -> lagging https://github.com/ocornut/imgui/issues/2938