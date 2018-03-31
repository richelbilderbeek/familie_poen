TEMPLATE = app
CONFIG += console c++14
QMAKE_CXXFLAGS += -std=c++14
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror

CONFIG -= app_bundle
CONFIG -= qt

include(familie_poen.pri)
include(familie_poen_test.pri)

SOURCES += \
    main_test.cpp

# Boost.Test
LIBS += -lboost_unit_test_framework

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
