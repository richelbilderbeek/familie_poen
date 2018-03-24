TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    console_game.cpp \
    game_state.cpp \
    card.cpp \
    card_color.cpp

HEADERS += \
    game.h \
    console_game.h \
    game_state.h \
    card.h \
    card_color.h
