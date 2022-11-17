# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Laero/Programming/cpp/spic-prj/game/cmake-build-debug/_deps/unengine-src"
  "C:/Users/Laero/Programming/cpp/spic-prj/game/cmake-build-debug/_deps/unengine-build"
  "C:/Users/Laero/Programming/cpp/spic-prj/game/cmake-build-debug/_deps/unengine-subbuild/unengine-populate-prefix"
  "C:/Users/Laero/Programming/cpp/spic-prj/game/cmake-build-debug/_deps/unengine-subbuild/unengine-populate-prefix/tmp"
  "C:/Users/Laero/Programming/cpp/spic-prj/game/cmake-build-debug/_deps/unengine-subbuild/unengine-populate-prefix/src/unengine-populate-stamp"
  "C:/Users/Laero/Programming/cpp/spic-prj/game/cmake-build-debug/_deps/unengine-subbuild/unengine-populate-prefix/src"
  "C:/Users/Laero/Programming/cpp/spic-prj/game/cmake-build-debug/_deps/unengine-subbuild/unengine-populate-prefix/src/unengine-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Laero/Programming/cpp/spic-prj/game/cmake-build-debug/_deps/unengine-subbuild/unengine-populate-prefix/src/unengine-populate-stamp/${subDir}")
endforeach()
