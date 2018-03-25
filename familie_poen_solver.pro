TEMPLATE = app
CONFIG += console c++14
QMAKE_CXXFLAGS += -std=c++14

QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror

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

# Debug and release settings
CONFIG += debug_and_release
CONFIG(release, debug|release) {

  DEFINES += NDEBUG

  # gprof
  QMAKE_CXXFLAGS += -pg
  QMAKE_LFLAGS += -pg
}

CONFIG(debug, debug|release) {

  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov

  # helgrind, for helgrind and memcheck
  QMAKE_LFLAGS += -pthread -Wl,--no-as-needed

  # UBSAN
  QMAKE_CXXFLAGS += -fsanitize=undefined
  QMAKE_LFLAGS += -fsanitize=undefined
  LIBS += -lubsan

}
