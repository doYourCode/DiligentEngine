# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Repos/DiligentEngine/DiligentSamples/Samples/GLTFViewer/assets/models"
  "D:/Repos/DiligentEngine/_deps/gltfassets-build"
  "D:/Repos/DiligentEngine/_deps/gltfassets-subbuild/gltfassets-populate-prefix"
  "D:/Repos/DiligentEngine/_deps/gltfassets-subbuild/gltfassets-populate-prefix/tmp"
  "D:/Repos/DiligentEngine/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src/gltfassets-populate-stamp"
  "D:/Repos/DiligentEngine/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src"
  "D:/Repos/DiligentEngine/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src/gltfassets-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Repos/DiligentEngine/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src/gltfassets-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Repos/DiligentEngine/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src/gltfassets-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
