TEMPLATE = app
CONFIG += console c++14
QMAKE_CXXFLAGS += -std=c++14

CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main_solver.cpp \
    game.cpp \
    game_state.cpp \
    card.cpp \
    card_color.cpp \
    game_graph.cpp \
    action.cpp \
    action_type.cpp \
    ai.cpp \
    ai_strategy.cpp

HEADERS += \
    game.h \
    game_state.h \
    card.h \
    card_color.h \
    game_graph.h \
    action.h \
    action_type.h \
    ai.h \
    ai_strategy.h
