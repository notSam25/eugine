//
// Created by aiden on 8/2/21.
//

#ifndef EUGINE_ENTRYPOINT_H
#define EUGINE_ENTRYPOINT_H

#ifdef EG_PLATFORM_LINUX

extern eg::Application* eg::createApplication();

int main(int argc, char** argv) {

    auto app = eg::createApplication();
    app -> run();
    delete app;
}

#endif

#endif //EUGINE_ENTRYPOINT_H