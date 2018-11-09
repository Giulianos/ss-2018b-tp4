cmake_minimum_required(VERSION 3.7)
project(ss_tp4)

set(CMAKE_CXX_STANDARD 11)

add_executable(ss_tp4 main.cpp types/Body.cpp types/Body.h forces/Force.h integrators/Integrator.h forces/GForce.cpp forces/GForce.h forces/SumForce.cpp forces/SumForce.h integrators/Beeman.cpp integrators/Beeman.h types/Space.cpp types/Space.h utils/LaunchSetup.cpp utils/LaunchSetup.h utils/ParamsManager.cpp utils/ParamsManager.h observers/Observer.h observers/OvitoObserver.cpp observers/OvitoObserver.h observers/MinimumJupiterDistanceObserver.cpp observers/MinimumJupiterDistanceObserver.h)