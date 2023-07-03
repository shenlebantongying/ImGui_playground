#include "utils.h"
#include <cstdlib>
#include <cstring>

void force_wayland()
{
    const char* XDG_SESSION_TYPE = getenv("XDG_SESSION_TYPE");
    if (XDG_SESSION_TYPE != nullptr && (strcmp(XDG_SESSION_TYPE, "wayland") == 0)) {
        setenv("SDL_VIDEODRIVER", "wayland", 1);
    }
}